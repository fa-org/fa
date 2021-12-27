using System.Collections.Generic;
using System.Text.Json.Serialization;

namespace fac {
	public class Releases {

		[JsonPropertyName("tag_name")]
		public string ReleaseVersion {
			get; set;
		}

		[JsonPropertyName("body")]
		public string Detail {
			get; set;
		}
		[JsonPropertyName("assets")]
		public IList<Assets> Asset {
			get; set;
		}
	}
	public class Assets {
		[JsonPropertyName("browser_download_url")]
		public string Download_url {
			get; set;
		}
	}
}

