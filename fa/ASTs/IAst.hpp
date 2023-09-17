#ifndef __INC_HPP__
#define __INC_HPP__



#include <cstdint>
#include <optional>
#include <string>

#include "../../fa_compile_runtime/fa_compile_runtime.hpp"



struct PAstExpr;
struct PAstStmt;
struct PAstType;
using AstValue_t = std::variant<bool, int64_t, uint64_t, double, std::string, PAstExpr, PAstStmt, PAstType>;
inline static std::map<size_t, std::string> s_literal_name { { 0, "bool"}, { 1, "int"}, { 2, "uint"}, { 3, "double"}, { 4, "string"}, { 5, "expr"}, { 6, "stmt"}, { 7, "type"}, };
struct AstValueCmp_t {
	[[nodiscard]]
	bool operator()(const AstValue_t &_Left, const AstValue_t &_Right) const;
};



inline std::string GenCppCode (fa::PublicLevel _level) {
	return _level == fa::PublicLevel::Protected ? "protected" : (_level == fa::PublicLevel::Private ? "private" : "public");
}



//struct std::vector<PAstStmt>: std::vector<PAstStmt> {
//	std::vector<PAstStmt> m_after;
//
//	std::vector<PAstStmt> () {}
//	std::vector<PAstStmt> (PAstStmt _stmt);
//
//	void Pure () {
//		insert (end (), m_after.begin (), m_after.end ());
//		m_after.clear ();
//	}
//
//	void Append (const std::vector<PAstStmt> &_other) {
//		Pure ();
//		insert (end (), _other.begin (), _other.end ());
//		insert (end (), _other.m_after.begin (), _other.m_after.end ());
//	}
//
//	void Swap (std::vector<PAstStmt> &_other) {
//		swap (_other);
//		m_after.swap (_other.m_after);
//	}
//
//	void Clear () {
//		clear ();
//		m_after.clear ();
//	}
//};



struct IAst: public fa::AstObj {
	IAst (antlr4::Token *_token): fa::AstObj (_token) {}



	void SetMembers (fa::ParseType _type, std::vector<AstObj *> _values) override {
		throw fa::Exception (m_token, "not implement");
	}
	std::vector<AstObj *> GetMembers (fa::ParseType _type) override {
		throw fa::Exception (m_token, "not implement");
	}
	void SetValues (fa::ParseValueType _type, std::vector<fa::ParseValue_t> _values) override {
		throw fa::Exception (m_token, "not implement");
	}
	std::vector<fa::ParseValue_t> GetValues (fa::ParseValueType _type) override {
		throw fa::Exception (m_token, "not implement");
	}
};



#endif //__INC_HPP__
