#ifndef __CLASS_TYPE_HPP__
#define __CLASS_TYPE_HPP__



#include <map>
#include <memory>
#include <optional>
#include <string>

#include "AstValue.hpp"

#include <llvm/IR/Type.h>



enum class PublicLevel { Public, Internal, Protected, Private };

class ClassField {
public:
	std::string					m_name;
	std::string					m_type_name;
	llvm::Type					*m_type;

	ClassField (std::string _name, std::string _type_name, llvm::Type *_type): m_name (_name), m_type_name (_type_name), m_type (_type) {}
};



class ClassType {
public:
	PublicLevel					m_level;
	std::string					m_name;
	std::vector<std::string>	m_parents;
	std::vector<ClassField>		m_fields;
	llvm::Type					*m_type = nullptr;

	ClassType (PublicLevel _level, std::string _name): m_level (_level), m_name (_name) {}
	void AddParent (std::string _name) {
		m_parents.push_back (_name);
	}
	void AddField (std::string _name, std::string _type_name, llvm::Type *_type) {
		m_fields.push_back (ClassField { _name, _type_name, _type });
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
