using fac.ASTs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.Outputs {
	interface IOutput {
		/// <summary>
		/// 生成结果，文件名和输出代码配对
		/// </summary>
		/// <param name="_programs">AST树列表，每项是一个源码文件的AST树</param>
		/// <returns></returns>
		List<(string _file, string _outcode)> Generate (List<AstProgram> _programs);
	}
}
