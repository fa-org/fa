#include "pch.h"

#include "../Blocks/AstClass.hpp"
#include "../Blocks/AstProgram.hpp"
#include "../../Common/CompileEnv.hpp"
#include "../Blocks/AstClassFunc.hpp"
#include "../Blocks/AstClassFuncEmpty.hpp"
#include "../Exprs/BuildIns/IAstBuildInExpr.hpp"
#include "../Exprs/AstExpr_array2.hpp"
#include "../Exprs/AstExpr_invoke.hpp"
#include "../Exprs/AstExpr_temp_name.hpp"
#include "../Exprs/AstExpr_this.hpp"
#include "../Exprs/AstExpr_type_wrap.hpp"
#include "../Exprs/IAstExpr.hpp"
#include "../Exprs/NameExprs/AstNameExpr_arg.hpp"
#include "../Exprs/NameExprs/AstNameExpr_class_var.hpp"
#include "../Exprs/NameExprs/AstNameExpr_enum_item.hpp"
#include "../Exprs/NameExprs/AstNameExpr_class_func.hpp"
#include "../Exprs/NameExprs/AstNameExpr_var.hpp"
#include "../Stmts/AstStmt_define_var.hpp"
#include "../Types/AstType_any.hpp"
#include "../Types/AstType_bool.hpp"
#include "../Types/AstType_class.hpp"
#include "../Types/AstType_class_template_item.hpp"
#include "../Types/AstType_float.hpp"
#include "../Types/AstType_func_template.hpp"
#include "../Types/AstType_int.hpp"
#include "../Types/AstType_temp_name.hpp"
#include "../Types/AstType_void.hpp"
#include "../Types/IAstType.hpp"



bool AstValueCmp_t::operator()(const AstValue_t &_Left, const AstValue_t &_Right) const {
	if (_Left.index () != _Right.index ()) {
		return _Left.index () < _Right.index ();
	} else if (_Left.index () == 5) {
		return std::get<5> (_Left)->m_token < std::get<5> (_Right)->m_token;
	} else if (_Left.index () == 6) {
		return std::get<6> (_Left)->m_token < std::get<6> (_Right)->m_token;
	} else if (_Left.index () == 7) {
		return std::get<7> (_Left)->m_token < std::get<7> (_Right)->m_token;
	} else {
		return _Left < _Right;
	}
}



std::optional<PAstExpr> CompileEnv::FindName (antlr4::Token *_token, std::string _name, std::vector<PAstType> _templates) {
	if (_name == "null") {
		_name = "fa.Option.Null";
	} else if (_name == "string") {
		_name = "fa.String";
	} else if (_name == "type") {
		_name = "fa.Type";
	} else if (_name == "dict") {
		_name = "fa.Dictionary";
	} else if (_name == "List") {
		_name = "fa.List";
	}
	size_t _r = _name.rfind ('.');
	if (_r == std::string::npos) {
		static std::map<std::string, std::function<PAstType (antlr4::Token *_token)>> s_type_creators {
			{ "void",    [] (antlr4::Token *_token) { return AstType_void::Make (_token); } },
			{ "Any",     [] (antlr4::Token *_token) { return AstType_any::Make (_token); } },
			{ "bool",    [] (antlr4::Token *_token) { return AstType_bool::Make (_token); } },
			{ "float32", [] (antlr4::Token *_token) { return AstType_float::Make (_token, 32); } },
			{ "float64", [] (antlr4::Token *_token) { return AstType_float::Make (_token, 64); } },
			{ "int8",    [] (antlr4::Token *_token) { return AstType_int::Make (_token, 8, true); } },
			{ "uint8",   [] (antlr4::Token *_token) { return AstType_int::Make (_token, 8, false); } },
			{ "int16",   [] (antlr4::Token *_token) { return AstType_int::Make (_token, 16, true); } },
			{ "uint16",  [] (antlr4::Token *_token) { return AstType_int::Make (_token, 16, false); } },
			{ "int32",   [] (antlr4::Token *_token) { return AstType_int::Make (_token, 32, true); } },
			{ "uint32",  [] (antlr4::Token *_token) { return AstType_int::Make (_token, 32, false); } },
			{ "int64",   [] (antlr4::Token *_token) { return AstType_int::Make (_token, 64, true); } },
			{ "uint64",  [] (antlr4::Token *_token) { return AstType_int::Make (_token, 64, false); } },
			{ "int",     [] (antlr4::Token *_token) { return AstType_int::Make (_token, 32, true); } },
			{ "uint",    [] (antlr4::Token *_token) { return AstType_int::Make (_token, 32, false); } },
			//{ "string",  [] (antlr4::Token *_token) { return AstType_string::Make (_token); } }
		};
		if (s_type_creators.contains (_name))
			return AstExpr_type_wrap::Make (_token, s_type_creators [_name] (_token));

		// 特殊名称
		if (_name == "this") {
			return AstExpr_this::Make (_token, CompileEnv::CurrentClass, {});
		}

		// 查找参数
		if (CompileEnv::CurrentFunc) {
			for (size_t i = 0; i < CompileEnv::CurrentFunc->m_arg_names.size (); ++i) {
				if (_name == CompileEnv::CurrentFunc->m_arg_names [i])
					return CompileEnv::CurrentFunc->GetArgumentRef (_token, i);
			}

			// 查找变量或类型
			if (auto _oexpr = CompileEnv::CurrentFuncVariables.FindVarOrArgument (_name); _oexpr != std::nullopt) {
				return _oexpr.value ();
			}

			// 查找模板类型
			for (size_t i = 0; i < CompileEnv::CurrentFunc->m_tpl_names.size (); ++i) {
				if (CompileEnv::CurrentFunc->m_tpl_names [i] == _name) {
					return AstExpr_type_wrap::Make (_token, AstType_func_template::Make (_token, CompileEnv::CurrentFunc, i));
				}
			}
		}

		// 查找当前类
		if (CompileEnv::CurrentClass) {
			std::optional<PAstExpr> _this = AstExpr_this::Make (_token, CompileEnv::CurrentClass, {});
			if (auto p = CompileEnv::CurrentClass->m_vars.find (_name); p != CompileEnv::CurrentClass->m_vars.end ())
				return AstNameExpr_class_var::Make (_token, _this, CompileEnv::CurrentClass, {}, _name);
			if (auto p = CompileEnv::CurrentClass->m_funcs.find (_name); p != CompileEnv::CurrentClass->m_funcs.end ())
				return AstNameExpr_class_func::Make (_token, _this, p->second, {}, {});

			// 查找模板类型
			for (size_t i = 0; i < CompileEnv::CurrentClass->m_tpl_names.size (); ++i) {
				if (CompileEnv::CurrentClass->m_tpl_names [i] == _name) {
					return AstExpr_type_wrap::Make (_token, AstType_class_template_item::Make (_token, CompileEnv::CurrentClass, i));
				}
			}
		}

		if (CompileEnv::AstProgram) {
			// 查找类型
			if (CompileEnv::AstProgram->m_types.contains (_name)) {
				return AstExpr_type_wrap::Make (_token, CompileEnv::AstProgram->m_types.at (_name));
			}

			// 查找当前类
			if (CompileEnv::AstProgram->m_classes.contains (_name)) {
				return AstExpr_type_wrap::Make (_token, AstType_class::Make (_token, CompileEnv::AstProgram->m_classes [_name], {}));
			}
		}
	} else {
		std::string _left_part = _name.substr (0, _r), _right_part = _name.substr (_r + 1);
		auto _oparent = FindName (_token, _left_part, {});
		if (_oparent.has_value ()) {
			return FindName (_oparent.value (), _right_part, _templates);
		} else if (_left_part == CompileEnv::AstProgram->m_namespace) {
			// TODO 查找所有命名空间

			// 查找类型
			if (CompileEnv::AstProgram->m_types.contains (_right_part)) {
				return AstExpr_type_wrap::Make (_token, CompileEnv::AstProgram->m_types.at (_right_part));
			}

			// 查找当前类
			if (CompileEnv::AstProgram->m_classes.contains (_right_part)) {
				return AstExpr_type_wrap::Make (_token, AstType_class::Make (_token, CompileEnv::AstProgram->m_classes [_right_part], {}));
			}
		}
		return std::nullopt;
	}
	return std::nullopt;
}

std::optional<PAstExpr> CompileEnv::FindName (PAstExpr _parent, std::string _name, std::vector<PAstType> _templates) {
	std::optional<PAstType> _ottype = std::nullopt;
	if (auto _tparent = dynamic_cast<AstExpr_type_wrap *> (_parent.get ())) {
		_ottype = _tparent->m_type;
	} else if (auto _tparent = dynamic_cast<AstExpr_this *> (_parent.get ())) {
		_ottype = _tparent->m_real_type;
	} else if (auto *_tname = dynamic_cast<IAstNameExpr *> (_parent.get ())) {
		_ottype = _tname->m_real_type;
	}
	if (_ottype.has_value ()) {
		PAstType _ttype = _ottype.value ();
		if (AstType_class *_tclass = dynamic_cast<AstType_class *> (_ttype.get ())) {
			if (_tclass->m_class->m_vars.contains (_name))
				return AstNameExpr_class_var::Make (_ttype->m_token, _parent, _tclass->m_class, _tclass->m_template_types, _name);
			if (_tclass->m_class->m_funcs.contains (_name))
				return AstNameExpr_class_func::Make (_ttype->m_token, _parent, _tclass->m_class->m_funcs [_name], _tclass->m_template_types, {});
			for (size_t i = 0; i < _tclass->m_class->m_enum_items.size (); ++i) {
				if (_tclass->m_class->m_enum_items [i]->m_name == _name)
					return AstNameExpr_enumitem::Make (_parent->m_token, std::nullopt, _tclass->m_class, _tclass->m_template_types, i);
			}
		}
	}
	//
	if (auto *_tname2 = dynamic_cast<AstExpr_temp_name *> (_parent.get ())) {
		auto _oparent = FindName (_tname2->m_token, _tname2->m_name, _templates);
		if (_oparent.has_value ())
			return FindName (_oparent.value (), _name, _templates);
	} else if (auto *_tname2 = dynamic_cast<AstType_temp_name *> (_parent.get ())) {
		auto _oparent = FindName (_tname2->m_token, _tname2->m_name, _templates);
		if (_oparent.has_value ())
			return FindName (_oparent.value (), _name, _templates);
	}
	return std::nullopt;
}



std::optional<PAstExpr> Evaluation::CallFunction (antlr4::Token *_token, std::shared_ptr<AstClassFuncEmpty> _func, std::optional<PAstExpr> _this, std::vector<PAstExpr> _args) {
	Evaluation _eval {};
	_eval.m_vars.AddLevel ();
	for (size_t i = 0; i < _func->m_arg_names.size (); ++i)
		_eval.m_vars.Add (AstNameExpr_argument::Make (_args [i]->m_token, _func, i), _args [i]);
	//
	if (_this.has_value ())
		_eval.m_vars.Add (AstExpr_this::Make (_token, _func->m_parent->shared_from_this (), {}), _this.value ());
	//if (_func->m_arg_types.size () > 0) {
	//	size_t _nlast = _func->m_arg_types.size () - 1;
	//	if (_args.size () == _func->m_arg_types.size () && _args [_nlast]->m_real_type->IsSame (_func->m_arg_types [_nlast])) {
	//		_eval.m_vars.AddVariable (_func->m_arg_names [_nlast], _args [_nlast]);
	//	} else {
	//		std::vector<PAstExpr> _last_arg;
	//		_last_arg.insert (_last_arg.begin (), _args.begin () + _nlast, _args.end ());
	//		auto _last_expr = AstExpr_array2::Make (_token, _last_arg);
	//		_eval.m_vars.AddVariable (_func->m_arg_names [_nlast], _last_expr);
	//	}
	//}
	//
	std::optional<PAstExpr> _oret = std::nullopt;
	if (auto _pfunc = dynamic_cast<AstClassFunc *> (_func.get ())) {
		for (size_t i = 0; i < _pfunc->m_contents.size (); ++i) {
			_pfunc->m_contents [i]->Evaluate (_eval);
			if (_eval.m_return)
				_oret = _eval.m_return_expr;
		}
	} else {
		bool build_in = false;
		for (auto &anno : _func->m_anno_parts) {
			if (anno->m_parent->m_full_name == "fa.BuildIn") {
				build_in = true;
				break;
			}
		}
		if (!build_in) {
			for (auto &anno : _func->m_parent->m_anno_parts) {
				if (anno->m_parent->m_full_name == "fa.BuildIn") {
					build_in = true;
					break;
				}
			}
		}
		if (build_in) {
			auto _obuildin = IAstBuildInExpr::CreateBuildInExpr (_token, _func->m_parent->m_full_name, {});
			if (_obuildin.has_value ()) {
				auto _buildin = dynamic_cast<IAstBuildInExpr *> (_obuildin.value ().get ());
				_oret = _buildin->Invoke (_eval, _func->m_name, _args);
			} else {
				throw fa::Exception (_token, "not implement");
			}
		} else {
			throw fa::Exception (_token, "not implement");
		}
	}
	_eval.m_vars.RemoveLevel ();
	return _oret;
}



void StackVariables::AddFunc (std::shared_ptr<AstClassFuncEmpty> _func) {
	m_stack.push_back ((PVariableItems) (VariableItems *) new FunctionEntry { _func });
	AddLevel ();
}
void StackVariables::RemoveFunc (std::shared_ptr<AstClassFuncEmpty> _func) {
	RemoveLevel ();
	if (auto _sfunc = dynamic_cast<FunctionEntry *> (m_stack.rbegin ()->get ())) {
		if (_sfunc->m_func->m_name == _func->m_name) {
			m_stack.pop_back ();
			return;
		}
	}
	throw fa::Exception (_func->m_token, "not implement");
}
void StackVariables::AddLevel () {
	m_stack.push_back (std::make_shared<VariableItems> ());
}
void StackVariables::RemoveLevel () {
	if (auto _sfunc = dynamic_cast<FunctionEntry *> (m_stack.rbegin ()->get ()))
		throw fa::Exception (nullptr, "not implement");
	m_stack.pop_back ();
}
void StackVariables::AddArgument (std::string _name, PAstExpr _value) {
	for (auto it = m_stack.rbegin (); it != m_stack.rend (); ++it) {
		if (dynamic_cast<FunctionEntry *> (it->get ())) {
			(*it)->Add (_name, _value);
			return;
		}
	}
	throw fa::Exception (nullptr, "not implement");
}
void StackVariables::AddVariable (std::string _name, PAstExpr _value) {
	for (auto it = m_stack.rbegin (); it != m_stack.rend (); ++it) {
		if (!dynamic_cast<FunctionEntry *> (it->get ())) {
			(*it)->Add (_name, _value);
			return;
		}
	}
	throw fa::Exception (nullptr, "not implement");
}
std::optional<PAstExpr> StackVariables::FindVarOrArgument (std::string _name) {
	for (auto it = m_stack.rbegin (); it != m_stack.rend (); ++it) {
		if (auto _ofind = (*it)->Find (_name); _ofind != std::nullopt)
			return _ofind.value ();
	}
	return std::nullopt;
}
PAstExpr StackVariables::FindArgument (std::shared_ptr<AstClassFuncEmpty> _func, std::string _name) {
	for (auto it = m_stack.rbegin (); it != m_stack.rend (); ++it) {
		if (auto _sfunc = dynamic_cast<FunctionEntry *> (it->get ()); _sfunc != nullptr && _sfunc->m_func.get () == _func.get ()) {
			auto _oret = (*it)->Find (_name);
			if (_oret.has_value ())
				return _oret.value ();
			break;
		}
	}
	throw fa::Exception (nullptr, "not implement");
}
PAstExpr StackVariables::FindVariable (std::string _name) {
	for (auto it = m_stack.rbegin (); it != m_stack.rend (); ++it) {
		if (!dynamic_cast<FunctionEntry *> (it->get ())) {
			auto _oret = (*it)->Find (_name);
			if (_oret.has_value ())
				return _oret.value ();
			break;
		}
	}
	throw fa::Exception (nullptr, "not implement");
}
