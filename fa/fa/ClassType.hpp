#ifndef __CLASS_TYPE_HPP__
#define __CLASS_TYPE_HPP__



#include <string>

#include "AstValue.hpp"

#include <llvm/IR/Type.h>



class ClassField {
public:
	std::string					m_name;
	std::string					m_type_name;
	llvm::Type					*m_normal_type;
	std::shared_ptr<FuncType>	m_func_type;
};



class ClassType {
public:
	ClassType (std::string _name): m_name (_name) {}

private:
	std::string					m_name;
	std::vector<ClassField>		m_fields;
};



class ClassTypes {
public:
};



#endif //__CLASS_TYPE_HPP__
