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
	public class AstExpr_BaseId: IAstExpr {
		public string Id { get; set; }



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) { }

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			// 单独处理枚举类型，另一部分代码位于AstExpr_OpN.cs
			if (_expect_type is AstType_Class _classty && (_classty.Class.ClassEnumItems?.Count ?? 0) > 0) {
				var _class_enum = AstExprName_ClassEnum_New._FindFromNameUncheckAttach (Token, _classty.Class, Id);
				_class_enum.ExpectType = _expect_type;
				return _class_enum;
			}
			//
			if (ExprTraversals.Init) {
				ExprTraversals.Complete = false;
				return this;
			} else {
				throw new CodeException (Token, $"未定义的标识符 {Id}");
			}
		}

		public override IAstType GuessType () => throw new Exception ("不应执行此处代码");

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => throw new Exception ("不应执行此处代码");

		public override string GenerateCSharp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => throw new UnimplException (Token);
	}
}
