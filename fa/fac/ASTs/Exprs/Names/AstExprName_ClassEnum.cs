using Antlr4.Runtime;
using fac.ASTs.Structs;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	public class AstExprName_ClassEnum: IAstExprName {
		public IAstClass EnumClass { init; get; }
		public int EnumItemIndex { init; get; }
		public IAstExpr AttachExpr { get; set; }
		public IAstType AttachType { get => EnumClass.ClassEnumItems[EnumItemIndex].AttachType; }
		public string LabelName { get => EnumClass.ClassEnumItems[EnumItemIndex].Name; }
		public string AttachName { get => EnumClass.ClassVars[EnumClass.GetRealAttachVarPos (EnumItemIndex)].Name; }



		public static AstExprName_ClassEnum FindFromName (IToken _token, string _name, IAstExprName _attach_var = null) {
			var _class_enum = FindFromNameUncheckAttach (_token, _name);
			if (_class_enum == null)
				throw new CodeException (_token, $"未识别的标识符 {_name}");
			if ((_class_enum.EnumClass.ClassEnumItems[_class_enum.EnumItemIndex].AttachType == null) != (_attach_var == null)) {
				throw new CodeException (_token, _attach_var == null ? "枚举类型需附带参数" : "枚举类型不应附带参数");
			}
			_class_enum.AttachExpr = _attach_var;
			return _class_enum;
		}

		public static AstExprName_ClassEnum FindFromNameUncheckAttach (IToken _token, string _name) {
			int _pt = _name.LastIndexOf ('.');
			string _class_name = _name[.._pt];
			var _classes = Info.GetClassFromName (_class_name);
			if (_classes.Count == 0) {
				return null;
			} else if (_classes.Count > 1) {
				return null;
			} else if (_classes[0] is AstEnum _enum) {
				_name = _name[(_pt + 1)..];
				for (int i = 0; i < _enum.ClassEnumItems.Count; ++i) {
					if (_enum.ClassEnumItems[i].Name == _name) {
						return new AstExprName_ClassEnum { Token = _token, EnumClass = _enum, EnumItemIndex = i };
					}
				}
				return null;
			} else {
				return null;
			}
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
			if (_need_attach)
				AttachExpr = AttachExpr.TraversalCalcType (EnumClass.ClassEnumItems[EnumItemIndex].AttachType);
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => AstType_Class.GetType (Token, EnumClass);

		public override string GenerateCSharp (int _indent) {
			bool _need_attach = EnumClass.ClassEnumItems[EnumItemIndex].AttachType != null;
			if (_need_attach) {
				int _real_var_index = EnumClass.GetRealAttachVarPos (EnumItemIndex);
				var _b = AttachExpr.GenerateCSharp (_indent);
				return $"new {EnumClass.FullName} {{ @index = {EnumItemIndex}, {EnumClass.ClassVars[_real_var_index].Name} = {_b} }}";
			} else {
				return $"new {EnumClass.FullName} {{ @index = {EnumItemIndex} }}";
			}
			//throw new NotImplementedException ();
		}

		public override bool AllowAssign () => false;
	}
}
