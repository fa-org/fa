#include <string>



std::string CODE = R"(
@import int32 __cdecl puts (cstr);
//// MT
//@lib "libucrt.lib";
//@lib "libcmt.lib";
////@lib "libvcruntime.lib";

// MD
@lib "ucrt.lib";
@lib "msvcrt.lib";
//@lib "vcruntime.lib";

//@lib "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "ole32.lib";
//@lib "advapi32.lib" "shell32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib";

public class AAA {
	public int32 num1;
	public int32 num2;
}

int32 FaMain () {
	var i = 0;
	var sum = 0;
	while i < 10 {
		i++;
		sum += i;
	}

	if sum == 55 {
		::puts ("sum == 55\n");
	} else {
		::puts ("sum != 55\n");
	}
	return 0;
}
)";
