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

namespace fac.ASTs {
	public class AstClassFunc: IAst {
		public PublicLevel Level { init; get; }
		public bool Static { init; get; }
		public string Name { init; get; }
		public IAstType ReturnType { init; get; }
		public List<(IAstType _type, string _name)> Arguments { init; get; }
		public FaParser.ClassFuncBodyContext BodyRaw { init; get; }
		public List<IAstStmt> BodyCodes { get; private set; } = null;

		public AstType_Func FuncType {
			get => new AstType_Func { Token = Token, ReturnType = ReturnType, ArgumentTypes = (from p in Arguments select p._type).ToList () };
		}



		public AstClassFunc (FaParser.ClassFuncContext _ctx) {
			Token = _ctx.Start;
			//
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			//
			Static = _ctx.Static () != null;
			//
			Name = _ctx.classFuncName ().GetText ();
			//
			ReturnType = IAstType.FromContext (_ctx.type ());
			//
			Arguments = AstElemParser.Parse (_ctx.typeVarList ());
			//
			BodyRaw = _ctx.classFuncBody ();
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
				if (_arg._type.Mut) {
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
