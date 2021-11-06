using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs.Exprs {
	class AstExpr_NewObject: IAstExpr, IAst {
		public string DataType { get; set; }
		public List<(string _name, IAstExpr _value)> InitialValues { get; set; } = null; // 结构体初值，当有值时ConstructorArguments为空
		public List<IAstExpr> ConstructorArguments { get; set; } = null;                 // 构造函数参数，当有值时InitialValues为空



		public override void Traversal (Func<IAstExpr, IAstExpr> _cb) {
			for (int i = 0; i < InitialValues.Count; ++i)
				InitialValues[i] = (_name: InitialValues[i]._name, _value: _cb (InitialValues[i]._value));
			for (int i = 0; i < ConstructorArguments.Count; ++i)
				ConstructorArguments[i] = _cb (ConstructorArguments[i]);
		}
	}
}
