using fac.AntlrTools;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_Array: IAstExpr, IAst {
		public string ItemDataType { get; set; }
		public IAstExpr InitCount { get; set; }
		public List<IAstExpr> InitValues { get; set; }

		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			InitCount = _cb (InitCount, _deep, _group);
			for (int i = 0; i < InitValues.Count; ++i)
				InitValues[i] = _cb (InitValues[i], _deep, _group);
		}

		public override IAstExpr TraversalCalcType (string _expect_type) {
			if (_expect_type == "") {
				if (ItemDataType == "")
					ItemDataType = GuessType ()[..^2];
			} else if (_expect_type[^2..] != "[]") {
				throw new CodeException (Token, $"无法从数组 {_expect_type} 类型中计算出单项的类型");
			} else {
				ItemDataType = _expect_type[..^2];
			}

			// 处理类型
			InitCount = InitCount.TraversalCalcType ("int");
			for (int i = 0; i < InitValues.Count; ++i)
				InitValues[i] = InitValues[i].TraversalCalcType (ItemDataType);
			ExpectType = $"{ItemDataType}[]";
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override string GuessType () {
			if (ItemDataType != "")
				return $"{ItemDataType}[]";
			return $"{TypeFuncs.GetCompatibleType ((from p in InitValues select p.GuessType ()).ToArray ())}[]";
		}
	}
}
