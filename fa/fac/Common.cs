﻿using Antlr4.Runtime;
using Antlr4.Runtime.Tree;
using fac.AntlrTools;
using fac.ASTs;
using fac.Exceptions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace fac {
	enum PublicLevel { Public, Protected, Private }



	class Common {
		/// <summary>
		/// 解析字符串为枚举类型
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="_str"></param>
		/// <returns></returns>
		public static T? ParseEnum<T> (string _str) where T : struct {
			if (string.IsNullOrEmpty (_str))
				return null;
			if (System.Enum.TryParse<T> (_str, out var _cc))
				return _cc;
			_str = $"{$"{_str[0]}".ToUpper ()}{_str[1..]}";
			if (System.Enum.TryParse<T> (_str, out var _cc1))
				return _cc1;
			return null;
		}

		/// <summary>
		/// 编译代码到AST
		/// </summary>
		/// <typeparam name="T">AST对象</typeparam>
		/// <param name="_code">源码</param>
		/// <returns>AST对象</returns>
		public static T ParseCode<T> (string _code) where T : class {
			var _stream = new AntlrInputStream (_code);
			var _lexer = new FaLexer (_stream);
			var _token_stream = new CommonTokenStream (_lexer);
			var _parser = new FaParser (_token_stream);
			//
			Info.Visitor = new FaVisitorImpl ();
			var _type = typeof (T);
			string _name = _type.FullName;
			if (_name.Contains ('.'))
				_name = _name.Substring (_name.LastIndexOf ('.') + 1);
			if (_name.StartsWith ("Ast"))
				_name = _name[3..];
			if (_name.StartsWith ("IAst"))
				_name = _name[4..];
			_name = _name.ToLower ();
			var _methods = (from p in typeof (FaParser).GetMethods () where p.Name.ToLower () == _name select p).ToList ();
			if (_methods.Count != 1)
				throw new Exception ($"Program.ParseCode<T>: 使用到了 {_type.FullName} 类型，但 {_name} 方法{(_methods.Any () ? "数量大于1" : "不存在")}");
			var _tree = (IParseTree) _methods[0].Invoke (_parser, null);
			return Info.Visitor.Visit (_tree) as T;
		}

		public static string GetStringLiterialText (ITerminalNode _node) {
			string _src = _node.GetText ();
			if (string.IsNullOrEmpty (_src))
				throw new CodeException (_node, "字符串格式错误");
			if (_src[0] == '"') {
				_src = _src[1..^1];
				var _dest = new StringBuilder ();
				for (int i = 0; i < _src.Length; ++i) {
					if (_src[i] != '\\') {
						_dest.Append (_src[i]);
					} else if (i + 1 == _src.Length) {
						throw new CodeException (_node, "字符串格式错误");
					} else {
						_dest.Append (_src[++i]);
					}
				}
				return $"{_dest}";
			}
			throw new UnimplException (_node);
		}

		public static string GetTempId () => $"_{Guid.NewGuid ().ToString ("N")[..8]}";

		public static string WrapStringValue (string _s) {
			var _sb = new StringBuilder ().Append ("\"");
			foreach (var _ch in _s) {
				if (sTransReverse.ContainsKey (_ch)) {
					_sb.Append (sTransReverse[_ch]);
				} else {
					_sb.Append (_ch);
				}
			}
			_sb.Append ("\"");
			return _sb.ToString ();
		}
		private static Dictionary<char, string> sTransReverse = new Dictionary<char, string> {
			['\r'] = "\\r", ['\n'] = "\\n", ['\t'] = "\\t", ['\''] = "\\'", ['\\'] = "\\\\", ['\"'] = "\\\"",
		};

		public static string UnwrapStringValue (string _s) {
			var _sb = new StringBuilder ();
			bool _trans = false;
			foreach (char _ch in _s[1..^1]) {
				if (_trans) {
					if (!sTransChar.ContainsKey (_ch))
						throw new Exception ($"未识别的转义字符 \\{_ch}");
					_sb.Append (sTransChar[_ch]);
					_trans = false;
				} else if (_ch == '\\') {
					_trans = true;
				} else {
					_sb.Append (_ch);
				}
			}
			return _sb.ToString ();
		}
		private static Dictionary<char, char> sTransChar = new Dictionary<char, char> {
			['r'] = '\r', ['n'] = '\n', ['t'] = '\t', ['\''] = '\'', ['\\'] = '\\', ['\"'] = '\"',
		};
	}
}
