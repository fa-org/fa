#ifndef __FA_COMPILE_RUNTIME_HPP__
#define __FA_COMPILE_RUNTIME_HPP__



#include <exception>
#include <functional>
#include <string>
#include <variant>
#include <vector>

#ifndef ANTLR4CPP_STATIC
#	define ANTLR4CPP_STATIC
#endif
#include <antlr4-runtime/antlr4-runtime.h>

namespace fa {
enum class AstType {
	// blocks
	Block_Program, Block_Use, Block_Anno, Block_AnnoPart, Block_Class, Block_ClassFunc, Block_ClassFuncEmpty, Block_ClassValueVar, Block_ClassVar, Block_Enum, Block_EnumItem,
	// Exprs
	ExprRef_Argument, ExprRef_ClassVar, ExprRef_ClassFunc, ExprRef_LocalVar, ExprRef_EnumItem,
	Expr_Array1, Expr_Array2, Expr_If, Expr_Invoke, Expr_Is, Expr_New, Expr_Op1, Expr_Op2, Expr_TempName, Expr_This, Expr_TypeWrap, Expr_Value,
	// Stmts
	Stmt_Break, Stmt_Continue, Stmt_DefineVar, Stmt_ExprWrap, Stmt_For1, Stmt_For2, Stmt_If, Stmt_Return, Stmt_Stmts, Stmt_While, Stmt_While2,
	// Types
	Type_Any, Type_Bool, Type_Class, Type_Float, Type_Func, Type_Int, Type_OptionWrap, Type_TempItem, Type_TempName, Type_TupleWrap, Type_UnsureWrap, Type_Void,
};
enum class ParseType {
	AnnoPart, ClassVar, ClassFunc, EnumItem, Use, Type, Anno, Enum, Class,
	Part_Parent, Part_Member, Part_Member2, Part_Type, Part_ReturnType, Part_ArgType, Part_FuncBody, Part_Init, Part_Condition, Part_Increment, Part_TrueContent, Part_FalseContent, Part_Value, Part_Func, Part_FuncArg, Part_ValueExpr, Part_ValueStmt, Part_ValueType,
};
enum class ParseValueType { PublicLevel, Namespace, Part_Name, Part_ArgAttr, Part_ArgName, Static, VarName, FullName, Name, Type, Value, Index, Operator, Templates };
enum class PublicLevel { Public, Internal, Protected, Private };
enum class ArgAttr { None, Mut, Params, Disperse };
using ParseValue_t = std::variant<std::string, bool, int64_t, uint64_t, double, PublicLevel, ArgAttr>;



inline std::string Indent (size_t _indent) { return std::string (_indent * 4, ' '); }

inline std::string RandomStr () {
	std::string _str = "";
	for (size_t i = 0; i < 16; ++i) {
		char n = (char) (::rand () % 52);
		_str.push_back (n < 26 ? (n + 'A') : (n - 26 + 'a'));
	}
	return _str;
}



struct Exception: public std::exception {
	antlr4::Token *m_token = nullptr;
	std::string m_err = "";
	template<typename ...Args>
	Exception (antlr4::Token *_token, const char *_err, Args ..._args) {
		m_err = sizeof... (_args) == 0 ? _err : std::vformat (_err, std::make_format_args (_args...));
	}
	char const *what () const override { return m_err.c_str (); }
};



struct AstObj {
	antlr4::Token *m_token = nullptr;
	AstObj (antlr4::Token *_token): m_token (_token) {}
	virtual void SetMembers (ParseType _type, std::vector<AstObj *> _values) = 0;
	virtual std::vector<AstObj *> GetMembers (ParseType _type) = 0;
	virtual void SetValues (ParseValueType _type, std::vector<ParseValue_t> _values) = 0;
	virtual std::vector<ParseValue_t> GetValues (ParseValueType _type) = 0;
};



void SetTypeGenFunc (std::function<AstObj* (AstType, antlr4::Token *_token)> _factory_cb);
AstObj *CompileCode (std::string _code, AstType _code_type);
}



#endif //__FA_COMPILE_RUNTIME_HPP__
