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



class FaLLVMGen {
public:
	FaLLVMGen (CodeVisitor *_visitor, std::string _module_name): m_visitor (_visitor), m_module_name (_module_name) {
		m_ctx = std::make_shared<llvm::LLVMContext> ();
		m_module = std::make_shared<llvm::Module> (_module_name, *m_ctx);
		m_etype_map = std::make_shared<TypeMap> (_visitor, m_ctx);
		m_value_builder = std::make_shared<ValueBuilder> (_visitor, m_ctx, m_module);
	}

	bool Compile (FaParser::ProgramContext *_program_ctx, std::string _file) {
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
			auto [_name, _ret_type_raw, _arg_types_raw, _cc] = m_visitor->visitImportStmt (_import_func_raw).as<std::tuple<
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
		auto [_ret_type_raw, _stmts_raw] = m_visitor->visitFaEntryMainFuncBlock (_mctx).as<std::tuple<
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
					AstValue _value = ExprBuilder (_builder, _normal_stmt_raw->expr (), _new_local_vars);
					if (!_value.IsValid ())
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
				std::tie (_conds, _bodys) = m_visitor->visitIfStmt (_stmt_raw->ifStmt ());
				if (!IfStmtBuilder (_builder, _conds, _bodys, _f, _new_local_vars))
					return false;
			} else if (_stmt_raw->whileStmt ()) {
				// TODO
				LOG_TODO (_stmt_raw->start);
				return false;
			} else if (_stmt_raw->defVarStmt ()) {
				auto _def_var_stmt_raw = _stmt_raw->defVarStmt ();
				std::optional<llvm::Type *> _ret_type = m_etype_map->GetType (_def_var_stmt_raw->type ());
				if (!_ret_type.has_value ())
					return false;
				std::string _var_name = _def_var_stmt_raw->Id ()->getText ();
				if (_new_local_vars.contains (_var_name)) {
					LOG_ERROR (_def_var_stmt_raw->Id ()->getSymbol (), fmt::format ("[{}] 变量重复定义", _var_name));
					return false;
				}
				_new_local_vars [_var_name] = _builder.CreateAlloca (_ret_type.value ());
				AstValue _var { m_value_builder, _new_local_vars [_var_name] };
				AstValue _value = ExprBuilder (_builder, _def_var_stmt_raw->expr (), _new_local_vars);
				if (!_value.IsValid ()) {
					return false;
				} else if (_value.IsValue ()) {
					_var.Assign (_builder, _value, _def_var_stmt_raw->Assign ()->getSymbol ());
				} else {
					LOG_TODO (_def_var_stmt_raw->Assign ()->getSymbol ());
					return false;
				}
			} else {
				LOG_ERROR (_stmt_raw->start, "未知的表达式");
				return false;
			}
		}
		return true;
	}

	bool IfStmtBuilder (llvm::IRBuilder<> &_builder, std::vector<FaParser::ExprContext *> &_conds_raw, std::vector<std::vector<FaParser::StmtContext *>> &_bodys_raw, llvm::Function *_f, std::map<std::string, llvm::AllocaInst *> &_local_vars) {
		if (_conds_raw.size () == 0) {
			if (_bodys_raw.size () >= 2) {
				LOG_ERROR (_bodys_raw [0][0]->start, "条件异常");
				return false;
			} else if (_bodys_raw.size () == 1) {
				if (!StmtBuilder (_builder, _bodys_raw [0], _f, _local_vars))
					return false;
				_bodys_raw.erase (_bodys_raw.begin ());
			}
			return true;
		}
		AstValue _cond = ExprBuilder (_builder, _conds_raw [0], _local_vars);
		if (!_cond.IsValid ()) {
			return false;
		} else if (!_cond.IsValue ()) {
			LOG_ERROR (_conds_raw [0]->start, "条件需指定为值类型");
			return false;
		}
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

	AstValue _ExprBuilder_GetCurrent (llvm::IRBuilder<> &_builder, FaParser::ExprBodyContext *_current_raw, std::map<std::string, llvm::AllocaInst *> &_local_vars) {
		// 第一次处理
		if (_current_raw->ids ()) {
			// TODO ids操作
			std::string _cur_name = _current_raw->getText ();
			if (_local_vars.contains (_cur_name)) {
				return AstValue { m_value_builder, _local_vars [_cur_name] };
			} else {
				LOG_ERROR (_current_raw->start, fmt::format ("变量 {} 不存在", _cur_name));
				return std::nullopt;
			}
		} else if (_current_raw->ColonColon ()) {
			// 外部 C API 调用
			std::string _cur_name = _current_raw->getText ();
			if (m_imports.contains (_cur_name)) {
				return AstValue { m_imports [_cur_name] };
			} else {
				LOG_ERROR (_current_raw->start, fmt::format ("未定义的外部符号：{}", _cur_name));
				return std::nullopt;
			}
		} else if (_current_raw->literal ()) {
			auto _literal = _current_raw->literal ();
			return AstValue { m_value_builder, _literal };
		} else if (_current_raw->ifElseExpr ()) {
			LOG_TODO (_current_raw->ifElseExpr ()->start);
			//return IfElseExprBuilder (_builder, _current_raw->ifElseExpr (), _local_vars);
		} else if (_current_raw->quotExpr ()) {
			return ExprBuilder (_builder, _current_raw->quotExpr ()->expr (), _local_vars);
		} else {
			LOG_TODO (_current_raw->start);
			return std::nullopt;
		}
	}

	AstValue ExprBuilder (llvm::IRBuilder<> &_builder, FaParser::ExprContext *_expr_raw, std::map<std::string, llvm::AllocaInst *> &_local_vars, AstValue &_assign_left_val/*TODO: 此处允许变量、类型字符串及空*/) {
		if (_expr_raw->ifElseExpr ()) {
			LOG_TODO (_expr_raw->ifElseExpr ()->start);
			//return IfElseExprBuilder (_builder, _expr_raw->ifElseExpr (), _local_vars);
		} else if (_expr_raw->quotExpr ()) {
			return ExprBuilder (_builder, _expr_raw->quotExpr ()->expr (), _local_vars);
		} else if (_expr_raw->normalExpr ()) {
			FaParser::NormalExprContext *_normal_expr_raw = _expr_raw->normalExpr ();
			FaParser::ExprBodyContext *_current_raw = _normal_expr_raw->exprBody ();
			AstValue _current = _ExprBuilder_GetCurrent (_builder, _current_raw, _local_vars);
			if (!_current.IsValid ())
				return std::nullopt;
			//
			std::vector<FaParser::ExprPrefixContext *> _prefix = _normal_expr_raw->exprPrefix ();
			std::vector<FaParser::ExprSuffixContext *> _suffix = _normal_expr_raw->exprSuffix ();
			while (_prefix.size () > 0 || _suffix.size () > 0) {
				if (_prefix.size () > 0) {
					auto _cur_prefix = _prefix [_prefix.size () - 1];
					_prefix.erase (_prefix.begin () + (_prefix.size () - 1));
					if (_cur_prefix->AddOp ()) {
						// do nothing
					} else if (_cur_prefix->SubOp ()) {
						// TODO 取反
					} else {
					}
					// TODO 提前处理
					LOG_TODO (_cur_prefix->start);
					return std::nullopt;
				} else if (_suffix.size () > 0) {
					auto _cur_suffix = _suffix [0];
					_suffix.erase (_suffix.begin ());
					if (_cur_suffix->AddAddOp () || _cur_suffix->SubSubOp ()) {
						// TODO
						LOG_TODO (_cur_suffix->start);
					} else if (_cur_suffix->QuotYuanL ()) {
						if (!_current.IsFunction ()) {
							LOG_ERROR (_cur_suffix->start, "函数调用表达式错误");
							return std::nullopt;
						}
						std::vector<llvm::Value *> _args;
						for (auto _arg_expr : _cur_suffix->expr ()) {
							AstValue _oarg = ExprBuilder (_builder, _arg_expr, _local_vars);
							if (!_oarg.IsValid ()) {
								return std::nullopt;
							} else if (_oarg.IsValue ()) {
								_args.push_back (_oarg.Value (_builder));
							} else {
								LOG_TODO (_cur_suffix->start);
								return std::nullopt;
							}
						}
						_current = _current.FunctionCall (_builder, _args);
					} else if (_cur_suffix->QuotFangL ()) {
						LOG_TODO (_cur_suffix->start);
						return std::nullopt;
					} else if (_cur_suffix->allAssign () || _cur_suffix->allOp2 ()) {
						if (_cur_suffix->allAssign () && (!_current.IsVariable ())) {
							LOG_ERROR (_cur_suffix->start, "非变量类型无法赋值");
							return std::nullopt;
						}
						//
						AstValue _val2 = ExprBuilder (_builder, _cur_suffix->expr (0), _local_vars);
						if (!_val2.IsValid ()) {
							return std::nullopt;
						} else if (!_val2.IsVariable ()) {
							LOG_TODO (_cur_suffix->start);
							return std::nullopt;
						}
						_current.DoOper2 (_builder, m_value_builder, _cur_suffix->allAssign ()->getText (), _val2, _cur_suffix->allAssign ()->start);
					} else if (_cur_suffix->ltOps ().size () > 0 || _cur_suffix->gtOps ().size () > 0 || _cur_suffix->equalOp () || _cur_suffix->notEqualOp ()) {
						LOG_TODO (_cur_suffix->start);
						return std::nullopt;
					} else {
						LOG_TODO (_cur_suffix->start);
						return std::nullopt;
					}
				}
			}
			return _current;
		} else {
			LOG_ERROR (_expr_raw->start, "未知的表达式");
		}
		return std::nullopt;
	}

	//bool IfExprBuilder (llvm::IRBuilder<> &_builder, AstValue &_dest, FaParser::IfExprContext *_expr_raw, std::map<std::string, llvm::AllocaInst *> &_local_vars) {
	//	std::vector<FaParser::ExprContext *> _conds;
	//	std::vector<FaParser::QuotStmtExprContext *> _bodys;
	//	std::tie (_conds, _bodys) = m_visitor->visitIfExpr (_expr_raw);
	//	LOG_TODO (_expr_raw->start);
	//	return false;
	//}

	//bool IfElseExprBuilder (llvm::IRBuilder<> &_builder, AstValue &_dest, FaParser::IfElseExprContext *_expr_raw, std::map<std::string, llvm::AllocaInst *> &_local_vars) {
	//	std::vector<FaParser::ExprContext *> _conds;
	//	std::vector<FaParser::QuotStmtExprContext *> _bodys;
	//	std::tie (_conds, _bodys) = m_visitor->visitIfElseExpr (_expr_raw);
	//	LOG_TODO (_expr_raw->start);
	//	return false;
	//}

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
