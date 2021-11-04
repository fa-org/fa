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
			var _programs = new List<AstProgram> ();
			foreach (var _src_file in _src_files) {
				Info.CurrentFile = _src_file;
				Info.CurrentCode = File.ReadAllText (_src_file, Encoding.UTF8);
				Log.Mark (LogMark.Parse);
				_programs.Add (Common.ParseCode<AstProgram> (Info.CurrentCode));
			}

			// 编译
			foreach (var _program in _programs)
				_program.Compile ();

			// 输出
			var _output = new OutputCSharp ();
			var _gens = _output.Generate (_programs);
			foreach (var (_file, _outcode) in _gens) {
				var _file_path = Path.Combine (Info.DestPath, _file);
				File.WriteAllText (_file_path, _outcode, Encoding.UTF8);
			}

			// TODO 调用命令编译

			Console.WriteLine ("按任意键退出");
			Console.ReadKey ();
		}
	}
}
