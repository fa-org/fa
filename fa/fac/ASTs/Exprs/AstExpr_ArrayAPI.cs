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
	public enum ArrayApiType { _AccessItem, New, Length, Add, AddRange, RemoveAt, IndexOf, LastIndexOf }
	public class AstExpr_ArrayAPI: IAstExpr {
		public IAstExpr Value { get; set; } = null;
		public ArrayApiType AccessType { get; set; }
		public List<IAstExpr> AttachArgs { get; set; } = null;



		public static IAstExpr Array_New (IAstType _type) => new AstExpr_ArrayAPI { AccessType = ArrayApiType.New, ExpectType = _type };

		public static IAstExpr Array_Length (IAstExpr _array) => new AstExpr_ArrayAPI { Token = _array.Token, Value = _array, AccessType = ArrayApiType.Length, ExpectType = IAstType.FromName ("int") };

		public static AstExpr_ArrayAPI Array_MakeMethodAccess (IAstExpr _array, ArrayApiType _type, params IAstExpr[] _items) {
			var _expect_type = _type switch {
				ArrayApiType.Add => IAstType.FromName ("void"),
				ArrayApiType.AddRange => IAstType.FromName ("void"),
				ArrayApiType.RemoveAt => IAstType.FromName ("void"),
				ArrayApiType.IndexOf => IAstType.FromName ("int"),
				ArrayApiType.LastIndexOf => IAstType.FromName ("int"),
				_ => throw new Exception ("不应执行此处代码"),
			};
			return new AstExpr_ArrayAPI { Token = _array.Token, Value = _array, AccessType = _type, AttachArgs = _items.ToList (), ExpectType = _expect_type };
		}

		public static IAstExpr Array_AccessItem (IAstExpr _array, IAstExpr _index, bool _pre_expand) {
			IAstType _item_type = null;
			if (!_pre_expand) {
				if (_array.ExpectType is not AstType_ArrayWrap)
					throw new CodeException (_array.Token, "类型必须指定为数组类型");
				_item_type = (_array.ExpectType as AstType_ArrayWrap).ItemType;
			}
			return new AstExpr_ArrayAPI { Token = _array.Token, Value = _array, AccessType = ArrayApiType._AccessItem, AttachArgs = new List<IAstExpr> { _index }, ExpectType = _item_type };
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (Value != null)
				Value = Value.TraversalWrap (_trav);
			if (AttachArgs != null)
				AttachArgs.TraversalWraps (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType? _expect_type) {
			bool _success = true;
			if (Value != null)
				_success &= Value.TraversalCalcTypeWrap (null, a => Value = a);
			if (AttachArgs != null)
				_success &= AttachArgs.TraversalCalcTypeWrap (null);
			return _success ? AstExprTypeCast.Make (this, _expect_type) : null;
		}

		public override IAstType GuessType () => ExpectType;

		public override (List<IAstStmt>, IAstExpr) ExpandExprAssign (IAstExpr _rval, (IAstExprName _var, AstStmt_Label _pos)? _cache_err) => (new List<IAstStmt> (), this);

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) => (new List<IAstStmt> (), this);

		public override string GenerateCSharp (int _indent) {
			var _b = Value?.GenerateCSharp (_indent) ?? "";
			var _exp = ExpectType?.GenerateCSharp (_indent) ?? "";
			var _attaches = AttachArgs != null ? string.Join (", ", from p in AttachArgs select p.GenerateCSharp (_indent)) : "";
			return AccessType switch {
				ArrayApiType._AccessItem => $"{_b} [{_attaches}]",
				ArrayApiType.New => $"new {_exp} ()",
				ArrayApiType.Length => Value.ExpectType is AstType_ArrayWrap ? $"{_b}.Count" : $"{_b}.Length",
				ArrayApiType.Add => $"{_b}.Add ({_attaches})",
				ArrayApiType.AddRange => $"{_b}.AddRange ({_attaches})",
				ArrayApiType.RemoveAt => $"{_b}.RemoveAt ({_attaches})",
				ArrayApiType.IndexOf => $"{_b}.IndexOf ({_attaches})",
				ArrayApiType.LastIndexOf => $"{_b}.LastIndexOf ({_attaches})",
				_ => throw new NotImplementedException (),
			};
		}

		public override string GenerateCpp (int _indent) => throw new Exception ("不应执行此处代码");

		public override bool AllowAssign () => AccessType == ArrayApiType._AccessItem && Value.AllowAssign ();

		public bool IsChangeData () => AccessType != ArrayApiType.Length && AccessType != ArrayApiType._AccessItem;
	}
}
