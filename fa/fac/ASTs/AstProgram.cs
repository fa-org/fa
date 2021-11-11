using fac.Exceptions;
using fac.Structures;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstProgram: IAst {
		public string CurrentFile { init; get; }
		public string CurrentSourceCode { init; get; }

		/// <summary>
		/// 当前模块名
		/// </summary>
		public string CurrentModule { init; get; }

		/// <summary>
		/// 当前模块的类列表
		/// </summary>
		public List<AstClass> CurrentClasses { get; set; }



		public AstProgram (FaParser.ProgramContext _ctx) {
			Token = _ctx.Start;
			CurrentFile = Info.CurrentFile;
			CurrentSourceCode = Info.CurrentSourceCode;

			// 生成模块名
			CurrentModule = $"{Info.ProjectName}.{Info.CurrentRelativeFile.Replace ('/', '.').Replace ('\\', '.')}"[..^3];

			// 生成命名空间
			Info.CurrentNamespace = CurrentModule[..CurrentModule.LastIndexOf ('.')];
			var _namespaces = _ctx.namespaceStmt ();
			if (_namespaces.Length > 1) {
				throw new CodeException (_ctx.namespaceStmt ()[1], "源码中不允许出现第二个 namespace 声明。");
			} else if (_namespaces.Length == 1) {
				Info.CurrentNamespace = _namespaces[0].ids ().GetText ();
			}

			// 处理当前引用
			Info.CurrentUses = (from p in _ctx.useStmt () select p.ids ().GetText ()).ToList ();

			// 处理当前文件引用的外部库
			foreach (var _lib_file in (from p in _ctx.libStmt () select Common.GetStringLiterialText (p.String1Literal ())))
				Info.ExternLibs.Add (_lib_file);

			// 处理当前文件引用的外部接口
			Info.CurrentExternApis = (from p in _ctx.importStmt () select new ExternApi (p)).ToList ();

			// 处理类
			CurrentClasses = (from p in _ctx.classStmt () select new AstClass (p)).ToList ();
		}

		public void Compile () {
			foreach (var _class in CurrentClasses)
				_class.Compile ();
		}

		public override (string, string) GenerateCSharp (int _indent) {
			if (CurrentClasses.Count == 0)
				return ("", "");
			StringBuilder _psb = new StringBuilder (), _sb = new StringBuilder ();
			_psb.AppendLine ($"{_indent.Indent ()}using System;");
			foreach (var _class in CurrentClasses) {
				var (_a, _b) = _class.GenerateCSharp (_indent);
				_sb.Append (_a).Append (_b);
			}
			return (_psb.ToString (), _sb.ToString ());
		}
	}
}
