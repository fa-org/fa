#ifndef __FA_LLVM_GEN_HPP__
#define __FA_LLVM_GEN_HPP__



#include <functional>
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
#include "FuncContext.hpp"
#include "ExpectCheck.hpp"



struct _ValueCtx {
	_ValueCtx (AstValue __val, antlr4::Token *__t, std::string __expect_type): _val (__val), _t (__t), _expect_type (__expect_type) {}

	AstValue _val {};
	antlr4::Token *_t = nullptr;
	std::string _expect_type = "";
};
struct _OperCtx {
	_OperCtx (FaParser::AllAssignContext *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start) {}
	_OperCtx (FaParser::AllOp2Context *_op_raw): _op (_op_raw->getText ()), _t (_op_raw->start) {}
	_OperCtx (std::string __op, FaParser::StrongExprPrefixContext *_op_raw): _op (__op), _t (_op_raw->start) {}
	_OperCtx (std::string __op, FaParser::StrongExprSuffixContext *_op_raw): _op (__op), _t (_op_raw->start) {}

	std::string _op = "";
	antlr4::Token *_t = nullptr;
};
struct _Op1ExprTreeCtx;
struct _Op2ExprTreeCtx;
struct _OpNExprTreeCtx;
struct _IfExprTreeCtx;
struct _ExprOrValue {
	_ExprOrValue () {}
	_ExprOrValue (std::shared_ptr<_ValueCtx> __val): _val (__val) {}
	_ExprOrValue (std::shared_ptr<_Op1ExprTreeCtx> __op1_expr): _op1_expr (__op1_expr) {}
	_ExprOrValue (std::shared_ptr<_Op2ExprTreeCtx> __op2_expr): _op2_expr (__op2_expr) {}
	_ExprOrValue (std::shared_ptr<_OpNExprTreeCtx> __opN_expr): _opN_expr (__opN_expr) {}
	_ExprOrValue (std::shared_ptr<_IfExprTreeCtx> __if_expr): _if_expr (__if_expr) {}

	std::shared_ptr<_ValueCtx> _val;
	std::shared_ptr<_Op1ExprTreeCtx> _op1_expr;
	std::shared_ptr<_Op2ExprTreeCtx> _op2_expr;
	std::shared_ptr<_OpNExprTreeCtx> _opN_expr;
	std::shared_ptr<_IfExprTreeCtx> _if_expr;

	std::string GetExpectType ();
};
//using _ExprOrValue = std::variant<
//	_ValueCtx,
//	std::shared_ptr<_Op1ExprTreeCtx>,
//	std::shared_ptr<_Op2ExprTreeCtx>,
//	std::shared_ptr<_OpNExprTreeCtx>,
//	std::shared_ptr<_IfExprTreeCtx>
//>;
enum class _Op1Type { Prefix, Suffix };
struct _Op1ExprTreeCtx {
	_OperCtx											_op;
	_ExprOrValue										_left;
	_Op1Type											_type;
	std::string											_expect_type;
};
struct _Op2ExprTreeCtx {
	_ExprOrValue										_left;
	_OperCtx											_op;
	_ExprOrValue										_right;
	std::string											_expect_type;

	bool CalcExpectType () {
		const static std::set<std::string> s_compare_ops { ">", ">=", "<", "<=", "==", "!=" };
		std::string _op_str = _op._op;
		if (s_compare_ops.contains (_op_str)) {
			_expect_type = "bool";
			return true;
		}

		if (_op_str == "??") {
			// TODO
			return false;
		}

		_expect_type = _left.GetExpectType ();
		return _expect_type != "";
	}
};
struct _OpNExprTreeCtx {
	_ExprOrValue										_left;
	_OperCtx											_op;
	std::vector<_ExprOrValue>							_rights;
	std::string											_expect_type;
};
struct _IfExprTreeCtx {
	std::vector<_ExprOrValue>							_conds;
	std::vector<std::vector<FaParser::StmtContext *>>	_bodys1_raw;
	std::vector<_ExprOrValue>							_bodys2;
	std::string											_expect_type;
};
inline std::string _ExprOrValue::GetExpectType () {
	if (_val) {
		return _val->_expect_type;
	} else if (_op1_expr) {
		return _op1_expr->_expect_type;
	} else if (_op2_expr) {
		return _op2_expr->_expect_type;
	} else if (_opN_expr) {
		return _opN_expr->_expect_type;
	} else if (_if_expr) {
		return _if_expr->_expect_type;
	} else {
		return "";
	}
}



class FaLLVMGen {
public:
	FaLLVMGen (CodeVisitor *_visitor, std::string _module_name): m_visitor (_visitor), m_module_name (_module_name) {
		m_ctx = std::make_shared<llvm::LLVMContext> ();
		m_module = std::make_shared<llvm::Module> (_module_name, *m_ctx);
		m_type_map = std::make_shared<TypeMap> (_visitor, m_ctx);
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
			//llvm::Function *_f = m_module->getFunction (_name);
			std::string _code_name = fmt::format ("::{}", _name);
			if (!m_imports.contains (_code_name)) {
				auto _ret_otype = m_type_map->GetExternType (_ret_type_raw);
				if (!_ret_otype.has_value ())
					return false;
				auto [_ret_type, _ret_type_str] = _ret_otype.value ();
				auto _arg_otypes = m_type_map->GetExternTypes (_arg_types_raw);
				if (!_arg_otypes.has_value ())
					return false;
				auto [_arg_types, _arg_types_str] = _arg_otypes.value ();
				llvm::FunctionType *_ft = llvm::FunctionType::get (_ret_type, _arg_types, false);
				llvm::Function *_f = llvm::Function::Create (_ft, llvm::Function::ExternalLinkage, _name, *m_module);
				if (_cc == "__cdecl") {
					_f->setCallingConv (llvm::CallingConv::C);
				} else if (_cc == "__stdcall") {
					_f->setCallingConv (llvm::CallingConv::X86_StdCall);
				} else if (_cc == "__fastcall") {
					_f->setCallingConv (llvm::CallingConv::X86_FastCall);
				}
				std::string _func_type = fmt::format ("Func<{} (", _ret_type_str);
				for (std::string _arg_type_str : _arg_types_str)
					_func_type += fmt::format ("{}, ", _arg_type_str);
				_func_type [_func_type.size () - 2] = ')';
				_func_type [_func_type.size () - 1] = '>';
				m_imports [_code_name] = { _f, _func_type };
			}
		}
		return true;
	}

	bool BuildFaEntryMain (FaParser::FaEntryMainFuncBlockContext *_mctx) {
		auto [_ret_type_raw, _stmts_raw] = m_visitor->visit (_mctx).as<std::tuple<
			FaParser::TypeContext *,
			std::vector<FaParser::StmtContext *>
			>> ();
		FuncContext _func_ctx { m_ctx, m_module, m_type_map, m_value_builder };
		if (!_func_ctx.InitFunc ("FaEntryMain", _ret_type_raw))
			return false;
		return StmtBuilder (_func_ctx, _stmts_raw);
	}

	bool StmtBuilder (FuncContext &_func_ctx, std::vector<FaParser::StmtContext *> &_stmts_raw) {
		for (FaParser::StmtContext *_stmt_raw : _stmts_raw) {
			if (_stmt_raw->normalStmt ()) {
				FaParser::NormalStmtContext *_normal_stmt_raw = _stmt_raw->normalStmt ();
				if (_normal_stmt_raw->Return () || _normal_stmt_raw->expr ()) {
					if (_normal_stmt_raw->expr ()) {
						AstValue _value = ExprBuilder (_func_ctx, _normal_stmt_raw->expr (), "");
						if (!_value.IsValid ())
							return false;
						if (_normal_stmt_raw->Return ()) {
							if (!_value.IsValue ()) {
								LOG_ERROR (_normal_stmt_raw->start, "无法返回表达式结果");
								return false;
							}
							_func_ctx.Return (_value);
						}
					} else {
						if (_normal_stmt_raw->Return ())
							_func_ctx.Return ();
					}
				} else if (_normal_stmt_raw->Break ()) {
					LOG_TODO (_normal_stmt_raw->start);
					return false;
				} else if (_normal_stmt_raw->Continue ()) {
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
				if (!IfStmtBuilder (_func_ctx, _conds, _bodys))
					return false;
			} else if (_stmt_raw->whileStmt ()) {
				LOG_TODO (_stmt_raw->start);
				return false;
			} else if (_stmt_raw->defVarStmt ()) {
				auto _def_var_stmt_raw = _stmt_raw->defVarStmt ();
				AstValue _var = _func_ctx.DefineVariable (_def_var_stmt_raw->type (), _def_var_stmt_raw->Id ()->getText ());
				if (!_var.IsValid ())
					return false;
				AstValue _val = ExprBuilder (_func_ctx, _def_var_stmt_raw->expr (), _def_var_stmt_raw->type ()->getText ());
				if (!_val.IsValid ())
					return false;
				_func_ctx.DoOper2 (_var, "=", _val, _def_var_stmt_raw->Assign ()->getSymbol ());
			} else {
				LOG_ERROR (_stmt_raw->start, "未知的表达式");
				return false;
			}
		}
		return true;
	}

	bool IfStmtBuilder (FuncContext &_func_ctx, std::vector<FaParser::ExprContext *> &_conds_raw, std::vector<std::vector<FaParser::StmtContext *>> &_bodys_raw) {
		if (_conds_raw.size () == 0)
			return StmtBuilder (_func_ctx, _bodys_raw [0]);
		//
		AstValue _cond = ExprBuilder (_func_ctx, _conds_raw [0], "bool");
		if (!_cond.IsValid ())
			return false;
		_conds_raw.erase (_conds_raw.begin ());
		_func_ctx.IfElse (_cond, [&] () {
			if (!StmtBuilder (_func_ctx, _bodys_raw [0]))
				return false;
			_bodys_raw.erase (_bodys_raw.begin ());
			return true;
		}, [&] () {
			return IfStmtBuilder (_func_ctx, _conds_raw, _bodys_raw);
		});
		return true;
	}

	AstValue ExprBuilder (FuncContext &_func_ctx, FaParser::ExprContext *_expr_raw, std::string _expect_type) {
		std::function<std::optional<_ExprOrValue> (FaParser::ExprContext *)> _parse_expr;
		std::function<std::optional<_ExprOrValue> (FaParser::MiddleExprContext *)> _parse_middle_expr;
		std::function<std::optional<_ExprOrValue> (std::vector<FaParser::StrongExprContext *> &_expr_raws, std::vector<FaParser::AllOp2Context *> &_op_raws, std::vector<size_t> &_op_levels)> _parse_middle_expr2;
		std::function<std::optional<_ExprOrValue> (FaParser::StrongExprContext *)> _parse_strong_expr;
		std::function<std::optional<_ExprOrValue> (FaParser::StrongExprBaseContext *)> _parse_strong_expr_base;
		std::function<std::optional<_ExprOrValue> (FaParser::IfExprContext *)> _parse_if_expr;
		_parse_expr = [&] (FaParser::ExprContext *_expr_raw) -> std::optional<_ExprOrValue> {
			auto _exprs = _expr_raw->middleExpr ();
			auto _ops = _expr_raw->allAssign ();
			auto _oval = _parse_middle_expr (_exprs [_exprs.size () - 1]);
			if (!_oval.has_value ())
				return std::nullopt;
			_ExprOrValue _val = _oval.value ();
			for (int i = (int) _ops.size () - 1; i >= 0; --i) {
				auto _ptr = std::make_shared<_Op2ExprTreeCtx> ();
				_oval = _parse_middle_expr (_exprs [i]);
				if (!_oval.has_value ())
					return std::nullopt;
				_ptr->_left = _oval.value ();
				_ptr->_op = _OperCtx { _ops [i] };
				_ptr->_right = _val;

				// 检查 _left 是否可赋值
				std::string _type_str = _ptr->_left.GetExpectType ();
				if (_type_str [0] != '$') {
					LOG_ERROR (_ops [i]->start, "对象不可被赋值");
					return std::nullopt;
				}
				// TODO 检查 _left 是否能接受 _right 类型变量
				// _expect_type改为不可赋值
				_ptr->_expect_type = _type_str.substr (1);
				_val = _ExprOrValue { _ptr };
			}
			return _val;
		};
		_parse_middle_expr = [&] (FaParser::MiddleExprContext *_expr_raw) -> std::optional<_ExprOrValue> {
			auto _exprs = _expr_raw->strongExpr ();
			auto _ops = _expr_raw->allOp2 ();
			std::vector<size_t> _op_levels;
			for (auto _op : _ops) {
				static std::map<std::string, size_t> s_priv_level {
					{ "**", 1 },
					{ "*", 2 }, { "/", 2 }, { "%", 2 },
					{ "+", 3 }, { "-", 3 },
					{ "<<", 4 }, { ">>", 4 },
					{ "&", 5 }, { "|", 5 }, { "^", 5 },
					{ "??", 6 },
					{ "<", 7 }, { "<=", 7 }, { ">", 7 }, { ">=", 7 }, { "==", 7 }, { "!=", 7 },
					{ "&&", 8 },
					{ "||", 9 },
				};
				std::string _op_str = _op->getText ();
				if (!s_priv_level.contains (_op_str)) {
					LOG_TODO (_op->start);
					return std::nullopt;
				}
				_op_levels.push_back (s_priv_level [_op_str]);
			}
			return _parse_middle_expr2 (_exprs, _ops, _op_levels);
		};
		_parse_middle_expr2 = [&] (std::vector<FaParser::StrongExprContext *> &_expr_raws, std::vector<FaParser::AllOp2Context *> &_op_raws, std::vector<size_t> &_op_levels) -> std::optional<_ExprOrValue> {
			if (_expr_raws.size () == 1)
				return _parse_strong_expr (_expr_raws [0]);
			size_t _pos = 0, _pos_level = _op_levels [0];
			for (size_t i = 1; i < _op_levels.size (); ++i) {
				if (_op_levels [i] > _pos_level) {
					_pos = i;
					_pos_level = _op_levels [i];
				}
			}
			//
			auto _ptr = std::make_shared<_Op2ExprTreeCtx> ();
			std::vector<FaParser::StrongExprContext *> _tmp_expr_raws;
			std::vector<FaParser::AllOp2Context *> _tmp_op_raws;
			std::vector<size_t> _tmp_op_levels;
			_tmp_expr_raws.assign (_expr_raws.begin (), _expr_raws.begin () + _pos + 1);
			if (_tmp_expr_raws.size () > 1) {
				_tmp_op_raws.assign (_op_raws.begin (), _op_raws.begin () + _pos);
				_tmp_op_levels.assign (_op_levels.begin (), _op_levels.begin () + _pos);
			}
			auto _tmp_val = _parse_middle_expr2 (_tmp_expr_raws, _tmp_op_raws, _tmp_op_levels);
			if (!_tmp_val.has_value ())
				return std::nullopt;
			_ptr->_left = _tmp_val.value ();
			//
			_ptr->_op = _OperCtx { _op_raws [_pos] };
			//
			_tmp_expr_raws.clear ();
			_tmp_op_raws.clear ();
			_tmp_op_levels.clear ();
			_tmp_expr_raws.assign (_expr_raws.begin () + _pos + 1, _expr_raws.end ());
			if (_tmp_expr_raws.size () > 1) {
				_tmp_op_raws.assign (_op_raws.begin () + _pos + 1, _op_raws.end ());
				_tmp_op_levels.assign (_op_levels.begin () + _pos + 1, _op_levels.end ());
			}
			_tmp_val = _parse_middle_expr2 (_tmp_expr_raws, _tmp_op_raws, _tmp_op_levels);
			if (!_tmp_val.has_value ())
				return std::nullopt;
			_ptr->_right = _tmp_val.value ();
			return _ptr;
		};
		_parse_strong_expr = [&] (FaParser::StrongExprContext *_expr_raw) -> std::optional<_ExprOrValue> {
			auto _tmp_val = _parse_strong_expr_base (_expr_raw->strongExprBase ());
			if (!_tmp_val.has_value ())
				return std::nullopt;
			_ExprOrValue _val = _tmp_val.value ();
			for (auto _suffix_raw : _expr_raw->strongExprSuffix ()) {
				if (_suffix_raw->AddAddOp () || _suffix_raw->SubSubOp ()) {
					auto _ptr = std::make_shared<_Op1ExprTreeCtx> ();
					_ptr->_op = _OperCtx { _suffix_raw->getText (), _suffix_raw };
					_ptr->_left = _val;
					_ptr->_type = _Op1Type::Suffix;
					_ptr->_expect_type = _val.GetExpectType ();
					if (_ptr->_expect_type [0] != '$') {
						LOG_ERROR (_suffix_raw->start, "对象不可被赋值");
						return std::nullopt;
					}
					_val = _ptr;
				} else if (_suffix_raw->QuotYuanL () || _suffix_raw->QuotFangL ()) {
					auto _ptr = std::make_shared<_OpNExprTreeCtx> ();
					_ptr->_left = _val;
					_ptr->_op = _OperCtx { _suffix_raw->QuotYuanL () ? "()" : "[]", _suffix_raw};
					for (auto _right_expr_raw : _suffix_raw->exprOpt ()) {
						if (_right_expr_raw->expr ()) {
							auto _right_oval = _parse_expr (_right_expr_raw->expr ());
							if (!_right_oval.has_value ())
								return std::nullopt;
							_ptr->_rights.push_back (_right_oval.value ());
						} else {
							_ptr->_rights.push_back (_ExprOrValue { std::make_shared<_ValueCtx> (AstValue {}, _right_expr_raw->start) });
						}
					}
					_ptr->_expect_type = _val.GetExpectType ();
					_val = _ptr;
				} else if (_suffix_raw->PointOp ()) {
					auto _ptr = std::make_shared<_Op2ExprTreeCtx> ();
					_ptr->_left = _val;
					_ptr->_op = _OperCtx { ".", _suffix_raw };
					_ptr->_right = _ExprOrValue { std::make_shared<_ValueCtx> (AstValue { _suffix_raw->Id ()->getText () }, _suffix_raw->Id ()->getSymbol ()) };
					if (!_ptr->CalcExpectType ()) {
						LOG_ERROR (_suffix_raw->start, "对象不存在目标成员");
						return std::nullopt;
					}
					_val = _ptr;
				} else {
					LOG_TODO (_expr_raw->start);
					return std::nullopt;
				}
			}
			auto _prefix_raws = _expr_raw->strongExprPrefix ();
			for (auto _prefix_praw = _prefix_raws.rbegin (); _prefix_praw != _prefix_raws.rend (); ++_prefix_praw) {
				auto _ptr = std::make_shared<_Op1ExprTreeCtx> ();
				_ptr->_op = _OperCtx { (*_prefix_praw)->getText (), *_prefix_praw };
				_ptr->_left = _val;
				_ptr->_type = _Op1Type::Prefix;
				_ptr->_expect_type = _val.GetExpectType ();
				_val = _ptr;
			}
			return _val;
		};
		_parse_strong_expr_base = [&] (FaParser::StrongExprBaseContext *_expr_raw) -> std::optional<_ExprOrValue> {
			if (_expr_raw->ids ()) {
				auto _val = _func_ctx.GetVariable (_expr_raw->ids ()->getText ());
				if (_val.IsValid ())
					return std::make_shared<_ValueCtx> (_expr_raw, _val, _val.GetType ());
			} else if (_expr_raw->ColonColon ()) {
				std::string _name = _expr_raw->getText ();
				if (m_imports.contains (_name)) {
					auto &[_func, _func_type] = m_imports [_name];
					return std::make_shared<_ValueCtx> (_expr_raw, AstValue { _func, _func_type }, _func_type);
				}
			} else if (_expr_raw->literal ()) {
				AstValue _oval { m_value_builder, _expr_raw->literal () };
				if (_oval.IsValid ())
					return std::make_shared<_ValueCtx> (_expr_raw, _oval, _oval.GetType ());
			} else if (_expr_raw->ifExpr ()) {
				return _parse_if_expr (_expr_raw->ifExpr ());
			} else if (_expr_raw->quotExpr ()) {
				return _parse_expr (_expr_raw->quotExpr ()->expr ());
			} else {
				LOG_TODO (_expr_raw->start);
			}
			return std::nullopt;
		};
		_parse_if_expr = [&] (FaParser::IfExprContext *_expr_raw)->std::optional<_ExprOrValue> {
			auto _if_expr = std::make_shared<_IfExprTreeCtx> ();
			for (auto _cond_raw : _expr_raw->expr ()) {
				auto _cond_oval = _parse_expr (_cond_raw);
				if (!_cond_oval.has_value ())
					return std::nullopt;
				_if_expr->_conds.push_back (_cond_oval.value ());
			}
			for (auto _body_raw : _expr_raw->quotStmtExpr ()) {
				_if_expr->_bodys1_raw.push_back (_body_raw->stmt ());
				auto _stmt_oval = _parse_expr (_body_raw->expr ());
				if (!_stmt_oval.has_value ())
					return std::nullopt;
				_if_expr->_bodys2.push_back (_stmt_oval.value ());
			}
			return _if_expr;
		};
		//
		std::optional<_ExprOrValue> _oev = _parse_expr (_expr_raw);
		if (!_oev.has_value ())
			return std::nullopt;
		_ExprOrValue _ev = _oev.value ();
		// TODO
	}

	//bool IfExprBuilder (FuncContext &_func_ctx, std::vector<FaParser::ExprContext *> &_conds_raw, std::vector<std::vector<FaParser::StmtContext *>> &_bodys_raw1, std::vector<FaParser::ExprContext *> &_bodys_raw2, std::string _expect_type, AstValue &_vt) {
	//	AstValue _cond {}, _tmp_vt {};
	//	if (_conds_raw.size () == 0) {
	//		if (!StmtBuilder (_func_ctx, _bodys_raw1 [0]))
	//			return false;
	//		if (!ExprBuilder (_func_ctx, _bodys_raw2 [0], _expect_type, _tmp_vt))
	//			return false;
	//		_func_ctx.DoOper2 (_vt, "=", _tmp_vt, _bodys_raw2 [0]->start);
	//		return true;
	//	}
	//	//
	//	if (!ExprBuilder (_func_ctx, _conds_raw [0], "bool", _cond))
	//		return false;
	//	_conds_raw.erase (_conds_raw.begin ());
	//	_func_ctx.IfElse (_cond, [&] () {
	//		if (!StmtBuilder (_func_ctx, _bodys_raw1 [0]))
	//			return false;
	//		_bodys_raw1.erase (_bodys_raw1.begin ());
	//		if (!ExprBuilder (_func_ctx, _bodys_raw2 [0], _expect_type, _tmp_vt))
	//			return false;
	//		_bodys_raw2.erase (_bodys_raw2.begin ());
	//		_func_ctx.DoOper2 (_vt, "=", _tmp_vt, _bodys_raw2 [0]->start);
	//		return true;
	//	}, [&] () {
	//		return IfExprBuilder (_func_ctx, _conds_raw, _bodys_raw1, _bodys_raw2, _expect_type, _vt);
	//	});
	//	return true;
	//}

	CodeVisitor *m_visitor = nullptr;
	std::string m_module_name;
	std::shared_ptr<llvm::LLVMContext> m_ctx;
	std::shared_ptr<llvm::Module> m_module;
	std::shared_ptr<TypeMap> m_type_map;
	std::shared_ptr<ValueBuilder> m_value_builder;

	std::vector<std::string> m_uses;
	std::map<std::string, std::tuple<llvm::Function *, std::string>> m_imports;
	std::vector<std::string> m_libs;
};



#endif //__FA_LLVM_GEN_HPP__
