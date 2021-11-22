using fac.ASTs;
using fac.ASTs.Exprs;
using fac.ASTs.Exprs.Names;
using fac.ASTs.Stmts;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.AntlrTools {
	[Flags]
	enum TraversalType {
		Root2Leaf = 1, // 从 表达式组合 遍历到 最基本元素，如果两种枚举方式皆存在则此种方式优先
		Leaf2Root = 2, // 从 最基本元素 遍历到 表达式组合，如果两种枚举方式皆存在则此种方式滞后
		CalcVar = 4, // 如果有此标识则计算 Info.CurrentFuncVariables
	}

	class ExprTraversals {
		public static List<TraversalType> TraversalTypes { get; } = new List<TraversalType> {
			TraversalType.Root2Leaf | TraversalType.CalcVar,
			TraversalType.Leaf2Root,
			TraversalType.Root2Leaf | TraversalType.Leaf2Root,
		};

		/// <summary>
		/// 枚举函数节点处理函数，每次遍历到的每一个节点都将调用此方法
		/// </summary>
		/// <param name="_expr">当前遍历到的节点</param>
		/// <param name="_index">第几轮节点遍历，不同数字需调用不同处理方法</param>
		/// <param name="_deep">函数内部作用域深度，默认0，有个大括号那么深度+1</param>
		/// <param name="_group">作用域深度组，比如if跳到else，深度相同，但非不同组，那么前组变量需清空</param>
		/// <returns></returns>
		public static IAstExpr Traversal (IAstExpr _expr, int _index, int _deep, int _group) {
			// 计算 Info.CurrentFuncVariables
			if (_deep != 0 && (TraversalTypes[_index] | TraversalType.CalcVar) > 0) { // _deep 为 0 代表类成员变量计算，不需计算方法变量，故跳过
				if (_deep > Info.CurrentFuncVariables.Count) {
					Info.CurrentFuncVariables.Add ((_vars: new Dictionary<string, ASTs.Stmts.AstStmt_DefVariable> (), _group));
					if (_deep != Info.CurrentFuncVariables.Count)
						throw new Exception ("节点遍历错误：不允许存在跳动过大的节点");
				} else {
					while (_deep < Info.CurrentFuncVariables.Count)
						Info.CurrentFuncVariables.RemoveAt (Info.CurrentFuncVariables.Count - 1);
					if (Info.CurrentFuncVariables[^1]._group != _group)
						Info.CurrentFuncVariables[^1] = (_vars: new Dictionary<string, ASTs.Stmts.AstStmt_DefVariable> (), _group: _group);
				}
			}

			if (_index == 0) {
				return Traversal0 (_expr);
			} else if (_index == 1) {
				return Traversal1 (_expr);
			} else if (_index == 2) {
				return Traversal2 (_expr);
			} else {
				throw new NotImplementedException ();
			}
		}

		// 第一遍遍历
		private static IAstExpr Traversal0 (IAstExpr _expr) {
			if (_expr is AstStmt_DefVariable _varexpr) {
				// 生成变量定义组
				Info.CurrentFuncVariables[^1]._vars.Add (_varexpr.VarName, _varexpr);
			} else if (_expr is AstExpr_BaseId _idexpr) {
				if (_idexpr.id == "_")
					return new AstExprName_Ignore { Token = _expr.Token };

				// 查找预定义名称
				var _buildinexpr = AstExprName_BuildIn.FindFromName (_idexpr.id);
				if (_buildinexpr != null)
					return _buildinexpr;

				// 映射变量名/参数
				var _nameexpr = IAstExprName.FindVariableOrArgument (_idexpr.Token, _idexpr.id);
				if (_nameexpr != null)
					return _nameexpr;

				// 查找当前类的成员变量
				var _is_static = Info.CurrentFunc.Static;
				for (int i = 0; i < Info.CurrentClass.ClassVars.Count; ++i) {
					if (Info.CurrentClass.ClassVars[i].Name != _idexpr.id)
						continue;
					if (_is_static != Info.CurrentClass.ClassVars[i].Static)
						throw new CodeException (_idexpr.Token, $"{(_is_static ? "静态" : "动态")}方法内无法访问{(!_is_static ? "静态" : "动态")}成员变量");
					var _cvarexpr = new AstExprName_ClassVar { Token = _idexpr.Token, Class = Info.CurrentClass, VariableIndex = i };
					if (!_is_static)
						_cvarexpr.ThisObject = new AstExprName_This { Token = _idexpr.Token, Class = Info.CurrentClass };
					return _cvarexpr;
				}

				// 查找当前类的成员方法
				for (int i = 0; i < Info.CurrentClass.ClassFuncs.Count; ++i) {
					if (Info.CurrentClass.ClassFuncs[i].Name != _idexpr.id)
						continue;
					if (_is_static != Info.CurrentClass.ClassFuncs[i].Static)
						throw new CodeException (_idexpr.Token, $"{(_is_static ? "静态" : "动态")}方法内无法访问{(!_is_static ? "静态" : "动态")}成员方法");
					var _cvarexpr = new AstExprName_ClassFunc { Token = _idexpr.Token, Class = Info.CurrentClass, FunctionIndex = i };
					if (!_is_static)
						_cvarexpr.ThisObject = new AstExprName_This { Token = _idexpr.Token, Class = Info.CurrentClass };
					return _cvarexpr;
				}

				// 查找类名称
				_nameexpr = IAstExprName.FindClass (_idexpr.Token, _idexpr.id);
				if (_nameexpr != null)
					return _nameexpr;
			}
			return _expr;
		}

		// 第二遍遍历
		private static IAstExpr Traversal1 (IAstExpr _expr) {
			if (_expr is AstExpr_Op1 _op1 && (!_op1.IsPrefix) && _op1.Operator[0] == '.') {
				string _access_name = _op1.Operator[1..];
				if (_op1.Value is AstExpr_BaseId _idexpr) {
					string _name = $"{_idexpr.id}.{_access_name}";

					// 查找类名称
					var _nameexpr = IAstExprName.FindClass (_idexpr.Token, _name);
					if (_nameexpr != null)
						return _nameexpr;

					// 查找预定义名称
					var _buildinexpr = AstExprName_BuildIn.FindFromName (_name);
					if (_buildinexpr != null)
						return _buildinexpr;

					// 合并冗余名称
					return new AstExpr_BaseId { Token = _idexpr.Token, id = _name };
				} else {
					// 访问类成员
					// 参数0为对象，当访问静态成员时传null
					// 参数1为类对象
					Func<IAstExpr, IAstClass, IAstExpr> _access_func = (_obj, _class) => {
						for (int i = 0; i < _class.ClassEnumItems.Count; ++i) {
							if (_class.ClassEnumItems[i].Name == _access_name)
								return new AstExprName_ClassEnum { Token = _expr.Token, EnumClass = _class, EnumItemIndex = i, AttachExpr = null };
						}
						for (int i = 0; i < _class.ClassVars.Count; ++i) {
							if (_class.ClassVars[i].Name == _access_name)
								return new AstExprName_ClassVar { Token = _expr.Token, Class = _class, VariableIndex = i, ThisObject = _obj };
						}
						for (int i = 0; i < _class.ClassFuncs.Count; ++i) {
							if (_class.ClassFuncs[i].Name == _access_name)
								return new AstExprName_ClassFunc { Token = _expr.Token, Class = _class, FunctionIndex = i, ThisObject = _obj };
						}
						throw new CodeException (_expr.Token, $"类 {_class.FullName} 不存在成员 {_access_name}");
					};

					// 访问类成员
					// 参数0为对象，当访问静态成员时传null
					// 参数1为类名
					Func<IAstExpr, IAstType, IAstExpr> _access_func2 = (_obj, _typeexpr) => {
						return _typeexpr switch {
							AstType_Class _classexpr => _access_func (_obj, _classexpr.Class),
							_ => throw new UnimplException (_typeexpr.Token),
						};
					};

					if (_op1.Value is AstExprName_Class _classexpr) {
						return _access_func (null, _classexpr.Class);
					} else if (_op1.Value is AstExprName_Argument _argexpr) {
						var _argtype = _argexpr.Func.Arguments[_argexpr.ArgumentIndex]._type;
						return _access_func2 (_argexpr, _argtype);
					} else if (_op1.Value is AstExprName_ClassVar _cvarexpr) {
						return _access_func (_cvarexpr, _cvarexpr.Class);
					} else if (_op1.Value is AstExprName_Variable _varexpr) {
						return _access_func2 (_varexpr, _varexpr.Var.DataType);
					}
				}
			} else if (_expr is AstExpr_OpN _opnexpr) {
				if (_opnexpr.Value is AstExpr_Op1 _op1expr
					&& (!_op1expr.IsPrefix) && _op1expr.Operator[1..] == "Format"
					&& _op1expr.Value is AstExpr_BaseValue _valexpr && _valexpr.DataType is AstType_String) {
					_opnexpr.Arguments.Insert (0, _op1expr.Value);
					_opnexpr.Value = AstExprName_BuildIn.FindFromName ("string.Format");
				} else if (_opnexpr.Value is AstExprName_ClassEnum _ceiexpr) {
					if (_opnexpr.Arguments.Count != 1)
						throw new CodeException (_ceiexpr.Token, "附带参数只能是一个");
					_ceiexpr.AttachExpr = _opnexpr.Arguments[0];
					return _ceiexpr;
				}
			} else if (_expr is AstExpr_Op2 _op2expr && (_op2expr.Operator == "==" || _op2expr.Operator == "!=")) {
				//IAstClass _enum = null;
				//if (_op2expr.Value1 is AstExprName_ClassEnum _ceiexpr)
				//	_enum = _ceiexpr.EnumClass;
				//if (_op2expr.Value1.GuessType () is AstType_Class _ctype && _ctype.Class is AstEnum _enum1)
				//	_enum = _enum1;
				//if (_enum != null) {
				//	int _enum_index = -1;
				//	if (_op2expr.Value1 is AstExprName_ClassEnum _ceiexpr1)
				//		_enum_index = _ceiexpr1.EnumItemIndex;
				//	if (_op2expr.Value2 is AstExprName_ClassEnum _ceiexpr2) {
				//		if (_enum_index != -1 && _enum_index != _ceiexpr2.EnumItemIndex)
				//			throw new CodeException (_expr.Token, "表达式两边不能同时出现不同的枚举值");
				//		_enum_index = (_enum_index != -1) ? _enum_index : _ceiexpr2.EnumItemIndex;
				//	}
				//	if (_enum_index == -1) {
				//		// TODO 判断完等式再识别index，判断对应attach value，这段代码以后再写
				//		throw new NotImplementedException ();
				//	}

				//	// 获得提取index的表达式
				//	Func<IAstExpr, IAstExpr> _get_index = (_expr0) => {
				//		if (_expr0 is AstExprName_ClassEnum _expr1) {
				//			return IAstExpr.FromValue ("int", $"{_enum_index}");
				//		} else if (_expr0.GuessType () is AstType_Class _expr2 && _expr2.Class is AstEnum) {
				//			return new AstExprName_ClassVar { Token = _expr0.Token, Class = _enum, VariableIndex = 0, ThisObject = _expr0 };
				//		} else {
				//			throw new CodeException (_expr0.Token, "表达式两端无法比较");
				//		}
				//	};

				//	// 获得提取attach的表达式
				//	Func<IAstExpr, IAstExpr> _get_attach = (_expr0) => {
				//		if (_expr0 is AstExprName_ClassEnum _expr1) {
				//			return _expr1.AttachExpr;
				//		} else if (_expr0.GuessType () is AstType_Class _expr2 && _expr2.Class is AstEnum) {
				//			int _real_var_index = _enum.GetRealAttachVarPos (_enum_index);
				//			return new AstExprName_ClassVar { Token = _expr0.Token, Class = _enum, VariableIndex = _real_var_index, ThisObject = _expr0 };
				//		} else {
				//			throw new CodeException (_expr0.Token, "表达式两端无法比较");
				//		}
				//	};

				//	if (_enum.ClassEnumItems[_enum_index].AttachType == null) {
				//		return new AstExpr_Op2 {
				//			Token = _op2expr.Token,
				//			Value1 = _get_index (_op2expr.Value1),
				//			Value2 = _get_index (_op2expr.Value2),
				//			Operator = _op2expr.Operator
				//		};
				//	} else {
				//		return new AstExpr_Op2 {
				//			Token = _op2expr.Token,
				//			Value1 = new AstExpr_Op2 {
				//				Token = _op2expr.Token,
				//				Value1 = _get_index (_op2expr.Value1),
				//				Value2 = _get_index (_op2expr.Value2),
				//				Operator = _op2expr.Operator
				//			},
				//			Value2 = new AstExpr_Op2 {
				//				Token = _op2expr.Token,
				//				Value1 = _get_attach (_op2expr.Value1),
				//				Value2 = _get_attach (_op2expr.Value2),
				//				Operator = _op2expr.Operator
				//			},
				//			Operator = _op2expr.Operator == "==" ? "&&" : "||"
				//		};
				//	}
				//}
			}
			return _expr;
		}

		// 第三遍遍历
		private static IAstExpr Traversal2 (IAstExpr _expr) {
			// 不允许再出现 AstExpr_BaseId 类型
			if (_expr is AstExpr_BaseId _idexpr) {
				throw new CodeException (_expr.Token, $"未识别的标识符 {_idexpr.id}");
			} else if (_expr is AstExpr_Op1 _op1expr && (!_op1expr.IsPrefix) && _op1expr.Operator[0]=='.') {
				throw new CodeException (_expr.Token, $"未识别的成员方法或属性 {_op1expr.Operator[1..]}");
			} else if (_expr is AstExpr_Op2 _op2expr && AstExpr_Op2.sAssignOp2s.Contains (_op2expr.Operator)) {
				if (!_op2expr.Value1.AllowAssign ())
					throw new CodeException (_op2expr.Value1.Token, "目标不可被赋值");
			}
			return _expr;
		}
	}
}
