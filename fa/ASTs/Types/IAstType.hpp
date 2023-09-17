#ifndef __AST_TYPE_HPP__
#define __AST_TYPE_HPP__



#include <functional>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "../IAst.hpp"



struct AstType_unsure_wrap;



struct IAstType;
struct PAstType: public std::shared_ptr<IAstType> {
	PAstType (std::shared_ptr<IAstType> _type): std::shared_ptr<IAstType> (_type) {}

	bool IsSame (PAstType &_other);
};

struct IAstType: public IAst, public std::enable_shared_from_this<IAstType> {
	IAstType (antlr4::Token *_token): IAst (_token) {}

	virtual PAstType ProcessDeclareType () = 0;
	virtual std::vector<AstType_unsure_wrap *> GetTypeTemplates () = 0;
	virtual bool NeedSure () = 0;
	virtual std::string GetTypeName () = 0;
};



#endif //__AST_TYPE_HPP__
