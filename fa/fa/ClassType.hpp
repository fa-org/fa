#ifndef __CLASS_TYPE_HPP__
#define __CLASS_TYPE_HPP__



#include <map>
#include <memory>
#include <optional>
#include <string>

//#include "AstValue.hpp"

#include <llvm/IR/Type.h>



enum class PublicLevel { Unknown, Public, Internal, Protected, Private };

class ClassType;



class ClassVar {
public:
	std::shared_ptr<ClassType>	m_parent;
	std::string					m_name;
	std::string					m_type_name;
	llvm::Type					*m_type;

	ClassVar (std::shared_ptr<ClassType> _parent, std::string _name, std::string _type_name, llvm::Type *_type)
		: m_parent (_parent), m_name (_name), m_type_name (_type_name), m_type (_type) {}
};



class ClassFunc {
public:
	ClassFunc () {}
};



class ClassType: public std::enable_shared_from_this<ClassType> {
public:
	PublicLevel								m_level;
	std::string								m_name;
	std::vector<std::string>				m_parents;
	std::vector<std::shared_ptr<ClassVar>>	m_vars;
	llvm::Type								*m_type = nullptr;

	ClassType (PublicLevel _level, std::string _name): m_level (_level), m_name (_name) {}
	void AddParents (std::vector<std::string> &_parents) {
		m_parents.assign (_parents.cbegin (), _parents.cend ());
	}
	void AddVar (std::string _name, std::string _type_name, llvm::Type *_type) {
		m_vars.push_back (std::make_shared<ClassVar> (shared_from_this (), _name, _type_name, _type));
	}

	std::optional<std::shared_ptr<ClassVar>> GetVar (std::string _name) {
		for (auto _var : m_vars) {
			if (_var->m_name == _name)
				return _var;
		}
		return std::nullopt;
	}
};



class ClassTypes {
public:
	std::optional<std::shared_ptr<ClassType>> GetClass (std::string _name) {
		if (m_classes.contains (_name)) {
			return m_classes [_name];
		} else {
			return std::nullopt;
		}
	}
	std::shared_ptr<ClassType> CreateNewClass (PublicLevel _level, std::string _name) {
		auto _cls = std::make_shared<ClassType> (_level, _name);
		m_classes [_name] = _cls;
		return _cls;
	}

private:
	std::map<std::string, std::shared_ptr<ClassType>> m_classes;
};



#endif //__CLASS_TYPE_HPP__
