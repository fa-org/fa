using fac.ASTs;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	[Flags]
	public enum TraversalType {
		Root2Leaf = 1, // 从 表达式组合 遍历到 最基本元素，如果两种枚举方式皆存在则此种方式优先
		Leaf2Root = 2, // 从 最基本元素 遍历到 表达式组合，如果两种枚举方式皆存在则此种方式滞后
		CalcVar = 4, // 如果有此标识则计算 Info.CurrentFuncVariables
	}

	class ExprTraversals {
		public static bool Init = true, Complete = true;
		public static List<TraversalType> TraversalTypes { get; } = new List<TraversalType> {
			TraversalType.Root2Leaf | TraversalType.CalcVar,
			TraversalType.Leaf2Root,
			TraversalType.Root2Leaf | TraversalType.CalcVar,
		};

		/// <summary>
		/// 枚举函数节点处理函数，每次遍历到的每一个节点都将调用此方法
		/// </summary>
		/// <param name="_expr">当前遍历到的节点</param>
		/// <param name="_deep">函数内部作用域深度，默认0，有个大括号那么深度+1</param>
		/// <param name="_group">作用域深度组，比如if跳到else，深度相同，但非不同组，那么前组变量需清空</param>
		/// <param name="_loop">第几轮节点遍历，不同数字需调用不同处理方法</param>
		/// <returns></returns>
		public static IAstExpr Traversal (IAstExpr _expr, int _deep, int _group, int _loop) {
			// 计算 Info.CurrentFuncVariables
			// TODO 这一堆应该放到表达式或语句里去，放此处逻辑不对
			if ((TraversalTypes[_loop] & TraversalType.CalcVar) > 0) { // _deep 为 0 代表类成员变量计算，不需计算方法变量，故跳过
				if (_expr is AstExpr_Lambda _lambdaexpr) {
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = _group + 1, LambdaFunc = _lambdaexpr });
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = _group + 2, Vars = new Dictionary<string, AstStmt_DefVariable> () });
				} else if (_deep >= Info.CurrentFuncVariables.Count) {
					Info.CurrentFuncVariables.Add (new Info.FuncArgumentOrVars { Group = _group, Vars = new Dictionary<string, ASTs.Stmts.AstStmt_DefVariable> () });
					//Info.CurrentFuncVariables.Add ((_vars: new Dictionary<string, ASTs.Stmts.AstStmt_DefVariable> (), _group));
					if (_deep < Info.CurrentFuncVariables.Count - 1)
						throw new Exception ("节点遍历错误：不允许存在跳动过大的节点");
				} else {
					// TODO: 检查切换语句时，后接大括号的情况是否正常
					while (_deep < Info.CurrentFuncVariables.Count - 1)
						Info.CurrentFuncVariables.RemoveAt (Info.CurrentFuncVariables.Count - 1);
					if (Info.CurrentFuncVariables[^1].Group != _group)
						Info.CurrentFuncVariables[^1] = (new Info.FuncArgumentOrVars { Group = _group, Vars = new Dictionary<string, ASTs.Stmts.AstStmt_DefVariable> () });
				}

				if (_expr is AstStmt_DefVariable _varexpr) {
					// 生成变量定义组
					Info.CurrentFuncVariables[^1].Vars.Add (_varexpr.VarName, _varexpr);
				}
			}

			if (_loop == 0) {
				return Traversal0 (_expr);
			} else if (_loop == 1) {
				return Traversal1 (_expr);
			} else if (_loop == 2) {
				return Traversal2 (_expr);
			} else {
				throw new NotImplementedException ();
			}
		}

		// 第一遍遍历
		private static IAstExpr Traversal0 (IAstExpr _expr) {
			if (_expr is AstExpr_BaseId _id_expr) {
				return _id_expr.TryParse ();
			}
			return _expr;
		}

		// 第二遍遍历
		private static IAstExpr Traversal1 (IAstExpr _expr) {
			if (_expr is AstExpr_Op1 _op1_expr) {
				return _op1_expr.TryParse ();
			} else if (_expr is AstExpr_OpN _opn_expr) {
				return _opn_expr.TryParse ();
			}
			return _expr;
		}

		// 第三遍遍历
		private static IAstExpr Traversal2 (IAstExpr _expr) {
			// 不允许再出现 AstExpr_BaseId 类型
			if (_expr is AstExpr_BaseId _idexpr) {
				if (Init) {
					Complete = false;
				} else {
					throw new CodeException (_expr.Token, $"未识别的标识符 {_idexpr.Id}");
				}
			} else if (_expr is AstExpr_Op1 _op1expr && (!_op1expr.IsPrefix) && _op1expr.Operator[0]=='.') {
				if (Init) {
					Complete = false;
				} else {
					throw new CodeException (_expr.Token, $"未识别的成员方法或属性 {_op1expr.Operator[1..]}");
				}
			} else if (_expr is AstExpr_Op2 _op2expr && AstExpr_Op2.sAssignOp2s.Contains (_op2expr.Operator)) {
				if (!_op2expr.Value1.AllowAssign ())
					throw new CodeException (_op2expr.Value1.Token, "目标不可被赋值");
			} else if (_expr is AstStmt_Return _ret_stmt) {
				if (Info.CurrentReturnType ().ToString () == "void?" && _ret_stmt.Expr == null) {
					_ret_stmt.Expr = IAstExpr.OptionalFromOk ();
				}
			}
			return _expr;
		}
	}
}
