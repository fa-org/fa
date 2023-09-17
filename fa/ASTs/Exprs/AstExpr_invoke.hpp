#ifndef __AST_EXPR_INVOKE_HPP__
#define __AST_EXPR_INVOKE_HPP__



#include <memory>
#include <optional>
#include <sstream>
#include <string>

#include "IAstExpr.hpp"
#include "AstExpr_temp_name.hpp"
#include "NameExprs/AstNameExpr_class_func.hpp"
#include "../Blocks/AstClassFuncEmpty.hpp"
#include "../Stmts/IAstStmt.hpp"
#include "../Types/AstType_func.hpp"
#include "../../common/Evaluation.hpp"



struct AstExpr_invoke: public IAstExpr {
	PAstExpr m_func;
	std::vector<PAstExpr> m_args;

	AstExpr_invoke (antlr4::Token *_token): IAstExpr (_token), m_func (nullptr) {}
	//AstExpr_invoke (antlr4::Token *_token, PAstExpr _func, std::optional<PAstExpr> _base, std::vector<PAstExpr> _args, std::string _op):
	//	IAstExpr (_token), m_func (_func), m_args (_args), m_op (_op) {}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Part_Func) {
			m_func = std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_values [0]));
		} else if (_type == fa::ParseType::Part_FuncArg) {
			for (auto _value : _values)
				m_args.push_back (std::shared_ptr<IAstExpr> (dynamic_cast<IAstExpr *> (_value)));
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	std::optional<PAstType> GuessType () override {
		auto _otype = m_func->GuessType ();
		if (_otype.has_value ()) {
			_otype = m_func->m_real_type.has_value () ? m_func->m_real_type : m_func->GuessType ();
			if (_otype.has_value ()) {
				if (auto _func_type = dynamic_cast<AstType_func *> (_otype.value ().get ())) {
					return _func_type->m_ret_type;
				//} else if (auto _cls_type = dynamic_cast<AstType_class *> (_otype.value ().get ())) {
				//	if (m_op == "[]") {
				//		auto _ofunc = CompileEnv::FindName (m_func, "operator[]");
				//		if (_ofunc.has_value ()) {
				//			m_func = _ofunc.value ();
				//			if (auto _ptmpname = dynamic_cast<AstExpr_temp_name *>(m_func.get ()); _ptmpname != nullptr && _ptmpname->m_name == "_data") {
				//				m_func = m_func;
				//			}
				//			if (auto _func_type = dynamic_cast<AstType_func *> (_ofunc.value ()->m_real_type.value ().get ())) {
				//				return _func_type->m_ret_type;
				//			}
				//		}
				//	}
				}
			}
		}
		throw fa::Exception (m_token, "not implement");
	}

	PAstExpr ProcessCodeType (std::optional<PAstType> _type) override {
		m_func = m_func->ProcessCodeType (std::nullopt);
		auto _process_args = [&] (AstType_func *_func_type) -> PAstExpr {
			for (size_t i = 0; i < _func_type->m_arg_types.size (); ++i) {
				std::optional<PAstType> _arg_type = std::nullopt;
				if (i >= _func_type->m_arg_types.size () - 1) {
					auto _arg_prefix = *_func_type->m_arg_attrs.rbegin ();
					if (_arg_prefix == fa::ArgAttr::Params || _arg_prefix == fa::ArgAttr::Disperse) {
						//auto _arrtype = dynamic_cast<AstType_class *> (_func_type->m_arg_types.rbegin ()->get ());
						//if (_arrtype && _arrtype->m_type_name == "fa.List")
						//	_arg_type = _arrtype->m_template_types [0];
						throw fa::Exception (m_token, "not implement");
					}
				}
				_arg_type = _arg_type.has_value () ? _arg_type : _func_type->m_arg_types [i];
				bool _needsure = _arg_type.value ()->NeedSure ();
				m_args [i] = m_args [i]->ProcessCodeType (_arg_type.value ());
			}
			m_real_type = _func_type->m_ret_type;
			return shared_from_this ();
		};
		if (auto _func_type = dynamic_cast<AstType_func *> (m_func->m_real_type.value ().get ())) {
			return _process_args (_func_type);
		//} else if (auto _cls_type = dynamic_cast<AstType_class *> (m_func->m_real_type.value ().get ())) {
		//	if (m_op == "[]") {
		//		auto _ofunc = CompileEnv::FindName (m_func, "operator[]");
		//		if (_ofunc.has_value ()) {
		//			m_func = _ofunc.value ();
		//			if (auto _func_type = dynamic_cast<AstType_func *> (_ofunc.value ()->m_real_type.value ().get ())) {
		//				return _process_args (_func_type);
		//			}
		//		}
		//	}
		}
		throw fa::Exception (m_token, "not implement");
	}

	std::optional<PAstExpr> Evaluate (Evaluation &_eval) override {
		if (auto _func = dynamic_cast<AstNameExpr_class_func *> (m_func.get ())) {
			for (auto &_arg : m_args)
				_arg = _arg->Evaluate (_eval).value ();
			return Evaluation::CallFunction (m_token, _func->m_func, _func->m_base, m_args);
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	//static PAstExpr Make (antlr4::Token *_token, PAstExpr _func, std::optional<PAstExpr> _base, std::vector<PAstExpr> _args, std::string _op) {
	//	return std::shared_ptr<IAstExpr> (new AstExpr_invoke { _token, _func, _base, _args, _op });
	//}
};



#endif //__AST_EXPR_INVOKE_HPP__
