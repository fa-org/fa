using fac.ASTs;
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
			Info.Path = "E:\\GitHub\\_\\fa\\src\\";
			var _src_files = _GetAllFiles (Info.Path);
			_src_files = (from p in _src_files where p[^3..].ToLower () == ".fa" select p).ToList ();
			foreach (var _src_file in _src_files) {
				Info.CurrentFile = _src_file;
				Info.CurrentCode = File.ReadAllText (_src_file, Encoding.UTF8);
				Log.Mark (LogMark.Parse);
				AstProgram _program = Common.ParseCode<AstProgram> (Info.CurrentCode);
			}
			Console.WriteLine ("按任意键退出");
			Console.ReadKey ();
		}
	}
}
