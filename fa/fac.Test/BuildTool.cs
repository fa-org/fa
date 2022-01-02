using fac;
using fac.AntlrTools;
using fac.ASTs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace fac.Test {
	class BuildTool {
		private static string _process_run (string _cmd) {
			int _p = _cmd.IndexOf (' ');
			string _file = _p == -1 ? _cmd : _cmd[.._p];
			string _arg = _p == -1 ? "" : _cmd[(_p+1)..];

			using var _ps = new Process ();
			_ps.StartInfo.UseShellExecute = false;
			_ps.StartInfo.FileName = _file;
			_ps.StartInfo.Arguments = _arg;
			_ps.StartInfo.CreateNoWindow = false;
			_ps.StartInfo.RedirectStandardOutput = true;
			_ps.Start ();
			string _ret = _ps.StandardOutput.ReadToEnd ();
			_ps.WaitForExit ();
			_ps.Close ();
			return _ret;
		}

		public static string RunAndGetReturn (string _code) {
			string _cur_directory = Directory.GetCurrentDirectory ();
			string _ret = "";
			try {
				_ret = _RunAndGetReturn (_code);
			} finally {
				Directory.SetCurrentDirectory (_cur_directory);
				try {
					Directory.Delete (Info.SrcPath, true);
				} catch (Exception) {
				}
			}
			return _ret;
		}

		private static string _RunAndGetReturn (string _code) {
			Info.ProjectName = $"FacTest_{Common.GetTempId ()}";
			Info.SrcPath = Info.DestPath = Path.Combine (Path.GetTempPath (), Info.ProjectName);
			if (!Directory.Exists (Info.DestPath))
				Directory.CreateDirectory (Info.DestPath);
			Info.Visitor = null;
			Info.CurrentNamespace = "";
			Info.CurrentUses = null;
			Info.CurrentExternApis = null;
			Info.CurrentTraversalType = TraversalType.Root2Leaf;
			Info.CurrentFuncVariables = null;
			Info.CurrentClass = null;
			Info.CurrentFunc = null;
			//
			Info.Programs.Clear ();
			fac.Program.ReadBuildinSourceAsync ().Wait ();
			// 读取源码
			Info.CurrentFile = Path.Combine (Info.SrcPath, "App.fa");
			File.WriteAllText (Info.CurrentFile, _code);
			Log.Mark (LogMark.Parse);
			Info.Programs.Add (Common.ParseCode<AstProgram> (Info.CurrentSourceCode = _code));

			// 编译
			Info.Programs.ProcessType ();
			Info.Programs.Compile ();

			// 输出
			Directory.SetCurrentDirectory (Info.DestPath);
			string _dest_src = Info.GenerateCSharp ();
			if (!File.Exists (Path.Combine (Info.DestPath, $"{Info.ProjectName}.csproj")))
				_process_run ("dotnet new console --force");
			string _dest_file = Path.Combine (Info.DestPath, "Program.cs");
			File.WriteAllText (_dest_file, _dest_src, Encoding.UTF8);
			string _out = _process_run ("dotnet build");

			// 获取运行结果
			string _bin_file = "";
			if (Directory.Exists (Path.Combine (Info.DestPath, "bin", "Debug", "net5.0"))) {
				_bin_file = Path.Combine (Info.DestPath, "bin", "Debug", "net5.0", $"{Info.ProjectName}.exe");
			} else {
				_bin_file = Path.Combine (Info.DestPath, "bin", "Debug", "net6.0", $"{Info.ProjectName}.exe");
			}
			return _process_run (_bin_file);
			//if (!File.Exists (_bin_file))
			//	throw new FileNotFoundException ();
			//Assembly _ass = Assembly.Load (_bin_file);
			//Type _type = _ass.GetType ($"{Info.ProjectName}.Program");
			//MethodInfo _method = _type.GetMethod ("Main");
			//_method.Invoke ()
		}
	}
}
