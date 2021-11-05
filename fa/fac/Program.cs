using fac.ASTs;
using fac.Outputs.Rust;
using System;
using System.Collections.Generic;
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

		static void Main (string[] args) {
			Info.ProjectName = "Hello";
			Info.SrcPath = "E:\\GitHub\\_\\fa\\src";
			Info.DestPath = "E:\\fa_tmp";
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
				Info.CurrentCode = File.ReadAllText (_src_file, Encoding.UTF8);
				Log.Mark (LogMark.Parse);
				Info.Programs.Add (Common.ParseCode<AstProgram> (Info.CurrentCode));
			}

			// 编译
			foreach (var _program in Info.Programs)
				_program.Compile ();

			// 输出
			string _out = OutputCSharp.Generate ();
			Console.WriteLine ($"编译成功。输出目标文件 {_out}");
			Console.WriteLine ("按任意键退出。。。");
			Console.ReadKey ();
		}
	}
}
