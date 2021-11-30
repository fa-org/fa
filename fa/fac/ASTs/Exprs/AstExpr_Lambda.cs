using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_Lambda: IAstExpr {
		public FaParser.LambdaExprContext LambdaExprCtx { init; get; }
		public IAstType ReturnType { get; set; } = null;
		public List<(IAstType _type, string _name)> Arguments { get; set; } = null;
		//public List<(IAstType _type, string _name)> CaptureVars { init; get; }
		//// TODO: 假如为true，那么捕获后的变量不可访问。假如在代码过程中捕获，那么要求之后的流程都不能访问变量；假如在循环里捕获，那么要求循环体任何地方都不能访问变量
		//public bool MoveCapture { get; } = false;
		public List<IAstStmt> BodyCodes { get; set; } = null;



		/// <summary>
		/// 初始化lambda
		/// </summary>
		/// <remarks>lambda表达式特殊性在于，必须悉知类型才能解析，此处独立出一个函数用于指定类型</remarks>
		/// <param name="_expect_type"></param>
		public void InitLambda (IAstType _expect_type) {
			Arguments = (from p in LambdaExprCtx.typeVar2List ().typeVar2 () select (_type: p.type () != null ? IAstType.FromContext (p.type ()) : null, _name: p.id ().GetText ())).ToList ();
			if (_expect_type is AstType_Func _functype) {
				ReturnType = _functype.ReturnType;
				if (_functype.ArgumentTypes.Count != Arguments.Count)
					throw new CodeException (Token, $"lambda 表达式参数数量与期望不匹配，期望 {_functype.ArgumentTypes.Count} 个参数，实际 {Arguments.Count} 个参数");
				for (int i = 0; i < Arguments.Count; ++i) {
					if (Arguments[i]._type != null) {
						if (!Arguments[i]._type.IsSame (_functype.ArgumentTypes[i]))
							throw new CodeException (Token, $"lambda 表达式第 {i} 个参数类型不匹配，期望 {_functype.ArgumentTypes[i]}，实际 {Arguments[i]._type}");
						Arguments[i] = (_type: _functype.ArgumentTypes[i], _name: Arguments[i]._name);
					}
				}
				BodyCodes = TypeFuncs.GetFuncBodyCodes (Token, ReturnType, LambdaExprCtx.expr (), LambdaExprCtx.stmt ());
			} else {
				throw new CodeException (Token, "lambda 表达式期望类型必须为 Func<>");
			}
		}

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			BodyCodes.Traversal (_deep + 2, 0, _cb);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (ReturnType == null)
				throw new CodeException (Token, "此处无法声明 lambda 表达式主体");
			BodyCodes.TraversalCalcType ();
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			return new AstType_Func { Token = Token, ReturnType = ReturnType, ArgumentTypes = (from p in Arguments select p._type).ToList () };
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			_sb.Append ("(").Append (string.Join (", ", from p in Arguments select p._name)).Append (") => {");
			_sb.AppendStmts (BodyCodes, _indent + 1);
			_sb.Append ($"{_indent.Indent ()}}}");
			return ("", _sb.ToString (), "");
		}

		public override bool AllowAssign () => false;
	}
}
