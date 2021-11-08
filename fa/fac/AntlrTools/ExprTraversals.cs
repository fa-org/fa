using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	[Flags]
	enum TraversalType {
		Root2Leaf = 1, // 从 表达式组合 遍历到 最基本元素，如果两种枚举方式皆存在则此种方式优先
		Leaf2Root = 2, // 从 最基本元素 遍历到 表达式组合，如果两种枚举方式皆存在则此种方式滞后
		CalcVar = 4, // 如果有此标识则计算 Info.CurrentFuncVariables
	}

	class ExprTraversals {
		public static List<TraversalType> TraversalTypes { get; } = new List<TraversalType> {
			TraversalType.Root2Leaf | TraversalType.CalcVar,
			TraversalType.Leaf2Root,
			TraversalType.Root2Leaf | TraversalType.Leaf2Root,
		};

		/// <summary>
		/// 枚举函数节点处理函数，每次遍历到的每一个节点都将调用此方法
		/// </summary>
		/// <param name="_expr">当前遍历到的节点</param>
		/// <param name="_index">第几轮节点遍历，不同数字需调用不同处理方法</param>
		/// <param name="_deep">函数内部作用域深度，默认0，有个大括号那么深度+1</param>
		/// <param name="_group">作用域深度组，比如if跳到else，深度相同，但非不同组，那么前组变量需清空</param>
		/// <returns></returns>
		public static IAstExpr Traversal (IAstExpr _expr, int _index, int _deep, int _group) {
			// 计算 Info.CurrentFuncVariables
			if (_deep != 0 && (TraversalTypes[_index] | TraversalType.CalcVar) > 0) { // _deep 为 0 代表类成员变量计算，不需计算方法变量，故跳过
				if (_deep > Info.CurrentFuncVariables.Count) {
					Info.CurrentFuncVariables.Add ((_vars: new Dictionary<string, ASTs.Stmts.AstStmt_DefVariable> (), _group));
					if (_deep != Info.CurrentFuncVariables.Count)
						throw new Exception ("节点遍历错误：不允许存在跳动过大的节点");
				} else {
					while (_deep < Info.CurrentFuncVariables.Count)
						Info.CurrentFuncVariables.RemoveAt (Info.CurrentFuncVariables.Count - 1);
					if (Info.CurrentFuncVariables[^1]._group != _group)
						Info.CurrentFuncVariables[^1] = (_vars: new Dictionary<string, ASTs.Stmts.AstStmt_DefVariable> (), _group: _group);
				}
			}

			if (_index == 0) {
				return Traversal0 (_expr);
			} else if (_index == 1) {
				return Traversal1 (_expr);
			} else if (_index == 2) {
				return Traversal2 (_expr);
			} else {
				throw new NotImplementedException ();
			}
		}

		// 第一遍遍历
		private static IAstExpr Traversal0 (IAstExpr _expr) {
			if (_expr is AstStmt_DefVariable _varexpr) {
				// 生成变量定义组
				Info.CurrentFuncVariables[^1]._vars.Add (_varexpr.VarName, _varexpr);
			} else if (_expr is AstExpr_BaseId _idexpr) {
				// 映射变量名/参数
				var _nameexpr = IAstExprName.FindVariableOrArgument (_idexpr.Token, _idexpr.Id);
				if (_nameexpr != null)
					return _nameexpr;
			}
			return _expr;
		}

		// 第二遍遍历
		private static IAstExpr Traversal1 (IAstExpr _expr) {
			if (_expr is AstExpr_Op1 _op1 && (!_op1.IsPrefix) && _op1.Operator[0] == '.') {
				if (_op1.Value is AstExpr_BaseId _base_id) {
					string _name = $"{_base_id.Id}{_op1.Operator}";
					var _nameexpr = IAstExprName.FindClass (_base_id.Token, _name);
					if (_nameexpr != null) {
						// 映射类名称
						return _nameexpr;
					} else {
						// 合并冗余名称
						return new AstExpr_BaseId { Token = _base_id.Token, Id = _name };
					}
				}
			}
			return _expr;
		}

		// 第三遍遍历
		private static IAstExpr Traversal2 (IAstExpr _expr) {
			// 不允许再出现 AstExpr_BaseId 类型
			if (_expr is AstExpr_BaseId _idexpr)
				throw new CodeException (_expr.Token, $"未识别的标识符 {_idexpr.Id}");
			return _expr;
		}



		// 第四遍遍历，只需传根节点
		public static IAstExpr TraversalCalcType (IAstExpr _expr, string _expect_type, bool _force_assign) {
			if (_expr is AstExprName_Argument _argexpr) {

			}
			if (_expr is IAstStmt) {
				_expr.Traversal (0, 0, (_child, _, _) => TraversalCalcType (_child, "", false));
				return _expr;
			} else if (_expr is AstExpr_Array _arrexpr) {
				// 确定列表每一项的类型
				if (_arrexpr.ItemDataType == "") {
					if (_expect_type == "") {
						_arrexpr.ItemDataType = GetCompatibleType ((from p in _arrexpr.InitValues select GuessType (p)).ToList ());
						if (_arrexpr.ItemDataType == "")
							throw new CodeException (_expr.Token, "无法计算表达式类型");
					} else if (_expect_type[^2..] != "[]") {
						throw new CodeException (_expr.Token, $"期望获得 {_expect_type} 类型，但实际是数组类型");
					} else {
						_arrexpr.ItemDataType = _expect_type[..^2];
					}
				} else {
					string _real_type = $"{_arrexpr.ItemDataType}[]";
					if (_expect_type != _real_type) {
						if (AllowTypeCast (_real_type, _expect_type)) {
							return new AstExprTypeCast { ExpectType = _expect_type, Token = _expr.Token, Value = TraversalCalcType (_expr, _real_type, _force_assign) };
						} else {
							throw new CodeException (_expr.Token, $"类型 {_real_type} 无法转为类型 {_expect_type}");
						}
					}
				}

				// 处理类型
				_arrexpr.InitCount = TraversalCalcType (_arrexpr.InitCount, "int", false);
				for (int i = 0; i < _arrexpr.InitValues.Count; ++i)
					_arrexpr.InitValues[i] = TraversalCalcType (_arrexpr.InitValues[i], _arrexpr.ItemDataType, false);
				return _arrexpr;
			} else if (_expr is AstExpr_Array _arrexpr) {

			}

			throw new UnimplException (_expr.Token);
		}
	}
}
