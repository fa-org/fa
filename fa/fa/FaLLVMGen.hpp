#ifndef __FA_LLVM_GEN_HPP__
#define __FA_LLVM_GEN_HPP__



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



class FaLLVMGen {
public:
	FaLLVMGen (CodeVisitor *_visitor, std::string _module_name): m_visitor (_visitor), m_module_name (_module_name) {
		m_ctx = std::make_shared<llvm::LLVMContext> ();
		m_module = std::make_shared<llvm::Module> (_module_name, *m_ctx);
	}

	std::optional<std::string> Compile (FaParser::ProgramContext *_program_ctx, std::string _file) {
		auto [_uses, _imports, _classes, _entry] = m_visitor->visitProgram (_program_ctx).as<std::tuple<std::vector<std::string>, FaParser::ImportBlockContext *, std::vector<FaParser::ClassBlockContext *>, FaParser::FaEntryMainFuncBlockContext *>> ();
		m_uses = _uses;

		// 引用外部模块
		std::tie (m_imports, m_libs) = m_visitor->visitImportBlock (_imports).as<std::tuple<std::vector<std::string>, std::vector<std::string>>> ();
		//m_imports.push_back ("puts");
		//m_libs.push_back ("libcmt.lib");
		ProcessImports ();

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
	void ProcessImports () {
		// TODO 链接接口
		// https://blog.csdn.net/adream307/article/details/83820543
	}

	void BuildFaEntryMain (FaParser::FaEntryMainFuncBlockContext *_mctx) {
		llvm::FunctionType *_ft = llvm::FunctionType::get (
			llvm::Type::getInt32Ty (*m_ctx),
			//{ llvm::Type::getInt32Ty (*m_ctx), llvm::Type::getInt32Ty (*m_ctx) },
			false
		);
		llvm::Function *_f = llvm::Function::Create (_ft, llvm::Function::ExternalLinkage, "fa_entry_main", *m_module);
		llvm::BasicBlock *_bb = llvm::BasicBlock::Create (*m_ctx, "fa_entry_main_block", _f);
		llvm::IRBuilder<> _builder (_bb);
		_builder.SetInsertPoint (_bb);
		_builder.CreateRet (llvm::ConstantInt::get (_ft->getReturnType (), llvm::APInt (32, 0, true)));
	}

	CodeVisitor *m_visitor = nullptr;
	std::string m_module_name;
	std::shared_ptr<llvm::LLVMContext> m_ctx;
	std::shared_ptr<llvm::Module> m_module;

	std::vector<std::string> m_uses;
	std::vector<std::string> m_imports, m_libs;
};



#endif //__FA_LLVM_GEN_HPP__
