using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.ASTs.Types.Mappings;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	public enum DictionaryApiType { _AccessItem, Add, Remove, ContainsKey, ContainsValue, Clear }
	public class AstExpr_DictionaryAPI_Temp: IAstExpr {
		public IAstExpr Value { get; set; } = null;
		public ArrayApiType AccessType { get; set; }
		public List<IAstExpr> AttachArgs { get; set; } = null;



		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Value != null)
				Value = Value.TraversalWrap (_trav);
			if (AttachArgs != null)
				AttachArgs.TraversalWraps (_trav);
		}

		public static IAstExpr Array_AccessItem (IAstExpr _array, IAstExpr _index) {
			IAstType _item_type = null;
			if (_array.ExpectType is AstTypeMap_Dictionary _dic_type) {
				_item_type = _dic_type.ValueType.Optional;
			} else {
				throw new CodeException (_array.Token, "类型必须指定为数组类型");
			}
			return new AstExpr_DictionaryAPI_Temp { Token = _array.Token, Value = _array, AccessType = ArrayApiType._AccessItem, AttachArgs = new List<IAstExpr> { _index }, ExpectType = _item_type };
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			throw new NotImplementedException ();
		}

		public override IAstType GuessType () {
			throw new NotImplementedException ();
		}

		public override bool AllowAssign () {
			throw new NotImplementedException ();
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			throw new NotImplementedException ();
		}

		public override string GenerateCSharp (int _indent) {
			throw new NotImplementedException ();
		}
	}
}
