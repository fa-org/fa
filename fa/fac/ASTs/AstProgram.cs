using fac.Exceptions;
using fac.Structures;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	class AstProgram: IAstNode {
		/// <summary>
		/// 当前模块名
		/// </summary>
		public string CurrentModule { init; get; }

		public AstProgram (FaParser.ProgramContext context) {
			// 生成模块名
			CurrentModule = $"{Info.ProjectName}.{Info.CurrentRelativeFile.Replace ('/', '.').Replace ('\\', '.')}"[..^3];

			// 生成命名空间
			Info.CurrentNamespace = CurrentModule[..CurrentModule.LastIndexOf ('.')];
			var _namespaces = context.namespaceStmt ();
			if (_namespaces.Length > 1) {
				throw new CodeException (context.namespaceStmt ()[1], "源码中不允许出现第二个 namespace 声明。");
			} else if (_namespaces.Length == 1) {
				Info.CurrentNamespace = _namespaces[0].ids ().GetText ();
			}

			// 处理当前引用
			Info.CurrentUses = (from p in context.useStmt () select p.ids ().GetText ()).ToList ();

			// 处理当前文件引用的外部库
			foreach (var _lib_file in (from p in context.libStmt () select Common.GetStringLiterialText (p.String1Literal ())))
				Info.ExternLibs.Add (_lib_file);

			// 处理当前文件引用的外部接口
			Info.CurrentExternApis = (from p in context.importStmt () select new ExternApi (p)).ToList ();

			// TODO 处理类
			Console.WriteLine ($"    当前模块名：{CurrentModule}");
			Console.WriteLine ($"    当前命名空间：{Info.CurrentNamespace}");
			Console.WriteLine ($"    当前use数量：{Info.CurrentUses.Count}");
			Console.WriteLine ($"    当前引用外部库数量：{Info.ExternLibs.Count}");
			Console.WriteLine ($"    当前引用外部接口数量：{Info.CurrentExternApis.Count}");
		}

		public string Generate_LLVM_IR () {
			throw new NotImplementedException ();
		}
	}
}
