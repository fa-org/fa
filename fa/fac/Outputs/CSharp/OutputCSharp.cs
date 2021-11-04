using fac.ASTs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.Outputs.Rust {
	class OutputCSharp: IOutput {
		public List<(string _file, string _outcode)> Generate (List<AstProgram> _programs) {
			throw new NotImplementedException ();
		}
	}
}
