#ifndef __COMPILE_ENV_HPP__
#define __COMPILE_ENV_HPP__



#include <memory>
#include <optional>
#include <variant>
#include <vector>

#include "../ASTs/Types/IAstType.hpp"



struct AstProgram;
struct AstClass;
struct AstClassFuncEmpty;
struct PAstStmt;
struct PAstExpr;
struct PAstType;

struct VariableItems {
	std::map<std::string, PAstExpr> m_vars;

	virtual std::optional<PAstExpr> Find (std::string _name) {
		if (auto _it = m_vars.find (_name); _it != m_vars.end ()) {
			return _it->second;
		} else {
			return std::nullopt;
		}
	}
	virtual void Add (std::string _name, PAstExpr _value) {
		m_vars.emplace (_name, _value);
	}
};
using PVariableItems = std::shared_ptr<VariableItems>;
struct FunctionEntry: public VariableItems {
	std::shared_ptr<AstClassFuncEmpty> m_func;

	FunctionEntry (std::shared_ptr<AstClassFuncEmpty> _func): m_func (_func) {}
};
struct StackVariables {
	std::vector<PVariableItems> m_stack;

	void Clear () { m_stack.clear (); }
	void AddFunc (std::shared_ptr<AstClassFuncEmpty> _func);
	void RemoveFunc (std::shared_ptr<AstClassFuncEmpty> _func);
	void AddLevel ();
	void RemoveLevel ();
	void AddArgument (std::string _name, PAstExpr _value);
	void AddVariable (std::string _name, PAstExpr _value);
	std::optional<PAstExpr> FindVarOrArgument (std::string _name);
	PAstExpr FindArgument (std::shared_ptr<AstClassFuncEmpty> _func, std::string _name);
	PAstExpr FindVariable (std::string _name);
};

struct CompileEnv {
	inline static std::shared_ptr<AstProgram> AstProgram {};

	static std::optional<PAstExpr> FindName (antlr4::Token *_token, std::string _name, std::vector<PAstType> _templates);
	static std::optional<PAstExpr> FindName (PAstExpr _parent, std::string _name, std::vector<PAstType> _templates);

	inline static std::shared_ptr<AstClass> CurrentClass {};
	inline static std::shared_ptr<AstClassFuncEmpty> CurrentFunc {};
	inline static StackVariables CurrentFuncVariables {};

	static void PushEnv () {
		m_pushed_classes.push_back (CurrentClass);
		m_pushed_funcs.push_back (CurrentFunc);
	}

	static void PopEnv () {
		CurrentClass = *m_pushed_classes.rbegin ();
		CurrentFunc = *m_pushed_funcs.rbegin ();
		m_pushed_classes.pop_back ();
		m_pushed_funcs.pop_back ();
	}

private:
	inline static std::vector<std::shared_ptr<AstClass>> m_pushed_classes {};
	inline static std::vector<std::shared_ptr<AstClassFuncEmpty>> m_pushed_funcs {};
};



#endif //__COMPILE_ENV_HPP__
