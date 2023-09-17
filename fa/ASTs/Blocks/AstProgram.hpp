#ifndef __AST_PROGRAM_HPP__
#define __AST_PROGRAM_HPP__



#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "AstClass.hpp"
#include "AstClassFuncEmpty.hpp"
#include "AstUse.hpp"
#include "IAstBlock.hpp"
#include "../Types/AstType_unsure_wrap.hpp"
#include "../Types/IAstType.hpp"
#include "../../common/CompileEnv.hpp"



struct AstProgram: public IAstBlock {
	std::set<PAstUse> m_uses;
	std::string m_namespace = "";
	std::map<std::string, PAstType> m_types;
	std::map<std::string, std::shared_ptr<AstClass>> m_classes;

	AstProgram (antlr4::Token *_token): IAstBlock (_token) {
		//for (auto &_use_stmt : _ctx->useStmt ())
		//	m_uses [fa::GetId (_use_stmt->Id ())] = fa::GetId (_use_stmt->ids ());
		//if (_ctx->namespaceStmt ())
		//	m_namespace = fa::GetId (_ctx->namespaceStmt ()->ids ());
		//for (auto &_type_ctx : _ctx->defTypeStmt ()) {
		//	std::string type_name = fa::GetId (_type_ctx->Id ());
		//	m_types.emplace (type_name, AstType_unsure_wrap::Make (_type_ctx->start, IAstType::FromCtxs (_type_ctx->type ()), type_name));
		//}
		//for (auto &_anno_ctx : _ctx->annotationBlock ()) {
		//	auto _anno = AstAnno::FromCtx (_anno_ctx);
		//	m_annos [_anno->m_name] = _anno;
		//}
		//for (auto &_enum_ctx : _ctx->enumBlock ()) {
		//	auto _enum = AstEnum::FromCtx (_enum_ctx);
		//	if (m_classes.contains (_enum->m_name))
		//		throw fa::Exception (_enum->m_token, "重定义的符号：{}", _enum->m_name);
		//	m_classes [_enum->m_name] = _enum;
		//}
		//for (auto &_class_ctx : _ctx->classBlock ()) {
		//	auto _class = ::FromCtx (_class_ctx);
		//	if (m_classes.contains (_class->m_name))
		//		throw fa::Exception (_class->m_token, "重定义的符号：{}", _class->m_name);
		//	m_classes [_class->m_name] = _class;
		//}
	}

	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		if (_type == fa::ParseValueType::Namespace) {
			m_namespace = std::get<std::string> (_values [0]);
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		if (_type == fa::ParseType::Use) {
			for (auto _value : _values)
				m_uses.emplace (std::shared_ptr<AstUse> (dynamic_cast<AstUse *> (_value)));
		} else if (_type == fa::ParseType::Type) {
			for (auto _value : _values) {
				auto _ast_type = dynamic_cast<AstType_unsure_wrap *> (_value);
				m_types.emplace (_ast_type->m_name, std::shared_ptr<IAstType> ((IAstType *) _ast_type));
			}
		} else if (_type == fa::ParseType::Anno || _type == fa::ParseType::Enum || _type == fa::ParseType::Class) {
			for (auto _value : _values) {
				auto _cls = std::shared_ptr<AstClass> (dynamic_cast<AstClass *> (_value));
				m_classes.emplace (_cls->m_name, _cls);
			}
		} else {
			throw fa::Exception (m_token, "not implement");
		}
	}

	void ProcessDeclareType () override {
		CompileEnv::CurrentClass = nullptr;
		CompileEnv::CurrentFunc = nullptr;
		//
		for (auto &[_type_name, _type] : m_types)
			_type = _type->ProcessDeclareType ();
		for (auto &[_class_name, _class] : m_classes)
			_class->ProcessDeclareType ();
	}

	void ProcessCodeType () override {
		CompileEnv::CurrentClass = nullptr;
		CompileEnv::CurrentFunc = nullptr;
		for (auto &[_class_name, _class] : m_classes)
			_class->ProcessCodeType ();
	}
};



#endif //__AST_PROGRAM_HPP__
