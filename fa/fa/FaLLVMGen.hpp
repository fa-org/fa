#ifndef __FA_LLVM_GEN_HPP__
#define __FA_LLVM_GEN_HPP__



#include <memory>
#include <optional>
#include <string>

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

#include "CodeVisitor.hpp"



class FaLLVMGen {
public:
	FaLLVMGen (CodeVisitor *_visitor, std::string _module_name): m_visitor (_visitor) {
		m_ctx = std::make_shared<llvm::LLVMContext> ();
		m_module = std::make_shared<llvm::Module> (_module_name, *m_ctx);
	}

	std::optional<std::string> Build (FaParser::ProgramContext *_program_ctx, std::string _file) {
		auto _entry = m_visitor->visitProgram (_program_ctx).as<FaParser::FaEntryMainFuncStmtContext*> ();
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

private:
	//bool BuildClassMethod () {
	//}

	void BuildFaEntryMain (FaParser::FaEntryMainFuncStmtContext *_mctx) {
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
	std::shared_ptr<llvm::LLVMContext> m_ctx;
	std::shared_ptr<llvm::Module> m_module;
};



#endif //__FA_LLVM_GEN_HPP__
