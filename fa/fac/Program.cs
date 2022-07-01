using fac.ASTs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text.Json;
using System.Threading.Tasks;

namespace fac {
	public class Program {
		/// <summary>
		/// 获取文件夹下所有文件
		/// </summary>
		/// <param name="_path"></param>
		/// <returns></returns>
		private static List<string> _GetAllFiles (string _path) {
			var _files = new List<string> ();
			_files.AddRange (Directory.GetFiles (_path));
			foreach (var _directory in Directory.GetDirectories (_path)) {
				if (_directory != Info.DestPath)
					_files.AddRange (_GetAllFiles (_directory));
			}
			return _files;
		}

		/// <summary>
		/// 调用进程
		/// </summary>
		/// <param name="_cmd"></param>
		/// <returns></returns>
		private static async Task RunProcessAsync (string _cmd) {
			int _p = _cmd.IndexOf (' ');
			string _file = _p == -1 ? _cmd : _cmd[.._p];
			string _arg = _p == -1 ? "" : _cmd[(_p+1)..];

			using var _ps = new Process ();
			_ps.StartInfo.UseShellExecute = false;
			_ps.StartInfo.FileName = _file;
			_ps.StartInfo.Arguments = _arg;
			_ps.StartInfo.CreateNoWindow = false;
			_ps.Start ();
			await _ps.WaitForExitAsync ();
		}

		/// <summary>
		/// 从路径中提取有意义的名称做项目名
		/// </summary>
		/// <param name="_path"></param>
		/// <returns></returns>
		private static string _GetLastName (string _path) {
			return _path[(_path.LastIndexOfAny (new char[] { '/', '\\' }) + 1)..];
		}

		/// <summary>
		/// 更新检查
		/// </summary>
		/// <param name="version"></param>
		/// <returns></returns>
		private static async Task CheckUpdatesAsync (Version version) {
			try {
				using var client = new HttpClient { Timeout = TimeSpan.FromSeconds (2) };
				client.DefaultRequestHeaders.Accept.Clear ();
				client.DefaultRequestHeaders.Accept.Add (new MediaTypeWithQualityHeaderValue ("application/vnd.github.v3+json"));
				client.DefaultRequestHeaders.Add("User-Agent", "falang Compiler Version Checker");
				var streamTask = await client.GetStringAsync ("https://api.github.com/repos/fa-org/fa/releases");
				var repositories = JsonSerializer.Deserialize<List<Releases>> (streamTask);

				var updatable = false;
				foreach (var releases in repositories) {
					var releaseVersion = new Version (releases.ReleaseVersion[1..]);
					if (releaseVersion <= version)
						break;
					if (!updatable) {
						Console.WriteLine ($"发现新版本");
						Console.WriteLine ($"Download Link:{releases.Asset[0].Download_url}");
					}
					Console.WriteLine ($"{releases.ReleaseVersion}:");
					Console.WriteLine ($"	-{releases.Detail}");
					Console.WriteLine ();
					updatable = true;
				}
			} catch (Exception) {
			}
		}

		/// <summary>
		/// 打印初始化信息
		/// </summary>
		private static async Task PrintInfoAsync () {
			var _asm = Assembly.GetExecutingAssembly ();
			Console.WriteLine ($"fa语言编译器");
			Console.WriteLine ($"    版权：{(Attribute.GetCustomAttribute (_asm, typeof (AssemblyCopyrightAttribute)) as AssemblyCopyrightAttribute).Copyright}");
			Console.WriteLine ($"    版本：{_asm.GetName ().Version}");
			Console.WriteLine ($"    源码：https://github.com/fa-org/fa");
			if (!Debugger.IsAttached)
				await CheckUpdatesAsync (_asm.GetName ().Version);
			Console.WriteLine ();
		}

		/// <summary>
		/// 打印使用手册
		/// </summary>
		private static void PrintManual () {
			var _exename = Process.GetCurrentProcess ().MainModule.ModuleName;
			if (_exename == "dotnet" || _exename == "dotnet.exe") {
				var _location = Assembly.GetEntryAssembly ().Location;
				_location = _location[(_location.LastIndexOfAny (new char[] { '/', '\\' }) + 1)..];
				_exename = $"{_exename} {_location}";
			}
			Console.WriteLine ($"用法：");
			Console.WriteLine ($"{_exename} fa程序文件目录|fa程序文件.fa [-d] [-r]");
			Console.WriteLine ();
			Console.WriteLine ($"    -d    调试模式，将在控制台打印C#后端输出");
			Console.WriteLine ($"    -r    发布模式，将编译为可发布版本");
			Console.WriteLine ();
			Console.WriteLine ($"备注：如果指定目录，则目录名不要以“.fa”结尾，另外fa程序扩展名必须小写");
			Console.WriteLine ($"示例：");
			if (RuntimeInformation.IsOSPlatform (OSPlatform.Windows)) {
				Console.WriteLine ($"    {_exename} D:\\FaProject -r");
				Console.WriteLine ($"    {_exename} D:\\FaProject\\Program.fa -d");
			} else {
				Console.WriteLine ($"    {_exename} /FaProject -r");
				Console.WriteLine ($"    {_exename} /FaProject/Program.fa -d");
			}
			Console.WriteLine ();
		}

		/// <summary>
		/// 读取编译器自带标准库，比如Error等，用于后续part拼接，以及替换掉buildin实现
		/// </summary>
		public static async Task ReadBuildinSourceAsync () {
			var _assembly = Assembly.GetExecutingAssembly ();
			var _fa_files = _assembly.GetManifestResourceNames ();
			_fa_files = (from p in _fa_files where p[..7] == "fac.fa." select p).ToArray ();
			foreach (var _fa_file in _fa_files) {
				Info.CurrentFile = $"res://fa/{_fa_file[7..]}";
				using var _stream = _assembly.GetManifestResourceStream (_fa_file);
				using var _reader = new StreamReader (_stream, Encoding.UTF8);
				Info.CurrentSourceCode = await _reader.ReadToEndAsync ();
				Log.Mark (LogMark.Parse);
				var _program = Common.ParseCode<AstProgram> (Info.CurrentSourceCode);
				if (_program == null) {
					if (Debugger.IsAttached) {
						Console.WriteLine ($"按任意键退出。。。");
						Console.ReadKey ();
					}
					return;
				}
				Info.Programs.Add (_program);
			}
		}

		private static async Task Main (string[] args) {
			await PrintInfoAsync ();
			if (args.Length == 0 || (args.Length == 1 && (args[0] == "--help" || args[0] == "-help" || args[0] == "/help" || args[0] == "-?" || args[0] == "/?"))) {
				PrintManual ();
				if (Debugger.IsAttached) {
					Console.WriteLine ($"按任意键退出。。。");
					Console.ReadKey ();
				}
				return;
			}

			string _path = Path.GetFullPath (args[0]);
			if (_path.EndsWith (".fa")) {
				// 文件
				if (!File.Exists (_path)) {
					Console.WriteLine ($"指定文件 {_path} 不存在，无法编译");
					if (Debugger.IsAttached) {
						Console.WriteLine ($"按任意键退出。。。");
						Console.ReadKey ();
					}
					return;
				}
				_path = _path[.._path.LastIndexOfAny (new char[] { '/', '\\' })];
				Info.ProjectName = _GetLastName (_path);
				Info.SrcPath = _path;
			} else {
				// 文件夹
				if (!Directory.Exists (_path)) {
					Console.WriteLine ($"指定目录 {_path} 不存在，无法编译");
					if (Debugger.IsAttached) {
						Console.WriteLine ($"按任意键退出。。。");
						Console.ReadKey ();
					}
					return;
				}
				Info.ProjectName = _GetLastName (_path);
				Info.SrcPath = args[0];
			}

			//Info.ProjectName = "Hello";
			//Info.SrcPath = "D:\\GitHub\\_\\fa\\test";
			Info.DestPath = Path.Combine (Info.SrcPath, "_build");
			if (!Directory.Exists (Info.SrcPath))
				Directory.CreateDirectory (Info.SrcPath);
			if (!Directory.Exists (Info.DestPath))
				Directory.CreateDirectory (Info.DestPath);

			// 处理源码文件
			List<string> _src_files;
			if (_path.EndsWith (".fa")) {
				_src_files = new List<string> { _path };
			} else {
				_src_files = _GetAllFiles (Info.SrcPath);
				_src_files = (from p in _src_files where p[^3..].ToLower () == ".fa" select p).ToList ();
			}

			await ReadBuildinSourceAsync ();

			// 读取源码
			foreach (var _src_file in _src_files) {
				Info.CurrentFile = _src_file;
				Info.CurrentSourceCode = await File.ReadAllTextAsync (_src_file, Encoding.UTF8);
				Log.Mark (LogMark.Parse);
				var _program = Common.ParseCode<AstProgram> (Info.CurrentSourceCode);
				if (_program == null) {
					if (Debugger.IsAttached) {
						Console.WriteLine ($"按任意键退出。。。");
						Console.ReadKey ();
					}
					return;
				}
				Info.Programs.Add (_program);
			}

			// 编译
			if (Debugger.IsAttached) {
				Info.Programs.ProcessType ();
				Info.Programs.Compile ();
			} else {
				try {
					Info.Programs.ProcessType ();
					Info.Programs.Compile ();
				} catch (CodeException _ce) {
					if (_ce.Token != null) {
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
							} else if (((short) _code[i]) < 128) {
								_sb.Append (' ');
							} else {
								_sb.Append ('　');
							}
						}
						Console.WriteLine ($"{_sb}^");
					} else {
						Console.WriteLine ($"位于 {Info.CurrentRelativeFile} 文件的错误：{_ce.Message}");
					}
					return;
				}
			}

			// 输出
			Directory.SetCurrentDirectory (Info.DestPath);
			string _dest_src = Info.GenerateCpp ();
			Console.WriteLine (_dest_src);
			//if (!File.Exists (Path.Combine (Info.DestPath, $"{Info.ProjectName}.csproj")))
			//	await RunProcessAsync ("dotnet new console --force");
			//if (args.Contains ("-d")) {
			//	Console.WriteLine ("-------------------- generate begin --------------------");
			//	Console.WriteLine (_dest_src);
			//	Console.WriteLine ("--------------------  generate end  --------------------");
			//}
			//string _dest_file = Path.Combine (Info.DestPath, "Program.cs");
			//await File.WriteAllTextAsync (_dest_file, _dest_src, Encoding.UTF8);
			//if (args.Contains ("-r")) {
			//	Console.WriteLine ("正在构建。。。");
			//	await RunProcessAsync ("dotnet publish");
			//} else {
			//	Console.WriteLine ("正在构建并运行。。。");
			//	await RunProcessAsync ("dotnet run");
			//}
			////
			//if (Debugger.IsAttached) {
			//	Console.WriteLine ($"按任意键退出。。。");
			//	Console.ReadKey ();
			//}
			Console.WriteLine ($"按任意键退出。。。");
			Console.ReadKey ();
		}
	}
}
