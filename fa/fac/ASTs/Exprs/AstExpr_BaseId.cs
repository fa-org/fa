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

		public IAstExpr TryParse () {
			if (Id == "_") {
				return new AstExprName_Ignore { Token = Token };
			} else if (Id == "this") {
				return new AstExprName_This { Token = Token, Class = Info.CurrentClass, ExpectType = Info.CurrentClass.GetClassType () };
			}

			// 查找预定义名称
			var _buildinexpr = AstExprName_BuildIn.FindFromName (Id);
			if (_buildinexpr != null)
				return _buildinexpr;

			// 映射变量名/参数
			var _nameexpr = Info.GetCurrentFuncVariableFromName (Token, Id);
			if (_nameexpr != null)
				return _nameexpr;

			// 查找当前类的成员变量
			var _is_static = Info.CurrentFunc.Static;
			for (int i = 0; i < Info.CurrentClass.ClassVars.Count; ++i) {
				if (Info.CurrentClass.ClassVars[i].Name != Id)
					continue;
				if (_is_static != Info.CurrentClass.ClassVars[i].Static)
					throw new CodeException (Token, $"{(_is_static ? "静态" : "动态")}方法内无法访问{(!_is_static ? "静态" : "动态")}成员变量");
				var _cvarexpr = new AstExprName_ClassVar { Token = Token, Class = Info.CurrentClass, VariableIndex = i };
				if (!_is_static)
					_cvarexpr.ThisObject = new AstExprName_This { Token = Token, Class = Info.CurrentClass, ExpectType = Info.CurrentClass.GetClassType () };
				return _cvarexpr;
			}

			// 查找当前类的成员方法
			for (int i = 0; i < Info.CurrentClass.ClassFuncs.Count; ++i) {
				if (Info.CurrentClass.ClassFuncs[i].Name != Id)
					continue;
				if (_is_static != Info.CurrentClass.ClassFuncs[i].Static)
					throw new CodeException (Token, $"{(_is_static ? "静态" : "动态")}方法内无法访问{(!_is_static ? "静态" : "动态")}成员方法");
				var _cvarexpr = new AstExprName_ClassFunc { Token = Token, Class = Info.CurrentClass, FunctionIndex = i };
				if (!_is_static)
					_cvarexpr.ThisObject = new AstExprName_This { Token = Token, Class = Info.CurrentClass, ExpectType = Info.CurrentClass.GetClassType () };
				return _cvarexpr;
			}

			// 查找类名称
			_nameexpr = IAstExprName.FindClass (Token, Id);
			if (_nameexpr != null)
				return _nameexpr;
			return this;
		}
	}
}
