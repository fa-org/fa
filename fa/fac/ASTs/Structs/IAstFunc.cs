using fac.AntlrTools;
using fac.ASTs.Exprs;
using fac.ASTs.Stmts;
using fac.ASTs.Structs.Part;
using fac.ASTs.Types;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Structs {
	public interface IAstFunc {
		public List<AstAnnoUsingPart> Annotations { init; get; }
		public IAstClass ParentClass { get; set; }
		public PublicLevel Level { init; get; }
		public bool Static { init; get; }
		public List<(IAstType _type, ArgumentTypeExt _ext, string _name)> Arguments { init; get; }
		public FaParser.FuncBodyContext? BodyRaw { get; }
		public List<IAstStmt>? BodyCodes { get; }

		public AstType_Func FuncType { get; }
	}
}
