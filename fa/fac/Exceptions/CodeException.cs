using Antlr4.Runtime;
using Antlr4.Runtime.Tree;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.Exceptions {
	class CodeException: Exception {
		public IToken Token { init; get; }

		public CodeException (ITerminalNode _node, string _msg) : base (_msg) {
			Token = _node.Symbol;
		}

		public CodeException (ParserRuleContext _ctx, string _msg) : base (_msg) {
			Token = _ctx.Start;
		}

		public CodeException (IToken _token, string _msg) : base (_msg) {
			Token = _token;
		}
	}
}
