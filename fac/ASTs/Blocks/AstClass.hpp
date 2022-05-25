#ifndef __AST_CLASS_HPP__
#define __AST_CLASS_HPP__



#include <memory>
#include <string>
#include <vector>

#include "AstClassVar.hpp"
#include "AstClassFunc.hpp"
#include "../../Common.hpp"



struct AstClass {
	PublicLevel m_level;
	std::string m_name = "";
	std::vector<std::shared_ptr<AstClassVar>> m_vars;
	std::vector<std::shared_ptr<AstClassFunc>> m_funcs;

	AstClass (FaParser::ClassBlockContext *_ctx) {
		m_level = GetPublicLevel (_ctx->publicLevel ());
		m_name = _ctx->id ()->getText ();
		for (auto _item : _ctx->classItem ()) {
			if (_item->classItemFuncExt ()) {
				m_funcs.push_back (std::make_shared<AstClassFunc> (_item));
			} else {
				m_vars.push_back (std::make_shared<AstClassVar> (_item));
			}
		}
	}
};



#endif //__AST_CLASS_HPP__
