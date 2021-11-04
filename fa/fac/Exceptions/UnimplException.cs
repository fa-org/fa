using Antlr4.Runtime;
using Antlr4.Runtime.Tree;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.Exceptions {
	class UnimplException: CodeException {
		public UnimplException (ITerminalNode _node) : base (_node, "此功能暂未实现") {}

		public UnimplException (ParserRuleContext _ctx) : base (_ctx, "此功能暂未实现") {}
	}
}
