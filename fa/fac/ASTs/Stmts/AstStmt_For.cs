using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Stmts {
	public class AstStmt_For: IAstStmt {
		public List<IAstStmt> Initializes { get; set; }
		public IAstExpr Condition { get; set; }
		public List<IAstExpr> Increment { get; set; }
		public List<IAstStmt> BodyCodes { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			Initializes.Traversal (_deep, _group, _cb);
			Condition = _cb (Condition, _deep, _group);
			Increment.Traversal (_deep, _group, _cb);
			BodyCodes.Traversal (_deep + 1, 0, _cb);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (_expect_type != null)
				throw new Exception ("语句类型不可指定期望类型");
			Initializes.TraversalCalcType ();
			if (Info.CurrentFunc.ReturnType is AstType_OptionalWrap) {
				try {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
				} catch (Exception) {
					Condition = Condition.TraversalCalcType (IAstType.FromName ("bool?"));
				}
			} else {
				Condition = Condition.TraversalCalcType (IAstType.FromName ("bool"));
			}
			Increment.TraversalCalcType ();
			BodyCodes.TraversalCalcType ();
			return this;
		}

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"{_indent.Indent ()}{{");
			string _a, _b, _c;
			foreach (var _initlize in Initializes) {
				(_a, _b, _c) = _initlize.GenerateCSharp (_indent + 1, Common.NoCheck (_initlize.Token));
				_sb.Append ($"{_a}{_b}{_c}");
			}
			(_a, _b, _c) = Condition.GenerateCSharp (_indent + 1, Common.NoCheck (Condition.Token));
			if (_a != "" || _c != "")
				throw new CodeException (Condition.Token, "条件不允许带隐藏逻辑的表达式");
			_sb.Append ($"{(_indent + 1).Indent ()}for (; {_b}; ");
			for (int i = 0; i < Increment.Count; ++i) {
				(_a, _b, _c) = Increment[i].GenerateCSharp (_indent + 1, Common.NoCheck (Condition.Token));
				if (_a != "" || _c != "")
					throw new CodeException (Condition.Token, "条件不允许带隐藏逻辑的表达式");
				_sb.Append (_b);
				if (i < Increment.Count - 1)
					_sb.Append (", ");
			}
			_sb.AppendLine ($") {{");
			_sb.AppendStmts (BodyCodes, _indent + 2);
			_sb.AppendLine ($"{(_indent + 1).Indent ()}}}");
			_sb.AppendLine ($"{_indent.Indent ()}}}");
			return ("", _sb.ToString (), "");
		}
	}
}
