#ifndef __FA_LLVM_GEN_HPP__
#define __FA_LLVM_GEN_HPP__



#include <map>
#include <memory>
#include <optional>
#include <string>
#include <variant>
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
#include "AstValue.hpp"
#include "AstCheck.hpp"



class FaLLVMGen {
public:
	FaLLVMGen (CodeVisitor *_visitor, std::string _module_name): m_visitor (_visitor), m_module_name (_module_name) {
		m_ctx = std::make_shared<llvm::LLVMContext> ();
		m_module = std::make_shared<llvm::Module> (_module_name, *m_ctx);
		m_etype_map = std::make_shared<TypeMap> (_visitor, m_ctx);
		m_value_builder = std::make_shared<ValueBuilder> (_visitor, m_ctx, m_module);
	}

	bool Compile (FaParser::ProgramContext *_program_ctx, std::string _file) {
		auto [_uses, _imports, _classes, _entry] = m_visitor->visit (_program_ctx).as<std::tuple<
			std::vector<std::string>,
			FaParser::ImportBlockContext *,
			std::vector<FaParser::ClassBlockContext *>,
			FaParser::FaEntryMainFuncBlockContext *
			>> ();
		m_uses = _uses;

		// 引用外部模块
		std::vector<FaParser::ImportStmtContext *> _imports_raw;
		std::tie (_imports_raw, m_libs) = m_visitor->visit (_imports).as<std::tuple<
			std::vector<FaParser::ImportStmtContext *>,
			std::vector<std::string>
			>> ();
		//m_imports.push_back ("puts");
		//m_libs.push_back ("libcmt.lib");
		if (!ProcessImports (_imports_raw))
			return false;

		// TODO: 编译类

		if (!_entry) {
			LOG_ERROR (nullptr, "未定义入口函数：FaEntryMain");
			return false;
		}
		if (!BuildFaEntryMain (_entry)) {
			return false;
		}

		llvm::InitializeAllTargetInfos ();
		llvm::InitializeAllTargets ();
		llvm::InitializeAllTargetMCs ();
		llvm::InitializeAllAsmParsers ();
		llvm::InitializeAllAsmPrinters ();
		std::string _target_triple = llvm::sys::getDefaultTargetTriple (), _err = "";
		m_module->setTargetTriple (_target_triple);
		const llvm::Target *_target = llvm::TargetRegistry::lookupTarget (_target_triple, _err);
		if (!_target) {
			LOG_ERROR (nullptr, _err);
			return false;
		}
		std::string _cpu = "";
		std::string _features = "";

		llvm::TargetOptions _opt;
		auto _model = llvm::Optional<llvm::Reloc::Model> ();
		auto _target_machine = _target->createTargetMachine (_target_triple, _cpu, _features, _opt, _model);
		m_module->setDataLayout (_target_machine->createDataLayout ());

		std::error_code _ec;
		llvm::raw_fd_ostream _dest (_file, _ec, llvm::sys::fs::F_None);

		if (_ec) {
			LOG_ERROR (nullptr, "无法打开输出文件");
			return false;
		}

		llvm::legacy::PassManager _pass;
		if (_target_machine->addPassesToEmitFile (_pass, _dest, nullptr, llvm::CGFT_ObjectFile)) {
			LOG_ERROR (nullptr, "无法输出编译文件");
			return false;
		}

		_pass.run (*m_module);
		_dest.flush ();
		return true;
	}

	std::string Link () {
		wchar_t *get_env (std::string _key, std::string _val);
#if 0
		// home
		std::string _link_exe_path = R"(D:\Software\Program\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30037\bin\Hostx86\x86\link.exe)";
		wchar_t *_env = get_env ("LIB", R"(D:\Software\Program\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30037\ATLMFC\lib\x86;D:\Software\Program\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30037\lib\x86;C:\Program Files (x86)\Windows Kits\NETFXSDK\4.8\lib\um\x86;C:\Program Files (x86)\Windows Kits\10\lib\10.0.19041.0\ucrt\x86;C:\Program Files (x86)\Windows Kits\10\lib\10.0.19041.0\um\x86)");
#else
		// company
		std::string _link_exe_path = R"(E:\Software\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30037\bin\Hostx86\x86\link.exe)";
		wchar_t *_env = get_env ("LIB", R"(E:\Software\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30037\ATLMFC\lib\x86;E:\Software\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30037\lib\x86;C:\Program Files (x86)\Windows Kits\NETFXSDK\4.8\lib\um\x86;D:\Windows Kits\10\lib\10.0.19041.0\ucrt\x86;D:\Windows Kits\10\lib\10.0.19041.0\um\x86)");
#endif
		std::string _cmd = fmt::format ("\"{}\" /subsystem:console /dynamicbase /machine:X86 /debug /entry:FaEntryMain /out:{}.exe /pdb:{}.pdb {}.obj", _link_exe_path, m_module_name, m_module_name, m_module_name);
		//std::string _cmd = R"(/OUT:"hello.exe" /MANIFEST /LTCG:incremental /NXCOMPAT /PDB:"hello.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /DEBUG /MACHINE:X86 /OPT:REF /SAFESEH /INCREMENTAL:NO /PGD:"hello.pgd" /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"hello.exe.intermediate.manifest" /LTCGOUT:"hello.iobj" /OPT:ICF /ERRORREPORT:PROMPT /ILK:"hello.ilk" /NOLOGO /TLBID:1)";
		for (auto _lib : m_libs) {
			_cmd += " ";
			_cmd += _lib;
		}
		std::string get_process_output (std::string _cmd, wchar_t *_env);
		return get_process_output (_cmd, _env);
	}

private:
	bool ProcessImports (std::vector<FaParser::ImportStmtContext *> _imports_raw) {
		// https://blog.csdn.net/adream307/article/details/83820543
		for (FaParser::ImportStmtContext *_import_func_raw : _imports_raw) {
			auto [_name, _ret_type_raw, _arg_types_raw, _cc] = m_visitor->visit (_import_func_raw).as<std::tuple<
				std::string,
				FaParser::ETypeContext *,
				std::vector<FaParser::ETypeContext *>,
				std::string
				>> ();
			llvm::Function *_f = m_module->getFunction (_name);
			if (_f == nullptr) {
				std::optional<llvm::Type *> _ret_type = m_etype_map->GetExternType (_ret_type_raw);
				if (!_ret_type.has_value ())
					return false;
				std::optional<std::vector<llvm::Type *>> _arg_types = m_etype_map->GetExternTypes (_arg_types_raw);
				if (!_arg_types.has_value ())
					return false;
				llvm::FunctionType *_ft = llvm::FunctionType::get (_ret_type.value (), _arg_types.value (), false);
				_f = llvm::Function::Create (_ft, llvm::Function::ExternalLinkage, _name, *m_module);
				if (_cc == "__cdecl") {
					_f->setCallingConv (llvm::CallingConv::C);
				} else if (_cc == "__stdcall") {
					_f->setCallingConv (llvm::CallingConv::X86_StdCall);
				} else if (_cc == "__fastcall") {
					_f->setCallingConv (llvm::CallingConv::X86_FastCall);
				}
			}
			m_imports [fmt::format ("::{}", _name)] = _f;
		}
		return true;
	}

	bool BuildFaEntryMain (FaParser::FaEntryMainFuncBlockContext *_mctx) {
		auto [_ret_type_raw, _stmts_raw] = m_visitor->visit (_mctx).as<std::tuple<
			FaParser::TypeContext *,
			std::vector<FaParser::StmtContext *>
			>> ();
		std::optional<llvm::Type *> _ret_type = m_etype_map->GetType (_ret_type_raw);
		if (!_ret_type.has_value ())
			return false;
		llvm::FunctionType *_ft = llvm::FunctionType::get (_ret_type.value (), false);
		llvm::Function *_f = llvm::Function::Create (_ft, llvm::Function::ExternalLinkage, "FaEntryMain", *m_module);
		_f->setCallingConv (llvm::CallingConv::C);
		llvm::BasicBlock *_bb = llvm::BasicBlock::Create (*m_ctx, "", _f);
		llvm::IRBuilder<> _builder (_bb);
		_builder.SetInsertPoint (_bb);
		std::map<std::string, llvm::AllocaInst *> _local_vars;
		return StmtBuilder (_builder, _stmts_raw, _f, _local_vars);
	}

	bool StmtBuilder (llvm::IRBuilder<> &_builder, std::vector<FaParser::StmtContext *> &_stmts_raw, llvm::Function *_f, std::map<std::string, llvm::AllocaInst *> &_local_vars) {
		std::map<std::string, llvm::AllocaInst *> _new_local_vars = _local_vars;
		for (FaParser::StmtContext *_stmt_raw : _stmts_raw) {
			if (_stmt_raw->normalStmt ()) {
				FaParser::NormalStmtContext *_normal_stmt_raw = _stmt_raw->normalStmt ();
				if (_normal_stmt_raw->expr ()) {
					AstValue _value;
					if (!ExprBuilder (_builder, _normal_stmt_raw->expr (), _f, _new_local_vars, "", _value))
						return false;

					if (_normal_stmt_raw->Return ()) {
						if (_value.IsValue ()) {
							_builder.CreateRet (_value.Value (_builder));
						} else {
							LOG_TODO (_stmt_raw->start);
							return false;
						}
					}
				} else if (_normal_stmt_raw->Break ()) {
					// TODO break
					LOG_TODO (_normal_stmt_raw->start);
					return false;
				} else if (_normal_stmt_raw->Continue ()) {
					// TODO continue
					LOG_TODO (_normal_stmt_raw->start);
					return false;
				} else {
					LOG_ERROR (_stmt_raw->start, "未知的表达式");
					return false;
				}
			} else if (_stmt_raw->ifStmt ()) {
				std::vector<FaParser::ExprContext *> _conds;
				std::vector<std::vector<FaParser::StmtContext *>> _bodys;
				std::tie (_conds, _bodys) = m_visitor->visit (_stmt_raw->ifStmt ()).as<std::tuple<
					std::vector<FaParser::ExprContext *>,
					std::vector<std::vector<FaParser::StmtContext *>>
				>> ();
				if (!IfStmtBuilder (_builder, _conds, _bodys, _f, _new_local_vars))
					return false;
			} else if (_stmt_raw->whileStmt ()) {
				// TODO
				LOG_TODO (_stmt_raw->start);
				return false;
			} else if (_stmt_raw->defVarStmt ()) {
				auto _def_var_stmt_raw = _stmt_raw->defVarStmt ();
				std::string _type_str = _def_var_stmt_raw->type ()->getText ();
				std::optional<llvm::Type *> _ret_type = m_etype_map->GetType (_type_str, _def_var_stmt_raw->type ()->start);
				if (!_ret_type.has_value ())
					return false;
				std::string _var_name = _def_var_stmt_raw->Id ()->getText ();
				if (_new_local_vars.contains (_var_name)) {
					LOG_ERROR (_def_var_stmt_raw->Id ()->getSymbol (), fmt::format ("[{}] 变量重复定义", _var_name));
					return false;
				}
				_new_local_vars [_var_name] = _builder.CreateAlloca (_ret_type.value ());
				AstValue _var { _new_local_vars [_var_name] };
				if (!ExprBuilder (_builder, _def_var_stmt_raw->expr (), _f, _new_local_vars, _type_str, _var))
					return false;
			} else {
				LOG_ERROR (_stmt_raw->start, "未知的表达式");
				return false;
			}
		}
		return true;
	}

	bool IfStmtBuilder (llvm::IRBuilder<> &_builder, std::vector<FaParser::ExprContext *> &_conds_raw, std::vector<std::vector<FaParser::StmtContext *>> &_bodys_raw, llvm::Function *_f, std::map<std::string, llvm::AllocaInst *> &_local_vars) {
		if (_conds_raw.size () == 0)
			return StmtBuilder (_builder, _bodys_raw [0], _f, _local_vars);
		//
		AstValue _cond {};
		if (!ExprBuilder (_builder, _conds_raw [0], _f, _local_vars, "bool", _cond))
			return false;
		_conds_raw.erase (_conds_raw.begin ());
		llvm::BasicBlock *_true_bb = llvm::BasicBlock::Create (*m_ctx, "", _f);
		llvm::BasicBlock *_false_bb = llvm::BasicBlock::Create (*m_ctx, "", _f);
		llvm::BasicBlock *_endif_bb = llvm::BasicBlock::Create (*m_ctx, "", _f);
		_builder.CreateCondBr (_cond.Value (_builder), _true_bb, _false_bb);
		//
		_builder.SetInsertPoint (_true_bb);
		if (!StmtBuilder (_builder, _bodys_raw [0], _f, _local_vars))
			return false;
		_bodys_raw.erase (_bodys_raw.begin ());
		_builder.CreateBr (_endif_bb);
		//
		_builder.SetInsertPoint (_false_bb);
		if (!IfStmtBuilder (_builder, _conds_raw, _bodys_raw, _f, _local_vars))
			return false;
		_builder.CreateBr (_endif_bb);
		//
		_builder.SetInsertPoint (_endif_bb);
		return true;
	}

	bool ExprBuilder (llvm::IRBuilder<> &_builder, FaParser::ExprContext *_expr_raw, llvm::Function *_f, std::map<std::string, llvm::AllocaInst *> &_local_vars, std::string _expect_type, AstValue &_vt) {
		// TODO: 计算所有前缀++--

		// 计算强表达式类型
		auto _strong_expect_type = AstCheck::TryGetStrongExpectType (_expr_raw, _expect_type);
		if (!_strong_expect_type.has_value ())
			return false;

		AstValue _tmp_vt = _vt;
		if (!StrongExprBuilder (_builder, _expr_raw->strongExpr (), _f, _local_vars, _strong_expect_type.value (), _tmp_vt))
			return false;
		_vt = _tmp_vt;

		// TODO: 计算所有后缀++--

		return true;
	}

	bool StrongExprBuilder (llvm::IRBuilder<> &_builder, FaParser::StrongExprContext *_expr_raw, llvm::Function *_f, std::map<std::string, llvm::AllocaInst *> &_local_vars, std::string _expect_type, AstValue &_vt) {
		bool _assigned = false;
		AstValue _val {};
		auto _base_raw = _expr_raw->strongExprBase ();
		if (_base_raw->ids ()) {
			// TODO 计算_val
			// TODO 计算是否符合期望
		} else if (_base_raw->ColonColon ()) {
			// 外部 C API 调用
			std::string _cur_name = _base_raw->getText ();
			if (m_imports.contains (_cur_name)) {
				_val = m_imports [_cur_name];
			} else {
				LOG_ERROR (_base_raw->start, fmt::format ("未定义的外部符号：{}", _cur_name));
				return false;
			}
		} else if (_base_raw->literal ()) {
			_val = AstValue { m_value_builder, _base_raw->literal () };
			// TODO 计算是否符合期望
		} else if (_base_raw->ifExpr ()) {
			std::vector<FaParser::ExprContext *> _conds;
			std::vector<std::vector<FaParser::StmtContext *>> _bodys1;
			std::vector<FaParser::ExprContext *> _bodys2;
			std::tie (_conds, _bodys1, _bodys2) = m_visitor->visit (_base_raw->ifExpr ()).as<std::tuple<
				std::vector<FaParser::ExprContext *>,
				std::vector<std::vector<FaParser::StmtContext *>>,
				std::vector<FaParser::ExprContext *>
			>> ();
			// TODO: 计算期望的类型
			if (!IfExprBuilder (_builder, _conds, _bodys1, _bodys2, _f, _local_vars, "", _vt))
				return false;
			_assigned = true;
		} else if (_base_raw->quotExpr ()) {
			// TODO: 计算期望的类型
			if (!ExprBuilder (_builder, _base_raw->quotExpr ()->expr (), _f, _local_vars, "", _val))
				return false;
		} else {
			LOG_TODO (_base_raw->start);
			return false;
		}

		// 处理后缀
		for (auto _suffix_raw : _expr_raw->strongExprSuffix ()) {
			if (_suffix_raw->QuotYuanL ()) {
				// 处理调用
				if (!_val.IsFunction ()) {
					LOG_ERROR (_suffix_raw->start, "无法将目标作为函数来调用");
					return false;
				}
				std::vector<llvm::Value *> _args;
				for (auto _arg_expr : _suffix_raw->expr ()) {
					AstValue _oarg {};
					// TODO: 计算期望类型
					if (!ExprBuilder (_builder, _arg_expr, _f, _local_vars, "", _oarg))
						return false;
					if (!_oarg.IsValue ()) {
						LOG_ERROR (_arg_expr->start, "参数只接收值类型");
						return false;
					}
					_args.push_back (_oarg.Value (_builder));
				}
				_val = _val.FunctionCall (_builder, _args);
			} else if (_suffix_raw->QuotFangL ()) {
				// TODO 处理索引
			}
		}

		//处理前缀
		for (int i = (int) _expr_raw->strongExprPrefix ().size () - 1; i >= 0; --i) {
			auto _prefix_raw = _expr_raw->strongExprPrefix () [i];
			std::string _prefix_text = _prefix_raw->getText ();
			if (_prefix_text == "~") {
				// TODO bool类型取反
			} else if (_prefix_text == "-") {
				// TODO 数字类型取负
			}
		}

		if (!_assigned) {
			_vt = _val;
			// TODO 返回结果前检查是否符合期望
		}
		return true;
	}

	bool IfExprBuilder (llvm::IRBuilder<> &_builder, std::vector<FaParser::ExprContext *> &_conds_raw, std::vector<std::vector<FaParser::StmtContext *>> &_bodys_raw1, std::vector<FaParser::ExprContext *> &_bodys_raw2, llvm::Function *_f, std::map<std::string, llvm::AllocaInst *> &_local_vars, std::string _expect_type, AstValue &_vt) {
		if (_conds_raw.size () == 0) {
			if (!StmtBuilder (_builder, _bodys_raw1 [0], _f, _local_vars))
				return false;
			return ExprBuilder (_builder, _bodys_raw2 [0], _f, _local_vars, _expect_type, _vt);
		}
		//
		AstValue _cond {};
		if (!ExprBuilder (_builder, _conds_raw [0], _f, _local_vars, "bool", _cond))
			return false;
		_conds_raw.erase (_conds_raw.begin ());
		llvm::BasicBlock *_true_bb = llvm::BasicBlock::Create (*m_ctx, "", _f);
		llvm::BasicBlock *_false_bb = llvm::BasicBlock::Create (*m_ctx, "", _f);
		llvm::BasicBlock *_endif_bb = llvm::BasicBlock::Create (*m_ctx, "", _f);
		_builder.CreateCondBr (_cond.Value (_builder), _true_bb, _false_bb);
		//
		_builder.SetInsertPoint (_true_bb);
		if (!StmtBuilder (_builder, _bodys_raw1 [0], _f, _local_vars))
			return false;
		_bodys_raw1.erase (_bodys_raw1.begin ());
		if (!ExprBuilder (_builder, _bodys_raw2 [0], _f, _local_vars, _expect_type, _vt))
			return false;
		_bodys_raw2.erase (_bodys_raw2.begin ());
		_builder.CreateBr (_endif_bb);
		//
		_builder.SetInsertPoint (_false_bb);
		if (!IfExprBuilder (_builder, _conds_raw, _bodys_raw1, _bodys_raw2, _f, _local_vars, _expect_type, _vt))
			return false;
		_builder.CreateBr (_endif_bb);
		//
		_builder.SetInsertPoint (_endif_bb);
		return true;
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
