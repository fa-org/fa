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
	public class AstExpr_Op2: IAstExpr {
		public IAstExpr Value1 { get; set; }
		public IAstExpr Value2 { get; set; }
		public string Operator { get; set; }



		public static AstExpr_Op2 MakeOp2 (IAstExpr _val1, string _op, IAstExpr _val2, IAstType _expect_type) {
			return new AstExpr_Op2 { Token = _val2.Token, Value1 = _val1, Value2 = _val2, Operator = _op, ExpectType = _expect_type };
		}
		public static AstExpr_Op2 MakeCondition (IAstExpr _val1, string _op, IAstExpr _val2) {
			return MakeOp2 (_val1, _op, _val2, IAstType.FromName ("bool"));
		}

		public override void Traversal ((int _deep, int _group, int _loop, Func<IAstExpr, int, int, int, IAstExpr> _cb) _trav) {
			Value1 = Value1.TraversalWrap (_trav);
			Value2 = Value2.TraversalWrap (_trav);
		}

		public override IAstExpr TraversalCalcType (IAstType _expect_type) {
			if (sCompareOp2s.Contains (Operator)) {
				// > >=
				var _exp_type = TypeFuncs.GetCompatibleType (false, Value1.GuessType (), Value2.GuessType ());
				Value1 = Value1.TraversalCalcType (_exp_type);
				Value2 = Value2.TraversalCalcType (_exp_type);
				ExpectType = IAstType.FromName ("bool");
				return AstExprTypeCast.Make (this, _expect_type);
			} else if (sLogicOp2s.Contains (Operator)) {
				// && ||
				ExpectType = IAstType.FromName ("bool");
				Value1 = Value1.TraversalCalcType (ExpectType);
				Value2 = Value2.TraversalCalcType (ExpectType);
				return AstExprTypeCast.Make (this, _expect_type);
			} else if (sNumOp2s.Contains (Operator)) {
				// + - * /
				var _exp_type = _expect_type ?? TypeFuncs.GetCompatibleType (false, Value1.GuessType (), Value2.GuessType ());
				if (_exp_type is AstType_OptionalWrap _owrap)
					_exp_type = _owrap.ItemType;
				Value1 = Value1.TraversalCalcType (_exp_type);
				Value2 = Value2.TraversalCalcType (_exp_type);
				ExpectType = _exp_type;
				return AstExprTypeCast.Make (this, _expect_type);
			} else if (sAssignOp2s.Contains (Operator)) {
				// = += -=
				Value1 = Value1.TraversalCalcType (null);
				Value2 = Value2.TraversalCalcType (Value1.ExpectType);
				ExpectType = Value1.ExpectType;
				return AstExprTypeCast.Make (this, _expect_type);
			} else if (sQusQusOp2s.Contains (Operator)) {
				// ?? ??=
				if (Operator == "??") {
					Value2 = Value2.TraversalCalcType (null);
					var _exp_type = (_expect_type == null || _expect_type is AstType_Any) ? Value2.ExpectType : _expect_type;
					_exp_type = _exp_type.Optional;
					Value1 = Value1.TraversalCalcType (_exp_type);
					ExpectType = Value2.ExpectType;
					return AstExprTypeCast.Make (this, _expect_type);
				} else if (Operator == "??=") {
					Value1 = Value1.TraversalCalcType (null);
					if (Value1.ExpectType is AstType_OptionalWrap _owrap) {
						try {
							Value2 = Value2.TraversalCalcType (_owrap.ItemType);
							ExpectType = _owrap.ItemType;
						} catch (Exception) {
							Value2 = Value2.TraversalCalcType (Value1.ExpectType);
							ExpectType = Value1.ExpectType;
						}
						return AstExprTypeCast.Make (this, _expect_type);
					} else {
						throw new CodeException (Token, "??= 运算符左操作数必须为可空类型");
					}
				}
			}
			throw new UnimplException (Token);
		}

		public override IAstType GuessType () {
			if (sCompareOp2s.Contains (Operator) || sLogicOp2s.Contains (Operator)) {
				return IAstType.FromName ("bool");
			} else if (sNumOp2s.Contains (Operator) || sAssignOp2s.Contains (Operator)) {
				bool _opt = Operator == "/" && Info.CurrentReturnType () is not AstType_OptionalWrap;
				var _type = TypeFuncs.GetCompatibleType (true, Value1.GuessType (), Value2.GuessType ());
				if (_opt)
					_type = _type.Optional;
				return _type;
			} else if (sQusQusOp2s.Contains (Operator)) {
				return Value2.GuessType ();
			} else {
				throw new UnimplException (Token);
			}
		}

		public override (List<IAstStmt>, IAstExpr) ExpandExpr ((IAstExprName _var, AstStmt_Label _pos)? _cache_err) {
			var _stmts = new List<IAstStmt> { };
			if (Operator == "??") {
				var _tmp_stmt = new AstStmt_DefVariable { DataType = Value1.ExpectType };
				_stmts.Add (_tmp_stmt);
				var _err_pos = new AstStmt_Label { };
				var _cache_err1 = (_var: _tmp_stmt.GetRef (), _pos: _err_pos);
				var (_stmts1, _val1) = Value1.ExpandExpr (_cache_err1);
				_stmts.AddRange (_stmts1);
				_stmts.Add (AstStmt_ExprWrap.MakeAssign (_tmp_stmt.GetRef (), _val1));
				_stmts.Add (_err_pos);
				var _ifstmt = new AstStmt_If {
					Token = Token,
					Condition = AstExpr_Op1.Not (AstExpr_Is.FromContext (Token, _tmp_stmt.GetRef (), "Val", "")),
					IfTrueCodes = new List<IAstStmt> {
						AstStmt_ExprWrap.MakeAssign (_cache_err?._var, IAstExpr.OptionalFromError (_tmp_stmt.GetRef (), fa_Error.Null)),
						_cache_err?._pos.GetRef (),
					},
				};
				(_stmts1, _val1) = Value2.ExpandExpr (_cache_err);
				_ifstmt.IfTrueCodes = _stmts1;
				_ifstmt.IfTrueCodes.Add (AstStmt_ExprWrap.MakeAssign (_tmp_stmt.GetRef (), _val1));
				_stmts.Add (_ifstmt);
				return (_stmts, _tmp_stmt.GetRef ());
			} else {
				var (_stmts1, _val1) = Value2.ExpandExpr (_cache_err);
				_stmts.AddRange (_stmts1);
				Value2 = _val1;
				if (Operator == "=") {
					if (Value1 is AstExprName_Ignore)
						throw new Exception ("不应执行此处代码");
					(_stmts1, _val1) = Value1.ExpandExprAssign (Value2, _cache_err);
					_stmts.AddRange (_stmts1);
					return (_stmts, _val1);
				}
				var _tmp_stmt = new AstStmt_DefVariable { DataType = ExpectType };
				_stmts.Add (_tmp_stmt);
				(_stmts1, _val1) = Value1.ExpandExpr (_cache_err);
				_stmts.AddRange (_stmts1);
				Value1 = _val1;
				//
				if (Operator == "/") {
					if (_cache_err == (null, null))
						throw new CodeException (Token, "除法结果可能为空，此处需使用");
					ExpectType = (ExpectType as AstType_OptionalWrap)?.ItemType ?? ExpectType;
					_stmts.Add (new AstStmt_If {
						Condition = AstExpr_Op2.MakeCondition (Value2, "==", IAstExpr.FromValue (Value2.ExpectType, "0")),
						IfTrueCodes = new List<IAstStmt> {
							AstStmt_ExprWrap.MakeAssign (_cache_err?._var, AstExpr_AccessBuildIn.Optional_FromError (_tmp_stmt.DataType.Optional, "除数不能为0")),
							_cache_err?._pos.GetRef (),
						},
						IfFalseCodes = new List<IAstStmt> {
							AstStmt_ExprWrap.MakeAssign (_tmp_stmt.GetRef (), this),
						},
					});
				} else if (Operator == "=") {
					_stmts.RemoveAt (0);
					if (Value1 is AstExpr_AccessBuildIn _biexpr && _biexpr.AccessType == AccessBuildInType.OPT_GetValue) {
						_stmts.Add (AstStmt_ExprWrap.MakeAssign (_biexpr.Value, AstExpr_AccessBuildIn.Optional_FromValue (Value2)));
					} else {
						_stmts.Add (AstStmt_ExprWrap.MakeFromExpr (this));
					}
					return (_stmts, Value1);
				} else {
					_stmts.Add (AstStmt_ExprWrap.MakeAssign (_tmp_stmt.GetRef (), this));
				}
				return (_stmts, _tmp_stmt.GetRef ());
			}
		}

		public override string GenerateCSharp (int _indent) {
			if (Operator == "??")
				throw new Exception ("不应执行此处代码");
			if (Operator == "=" && Value1 is AstExprName_Ignore)
				return Value2.GenerateCSharp (_indent);

			if (sAssignOp2s.Contains (Operator)) {
				return $"{Value1.GenerateCSharp (_indent)} {Operator} {Value2.GenerateCSharp (_indent)}";
			} else {
				return $"({Value1.GenerateCSharp (_indent)} {Operator} {Value2.GenerateCSharp (_indent)})";
			}
		}

		public override bool AllowAssign () => false;

		private static HashSet<string> sCompareOp2s = new HashSet<string> { ">", "<", ">=", "<=", "==", "!=" };
		private static HashSet<string> sLogicOp2s = new HashSet<string> { "||", "&&" };
		private static HashSet<string> sNumOp2s = new HashSet<string> { "+", "-", "*", "/", "%", "|", "&", "^", "<<", ">>" };
		public static HashSet<string> sAssignOp2s = new HashSet<string> { "=", "+=", "-=", "*=", "/=", "%=", "|=", "&=", "^=", "<<=", ">>=" };
		private static HashSet<string> sQusQusOp2s = new HashSet<string> { "??", "??=" };
	}
}
