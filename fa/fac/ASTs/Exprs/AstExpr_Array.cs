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



		public override void Traversal ((int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) _trav) {
			InitCount = InitCount.TraversalWrap (_trav);
			InitValues.TraversalWraps (_trav);
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

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = new List<IAstStmt> ();
			var _var_id = Common.GetTempId ();
			var _defvar_stmt = new AstStmt_DefVariable { Token = Token, DataType = ExpectType, VarName = _var_id, Expr = AstExpr_AccessBuildIn.Array_New (ExpectType) };
			_stmts.Add (_defvar_stmt);
			foreach (var _val in InitValues) {
				var (_stmts1, _val1) = _val.ExpandExpr (_cache_err);
				_stmts.AddRange (_stmts1);
				_stmts.Add (AstStmt_ExprWrap.MakeFromExpr (AstExpr_AccessBuildIn.Array_Add (_defvar_stmt.GetRef (), _val1)));
			}
			return (_stmts, _defvar_stmt.GetRef ());
		}

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => false;
	}
}
