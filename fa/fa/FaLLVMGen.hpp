#ifndef __FA_LLVM_GEN_HPP__
#define __FA_LLVM_GEN_HPP__



#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/Optional.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/DIBuilder.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>

#include <fmt/core.h>

#include "CodeVisitor.hpp"
#include "TypeMap.hpp"
#include "ValueBuilder.hpp"



class FaLLVMGen {
public:
	FaLLVMGen (CodeVisitor *_visitor, std::string _module_name): m_visitor (_visitor), m_module_name (_module_name) {
		m_ctx = std::make_shared<llvm::LLVMContext> ();
		m_module = std::make_shared<llvm::Module> (_module_name, *m_ctx);
		m_etype_map = std::make_shared<TypeMap> (_visitor, *m_ctx);
		m_value_builder = std::make_shared<ValueBuilder> (_visitor, *m_ctx);
	}

	std::optional<std::string> Compile (FaParser::ProgramContext *_program_ctx, std::string _file) {
		auto [_uses, _imports, _classes, _entry] = m_visitor->visitProgram (_program_ctx).as<std::tuple<
			std::vector<std::string>,
			FaParser::ImportBlockContext *,
			std::vector<FaParser::ClassBlockContext *>,
			FaParser::FaEntryMainFuncBlockContext *
		>> ();
		m_uses = _uses;

		// 引用外部模块
		std::vector<FaParser::ImportStmtContext *> _imports_raw;
		std::tie (_imports_raw, m_libs) = m_visitor->visitImportBlock (_imports).as<std::tuple<
			std::vector<FaParser::ImportStmtContext *>,
			std::vector<std::string>
		>> ();
		//m_imports.push_back ("puts");
		//m_libs.push_back ("libcmt.lib");
		ProcessImports (_imports_raw);

		// TODO: 编译类

		if (!_entry)
			return "未定义入口点";
		BuildFaEntryMain (_entry);

		llvm::InitializeAllTargetInfos ();
		llvm::InitializeAllTargets ();
		llvm::InitializeAllTargetMCs ();
		llvm::InitializeAllAsmParsers ();
		llvm::InitializeAllAsmPrinters ();
		std::string _target_triple = llvm::sys::getDefaultTargetTriple (), _err = "";
		m_module->setTargetTriple (_target_triple);
		const llvm::Target *_target = llvm::TargetRegistry::lookupTarget (_target_triple, _err);
		if (!_target)
			return _err;
		std::string _cpu = "";
		std::string _features = "";

		llvm::TargetOptions _opt;
		auto _model = llvm::Optional<llvm::Reloc::Model> ();
		auto _target_machine = _target->createTargetMachine (_target_triple, _cpu, _features, _opt, _model);
		m_module->setDataLayout (_target_machine->createDataLayout ());

		std::error_code _ec;
		llvm::raw_fd_ostream _dest (_file, _ec, llvm::sys::fs::F_None);

		if (_ec)
			return "无法打开输出文件";

		llvm::legacy::PassManager _pass;
		if (_target_machine->addPassesToEmitFile (_pass, _dest, nullptr, llvm::CGFT_ObjectFile))
			return "无法输出编译文件";

		_pass.run (*m_module);
		_dest.flush ();
		return std::nullopt;
	}

	std::string Link (std::string _link_exe_path) {
		wchar_t *get_env (std::string _key, std::string _val);
		wchar_t *_env = get_env ("LIB", R"(LIBPATH=E:\Software\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\ATLMFC\lib\x86;E:\Software\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\lib\x86;E:\Software\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\lib\x86\store\references;D:\Windows Kits\10\UnionMetadata\10.0.19041.0;D:\Windows Kits\10\References\10.0.19041.0;C:\Windows\Microsoft.NET\Framework\v4.0.30319\0\0)");

		std::string _cmd = fmt::format ("\"{}\" /subsystem:console /dynamicbase /machine:X86 /debug /entry:fa_entry_main /out:{}.exe /pdb:{}.pdb {}.obj", _link_exe_path, m_module_name, m_module_name, m_module_name);
		for (auto _lib : m_libs) {
			_cmd += " ";
			_cmd += _lib;
		}
		std::string get_process_output (std::string _cmd, wchar_t *_env);
		return get_process_output (_cmd, _env);
	}

private:
	void ProcessImports (std::vector<FaParser::ImportStmtContext *> _imports_raw) {
		// https://blog.csdn.net/adream307/article/details/83820543
		for (FaParser::ImportStmtContext *_import_func_raw : _imports_raw) {
			auto [_name, _ret_type_raw, _arg_types_raw, _cc] = m_visitor->visitImportStmt (_import_func_raw).as<std::tuple<
				std::string,
				FaParser::ETypeContext *,
				std::vector<FaParser::ETypeContext *>,
				std::string
			>> ();
			llvm::Function *_f = m_module->getFunction (_name);
			if (_f == nullptr) {
				llvm::Type *_ret_type = m_etype_map->GetExternType (_ret_type_raw);
				std::vector<llvm::Type *> _arg_types = m_etype_map->GetExternTypes (_arg_types_raw);
				llvm::FunctionType *_ft = llvm::FunctionType::get (_ret_type, _arg_types, false);
				_f = llvm::Function::Create (_ft, llvm::Function::ExternalLinkage, _name, *m_module);
				if (_cc == "__cdecl") {
					_f->setCallingConv (llvm::CallingConv::C);
				} else if (_cc == "__stdcall") {
					_f->setCallingConv (llvm::CallingConv::X86_StdCall);
				} else if (_cc == "__fastcall") {
					_f->setCallingConv (llvm::CallingConv::X86_FastCall);
				}
			}
			m_imports [_name] = _f;
		}
	}

	void BuildFaEntryMain (FaParser::FaEntryMainFuncBlockContext *_mctx) {
		auto [_ret_type_raw, _stmts_raw] = m_visitor->visitFaEntryMainFuncBlock (_mctx).as<std::tuple<
			FaParser::TypeContext *,
			std::vector<FaParser::StmtContext *>
		>> ();
		llvm::Type *_ret_type = m_etype_map->GetType (_ret_type_raw);
		llvm::FunctionType *_ft = llvm::FunctionType::get (_ret_type, false);
		llvm::Function *_f = llvm::Function::Create (_ft, llvm::Function::ExternalLinkage, "fa_entry_main", *m_module);
		llvm::BasicBlock *_bb = llvm::BasicBlock::Create (*m_ctx, "fa_entry_main_block", _f);
		llvm::IRBuilder<> _builder (_bb);
		_builder.SetInsertPoint (_bb);
		FuncCodeBuilder (_builder, _stmts_raw, _ret_type);
	}

	void FuncCodeBuilder (llvm::IRBuilder<> &_builder, std::vector<FaParser::StmtContext *> _stmts_raw, llvm::Type *_ret_type) {
		for (FaParser::StmtContext *_stmt_raw : _stmts_raw) {
			FaParser::ExprContext *_expr = _stmt_raw->expr ();
			llvm::Value *_value = ExprCodeBuilder (_expr);
			//
			if (_stmt_raw->Return () != nullptr)
				_builder.CreateRet (_value);
		}
		//llvm::ConstantInt::get (_ret_type, llvm::APInt (32, 0, true))
	}

	llvm::Value *ExprCodeBuilder (FaParser::ExprContext *_expr) {
		if (_expr == nullptr)
			return nullptr;
		if (_expr->quotExpr () != nullptr)
			return ExprCodeBuilder (_expr->quotExpr ()->expr ());
		std::vector<FaParser::ExprPrefixContext *> _prefix = _expr->exprPrefix (); // TODO
		FaParser::ExprBodyContext *_body = _expr->exprBody ();
		std::vector<FaParser::ExprSuffixContext *> _suffix = _expr->exprSuffix (); // TODO
		if (_body->ids () != nullptr) {
			// TODO ids操作
			std::string _cur_name = _body->ids ()->getText ();
		} else if (_body->ColonColon () != nullptr) {
			// TODO 外部 C API 调用
		} else {
			// TODO 元素
			auto _literal = _body->literal ();
			if (_literal->BoolLiteral ()) {
				return llvm::ConstantInt::get ();
			}
		}
	}

	CodeVisitor *m_visitor = nullptr;
	std::string m_module_name;
	std::shared_ptr<llvm::LLVMContext> m_ctx;
	std::shared_ptr<llvm::Module> m_module;
	std::shared_ptr<TypeMap> m_etype_map;
	std::shared_ptr<ValueBuilder> m_value_builder;

	std::vector<std::string> m_uses;
	std::map<std::string, llvm::Function *> m_imports;
	std::vector<std::string> m_libs;
};



#endif //__FA_LLVM_GEN_HPP__
