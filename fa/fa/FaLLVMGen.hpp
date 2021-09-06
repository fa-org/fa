#ifndef __FA_LLVM_GEN_HPP__
#define __FA_LLVM_GEN_HPP__



#include <format>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
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

#include "CodeVisitor.hpp"
#include "TypeMap.hpp"
#include "ValueBuilder.hpp"
#include "AstValue.hpp"
#include "FuncContext.hpp"
#include "OperAST.hpp"
#include "FuncType.hpp"
#include "ClassType.hpp"



class FaLLVMGen {
public:
	FaLLVMGen (CodeVisitor *_visitor, std::string _module_name): m_visitor (_visitor), m_module_name (_module_name) {
		m_ctx = std::make_shared<llvm::LLVMContext> ();
		m_module = std::make_shared<llvm::Module> (m_module_name, *m_ctx);
		m_type_map = std::make_shared<TypeMap> (m_visitor, m_ctx);
		m_value_builder = std::make_shared<ValueBuilder> (m_visitor, m_ctx, m_module);
		m_global_funcs = std::make_shared<FuncTypes> (m_ctx, m_type_map, m_module, m_value_builder);
		m_global_classes = std::make_shared<ClassTypes> ();
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

		// 获取访问级别
		std::function<PublicLevel (FaParser::PublicLevelContext *, PublicLevel)> _public_level = [&] (FaParser::PublicLevelContext *_public_raw, PublicLevel _default) {
			if (_public_raw == nullptr)
				return _default;
			PublicLevel _ret = m_visitor->visit (_public_raw).as<PublicLevel> ();
			return _ret == PublicLevel::Unknown ? _default : _ret;
		};

		// 编译类
		for (auto _class_raw : _program_ctx->classBlock ()) {
			// 访问级别
			PublicLevel _pl = _public_level (_class_raw->publicLevel (), PublicLevel::Internal);

			// 类名
			std::string _name = _class_raw->Id ()->getText ();
			auto _oclass = m_global_classes->GetClass (_name);
			if (_oclass.has_value ()) {
				LOG_ERROR (_class_raw->Id ()->getSymbol (), "类名重复定义");
				return false;
			}
			std::shared_ptr<ClassType> _class = m_global_classes->CreateNewClass (_pl, _name);

			// 父类型
			if (_class_raw->classParent ()) {
				std::vector<std::string> _parents = m_visitor->visit (_class_raw->classParent ()).as<std::vector<std::string>> ();
				_class->AddParents (_parents);
			}

			// 成员变量
			for (auto _var_raw : _class_raw->classVar ()) {
				// 访问级别
				_pl = _public_level (_var_raw->publicLevel (), PublicLevel::Private);

				// 是否静态
				bool _is_static = !!_var_raw->Static ();

				// 类型
				std::string _type = _var_raw->type ()->getText ();

				// 名称
				_name = _var_raw->Id ()->getText ();
				auto _var = _class->AddVar (_pl, _is_static, _type, _name);

				// 初始值和 getter setter
				auto _var_ext_raw = _var_raw->classVarExt ();
				if (_var_ext_raw) {
					// 属性变量，所有属性均为实体属性
					// 初值
					if (_var_ext_raw->tmpAssignExpr ())
						_var->SetInitValue (_var_ext_raw->tmpAssignExpr ()->expr ());

					// 类变量 getter setter
					for (auto _ext_func_raw : _var_ext_raw->classVarExtFunc ()) {
						_pl = _public_level (_ext_func_raw->publicLevel (), PublicLevel::Public);
						auto [_suc, _err] = _var->AddVarFunc (_pl, _ext_func_raw->Id (), _ext_func_raw->classFuncBody ());
						if (!_suc) {
							LOG_ERROR (_ext_func_raw->start, _err);
							return false;
						}
					}
				} else {
					// 普通变量
					// 初值
					if (_var_raw->tmpAssignExpr ())
						_var->SetInitValue (_var_raw->tmpAssignExpr ()->expr ());
				}
			}

			// TODO 成员函数
			for (auto _func_raw : _class_raw->classFunc ()) {
				// 访问级别
				_pl = _public_level (_func_raw->publicLevel (), PublicLevel::Private);

				// 是否静态
				bool _is_static = !!_func_raw->Static ();

				// 类型
				std::string _type = _func_raw->type ()->getText ();

				// 名称
				_name = _func_raw->classFuncName ()->getText ();
			}
		}

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
		std::string _cmd = std::format ("\"{}\" /subsystem:console /dynamicbase /machine:X86 /debug /entry:@fa_main /out:{}.exe /pdb:{}.pdb {}.obj", _link_exe_path, m_module_name, m_module_name, m_module_name);
		// 依赖处理差的链接命令
		// link /subsystem:console /dynamicbase /machine:X86 /debug /entry:@fa_main /out:hello.exe /pdb:hello.pdb hello.obj "libucrt.lib" "libcmt.lib"
		// 编译程序无法运行的链接命令
		// link /OUT:"hello.exe" /MANIFEST /LTCG:incremental /NXCOMPAT /PDB:"hello.pdb" /DYNAMICBASE /entry:@fa_main hello.obj "libucrt.lib" "libcmt.lib" /DEBUG /MACHINE:X86 /OPT:REF /SAFESEH /INCREMENTAL:NO /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"hello.exe.intermediate.manifest" /LTCGOUT:"hello.iobj" /OPT:ICF /ERRORREPORT:PROMPT /ILK:"hello.ilk" /NOLOGO /TLBID:1
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
			auto [_name, _ret_type_raw, _arg_types_raw, _cc_str] = m_visitor->visit (_import_func_raw).as<std::tuple<
				std::string,
				FaParser::ETypeContext *,
				std::vector<FaParser::ETypeContext *>,
				std::string
			>> ();
			std::string _func_name = std::format ("::{}", _name);
			if (!m_global_funcs->Contains (_func_name)) {
				llvm::CallingConv::ID _cc = llvm::CallingConv::C;
				if (_cc_str == "__cdecl") {
					_cc = llvm::CallingConv::C;
				} else if (_cc_str == "__stdcall") {
					_cc = llvm::CallingConv::X86_StdCall;
				} else if (_cc_str == "__fastcall") {
					_cc = llvm::CallingConv::X86_FastCall;
				}
				if (!m_global_funcs->MakeExtern (_func_name, _ret_type_raw, _arg_types_raw, _cc))
					return false;
			}
		}
		return true;
	}

	bool BuildFaEntryMain (FaParser::FaEntryMainFuncBlockContext *_mctx) {
		auto [_ret_type_raw, _stmts_raw] = m_visitor->visit (_mctx).as<std::tuple<
			FaParser::TypeContext *,
			std::vector<FaParser::StmtContext *>
		>> ();
		std::vector<FaParser::TypeContext *> _arg_type_raws;
		if (!m_global_funcs->Make ("@fa_main", true, _ret_type_raw, _arg_type_raws, llvm::CallingConv::C))
			return false;
		FuncContext _func_ctx { m_global_funcs, "@fa_main" };
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
		return _func_ctx.IfElse (_cond, [&] () {
			if (!StmtBuilder (_func_ctx, _bodys_raw [0]))
				return false;
			_bodys_raw.erase (_bodys_raw.begin ());
			return true;
		}, [&] () {
			return IfStmtBuilder (_func_ctx, _conds_raw, _bodys_raw);
		});
	}

	AstValue ExprBuilder (FuncContext &_func_ctx, FaParser::ExprContext *_expr_raw, std::string _expect_type) {
		// 定义解析函数
		std::function<std::optional<_AST_ExprOrValue> (FaParser::ExprContext *, std::string)> _parse_expr;
		std::function<std::optional<_AST_ExprOrValue> (FaParser::MiddleExprContext *, std::string)> _parse_middle_expr;
		std::function<std::optional<_AST_ExprOrValue> (std::vector<FaParser::StrongExprContext *> &_expr_raws, std::vector<FaParser::AllOp2Context *> &_op_raws, std::vector<size_t> &_op_levels, std::string)> _parse_middle_expr2;
		std::function<std::optional<_AST_ExprOrValue> (FaParser::StrongExprContext *, std::string)> _parse_strong_expr;
		std::function<std::optional<_AST_ExprOrValue> (FaParser::StrongExprBaseContext *, std::string)> _parse_strong_expr_base;
		std::function<std::optional<_AST_ExprOrValue> (FaParser::IfExprContext *, std::string)> _parse_if_expr;
		_parse_expr = [&] (FaParser::ExprContext *_expr_raw, std::string _exp_type) -> std::optional<_AST_ExprOrValue> {
			auto _exprs = _expr_raw->middleExpr ();
			auto _ops = _expr_raw->allAssign ();
			if (_exprs.size () == 1) {
				return _parse_middle_expr (_exprs [0], _exp_type);
			} else {
				if (_exp_type != "" && _exp_type [0] == '$') {
					LOG_ERROR (_ops [0]->start, "带赋值运算的表达式无法再次赋值");
					return std::nullopt;
				}
				auto _ret = std::make_shared<_AST_Op2ExprTreeCtx> ();
				auto _oval = _parse_middle_expr (_exprs [0], "$");
				if (!_oval.has_value ())
					return std::nullopt;
				_ret->_left = _oval.value ();
				_ret->_op = _AST_Oper2Ctx { _ops [0] };
				std::string _cur_type = _ret->_left.GetExpectType ();
				if (!TypeMap::CanImplicitConvTo (_cur_type, _exp_type))
					return std::nullopt;
				_ret->_expect_type = _exp_type;
				_exp_type = _cur_type.substr (1);
				auto _cur = _ret;
				for (size_t i = 1; i < _ops.size (); ++i) {
					auto _cur_tmp = std::make_shared<_AST_Op2ExprTreeCtx> ();
					_cur->_right = _cur_tmp;
					_cur = _cur_tmp;
					auto _oval = _parse_middle_expr (_exprs [i], "$");
					if (!_oval.has_value ())
						return std::nullopt;
					_cur->_left = _oval.value ();
					_cur->_op = _AST_Oper2Ctx { _ops [i] };
					_cur_type = _cur->_left.GetExpectType ();
					if (!TypeMap::CanImplicitConvTo (_cur_type, _exp_type))
						return std::nullopt;
					_cur->_expect_type = _exp_type;
					_exp_type = _cur_type.substr (1);
				}
				_oval = _parse_middle_expr (_exprs [_exprs.size () - 1], _exp_type);
				if (!_oval.has_value ())
					return std::nullopt;
				_cur->_right = _oval.value ();
				return _ret;
			}
		};
		_parse_middle_expr = [&] (FaParser::MiddleExprContext *_expr_raw, std::string _exp_type) -> std::optional<_AST_ExprOrValue> {
			auto _exprs = _expr_raw->strongExpr ();
			auto _ops = _expr_raw->allOp2 ();
			std::vector<size_t> _op_levels;
			for (auto _op : _ops) {
				std::string _op_str = _op->getText ();
				size_t _level = OperAST::GetOpLevel (_op_str);
				if (_level == std::string::npos) {
					LOG_TODO (_op->start);
					return std::nullopt;
				}
				_op_levels.push_back (_level);
			}
			return _parse_middle_expr2 (std::ref (_exprs), std::ref (_ops), std::ref (_op_levels), _exp_type);
		};
		_parse_middle_expr2 = [&] (std::vector<FaParser::StrongExprContext *> &_expr_raws, std::vector<FaParser::AllOp2Context *> &_op_raws, std::vector<size_t> &_op_levels, std::string _exp_type) -> std::optional<_AST_ExprOrValue> {
			if (_expr_raws.size () == 1)
				return _parse_strong_expr (_expr_raws [0], _exp_type);
			size_t _pos = 0, _pos_level = _op_levels [0];
			for (size_t i = 1; i < _op_levels.size (); ++i) {
				if (_op_levels [i] > _pos_level) {
					_pos = i;
					_pos_level = _op_levels [i];
				}
			}

			// 根据优先级拆分为两块
			auto _ptr = std::make_shared<_AST_Op2ExprTreeCtx> ();
			_ptr->_op = _AST_Oper2Ctx { _op_raws [_pos] };
			std::vector<FaParser::StrongExprContext *> _expr_raws_L, _expr_raws_R;
			std::vector<FaParser::AllOp2Context *> _op_raws_L, _op_raws_R;
			std::vector<size_t> _op_levels_L, _op_levels_R;
			_expr_raws_L.assign (_expr_raws.begin (), _expr_raws.begin () + _pos + 1);
			if (_expr_raws_L.size () > 1) {
				_op_raws_L.assign (_op_raws.begin (), _op_raws.begin () + _pos);
				_op_levels_L.assign (_op_levels.begin (), _op_levels.begin () + _pos);
			}
			_expr_raws_R.assign (_expr_raws.begin () + _pos + 1, _expr_raws.end ());
			if (_expr_raws_R.size () > 1) {
				_op_raws_R.assign (_op_raws.begin () + _pos + 1, _op_raws.end ());
				_op_levels_R.assign (_op_levels.begin () + _pos + 1, _op_levels.end ());
			}

			// 初步计算期望类型
			std::string _exp_type_L = "", _exp_type_R = "";
			if (_ptr->_op._type == _Op2Type::Assign) {
				LOG_TODO (_ptr->_op._t);
				return std::nullopt;
			} else if (_ptr->_op._type == _Op2Type::NoChange) {
				if (_exp_type != "") {
					_exp_type_L = _exp_type_R = _exp_type;
				}
			} else if (_ptr->_op._type == _Op2Type::Compare) {
				if (_exp_type != "" && _exp_type != "bool") {
					LOG_ERROR (_ptr->_op._t, std::format ("比较运算无法产生 {} 类型的值", _exp_type));
					return std::nullopt;
				}
			} else {
				if (_ptr->_op._op != "??") {
					LOG_TODO (_ptr->_op._t);
					return std::nullopt;
				}
				if (_exp_type != "") {
					_exp_type_R = _exp_type;
					_exp_type_L = _exp_type [_exp_type.size () - 1] == '?' ? _exp_type : std::format ("{}?", _exp_type);
				}
			}

			// 计算结果
			auto _oval = _parse_middle_expr2 (std::ref (_expr_raws_L), std::ref (_op_raws_L), std::ref (_op_levels_L), _exp_type_L);
			if (!_oval.has_value ())
				return std::nullopt;
			_ptr->_left = _oval.value ();
			_oval = _parse_middle_expr2 (std::ref (_expr_raws_R), std::ref (_op_raws_R), std::ref (_op_levels_R), _exp_type_R);
			if (!_oval.has_value ())
				return std::nullopt;
			_ptr->_right = _oval.value ();

			// 确定具体的期望
			_exp_type_L = _ptr->_left.GetExpectType ();
			_exp_type_R = _ptr->_right.GetExpectType ();
			if (_ptr->_op._type == _Op2Type::Assign) {
				LOG_TODO (_ptr->_op._t);
				return std::nullopt;
			} else if (_ptr->_op._type == _Op2Type::NoChange || _ptr->_op._type == _Op2Type::Compare) {
				if ((_ptr->_op._type == _Op2Type::NoChange && _exp_type == "") || _ptr->_op._type == _Op2Type::Compare) {
					if (_exp_type_L == _exp_type_R) {
						_exp_type = _exp_type_L;
					} else {
						// 预期类型不同，那么获取适配类型
						auto _exp_otype = TypeMap::GetCompatibleType (_ptr->_op._t, { _exp_type_L, _exp_type_R });
						if (!_exp_otype.has_value ())
							return std::nullopt;
						_exp_type = _exp_otype.value ();
						if (_exp_type_L != _exp_type) {
							_oval = _parse_middle_expr2 (std::ref (_expr_raws_L), std::ref (_op_raws_L), std::ref (_op_levels_L), _exp_type_L);
							if (!_oval.has_value ())
								return std::nullopt;
							_ptr->_left = _oval.value ();
						}
						if (_exp_type_R != _exp_type) {
							_oval = _parse_middle_expr2 (std::ref (_expr_raws_R), std::ref (_op_raws_R), std::ref (_op_levels_R), _exp_type_R);
							if (!_oval.has_value ())
								return std::nullopt;
							_ptr->_right = _oval.value ();
						}
					}
				}
			} else {
				if (_ptr->_op._op == "??") {
					if (_exp_type_L [_exp_type_L.size () - 1] != '?') {
						LOG_ERROR (_ptr->_op._t, "不可空类型无法使用 ?? 运算");
						return std::nullopt;
					}
					if (_exp_type_R [_exp_type_R.size () - 1] == '?' && _exp_type_L == _exp_type_R) {
						_exp_type = _exp_type_R;
					} else if (_exp_type_L == std::format ("{}?", _exp_type_R)) {
						_exp_type = _exp_type_R;
					} else {
						LOG_ERROR (_ptr->_op._t, "无法使用 ?? 运算");
						return std::nullopt;
					}
				} else {
					LOG_TODO (_ptr->_op._t);
					return std::nullopt;
				}
			}
			_ptr->_expect_type = _exp_type;
			return _ptr;
		};
		_parse_strong_expr = [&] (FaParser::StrongExprContext *_expr_raw, std::string _exp_type) -> std::optional<_AST_ExprOrValue> {
			if (_exp_type != "" && _exp_type != "$") {
				// 外到内层层解析类型
				// prefix 0->x
				// suffix x->0
				_AST_ExprOrValue _ret, _cur;
				bool _init = true;
				std::function<void (_AST_ExprOrValue)> _update_next = [&] (_AST_ExprOrValue _ev) {
					if (_init) {
						_init = false;
						_ret = _cur = _ev;
					} else {
						if (_cur._op1_expr) {
							_cur._op1_expr->_left = _ev;
							_cur = _cur._op1_expr->_left;
						} else if (_cur._op2_expr) {
							_cur._op2_expr->_left = _ev;
							_cur = _cur._op2_expr->_left;
						} else if (_cur._opN_expr) {
							_cur._opN_expr->_left = _ev;
							_cur = _cur._opN_expr->_left;
						}
					}
				};
				//
				for (auto _prefix_raw : _expr_raw->strongExprPrefix ()) {
					auto _ptr = std::make_shared<_AST_Op1ExprTreeCtx> ();
					_ptr->_op = _AST_Oper1Ctx { _prefix_raw };
					_ptr->_expect_type = _exp_type;
					_update_next (_ptr);
				}
				//
				auto _suffix_raws = _expr_raw->strongExprSuffix ();
				for (auto _suffix_praw = _suffix_raws.rbegin (); _suffix_praw != _suffix_raws.rend (); ++_suffix_praw) {
					auto _suffix_raw = *_suffix_praw;
					if (_suffix_raw->AddAddOp () || _suffix_raw->SubSubOp ()) {
						auto _ptr = std::make_shared<_AST_Op1ExprTreeCtx> ();
						_ptr->_op = _AST_Oper1Ctx { _suffix_raw };
						_ptr->_expect_type = _exp_type;
						if (_ptr->_expect_type [0] != '$') {
							LOG_ERROR (_suffix_raw->start, "对象不可被赋值");
							return std::nullopt;
						}
						_update_next (_ptr);
					} else if (_suffix_raw->QuotYuanL () || _suffix_raw->QuotFangL ()) {
						auto _ptr = std::make_shared<_AST_OpNExprTreeCtx> ();
						_ptr->_op = _AST_Oper2Ctx { _suffix_raw };
						auto _func = m_global_funcs->GetFunc (_exp_type);
						auto _expr_opt_raws = _suffix_raw->exprOpt ();
						if (_expr_opt_raws.size () == 1 && (!_expr_opt_raws [0]->expr ()))
							_expr_opt_raws.clear ();
						if (_expr_opt_raws.size () != _func->m_arg_types.size ()) {
							LOG_ERROR (_suffix_raw->start, "参数数量不匹配");
							return std::nullopt;
						}
						for (size_t i = 0; i < _func->m_arg_types.size (); ++i) {
							if (_expr_opt_raws [i]->expr ()) {
								auto _right_oval = _parse_expr (_expr_opt_raws [i]->expr (), _func->m_arg_types [i]);
								if (!_right_oval.has_value ())
									return std::nullopt;
								_ptr->_rights.push_back (_right_oval.value ());
							} else {
								//_ptr->_rights.push_back (_AST_ExprOrValue { std::make_shared<_AST_ValueCtx> (std::nullopt, _expr_opt_raws [i]->start, "?") });
								LOG_TODO (_expr_opt_raws [i]->start);
								return std::nullopt;
							}
						}
						_exp_type = _ptr->_expect_type = _func->m_ret_type;
						_update_next (_ptr);
					} else if (_suffix_raw->PointOp ()) {
						auto _ptr = std::make_shared<_AST_Op2ExprTreeCtx> ();
						_ptr->_op = _AST_Oper2Ctx { _suffix_raw };
						_ptr->_right = _AST_ExprOrValue { std::make_shared<_AST_ValueCtx> (AstValue { _suffix_raw->Id ()->getText () }, _suffix_raw->Id ()->getSymbol (), "[member]") };
						if (!_ptr->CalcExpectType ()) {
							LOG_ERROR (_suffix_raw->start, "对象不存在目标成员");
							return std::nullopt;
						}
						_update_next (_ptr);
					} else {
						LOG_TODO (_expr_raw->start);
						return std::nullopt;
					}
				}
				auto _oval = _parse_strong_expr_base (_expr_raw->strongExprBase (), _exp_type);
				if (!_oval.has_value ())
					return std::nullopt;
				_update_next (_oval.value ());
				return _ret;
			} else {
				// 内到外层层叠加类型
				// suffix 0->x
				// prefix x->0
				auto _oval = _parse_strong_expr_base (_expr_raw->strongExprBase (), "");
				if (!_oval.has_value ())
					return std::nullopt;
				_AST_ExprOrValue _val = _oval.value ();
				for (auto _suffix_raw : _expr_raw->strongExprSuffix ()) {
					if (_suffix_raw->AddAddOp () || _suffix_raw->SubSubOp ()) {
						auto _ptr = std::make_shared<_AST_Op1ExprTreeCtx> ();
						_ptr->_op = _AST_Oper1Ctx { _suffix_raw };
						_ptr->_left = _val;
						_ptr->_expect_type = _val.GetExpectType ();
						if (_ptr->_expect_type [0] != '$') {
							LOG_ERROR (_suffix_raw->start, "对象不可被赋值");
							return std::nullopt;
						}
						_val = _ptr;
					} else if (_suffix_raw->QuotYuanL () || _suffix_raw->QuotFangL ()) {
						auto _ptr = std::make_shared<_AST_OpNExprTreeCtx> ();
						_ptr->_left = _val;
						_ptr->_op = _AST_Oper2Ctx { _suffix_raw };
						auto _func = m_global_funcs->GetFunc (_val.GetFuncName ());
						auto _expr_opt_raws = _suffix_raw->exprOpt ();
						if (_expr_opt_raws.size () == 1 && (!_expr_opt_raws [0]->expr ()))
							_expr_opt_raws.clear ();
						if (_expr_opt_raws.size () != _func->m_arg_types.size ()) {
							LOG_ERROR (_suffix_raw->start, "参数数量不匹配");
							return std::nullopt;
						}
						for (size_t i = 0; i < _func->m_arg_types.size (); ++i) {
							if (_expr_opt_raws [i]->expr ()) {
								auto _right_oval = _parse_expr (_expr_opt_raws [i]->expr (), _func->m_arg_types [i]);
								if (!_right_oval.has_value ())
									return std::nullopt;
								_ptr->_rights.push_back (_right_oval.value ());
							} else {
								//_ptr->_rights.push_back (_AST_ExprOrValue { std::make_shared<_AST_ValueCtx> (std::nullopt, _expr_opt_raws [i]->start, "?") });
								LOG_TODO (_expr_opt_raws [i]->start);
								return std::nullopt;
							}
						}
						_ptr->_expect_type = _func->m_ret_type;
						_val = _ptr;
					} else if (_suffix_raw->PointOp ()) {
						auto _ptr = std::make_shared<_AST_Op2ExprTreeCtx> ();
						_ptr->_left = _val;
						_ptr->_op = _AST_Oper2Ctx { _suffix_raw };
						_ptr->_right = _AST_ExprOrValue { std::make_shared<_AST_ValueCtx> (AstValue { _suffix_raw->Id ()->getText () }, _suffix_raw->Id ()->getSymbol (), "[member]") };
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
					auto _ptr = std::make_shared<_AST_Op1ExprTreeCtx> ();
					_ptr->_op = _AST_Oper1Ctx { *_prefix_praw };
					_ptr->_left = _val;
					_ptr->_expect_type = _val.GetExpectType ();
					_val = _ptr;
				}
				if (!TypeMap::CanImplicitConvTo (_val.GetExpectType (), _exp_type))
					return std::nullopt;
				return _val;
			}
		};
		_parse_strong_expr_base = [&] (FaParser::StrongExprBaseContext *_expr_raw, std::string _exp_type) -> std::optional<_AST_ExprOrValue> {
			if (_expr_raw->ids ()) {
				auto _val = FindValueType (_func_ctx, _expr_raw->ids ()->getText ());
				if (!_val.IsValid ())
					return std::nullopt;
				if (!TypeMap::CanImplicitConvTo (_val.GetType (), _exp_type))
					return std::nullopt;
				return std::make_shared<_AST_ValueCtx> (_val, _expr_raw->start, _exp_type == "" ? _val.GetType () : _exp_type);
			} else if (_expr_raw->ColonColon ()) {
				std::string _name = _expr_raw->getText ();
				if (!m_global_funcs->Contains (_name))
					return std::nullopt;
				auto _f = m_global_funcs->GetFunc (_name);
				if (!TypeMap::CanImplicitConvTo (_f->m_type, _exp_type))
					return std::nullopt;
				return std::make_shared<_AST_ValueCtx> (AstValue { _f }, _expr_raw->start, _exp_type == "" ? _f->m_type : _exp_type);
			} else if (_expr_raw->literal ()) {
				AstValue _val { m_value_builder, _expr_raw->literal (), _exp_type };
				if (!_val.IsValid ())
					return std::nullopt;
				if (!TypeMap::CanImplicitConvTo (_val.GetType (), _exp_type))
					return std::nullopt;
				return std::make_shared<_AST_ValueCtx> (_val, _expr_raw->start, _exp_type == "" ? _val.GetType () : _exp_type);
			} else if (_expr_raw->ifExpr ()) {
				return _parse_if_expr (_expr_raw->ifExpr (), _exp_type);
			} else if (_expr_raw->quotExpr ()) {
				return _parse_expr (_expr_raw->quotExpr ()->expr (), _exp_type);
			}
			LOG_TODO (_expr_raw->start);
			return std::nullopt;
		};
		_parse_if_expr = [&] (FaParser::IfExprContext *_expr_raw, std::string _exp_type)->std::optional<_AST_ExprOrValue> {
			auto _if_expr = std::make_shared<_AST_IfExprTreeCtx> ();
			for (auto _cond_raw : _expr_raw->expr ()) {
				auto _cond_oval = _parse_expr (_cond_raw, "bool");
				if (!_cond_oval.has_value ())
					return std::nullopt;
				_if_expr->_conds.push_back (_cond_oval.value ());
			}

			// 计算期望类型
			std::vector<std::string> _exp_types;
			for (auto _body_raw : _expr_raw->quotStmtExpr ()) {
				// 在虚拟环境中计算类型，避免影响真实环境
				if (!_func_ctx.CreateVirtualEnv<bool> ([&] () {
					// 遍历代码，寻找所有新定义变量，在计算最后表达式类型时可能需要用到
					auto _stmts = _body_raw->stmt ();
					if (!StmtBuilder (_func_ctx, _stmts))
						return false;

					// 获取表达式类型
					//_if_expr->_bodys1_raw.push_back (_body_raw->stmt ());
					auto _stmt_oval = _parse_expr (_body_raw->expr (), _exp_type);
					if (!_stmt_oval.has_value ())
						return false;
					//_if_expr->_bodys2.push_back (_stmt_oval.value ());
					_exp_types.push_back (_stmt_oval.value ().GetExpectType ());
					return true;
				}))
					return std::nullopt;
			}
			auto _real_exp_otype = TypeMap::GetCompatibleType (_expr_raw->start, _exp_types);
			if (!_real_exp_otype.has_value ())
				return std::nullopt;
			_if_expr->_expect_type = _real_exp_otype.value ();

			// 根据真实期望类型生成代码
			for (auto _body_raw : _expr_raw->quotStmtExpr ()) {
				_if_expr->_bodys1_raw.push_back (_body_raw->stmt ());
				_if_expr->_bodys2.push_back (_body_raw->expr ());
			}
			return _if_expr;
		};

		// 解析并生成新语法树
		std::optional<_AST_ExprOrValue> _oev = _parse_expr (_expr_raw, _expect_type);
		if (!_oev.has_value ())
			return std::nullopt;
		_AST_ExprOrValue _ev = _oev.value ();

		// 转换类型
		std::function<AstValue (AstValue, std::string)> _trans_type = [] (AstValue _val, std::string _exp_type) -> AstValue {
			// TODO
			return _val;
		};

		// 生成代码
		std::function<std::optional<std::tuple<AstValue, std::string>> (_AST_ExprOrValue _ast_ev)> _generate_code;
		_generate_code = [&] (_AST_ExprOrValue _ast_ev) -> std::optional<std::tuple<AstValue, std::string>> {
			std::string _rexp_type = _ast_ev.GetExpectType ();
			if (_ast_ev._val) {
				auto _left = _trans_type (_ast_ev._val->_val, _rexp_type);
				return std::make_tuple (_left, _rexp_type);
			} else if (_ast_ev._op1_expr) {
				auto _oleft = _generate_code (_ast_ev._op1_expr->_left);
				if (!_oleft.has_value ())
					return std::nullopt;
				auto [_left, _exp_type] = _oleft.value ();
				_left = _trans_type (_left, _exp_type);
				auto _val = _func_ctx.DoOper1 (_left, _ast_ev._op1_expr->_op._op, _ast_ev._op1_expr->_op._t);
				return std::make_tuple (_val, _rexp_type);
			} else if (_ast_ev._op2_expr) {
				auto _oleft = _generate_code (_ast_ev._op2_expr->_left);
				if (!_oleft.has_value ())
					return std::nullopt;
				auto [_left, _exp_type] = _oleft.value ();
				_left = _trans_type (_left, _exp_type);
				//
				auto _oright = _generate_code (_ast_ev._op2_expr->_right);
				if (!_oright.has_value ())
					return std::nullopt;
				auto [_right, _exp_type2] = _oright.value ();
				_right = _trans_type (_right, _exp_type2);
				//
				auto _val = _func_ctx.DoOper2 (_left, _ast_ev._op2_expr->_op._op, _right, _ast_ev._op2_expr->_op._t);
				_val = _trans_type (_val, _rexp_type);
				return std::make_tuple (_val, _rexp_type);
			} else if (_ast_ev._opN_expr) {
				if (_ast_ev._opN_expr->_op._op == "()") {
					auto _oobj = _generate_code (_ast_ev._opN_expr->_left);
					if (!_oobj.has_value ())
						return std::nullopt;
					AstValue _obj = std::get<0> (_oobj.value ());
					std::vector<std::string> _arg_types = std::get<1> (_obj.GetFuncType ());
					std::vector<AstValue> _args;
					for (size_t i = 0; i < _arg_types.size (); ++i) {
						auto _oarg = _generate_code (_ast_ev._opN_expr->_rights [i]);
						if (!_oarg.has_value ())
							return std::nullopt;
						auto _arg = _trans_type (std::get<0> (_oarg.value ()), _arg_types [i]);
						_args.push_back (_arg);
					}
					AstValue _val = _func_ctx.FuncInvoke (_obj, _args);
					_val = _trans_type (_val, _rexp_type);
					return std::make_tuple (_val, _rexp_type);
				} else if (_ast_ev._opN_expr->_op._op == "[]") {
					// TODO
					LOG_TODO (_ast_ev._opN_expr->_op._t);
					return std::nullopt;
				} else {
					LOG_TODO (_ast_ev._opN_expr->_op._t);
					return std::nullopt;
				}
			} else if (_ast_ev._if_expr) {
				AstValue _var_temp = _func_ctx.DefineVariable (_rexp_type, _ast_ev._if_expr->_bodys2 [0]->start);
				//
				std::function<bool ()> _process_first_block = [&] () {
					if (!StmtBuilder (_func_ctx, _ast_ev._if_expr->_bodys1_raw [0]))
						return false;
					_ast_ev._if_expr->_bodys1_raw.erase (_ast_ev._if_expr->_bodys1_raw.begin ());
					AstValue _block_ret = ExprBuilder (_func_ctx, _ast_ev._if_expr->_bodys2 [0], _rexp_type);
					if (!_block_ret.IsValid ())
						return false;
					AstValue _ret = _func_ctx.DoOper2 (_var_temp, "=", _block_ret, _ast_ev._if_expr->_bodys2 [0]->start);
					if (!_ret.IsValid ())
						return false;
					_ast_ev._if_expr->_bodys2.erase (_ast_ev._if_expr->_bodys2.begin ());
					return true;
				};
				//
				std::function<bool ()> _generate_ifexpr;
				_generate_ifexpr = [&] () -> bool {
					if (_ast_ev._if_expr->_conds.size () > 0) {
						// if {} else
						auto _ocond = _generate_code (_ast_ev._if_expr->_conds [0]);
						if (!_ocond.has_value ())
							return false;
						_ast_ev._if_expr->_conds.erase (_ast_ev._if_expr->_conds.begin ());
						auto _cond = std::get<0> (_ocond.value ());
						return _func_ctx.IfElse (_cond, [&] () -> bool {
							return _process_first_block ();
						}, [&] () -> bool {
							return _generate_ifexpr ();
						});
					} else {
						// else {}
						return _process_first_block ();
					}
				};
				if (!_generate_ifexpr ())
					return std::nullopt;
				return std::make_tuple (_var_temp, _rexp_type);
			}
			LOG_TODO (nullptr);
			return std::nullopt;
		};
		auto _oret = _generate_code (_ev);
		if (!_oret.has_value ())
			return std::nullopt;
		return std::get<0> (_oret.value ());
	}

	std::optional<std::shared_ptr<ClassType>> FindClassType (FuncContext &_func_ctx, std::string _raw_name) {
		// TODO 如果没找到，但有 . 运算符，那么递归
		return std::nullopt;
	}

	AstValue FindValueType (FuncContext &_func_ctx, std::string _raw_name) {
		size_t _p = _raw_name.rfind ('.');
		if (_p != std::string::npos) {
			// 包含 . 运算符，前半段可能是类或对象
			auto _oct = FindClassType (_func_ctx, _raw_name.substr (0, _p));
			if (_oct.has_value ()) {
				auto _ovar = _oct.value ()->GetVar (_raw_name.substr (_p + 1));
				if (_ovar.has_value ()) {
					// TODO
				}
			}
		} else {
			// 不包含 . 运算符，可能是变量、类方法或类属性
			return _func_ctx.GetVariable (_raw_name);
		}
		return std::nullopt;
	}

	CodeVisitor *m_visitor = nullptr;
	std::string m_module_name;
	std::shared_ptr<llvm::LLVMContext> m_ctx;
	std::shared_ptr<llvm::Module> m_module;
	std::shared_ptr<TypeMap> m_type_map;
	std::shared_ptr<ValueBuilder> m_value_builder;
	std::shared_ptr<FuncTypes> m_global_funcs;
	std::shared_ptr<ClassTypes> m_global_classes;

	std::vector<std::string> m_uses;
	std::vector<std::string> m_libs;
};



#endif //__FA_LLVM_GEN_HPP__
