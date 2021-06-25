#ifndef __FAGENAST_HPP__
#define __FAGENAST_HPP__



#include <string>

#include <Facc/IEnumerator.hpp>
#include <Facc/Grammar/ASTGenerator.hpp>



class FaGenAST {
public:
	static void generate () {
		std::string _grammar = R"(
id					::= [a-zA-Z\x80-\xff_][0-9a-zA-Z\x80-\xff_]*
ids					::= id ('.' id)*
s					::= ([ \t\r\n] | ('\x30\x30' ^'\n' '\n') | ('\x30*' ^'*\x30' '*\x30'))*
public_opt			::= ('public' | 'internal' | 'protected' | 'private')?

type_tuple			::= '(' type id? (',' type id?)+ ')'
type_generic		::= ids '<' type (',' type)* '>'
type_ext			::= type ('[]' | '&' | '?')+
type				::= s (ids | type_tuple | type_generic | type_ext) s
func_args			::= (s type s id (s ',' s type s id)*)?

use_expr			::= s 'use' s ids s ';'
func_expr			::= '(' func_args ')' s '{}'
class_item_expr		::= s public_opt s type s id s (func_expr | ';')
class_expr			::= s public_opt s 'class' s id (s ':' s ids s (',' s ids)*)? s '{' class_item_expr* s '}'
program				::= use_expr* class_expr* s
)";
		std::string _path = "ASTs";
		AstGenerator _generator { _grammar, _path };
		_generator.ClearPath ();
		_generator.Generate ();
	}
};



#endif //__FAGENAST_HPP__
