using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs.Names {
	class AstExprName_ClassEnumItem: IAstExprName {
		public IAstClass EnumClass { init; get; }
		public int EnumItemIndex { init; get; }
		public List<IAstExpr> AttachExprs { get; set; }



		public override void Traversal (int _deep, int _group, Func<IAstExpr, int, int, IAstExpr> _cb) {
			for (int i = 0; i < AttachExprs.Count; ++i)
				AttachExprs[i].Traversal (_deep, _group, _cb);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (AttachExprs.Count != EnumClass.ClassEnumItems[EnumItemIndex].AttachTypes.Count)
				throw new CodeException (Token, $"{EnumClass.ClassEnumItems[EnumItemIndex].Name} 枚举条件只能接受 {EnumClass.ClassEnumItems[EnumItemIndex].AttachTypes.Count} 个参数，但实际指定 {AttachExprs.Count} 个参数");
			for (int i = 0; i < AttachExprs.Count; ++i)
				AttachExprs[i] = AttachExprs[i].TraversalCalcType (EnumClass.ClassEnumItems[EnumItemIndex].AttachTypes[i]);
			ExpectType = GuessType ();
			return AstExprTypeCast.Make (this, _expect_type);
		}

		public override IAstType GuessType () => new AstType_Class { Token = Token, Class = EnumClass, TemplateTypes = new List<IAstType> () };

		public override (string, string, string) GenerateCSharp (int _indent, Action<string, string> _check_cb) {
			return new ("", $"new {EnumClass.FullName} {{ @index = {EnumItemIndex} }}", "");
		}

		public override bool AllowAssign () => false;
	}
}
