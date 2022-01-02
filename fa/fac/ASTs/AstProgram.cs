using fac.Exceptions;
using fac.Structures;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fac.ASTs {
	public class AstProgram: IAst {
		public string CurrentFile { init; get; }
		public string CurrentSourceCode { init; get; }
		public string CurrentModule { init; get; }
		public string CurrentNamespace { init; get; }
		public List<string> CurrentUses { init; get; }
		public List<ExternApi> CurrentExternApis { init; get; }

		/// <summary>
		/// 当前模块的类列表
		/// </summary>
		public List<IAstClass> CurrentClasses { get; set; }



		public AstProgram (FaParser.ProgramContext _ctx) {
			Token = _ctx.Start;
			CurrentFile = Info.CurrentFile;
			CurrentSourceCode = Info.CurrentSourceCode;

			// 生成模块名
			CurrentModule = Info.CurrentRelativeFile.Replace ('/', '.').Replace ('\\', '.')[..^3];

			// 生成命名空间
			CurrentNamespace = CurrentModule[..CurrentModule.LastIndexOf ('.')];
			var _namespaces = _ctx.namespaceStmt ();
			if (_namespaces.Length > 1) {
				throw new CodeException (_ctx.namespaceStmt ()[1], "源码中不允许出现第二个 namespace 声明。");
			} else if (_namespaces.Length == 1) {
				CurrentNamespace = _namespaces[0].ids ().GetText ();
			}
			Info.CurrentNamespace = CurrentNamespace = CurrentNamespace[(CurrentNamespace.LastIndexOfAny (new char[] { '/', '\\' }) + 1)..];

			// 处理当前引用
			CurrentUses = Info.CurrentUses = (from p in _ctx.useStmt () select p.ids ().GetText ()).ToList ();

			// 处理当前文件引用的外部库
			foreach (var _lib_file in (from p in _ctx.libStmt () select Common.GetStringLiterialText (p.String1Literal ())))
				Info.ExternLibs.Add (_lib_file);

			// 处理当前文件引用的外部接口
			CurrentExternApis = Info.CurrentExternApis = (from p in _ctx.importStmt () select new ExternApi (p)).ToList ();

			// 处理枚举
			CurrentClasses = (from p in _ctx.enumStmt () select IAstClass.FromContext (p)).ToList ();

			// 处理类
			CurrentClasses.AddRange (from p in _ctx.classStmt () select IAstClass.FromContext (p));
		}

		public void ProcessType () {
			foreach (var _class in CurrentClasses)
				_class.ProcessType ();
		}

		public bool Compile () {
			bool _b = false;
			foreach (var _class in CurrentClasses)
				_b |= _class.Compile ();
			return _b;
		}

		public override string GenerateCSharp (int _indent) {
			Info.CurrentFile = CurrentFile;
			Info.CurrentSourceCode = CurrentSourceCode;
			Info.CurrentNamespace = CurrentNamespace;
			Info.CurrentUses = CurrentUses;
			Info.CurrentExternApis = CurrentExternApis;
			Log.Mark (LogMark.Build);
			//
			if (CurrentClasses.Count == 0)
				return "";
			var _sb = new StringBuilder ();
			_sb.AppendLine ($"namespace {Info.CurrentNamespace} {{");
			foreach (var _class in CurrentClasses)
				_sb.Append (_class.GenerateCSharp (_indent));
			_sb.AppendLine ($"}}");
			return _sb.ToString ();
		}
	}
}
