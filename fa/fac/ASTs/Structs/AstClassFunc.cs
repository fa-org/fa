using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs {
	public class AstClassFunc: IAst {
		public IAstClass ParentClass { get; set; }
		public PublicLevel Level { init; get; }
		public bool Static { init; get; }
		public string Name { get; set; }
		public IAstType ReturnType { get; set; }
		public List<(IAstType _type, ArgumentTypeExt _ext, string _name)> Arguments { init; get; }
		public FaParser.ClassItemFuncExtBodyContext BodyRaw { init; get; }
		public List<IAstStmt> BodyCodes { get; private set; } = null;

		public AstType_Func FuncType {
			get {
				var _args = new List<(IAstType _type, ArgumentTypeExt _ext)> ();
				if (!Static) {
					_args.Add ((_type: AstType_Class.GetType (Token, ParentClass), _ext: ArgumentTypeExt.None));
				}
				_args.AddRange (from p in Arguments select (_type: p._type, _ext: p._ext));
				return new AstType_Func { Token = Token, ReturnType = ReturnType, ArgumentTypes = _args };
			}
		}



		public AstClassFunc (IAstClass _class, AstClassFunc _src, Func<string, IAstType> _get_impl_type) {
			Token = _src.Token;
			ParentClass = _class;
			Level = _src.Level;
			Static = _src.Static;
			Name = _src.Name;
			ReturnType = _src.ReturnType is AstType_Placeholder _phtype ? _get_impl_type (_phtype.Name) : _src.ReturnType;
			Arguments = new List<(IAstType _type, ArgumentTypeExt _ext, string _name)> ();
			foreach (var (_type, _ext, _name) in _src.Arguments) {
				Arguments.Add ((_type is AstType_Placeholder _phtype1 ? _get_impl_type (_phtype1.Name) : _type, _ext, _name));
			}
			BodyRaw = _src.BodyRaw;
		}

		public AstClassFunc (IAstClass _parent_class, FaParser.ClassItemFuncContext _ctx) {
			if (_parent_class == null)
				throw new NotImplementedException ();
			Token = _ctx.Start;
			ParentClass = _parent_class;
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			Static = _ctx.Static () != null;
			Name = _ctx.id ().GetText ();
			ReturnType = new AstType_TempType (_ctx.type ());
			Arguments = AstElemParser.Parse (_ctx.typeWrapVarList1 ());
			BodyRaw = _ctx.classItemFuncExtBody ();
		}

		public AstClassFunc (IAstClass _parent_class, FaParser.ClassItem2Context _ctx) {
			if (_ctx.classItemFuncExt2 () == null)
				throw new NotImplementedException ();
			Token = _ctx.Start;
			ParentClass = _parent_class;
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			Static = _ctx.Static () != null;
			Name = _ctx.id ().GetText ();
			ReturnType = new AstType_TempType (_ctx.type ());
			Arguments = AstElemParser.Parse (_ctx.classItemFuncExt2 ().typeWrapVarList2 ());
			BodyRaw = _ctx.classItemFuncExt2 ().classItemFuncExtBody ();
		}

		public void ProcessType () {
			if (ReturnType is AstType_TempType _ttype)
				ReturnType = _ttype.GetRealType ();
			for (int i = 0; i < Arguments.Count; ++i) {
				if (Arguments[i]._type is AstType_TempType _ttype1)
					Arguments[i] = (_type: _ttype1.GetRealType (), _ext: Arguments[i]._ext, _name: Arguments[i]._name);
			}
		}

		public void ToAST () {
			Info.CurrentFunc = this;
			BodyCodes = TypeFuncs.GetFuncBodyCodes (Token, ReturnType, BodyRaw.expr (), BodyRaw.stmt ());
		}

		public void ExpandFunc () {
			Info.CurrentFunc = this;
			BodyCodes = TypeFuncs.ExpandFuncCodes (ReturnType, BodyCodes);
		}

		public override string GenerateCSharp (int _indent) {
			Info.CurrentFunc = this;
			var _sb = new StringBuilder ();
			var _b = ReturnType.GenerateCSharp (_indent);
			_sb.Append ($"{_indent.Indent ()}{Level.ToString ().ToLower ()}{(Static ? " static" : "")} {_b} {Name} (");
			foreach (var _arg in Arguments) {
				//if (_arg._type is AstType_ArrayWrap _awrap && _awrap.Params)
				//	_sb.Append ("params ");
				if (_arg._ext == ArgumentTypeExt.Mut) {
					_sb.Append ("ref ");
				}
				_sb.Append ($"{_arg._type.GenerateCSharp (_indent)} {_arg._name}, ");
			}
			if (Arguments.Any ())
				_sb.Remove (_sb.Length - 2, 2);
			_sb.AppendLine (") {");
			_sb.AppendStmts (BodyCodes, _indent + 1);
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return _sb.ToString ();
		}
	}
}
