#include "pch.h"
#include <iostream>
#include <string>

#include "File.hpp"
#include "../fa_compile_runtime/fa_compile_runtime.hpp"
#include "common/Evaluation.hpp"
// blocks
#include "ASTs/Blocks/AstClass.hpp"
#include "ASTs/Blocks/AstAnnoPart.hpp"
#include "ASTs/Blocks/AstClassFunc.hpp"
#include "ASTs/Blocks/AstClassValueVar.hpp"
#include "ASTs/Blocks/AstClassVar.hpp"
#include "ASTs/Blocks/AstClassFuncEmpty.hpp"
#include "ASTs/Blocks/AstEnumItem.hpp"
#include "ASTs/Blocks/AstProgram.hpp"
#include "ASTs/Blocks/AstUse.hpp"
// exprs
#include "ASTs/Exprs/BuildIns/AstBuildInExpr_Dictionary.hpp"
#include "ASTs/Exprs/BuildIns/AstBuildInExpr_String.hpp"
#include "ASTs/Exprs/NameExprs/AstNameExpr_arg.hpp"
#include "ASTs/Exprs/NameExprs/AstNameExpr_class_var.hpp"
#include "ASTs/Exprs/NameExprs/AstNameExpr_class_func.hpp"
#include "ASTs/Exprs/NameExprs/AstNameExpr_var.hpp"
#include "ASTs/Exprs/AstExpr_array1.hpp"
#include "ASTs/Exprs/AstExpr_array2.hpp"
#include "ASTs/Exprs/AstExpr_if.hpp"
#include "ASTs/Exprs/AstExpr_invoke.hpp"
#include "ASTs/Exprs/AstExpr_is.hpp"
#include "ASTs/Exprs/AstExpr_new.hpp"
#include "ASTs/Exprs/AstExpr_op1.hpp"
#include "ASTs/Exprs/AstExpr_op2.hpp"
#include "ASTs/Exprs/AstExpr_temp_name.hpp"
#include "ASTs/Exprs/AstExpr_this.hpp"
#include "ASTs/Exprs/AstExpr_type_wrap.hpp"
#include "ASTs/Exprs/AstExpr_value.hpp"
// stmts
#include "ASTs/Stmts/AstStmt_break.hpp"
#include "ASTs/Stmts/AstStmt_continue.hpp"
#include "ASTs/Stmts/AstStmt_define_var_group.hpp"
#include "ASTs/Stmts/AstStmt_define_var.hpp"
#include "ASTs/Stmts/AstStmt_expr_wrap.hpp"
#include "ASTs/Stmts/AstStmt_for1.hpp"
#include "ASTs/Stmts/AstStmt_for2.hpp"
#include "ASTs/Stmts/AstStmt_if.hpp"
#include "ASTs/Stmts/AstStmt_return.hpp"
#include "ASTs/Stmts/AstStmt_stmts.hpp"
// types
#include "ASTs/Types/AstType_any.hpp"
#include "ASTs/Types/AstType_bool.hpp"
#include "ASTs/Types/AstType_class.hpp"
#include "ASTs/Types/AstType_float.hpp"
#include "ASTs/Types/AstType_func.hpp"
#include "ASTs/Types/AstType_int.hpp"
#include "ASTs/Types/AstType_temp_item.hpp"
#include "ASTs/Types/AstType_temp_name.hpp"
#include "ASTs/Types/AstType_tuple_wrap.hpp"
#include "ASTs/Types/AstType_unsure_wrap.hpp"
#include "ASTs/Types/AstType_void.hpp"

#ifdef _MSC_VER
#	pragma comment (lib, "antlr4-runtime-static.lib")
#	pragma comment (lib, "fa_compile_runtime.lib")
#endif



fa::AstObj *TypeFactory (fa::AstType _type, antlr4::Token *_token) {
	switch (_type) {
		// blocks
	case fa::AstType::Block_Anno:
		return new AstClass (_token, "anno");
	case fa::AstType::Block_AnnoPart:
		return new AstAnnoPart (_token);
	case fa::AstType::Block_Class:
		return new AstClass (_token, "class");
	case fa::AstType::Block_ClassFunc:
		return new AstClassFunc (_token);
	case fa::AstType::Block_ClassFuncEmpty:
		return new AstClassFuncEmpty (_token);
	case fa::AstType::Block_ClassValueVar:
		return new AstClassValueVar (_token);
	case fa::AstType::Block_ClassVar:
		return new AstClassVar (_token);
	case fa::AstType::Block_Enum:
		return new AstClass (_token, "enum");
	case fa::AstType::Block_EnumItem:
		return new AstEnumItem (_token);
	case fa::AstType::Block_Program:
		return new AstProgram (_token);
	case fa::AstType::Block_Use:
		return new AstUse (_token);
		// Exprs
	case fa::AstType::ExprRef_Argument:
	case fa::AstType::ExprRef_ClassVar:
	case fa::AstType::ExprRef_ClassFunc:
	case fa::AstType::ExprRef_LocalVar:
		throw fa::Exception (_token, "not implement");
		throw fa::Exception (_token, "not implement");
	case fa::AstType::Expr_Array1:
		return new AstExpr_array1 (_token);
	case fa::AstType::Expr_Array2:
		return new AstExpr_array2 (_token);
	case fa::AstType::Expr_If:
		return new AstExpr_if (_token);
	case fa::AstType::Expr_Invoke:
		return new AstExpr_invoke (_token);
	case fa::AstType::Expr_Is:
		return new AstExpr_is (_token);
	case fa::AstType::Expr_New:
		return new AstExpr_new (_token);
	case fa::AstType::Expr_Op1:
		return new AstExpr_op1 (_token);
	case fa::AstType::Expr_Op2:
		return new AstExpr_op2 (_token);
	case fa::AstType::Expr_TempName:
		return new AstExpr_temp_name (_token);
	case fa::AstType::Expr_This:
		return new AstExpr_this (_token);
	case fa::AstType::Expr_TypeWrap:
		return new AstExpr_type_wrap (_token);
	case fa::AstType::Expr_Value:
		return new AstExpr_value (_token);
		// Stmts
	case fa::AstType::Stmt_Break:
		return new AstStmt_break (_token);
	case fa::AstType::Stmt_Continue:
		return new AstStmt_continue (_token);
	case fa::AstType::Stmt_DefineVar:
		return new AstStmt_define_var_group (_token);
	case fa::AstType::Stmt_ExprWrap:
		return new AstStmt_expr_wrap (_token);
	case fa::AstType::Stmt_For1:
		return new AstStmt_for1 (_token);
	case fa::AstType::Stmt_For2:
		return new AstStmt_for2 (_token);
	case fa::AstType::Stmt_If:
		return new AstStmt_if (_token);
	case fa::AstType::Stmt_Return:
		return new AstStmt_return (_token);
	case fa::AstType::Stmt_Stmts:
		return new AstStmt_stmts (_token);
	case fa::AstType::Stmt_While:
	case fa::AstType::Stmt_While2:
		throw fa::Exception (_token, "not implement");
		throw fa::Exception (_token, "not implement");
		// Types
	case fa::AstType::Type_Any:
		return new AstType_any (_token);
	case fa::AstType::Type_Bool:
		return new AstType_bool (_token);
	case fa::AstType::Type_Class:
		return new AstType_class (_token);
	case fa::AstType::Type_Float:
		return new AstType_float (_token);
	case fa::AstType::Type_Func:
		return new AstType_func (_token);
	case fa::AstType::Type_Int:
		return new AstType_int (_token);
	case fa::AstType::Type_OptionWrap:
		return new AstType_temp_name (_token, "fa.Option");
	case fa::AstType::Type_TempItem:
		return new AstType_temp_item (_token);
	case fa::AstType::Type_TempName:
		return new AstType_temp_name (_token);
	case fa::AstType::Type_TupleWrap:
		throw fa::Exception (_token, "not implement");
	case fa::AstType::Type_UnsureWrap:
		return new AstType_unsure_wrap (_token);
	case fa::AstType::Type_Void:
		return new AstType_void (_token);
	}
	throw fa::Exception (_token, "not implement");
}

int main (int argc, char *argv []) {
	std::cout << "fa compiler v0.0.1\n";
	fa::SetTypeGenFunc (TypeFactory);
	if (argc == 2) {
		std::string _code = File::ReadAllText (argv [1]);
		CompileEnv::AstProgram = std::shared_ptr<AstProgram> (dynamic_cast<AstProgram *> (fa::CompileCode (_code, fa::AstType::Block_Program)));
		CompileEnv::AstProgram->ProcessDeclareType ();
		CompileEnv::AstProgram->ProcessCodeType ();
		//std::string _cppcode = CompileEnv::AstProgram->GenCppCode (0);
		//std::cout << _cppcode << std::endl;
		//File::WriteAllText ("main.cpp", _cppcode);
		//if (File::IsExist ("Debug\\faproject.exe"))
		//	File::Delete ("Debug\\faproject.exe");
		//system ("\"D:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\Msbuild\\Current\\Bin\\MSBuild.exe\" -t:rebuild");
		//if (File::IsExist ("Debug\\faproject.exe"))
		//	system ("Debug\\faproject.exe");
		auto _func = CompileEnv::AstProgram->m_classes ["Program"]->m_funcs ["Meta"];
		auto _ofind = CompileEnv::FindName (_func->m_token, "string", {}).value ();
		auto _tkey = dynamic_cast<AstExpr_type_wrap *> (_ofind.get ())->m_type;
		_ofind = CompileEnv::FindName (_func->m_token, "Type", {}).value ();
		auto _tvalue = dynamic_cast<AstExpr_type_wrap *> (_ofind.get ())->m_type;
		auto _classes = AstBuildInExpr_Dictionary::Make (_func->m_token, _tkey, _tvalue);
		auto _classes_dic = dynamic_cast<AstBuildInExpr_Dictionary *> (_classes.get ());
		for (auto &[_key, _val] : CompileEnv::AstProgram->m_classes) {
			_classes_dic->m_values.emplace (_key, AstExpr_value::Make (_val->m_token, AstType_class::Make (_val->m_token, _val, {})));
		}
		//auto _invoke = new AstExpr_invoke {_func->m_token};
		//_invoke->m_func = AstNameExpr_class_func::Make (_func->m_token, std::nullopt, _func, {}, {});
		//_invoke->m_args = { _classes };
		//Evaluation::Expr (std::shared_ptr<IAstExpr> ((IAstExpr *) _invoke));
		Evaluation::CallFunction (_func->m_token, _func, std::nullopt, { _classes });
	} else {
		std::cout << "usage:\n";
		std::cout << "    fac main.fa\n";
	}
	system ("pause");
	return 0;
}
