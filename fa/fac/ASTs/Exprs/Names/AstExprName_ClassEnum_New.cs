using Antlr4.Runtime;
using fac.ASTs.Stmts;
using fac.ASTs.Structs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public class AstExprName_ClassEnum_New: IAstExprName {
		public IAstClass EnumClass { init; get; }
		public int EnumItemIndex { init; get; }
		public IAstExpr AttachExpr { get; set; }
		public IAstType AttachType {
			get {
				var _type = EnumClass.ClassEnumItems[EnumItemIndex].AttachType;
				return EnumClass is AstTemplateEnumInst _enum_inst ? _enum_inst.GetImplType ((_type as AstType_Placeholder).Name) : _type;
			}
		}
		public string AttachName { get => EnumClass.ClassVars[EnumClass.GetRealAttachVarPos (EnumItemIndex)].Name; }



		//public static AstExprName_ClassEnum_New FindFromName (IToken _token, string _name, IAstExprName _attach_var = null) {
		//	var _class_enum = FindFromNameUncheckAttach (_token, _name);
		//	if (_class_enum == null)
		//		throw new CodeException (_token, $"未识别的标识符 {_name}");
		//	if (_name == "Value") {
		//		if (_attach_var == null)
		//			throw new CodeException (_token, "枚举类型需附带参数");
		//	} else if (_class_enum.EnumClass.ClassEnumItems[_class_enum.EnumItemIndex].AttachType == null && _attach_var != null) {
		//		throw new CodeException (_token, "枚举类型不应附带参数");
		//	}
		//	_class_enum.AttachExpr = _attach_var;
		//	return _class_enum;
		//}

		public static AstExprName_ClassEnum_New _FindFromNameUncheckAttach (IToken _token, string _name) {
			int _pt = _name.LastIndexOf ('.');
			if (_pt == -1)
				return _FindFromNameUncheckAttach (_token, Info.CurrentClass, _name);
			string _class_name = _name[.._pt];
			var _classes = Info.GetClassFromName (_class_name);
			if (_classes.Count == 1) {
				return _FindFromNameUncheckAttach (_token, _classes[0], _name[(_pt + 1)..]);
			} else {
				return null;
			}
		}

		public static AstExprName_ClassEnum_New FindFromName (IToken _token, IAstClass _class, string _name, IAstExpr _attach_var = null) {
			var _class_enum = _FindFromNameUncheckAttach (_token, _class, _name);
			if (_class_enum == null)
				throw new CodeException (_token, $"未识别的标识符 {_name}");
			if (_name == "Value") {
				if (_attach_var == null)
					throw new CodeException (_token, "枚举类型需附带参数");
			} else if (_class_enum.EnumClass.ClassEnumItems[_class_enum.EnumItemIndex].AttachType == null && _attach_var != null) {
				throw new CodeException (_token, _attach_var == null ? "枚举类型需附带参数" : "枚举类型不应附带参数");
			}
			_class_enum.AttachExpr = _attach_var;
			return _class_enum;
		}

		public static AstExprName_ClassEnum_New _FindFromNameUncheckAttach (IToken _token, IAstClass _class, string _name) {
			for (int i = 0; i < _class.ClassEnumItems.Count; ++i) {
				if (_class.ClassEnumItems[i].Name == _name) {
					return new AstExprName_ClassEnum_New { Token = _token, EnumClass = _class, EnumItemIndex = i };
				}
			}
			return null;
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			if (AttachExpr != null)
				AttachExpr = AttachExpr.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			bool _need_attach = EnumClass.ClassEnumItems[EnumItemIndex].AttachType != null;
			if ((AttachExpr != null) != _need_attach) {
				throw new CodeException (Token, $"{EnumClass.ClassEnumItems[EnumItemIndex].Name} 枚举条件{(_need_attach ? "需要附带参数" : "不能附带参数")}，但实际{(_need_attach ? "没有附带参数" : "附带了参数")}");
			}
			if (_need_attach) {
				if (!AttachExpr.TraversalCalcTypeWrap (AttachType, a => AttachExpr = a))
					return null;
			}
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => AstType_Class.GetType (Token, EnumClass);

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			if (AttachExpr == null)
				return (new List<IAstStmt> (), this);
			var (_stmts, _expr) = AttachExpr.ExpandExpr (_cache_err);
			AttachExpr = _expr;
			return (_stmts, this);
		}

		public override string GenerateCSharp (int _indent) {
			bool _need_attach = EnumClass.ClassEnumItems[EnumItemIndex].AttachType != null;
			if (_need_attach) {
				int _real_var_index = EnumClass.GetRealAttachVarPos (EnumItemIndex);
				var _b = AttachExpr.GenerateCSharp (_indent);
				return $"new {EnumClass.CSharpFullName} {{ __index__ = {EnumItemIndex}, {EnumClass.ClassVars[_real_var_index].Name} = {_b} }}";
			} else {
				return $"new {EnumClass.CSharpFullName} {{ __index__ = {EnumItemIndex} }}";
			}
			//throw new NotImplementedException ();
		}

		public override bool AllowAssign () => false;
	}
}
