using fac.AntlrTools;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_Array: IAstExpr {
		public IAstType ItemDataType { get; set; }
		public IAstExpr InitCount { get; set; }
		public List<IAstExpr> InitValues { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			InitCount = _cb (InitCount, _deep, _group);
			for (int i = 0; i < InitValues.Count; ++i)
				InitValues[i] = _cb (InitValues[i], _deep, _group);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type == null) {
				if (ItemDataType == null)
					ItemDataType = (GuessType () as AstType_ArrayWrap).ItemType;
			} else if (_expect_type is AstType_ArrayWrap _tmptype) {
				ItemDataType = _tmptype.ItemType;
			} else {
				if (ItemDataType == null)
					ItemDataType = (GuessType () as AstType_ArrayWrap).ItemType;
			}

			// 处理类型
			InitCount = InitCount.TraversalCalcType (IAstType.FromName ("int"));
			for (int i = 0; i < InitValues.Count; ++i)
				InitValues[i] = InitValues[i].TraversalCalcType (ItemDataType);
			ExpectType = new AstType_ArrayWrap { Token = Token, ItemType = ItemDataType };
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () {
			if (ItemDataType != null)
				return new AstType_ArrayWrap { Token = Token, ItemType = ItemDataType };
			var _item_type = TypeFuncs.GetCompatibleType (true, (from p in InitValues select p.GuessType ()).ToArray ());
			return new AstType_ArrayWrap { Token = Token, ItemType = _item_type };
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr () {
			var _stmts = new List<IAstStmt> ();
			var _var_id = Common.GetTempId ();
			var _defvar_stmt = new AstStmt_DefVariable { Token = Token, DataType = ExpectType, VarName = _var_id };
			_stmts.Add (_defvar_stmt);
			var _var_expr = new AstExprName_Variable { Token = Token, Var = _defvar_stmt, ExpectType = _defvar_stmt.DataType };
			foreach (var _val in InitValues) {
				var (_stmts1, _val1) = _val.ExpandExpr ();
				_stmts.AddRange (_stmts1);
				_stmts1 = new AstStmt_ExprWrap { Token = _val1.Token, Expr = AstExpr_AccessBuildIn.Array_Add (_var_expr, _val1) }.ExpandStmt ();
				_stmts.AddRange (_stmts1);
			}
			return (_stmts, _var_expr);
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}
