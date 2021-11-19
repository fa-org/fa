using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstEnum: IAst, IAstClass {
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public List<AstEnumItem> ClassEnumItems { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { init; get; }

		//public static bool operator == (AstEnum _l, AstEnum _r) {
		//	return _l.FullName == _r.FullName;
		//}
		//public static bool operator != (AstEnum _l, AstEnum _r) => !(_l.FullName == _r.FullName);

		public AstEnum (FaParser.EnumStmtContext _ctx) {
			Token = _ctx.Start;
			//
			FullName = $"{Info.CurrentNamespace}.{_ctx.Id ().GetText ()}";
			//
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			//
			ClassEnumItems = (from p in _ctx.classEnumItem () select new AstEnumItem (p)).ToList ();
			//
			var _types = (from p in ClassEnumItems where p.AttachType != null select p.AttachType).ToList ();
			for (int i = 0; i < _types.Count - 1; ++i) {
				for (int j = i + 1; j < _types.Count; ++j) {
					if (_types[i].IsSame (_types[j]))
						_types.RemoveAt (j--);
				}
			}
			ClassVars = new List<AstClassVar> { new AstClassVar { Token = null, Level = PublicLevel.Public, Static = false, DataType = IAstType.FromName ("int"), Name = "@index" } };
			ClassVars.AddRange (from p in _types select new AstClassVar { Token = p.Token, Level = PublicLevel.Public, Static = false, DataType = p, DefaultValueRaw = null, Name = Common.GetTempId () });
			//
			ClassFuncs = new List<AstClassFunc> ();
		}

		public int GetRealAttachVarPos (int _enum_index) {
			var _attach_type = ClassEnumItems[_enum_index].AttachType;
			for (int i = 1; i < ClassVars.Count; ++i) {
				if (_attach_type.IsSame (ClassVars[i].DataType))
					return i;
			}
			return -1;
		}

		public void Compile () {
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
					Info.CurrentFuncVariables = new List<(Dictionary<string, AstStmt_DefVariable> _vars, int _group)> ();
					Info.CurrentFuncVariables.Add ((_vars: new Dictionary<string, AstStmt_DefVariable> (), _group: 0));
					//
					for (int k = 0; k < ClassFuncs[j].BodyCodes.Count; ++k) {
						if (Info.TraversalFirst)
							ClassFuncs[j].BodyCodes[k] = ExprTraversals.Traversal (ClassFuncs[j].BodyCodes[k], i, 1, 0) as IAstStmt;
						ClassFuncs[j].BodyCodes[k].TraversalWrap (1, 0, (_expr, _deep, _group) => ExprTraversals.Traversal (_expr, i, _deep, _group));
						if (Info.TraversalLast)
							ClassFuncs[j].BodyCodes[k] = ExprTraversals.Traversal (ClassFuncs[j].BodyCodes[k], i, 1, 0) as IAstStmt;
					}
				}
			}
			foreach (var _func in ClassFuncs) {
				Info.CurrentFunc = _func;
				_func.BodyCodes.TraversalCalcType ();
			}
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			Info.CurrentClass = null;
			Info.CurrentFuncVariables = null;
			//
			var _sb = new StringBuilder ();
			_sb.Append ($"{_indent.Indent ()}{Level.ToString ().ToLower ()} class {FullName[(FullName.LastIndexOf ('.') + 1)..]}");
			_sb.AppendLine ($" {{");
			foreach (var _var in ClassVars) {
				var (_a, _b, _c) = _var.GenerateCSharp (_indent + 1, null);
				_sb.Append (_a).Append (_b).Append (_c);
			}
			foreach (var _func in ClassFuncs) {
				var (_a, _b, _c) = _func.GenerateCSharp (_indent + 1, null);
				_sb.Append (_a).Append (_b).Append (_c);
			}
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return ("", _sb.ToString (), "");
		}
	}
}
