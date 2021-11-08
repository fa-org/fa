﻿using fac.AntlrTools;
using fac.ASTs.Stmts;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	enum AstClassType { Class, Interface, Enum }

	class AstClassStmt: IAst {
		public string FullName { init; get; }
		public PublicLevel Level { init; get; }
		public AstClassType ClassType { init; get; }
		public List<AstClassEnumAtom> ClassEnumAtoms { init; get; }
		public List<AstClassVar> ClassVars { init; get; }
		public List<AstClassFunc> ClassFuncs { init; get; }



		public AstClassStmt (FaParser.ClassStmtContext _ctx) {
			FullName = $"{Info.CurrentNamespace}{_ctx.Id ().GetText ()}";
			//
			Level = Common.ParseEnum<PublicLevel> (_ctx.publicLevel ()?.GetText ()) ?? PublicLevel.Public;
			//
			var _cls_type = Common.ParseEnum<AstClassType> (_ctx.classType ().GetText ());
			if (_cls_type != null) {
				ClassType = _cls_type.Value;
			} else {
				throw new UnimplException (_ctx);
			}
			//
			ClassEnumAtoms = (from p in _ctx.classEnumAtom () select new AstClassEnumAtom (p)).ToList ();
			if (ClassType != AstClassType.Enum && ClassEnumAtoms.Count > 0)
				throw new CodeException (_ctx.classEnumAtom ()[0], $"{ClassType} 类型结构不允许出现枚举成员");
			//
			ClassVars = (from p in _ctx.classVar () select new AstClassVar (p)).ToList ();
			//
			ClassFuncs = (from p in _ctx.classFunc () select new AstClassFunc (p)).ToList ();
		}

		public void Compile () {
			// Antlr转AST
			foreach (var _var in ClassVars)
				_var.ToAST ();
			foreach (var _func in ClassFuncs)
				_func.ToAST ();

			// 处理AST
			for (int i = 0; i < ExprTraversals.TraversalTypes.Count; ++i) {
				Info.CurrentTraversalType = ExprTraversals.TraversalTypes [i];

				// 类成员变量默认初始化值
				for (int j = 0; j < ClassVars.Count; ++j) {
					if (ClassVars[j].DefaultValue == null)
						continue;
					Info.CurrentFunc = null;
					Info.CurrentFuncVariables = new List<(Dictionary<string, AstStmt_DefVariable> _vars, int _group)> ();
					//
					if (Info.TraversalFirst)
						ClassVars[j].DefaultValue = ExprTraversals.Traversal (ClassVars[j].DefaultValue, i, 0, 0);
					ClassVars[j].DefaultValue.TraversalWrap (0, 0, (_expr, _deep, _group) => ExprTraversals.Traversal (_expr, i, _deep, _group));
					if (Info.TraversalLast)
						ClassVars[j].DefaultValue = ExprTraversals.Traversal (ClassVars[j].DefaultValue, i, 0, 0);
				}

				// 类成员方法
				for (int j = 0; j < ClassFuncs.Count; ++j) {
					Info.CurrentFunc = ClassFuncs[j];
					Info.CurrentFuncVariables = new List<(Dictionary<string, AstStmt_DefVariable> _vars, int _group)> ();
					Info.CurrentFuncVariables.Add ((_vars: new Dictionary<string, AstStmt_DefVariable> (), _group: 0));
					//
					for (int k = 0; k < ClassFuncs[j].BodyCodes.Count; ++k) {
						if (Info.TraversalFirst)
							ClassFuncs[j].BodyCodes[k] = ExprTraversals.Traversal (ClassFuncs[j].BodyCodes[k], i, 1, 0) as IAstStmt;
						ClassFuncs[j].BodyCodes[k].TraversalWrap (1, 0, (_expr, _deep, _group) => ExprTraversals.Traversal (_expr, i, _deep, _group));
						if (Info.TraversalLast)
							ClassFuncs[j].BodyCodes[k] = ExprTraversals.Traversal (ClassFuncs[j].BodyCodes[k], i, 1, 0) as IAstStmt;
					}
				}
			}
			foreach (var _var in ClassVars) {
				if (_var.DefaultValue != null)
					_var.DefaultValue = ExprTraversals.TraversalCalcType (_var.DefaultValue, _var.DataType, false);
			}
			foreach (var _func in ClassFuncs) {
				for (int i = 0; i < _func.BodyCodes.Count; ++i) {
					_func.BodyCodes[i] = ExprTraversals.TraversalCalcType (_func.BodyCodes[i], "", false) as IAstStmt;
				}
			}
		}
	}
}