using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace fac {
	public static class StaticHelper {
		public static string GetDisplayName (this Enum _enum) {
			var _def_name = $"{_enum}";
			var _info = _enum.GetType ().GetField (_def_name);
			var _attrs = _info.GetCustomAttributes (typeof (DisplayAttribute), false) as DisplayAttribute [];
			return _attrs.Length > 0 ? _attrs [0].Name : _def_name;
		}

		public static string Indent (this int _indent) => new string (' ', _indent * 4);
	}
}
