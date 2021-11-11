using fac.ASTs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace fac {
	class Program {
		private static List<string> _GetAllFiles (string _path) {
			var _files = new List<string> ();
			_files.AddRange (Directory.GetFiles (_path));
			foreach (var _directory in Directory.GetDirectories (_path))
				_files.AddRange (_GetAllFiles (_directory));
			return _files;
		}

		private static void _process_run (string _cmd) {
			int _p = _cmd.IndexOf (' ');
			string _file = _p == -1 ? _cmd : _cmd[.._p];
			string _arg = _p == -1 ? "" : _cmd[(_p+1)..];

			using var _ps = new Process ();
			_ps.StartInfo.UseShellExecute = false;
			_ps.StartInfo.FileName = _file;
			_ps.StartInfo.Arguments = _arg;
			_ps.StartInfo.CreateNoWindow = false;
			_ps.Start ();
			_ps.WaitForExit ();
		}

		static void Main (string[] args) {
			Info.ProjectName = "Hello";
			Info.SrcPath = "D:\\GitHub\\_\\fa\\src";
			Info.DestPath = $"D:\\fa_tmp\\{Info.ProjectName}";
			if (!Directory.Exists (Info.SrcPath))
				Directory.CreateDirectory (Info.SrcPath);
			if (!Directory.Exists (Info.DestPath))
				Directory.CreateDirectory (Info.DestPath);

			// 处理源码文件
			var _src_files = _GetAllFiles (Info.SrcPath);
			_src_files = (from p in _src_files where p[^3..].ToLower () == ".fa" select p).ToList ();

			// 读取源码
			foreach (var _src_file in _src_files) {
				Info.CurrentFile = _src_file;
				Info.CurrentSourceCode = File.ReadAllText (_src_file, Encoding.UTF8);
				Log.Mark (LogMark.Parse);
				Info.Programs.Add (Common.ParseCode<AstProgram> (Info.CurrentSourceCode));
			}

			try {
				// 编译
				foreach (var _program in Info.Programs)
					_program.Compile ();
			} catch (CodeException _ce) {
				Console.WriteLine ($"位于 {Info.CurrentRelativeFile} 文件第 {_ce.Token.Line} 行的错误：{_ce.Message}");
				int _start = Info.CurrentSourceCode.LastIndexOfAny (new char[] { '\r', '\n' }, _ce.Token.StartIndex) + 1;
				string _code = Info.CurrentSourceCode[_start..];
				int _p = _code.IndexOfAny (new char [] { '\r', '\n' });
				_code = _code[.._p];
				Console.WriteLine (_code);
				var _sb = new StringBuilder ();
				for (int i = 0; i < _ce.Token.Column; ++i) {
					if (_code[i] == '\t') {
						_sb.Append ('\t');
					} else if (((short)_code[i]) < 128) {
						_sb.Append (' ');
					} else {
						_sb.Append ('　');
					}
				}
				Console.WriteLine ($"{_sb}^");
				Console.WriteLine ($"按任意键退出。。。");
				Console.ReadKey ();
				return;
			}

			// 输出
			Directory.SetCurrentDirectory (Info.DestPath);
			if (!File.Exists (Path.Combine (Info.DestPath, $"{Info.ProjectName}.csproj")))
				_process_run ("dotnet new console");
			string _dest_src = Info.GenerateCSharp ();
			Console.WriteLine ("-------------------- generate begin --------------------");
			Console.WriteLine (_dest_src);
			Console.WriteLine ("--------------------  generate end  --------------------");
			string _dest_file = Path.Combine (Info.DestPath, "Program.cs");
			File.WriteAllText (_dest_file, _dest_src, Encoding.UTF8);
			_process_run ("dotnet run");
			//
			Console.WriteLine ($"按任意键退出。。。");
			Console.ReadKey ();
		}
	}
}
