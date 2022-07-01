using Antlr4.Runtime;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public class AstExpr_OptError: IAstExpr {
		public string ErrInfo { get; set; } = "";

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			return (new List<IAstStmt> (), this);
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
		}

		public override IAstType GuessType () => new AstType_Error ();

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type is not AstType_Error)
				throw new Exception ("AstExpr_Error 对象的数据类型只能是 AstType_Error");
			ExpectType = _expect_type;
			return this;
		}

		public override string GenerateCSharp (int _indent) {
			throw new NotImplementedException ();
		}

		public override string GenerateCpp (int _indent) => Common.WrapStringValue (ErrInfo);

		public override bool AllowAssign () => false;

		public static AstExpr_OptError MakeFromNull (IToken _token = null) => new AstExpr_OptError { Token = _token, ErrInfo = "对象为 null" };
		public static AstExpr_OptError MakeFromIndexOutOfBounds (IToken _token = null, IAstType _expect_type = null) => new AstExpr_OptError { Token = _token, ExpectType = _expect_type, ErrInfo = "索引超范围" };
		public static AstExpr_OptError MakeFromDivideZero (IToken _token = null, IAstType _expect_type = null) => new AstExpr_OptError { ExpectType = _expect_type, ErrInfo = "除数为0" };
		public static AstExpr_OptError MakeFromNotFound (IToken _token = null, IAstType _expect_type = null) => new AstExpr_OptError { ExpectType = _expect_type, ErrInfo = "未找到" };
	}
}
