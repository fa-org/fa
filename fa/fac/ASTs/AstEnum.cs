using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	public class AstEnum: IAst, IAstClass {
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstEnumItem> ClassEnumItems { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { init; get; }
		private bool m_compiled = false;



		public static AstEnum FromContext (FaParser.EnumStmtContext _ctx) {
			var _enum_items = (from p in _ctx.classEnumItem () select new AstEnumItem (p)).ToList ();
			var _types = (from p in _enum_items where p.AttachType != null select p.AttachType).ToList ();
			for (int i = 0; i < _types.Count - 1; ++i) {
				for (int j = i + 1; j < _types.Count; ++j) {
					if (_types[i].IsSame (_types[j]))
						_types.RemoveAt (j--);
				}
			}
			var _vars = new List<AstClassVar> { new AstClassVar { Token = null, Level = PublicLevel.Public, Static = false, DataType = IAstType.FromName ("int"), Name = "@index" } };
			_vars.AddRange (from p in _types select new AstClassVar { Token = p.Token, Level = PublicLevel.Public, Static = false, DataType = p, DefaultValueRaw = null, Name = Common.GetTempId () });
			//
			return new AstEnum {
				Token = _ctx.Start,
				FullName = $"{Info.CurrentNamespace}.{_ctx.id ().GetText ()}",
				Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public,
				ClassEnumItems = _enum_items,
				ClassVars = _vars,
				ClassFuncs = new List<AstClassFunc> (),
			};
		}

		public int GetRealAttachVarPos (int _enum_index) {
			var _attach_type = ClassEnumItems[_enum_index].AttachType;
			for (int i = 1; i < ClassVars.Count; ++i) {
				if (_attach_type.IsSame (ClassVars[i].DataType))
					return i;
			}
			return -1;
		}

		public bool Compile () {
			if (m_compiled)
				return false;
			m_compiled = true;

			Info.CurrentClass = this;
			Info.CurrentFuncVariables = null;

			string _name = FullName[(FullName.LastIndexOf ('.') + 1)..];
			var _sb = new StringBuilder ();
			_sb.Append (@$"public static bool operator== ({_name} _l, {_name} _r) {{
if (_l.@index != _r.@index) {{
	return false;
}}
");
			for (int i = 0; i < ClassEnumItems.Count; ++i) {
				_sb.AppendLine ($" else if (_l.@index == {i}) {{");
				if (ClassEnumItems[i].AttachType == null) {
					_sb.AppendLine ($"return true;");
				} else {
					var _real_var_index = GetRealAttachVarPos (i);
					_sb.AppendLine ($"return _l.{ClassVars[_real_var_index].Name} == _r.{ClassVars[_real_var_index].Name};");
				}
				_sb.AppendLine ($"}}");
			}
			_sb.AppendLine ($" else {{ return false; }}");
			_sb.AppendLine (@$"}}");
			ClassFuncs.Add (Common.ParseCode<AstClassFunc> (_sb.ToString ()));
			ClassFuncs.Add (Common.ParseCode<AstClassFunc> (@$"public static bool operator!= ({_name} _l, {_name} _r) => !(_l == _r);"));
			ClassFuncs[0].ToAST ();
			ClassFuncs[1].ToAST ();

			// 处理AST
			for (int i = 0; i < ExprTraversals.TraversalTypes.Count; ++i) {
				Info.CurrentTraversalType = ExprTraversals.TraversalTypes[i];

				// 类成员方法
				for (int j = 0; j < ClassFuncs.Count; ++j) {
					Info.CurrentFunc = ClassFuncs[j];
					Info.CurrentFuncVariables = new List<Info.FuncArgumentOrVars> ();
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = -1, ClassFunc = Info.CurrentFunc });
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = 0, Vars = new Dictionary<string, AstStmt_DefVariable> () });
					//
					for (int k = 0; k < ClassFuncs[j].BodyCodes.Count; ++k) {
						ClassFuncs[j].BodyCodes[k] = ClassFuncs[j].BodyCodes[k].TraversalWrap ((_deep: 1, _group: 0, _loop: i, _cb: ExprTraversals.Traversal)) as IAstStmt;
					}
				}
			}
			foreach (var _func in ClassFuncs) {
				Info.CurrentFunc = _func;
				_func.BodyCodes.TraversalCalcType ();
			}
			return true;
		}

		public override string GenerateCSharp (int _indent) {
			Info.CurrentClass = null;
			Info.CurrentFuncVariables = null;
			//
			var _sb = new StringBuilder ();
			_sb.Append ($"{_indent.Indent ()}{Level.ToString ().ToLower ()} class {FullName[(FullName.LastIndexOf ('.') + 1)..]}");
			_sb.AppendLine ($" {{");
			foreach (var _var in ClassVars)
				_sb.Append (_var.GenerateCSharp (_indent + 1));
			foreach (var _func in ClassFuncs)
				_sb.Append (_func.GenerateCSharp (_indent + 1));
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}
	}
}
