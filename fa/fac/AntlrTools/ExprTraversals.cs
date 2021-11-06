using fac.ASTs.Exprs;
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
	}

	class ExprTraversals {
		public static List<TraversalType> TraversalTypes { get; } = new List<TraversalType> {
			TraversalType.Leaf2Root,
			TraversalType.Root2Leaf | TraversalType.Leaf2Root
		};

		public static IAstExpr Traversal (IAstExpr _expr, int _index) {
			if (_index == 0) {
				return Traversal0 (_expr);
			} else if (_index == 1) {
				return Traversal1 (_expr);
			} else {
				throw new NotImplementedException ();
			}
		}

		// 第一遍遍历代码
		public static IAstExpr Traversal0 (IAstExpr _expr) {
			// TODO 合并冗余名称、合并冗余符号至数字逻辑
			return _expr;
		}

		// 第二遍遍历代码
		public static IAstExpr Traversal1 (IAstExpr _expr) {
			// TODO 计算期望类型、插入类型转换AST对象
			return _expr;
		}
	}
}
