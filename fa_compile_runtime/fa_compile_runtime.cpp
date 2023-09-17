#include <format>
#include <string>

#include "fa_compile_runtime.hpp"
#include "common/StringWrap.hpp"

#ifdef _MSC_VER
#	pragma warning (push)
#	pragma warning (disable: 4141)
#	pragma warning (disable: 4146)
#	pragma warning (disable: 4244)
#	pragma warning (disable: 4251)
#	pragma warning (disable: 4275)
#	pragma warning (disable: 4624)
#endif

#include "antlr_gen/FaLexer.h"
#include "antlr_gen/FaParser.h"
#include "antlr_gen/FaParserVisitor.h"
#include "antlr_gen/FaParserBaseVisitor.h"

#ifdef _MSC_VER
#	pragma warning (pop)
#endif




namespace fa {
template<typename T>
std::string GetId (T *_ctx, std::string _default = "") { return _ctx ? _ctx->getText () : _default; }
template<typename T>
std::vector<std::string> GetIds (std::vector<T *> _ctxs, std::string _default = "") {
	std::vector<std::string> _v;
	for (auto _ctx : _ctxs)
		_v.push_back (GetId (_ctx));
	return _v;
}
//std::string GetId (FaParser::IdsContext *_ctx, std::string _default = "") { return _ctx ? _ctx->getText () : _default; }
//std::string GetId (FaParser::AllOp2Context *_ctx, std::string _default = "") { return _ctx ? _ctx->getText () : _default; }
//std::string GetId (FaParser::ItemNameContext *_ctx, std::string _default = "") { return _ctx ? _ctx->getText () : _default; }
//std::string GetId (antlr4::tree::TerminalNode *_ctx, std::string _default = "") { return _ctx ? _ctx->getText () : _default; }
ArgAttr GetArgAttr (FaParser::ArgAttrContext *_ctx) {
	if (!_ctx) {
		return ArgAttr::None;
	} else if (_ctx->Mut ()) {
		return ArgAttr::Mut;
	} else if (_ctx->Params ()) {
		return ArgAttr::Params;
	} else if (_ctx->Disperse ()) {
		return ArgAttr::Disperse;
	} else {
		throw fa::Exception (_ctx->start, "not support public level");
	}
}
PublicLevel GetPublicLevel (FaParser::PublicLevelContext *_ctx) {
	if ((!_ctx) || _ctx->Public ()) {
		return PublicLevel::Public;
	} else if (_ctx->Internal ()) {
		return PublicLevel::Internal;
	} else if (_ctx->Protected ()) {
		return PublicLevel::Protected;
	} else if (_ctx->Private ()) {
		return PublicLevel::Private;
	} else {
		throw fa::Exception (_ctx->start, "not support public level");
	}
}

std::function<AstObj *(AstType, antlr4::Token *_token)> s_factory_cb;

void SetTypeGenFunc (std::function<AstObj *(AstType, antlr4::Token *_token)> _factory_cb) {
	s_factory_cb = _factory_cb;
}

struct AstTool {
	static AstObj *NameExpr (antlr4::Token *_token, std::string _name) {
		auto _obj = s_factory_cb (AstType::Expr_TempName, _token);
		_obj->SetValues (ParseValueType::Name, { _name });
		return _obj;
	}

	static AstObj *LiterilExpr (antlr4::Token *_token, std::string _value) {
		auto _obj = s_factory_cb (AstType::Expr_Value, _token);
		_obj->SetValues (ParseValueType::Value, { _value });
		return _obj;
	}

	static AstObj *InvokeExpr (antlr4::Token *_token, std::string _func_name, std::vector<AstObj *> _items) {
		return InvokeExpr (_token, NameExpr (_token, _func_name), _items);
	}

	static AstObj *InvokeExpr (antlr4::Token *_token, AstObj *_this, std::string _func_name, std::vector<AstObj *> _items) {
		auto _func = s_factory_cb (AstType::Expr_Op2, _token);
		_func->SetMembers (ParseType::Part_Member, { _this });
		_func->SetValues (ParseValueType::Operator, { "." });
		_func->SetMembers (ParseType::Part_Member2, { AstTool::NameExpr (_token, _func_name)});
		return InvokeExpr (_token, _func, _items);
	}

	static AstObj *InvokeExpr (antlr4::Token *_token, AstObj *_func, std::vector<AstObj *> _items) {
		auto _obj = s_factory_cb (AstType::Expr_Invoke, _token);
		_obj->SetMembers (ParseType::Part_Func, { _func });
		_obj->SetMembers (ParseType::Part_FuncArg, _items);
		return _obj;
	}
};



template<typename T>
AstObj *ParseContext (T *_ctx) {
	throw fa::Exception (_ctx->start, "not implement ast type");
}

template<typename T>
std::vector<AstObj *> ParseContexts (std::vector<T *> _ctxs) {
	std::vector<AstObj *> _v;
	for (auto _ctx : _ctxs)
		_v.push_back (ParseContext (_ctx));
	return _v;
}



#pragma region Type
template<>
AstObj *ParseContext (FaParser::TypeContext *_ctx) {
	AstObj *_obj;
	if (_ctx->ids ()) {
		_obj = s_factory_cb (AstType::Type_TempName, _ctx->start);
		_obj->SetValues (ParseValueType::Name, { GetId (_ctx->ids ()) });
	} else if (_ctx->Type ()) {
		_obj = s_factory_cb (AstType::Type_TempName, _ctx->start);
		_obj->SetValues (ParseValueType::Name, { GetId (_ctx->Type ()) });
	} else {
		_obj = s_factory_cb (AstType::Type_TupleWrap, _ctx->start);
		std::vector<AstObj *> _types;
		std::vector<ParseValue_t> _names;
		size_t i = 0;
		for (auto _type_var : _ctx->typeTuple ()->typeVar ()) {
			_types.push_back (ParseContext (_type_var->type ()));
			++i;
			_names.push_back (GetId (_type_var->Id (), std::format ("Item{}", i)));
		}
		_obj->SetMembers (ParseType::Part_Member, _types);
		_obj->SetValues (ParseValueType::VarName, _names);
	}
	for (auto _after : _ctx->typeAfter ()) {
		if (_after->quotFangL ()) {
			auto _obj2 = s_factory_cb (AstType::Type_TempName, _ctx->start);
			_obj2->SetValues (ParseValueType::Name, { "fa.List" });
			_obj2->SetMembers (ParseType::Part_Member, { _obj });
			_obj = _obj2;
		} else if (_after->Qus ()) {
			auto _obj2 = s_factory_cb (AstType::Type_OptionWrap, _ctx->start);
			_obj2->SetMembers (ParseType::Part_Member, { _obj });
			_obj = _obj2;
		} else if (_after->ColonColon ()) {
			auto _obj2 = s_factory_cb (AstType::Type_TempItem, _ctx->start);
			_obj2->SetMembers (ParseType::Part_Member, { _obj });
			std::string _sidx = GetId (_after->IntLiteral (), "-1");
			_obj2->SetValues (ParseValueType::Index, { (int64_t) ::atoll (_sidx.c_str ()) });
			_obj = _obj2;
		} else if (_after->quotJianL ()) {
			_obj->SetMembers (ParseType::Part_Member, ParseContexts (_after->types ()->type ()));
		}
	}
	return _obj;
}
#pragma endregion



#pragma region Expr
template<>
AstObj *ParseContext (FaParser::ExprContext *_ctx);
template<>
AstObj *ParseContext (FaParser::NormalStmtPartContext *_ctx);
template<>
AstObj *ParseContext (FaParser::MiddleExprContext *_ctx);

template<>
AstObj *ParseContext (FaParser::LiteralContext *_ctx) {
	AstObj *_obj = s_factory_cb (AstType::Expr_Value, _ctx->start);
	std::string _sval = GetId (_ctx);
	char *_tmp = nullptr;
	if (_ctx->BoolLiteral ()) {
		bool _val = GetId (_ctx) == "true";
		_obj->SetValues (ParseValueType::Value, { _val });
		return _obj;
	} else if (_ctx->HexLiteral ()) {
		uint64_t _val = std::strtoull (&_sval.c_str () [2], &_tmp, 16);
		_obj->SetValues (ParseValueType::Value, { _val });
		return _obj;
	} else if (_ctx->intNum ()) {
		uint64_t _val = std::strtoull (_sval.c_str (), &_tmp, 10);
		_obj->SetValues (ParseValueType::Value, { _val });
		return _obj;
	} else if (_ctx->floatNum ()) {
		double _dval = std::strtod (_sval.c_str (), &_tmp);
		_obj->SetValues (ParseValueType::Value, { _dval });
		return _obj;
	} else if (auto _str_ctx = _ctx->stringLiteral ()) {
		if (_str_ctx->String1Literal () || _str_ctx->String2Literal () || _str_ctx->String3Literal ()) {
			_sval = StringWrap::GetRealValue (_str_ctx->start, _sval);
			_obj->SetValues (ParseValueType::Value, { _sval });
			return _obj;
		} else if (auto _fs1_ctx = _str_ctx->formatString1 ()) {
			std::vector<AstObj *> _args;
			std::string _tmp_str = "";
			auto _flush_tmp_str = [&] () {
				if (_tmp_str.size () == 0)
					return;
				auto _obj2 = s_factory_cb (AstType::Expr_Value, _ctx->start);
				_obj2->SetValues (ParseValueType::Value, { _tmp_str });
				_args.push_back (_obj2);
				_tmp_str = "";
			};
			for (auto _str_ctx : _fs1_ctx->formatString1Part ()) {
				if (auto _str_expr_ctx = _str_ctx->middleExpr ()) {
					_flush_tmp_str ();
					auto _fmt_str_ctx = _str_ctx->FormatString ();
					std::string _fmt_str = GetId (_fmt_str_ctx, "");
					auto _obj3 = ParseContext (_str_expr_ctx);
					antlr4::Token *_obj4_token = _fmt_str_ctx ? _fmt_str_ctx->getSymbol () : _str_ctx->start;
					auto _obj4 = AstTool::LiterilExpr (_obj4_token, _fmt_str);
					_args.push_back (AstTool::InvokeExpr (_str_expr_ctx->start, "fa.Object.ToString", { _obj3, _obj4 }));
				} else if (_str_ctx->QHuaLQHuaL ()) {
					_tmp_str += "{";
				} else if (_str_ctx->QHuaRQHuaR ()) {
					_tmp_str += "}";
				} else if (auto _rchar_ctx = _str_ctx->RegularCharInside ()) {
					std::string s = _rchar_ctx->getText ();
					bool _update = true;
					if (s [0] == '\\') {
						switch (s [1]) {
							case 'r': _tmp_str += "\r"; break;
							case 'n': _tmp_str += "\n"; break;
							case 't': _tmp_str += "\t"; break;
							case '\\': _tmp_str += "\\"; break;
							case '\'': _tmp_str += "\'"; break;
							case '\"': _tmp_str += "\""; break;
							default: _update = false; break;
						}
					} else {
						_update = false;
					}
					if (!_update)
						throw fa::Exception (_ctx->start, "not implement");
				} else if (auto _rstr_ctx = _str_ctx->RegularStringInside ()) {
					std::string s = _rstr_ctx->getText ();
					throw fa::Exception (_ctx->start, "not implement");
				}
			}
			_flush_tmp_str ();
			if (_args.size () == 1)
				return _args [0];
			return AstTool::InvokeExpr (_ctx->start, "fa.String.Combine", _args);
		} else if (auto _fs2_ctx = _str_ctx->formatString2 ()) {
			std::vector<AstObj *> _args;
			std::string _tmp_str = "";
			auto _flush_tmp_str = [&] () {
				if (_tmp_str.size () == 0)
					return;
				auto _obj2 = s_factory_cb (AstType::Expr_Value, _ctx->start);
				_obj2->SetValues (ParseValueType::Value, { _tmp_str });
				_args.push_back (_obj2);
				_tmp_str = "";
			};
			for (auto _str_ctx : _fs2_ctx->formatString2Part ()) {
				if (auto _str_expr_ctx = _str_ctx->middleExpr ()) {
					_flush_tmp_str ();
					std::string _fmt_str = GetId (_str_ctx->FormatString (), "");
					_args.push_back (AstTool::InvokeExpr (_str_expr_ctx->start, "fa.Object.ToString", {
						ParseContext (_str_expr_ctx),
						AstTool::LiterilExpr (_str_ctx->FormatString ()->getSymbol (), _fmt_str)
					}));
				} else if (_str_ctx->QHuaLQHuaL ()) {
					_tmp_str += "{";
				} else if (_str_ctx->QHuaRQHuaR ()) {
					_tmp_str += "}";
				} else if (auto _rchar_ctx = _str_ctx->VerbatiumDoubleQuoteInside ()) {
					std::string s = _rchar_ctx->getText ();
					throw fa::Exception (_ctx->start, "not implement");
				} else if (auto _rstr_ctx = _str_ctx->VerbatiumInsideString ()) {
					std::string s = _rstr_ctx->getText ();
					throw fa::Exception (_ctx->start, "not implement");
				}
			}
			_flush_tmp_str ();
			if (_args.size () == 1)
				return _args [0];
			return AstTool::InvokeExpr (_ctx->start, "fa.String.Combine", _args);
		}
	}
	throw fa::Exception (_ctx->start, "not implement");
}

template<>
AstObj *ParseContext (FaParser::IfExprContext *_ctx) {
	throw fa::Exception (_ctx->start, "not implement");
}

template<>
AstObj *ParseContext (FaParser::SwitchExpr1Context *_ctx) {
	throw fa::Exception (_ctx->start, "not implement");
}

template<>
AstObj *ParseContext (FaParser::SwitchExpr2Context *_ctx) {
	throw fa::Exception (_ctx->start, "not implement");
}

template<>
AstObj *ParseContext (FaParser::Middle3OpExprContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Expr_If, _ctx->start);
	auto _exprs = ParseContexts (_ctx->strongExpr ());
	_obj->SetMembers (ParseType::Part_Condition, { _exprs [0] });
	_obj->SetMembers (ParseType::Part_TrueContent, { _exprs [1] });
	_obj->SetMembers (ParseType::Part_FalseContent, { _exprs [2] });
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::StrongExprBaseContext *_ctx) {
	if (_ctx->ids ()) {
		return AstTool::NameExpr (_ctx->start, GetId (_ctx));
	} else if (_ctx->literal ()) {
		return ParseContext (_ctx->literal ());
	} else if (_ctx->lambdaExpr ()) {
		return ParseContext (_ctx->lambdaExpr ());
	} else if (_ctx->quotExpr ()) {
		return ParseContext (_ctx->quotExpr ()->expr ());
	} else if (_ctx->tupleExpr ()) {
		return ParseContext (_ctx->tupleExpr ());
	} else if (_ctx->newExpr1 ()) {
		return ParseContext (_ctx->newExpr1 ());
	} else if (_ctx->newExpr2 ()) {
		return ParseContext (_ctx->newExpr2 ());
	} else if (_ctx->arrayExpr1 ()) {
		return ParseContext (_ctx->arrayExpr1 ());
	} else if (_ctx->arrayExpr2 ()) {
		return ParseContext (_ctx->arrayExpr2 ());
	} else if (_ctx->arrayExpr3 ()) {
		return ParseContext (_ctx->arrayExpr3 ());
	}
	throw fa::Exception (_ctx->start, "not implement");
}

template<>
AstObj *ParseContext (FaParser::ExprOptContext *_ctx) {
	if (!_ctx->expr ())
		return nullptr;
	return ParseContext (_ctx->expr ());
}

template<>
AstObj *ParseContext (FaParser::StrongExprContext *_ctx) {
	auto _obj = ParseContext (_ctx->strongExprBase ());
	for (auto _suffix_ctx : _ctx->strongExprSuffix ()) {
		if (_suffix_ctx->quotYuanL ()) {
			auto _obj2 =  s_factory_cb (AstType::Expr_Invoke, _suffix_ctx->start);
			_obj2->SetMembers (ParseType::Part_Func, { _obj });
			_obj2->SetMembers (ParseType::Part_FuncArg, ParseContexts (_suffix_ctx->middleExpr ()));
			_obj = _obj2;
		} else if (_suffix_ctx->quotFangL ()) {
			auto _token = _suffix_ctx->quotFangL ()->start;
			auto _obj2 =  s_factory_cb (AstType::Expr_Invoke, _suffix_ctx->start);
			auto _op2_expr = s_factory_cb (AstType::Expr_Op2, _token);
			_op2_expr->SetMembers (ParseType::Part_Member, { _obj });
			_op2_expr->SetValues (ParseValueType::Operator, { "." });
			_op2_expr->SetMembers (ParseType::Part_Member2, { AstTool::NameExpr (_token, "operator[]")});
			_obj2->SetMembers (ParseType::Part_Func, { _op2_expr });
			_obj2->SetMembers (ParseType::Part_FuncArg, ParseContexts (_suffix_ctx->exprOpt ()));
			_obj = _obj2;
		} else if (_suffix_ctx->quotJianL ()) {
			auto _types = ParseContexts (_suffix_ctx->type ());
		} else if (_suffix_ctx->PointOp ()) {
			auto _obj2 =  s_factory_cb (AstType::Expr_Op2, _suffix_ctx->start);
			_obj2->SetMembers (ParseType::Part_Member, { _obj });
			_obj2->SetValues (ParseValueType::Operator, { _suffix_ctx->Qus () ? "?." : "."});
			_obj2->SetMembers (ParseType::Part_Member2, { AstTool::NameExpr (_suffix_ctx->start, GetId (_suffix_ctx->Id ())) });
			_obj = _obj2;
		} else if (_suffix_ctx->Is ()) {
			throw fa::Exception (_ctx->start, "not implement");
		} else if (_suffix_ctx->AddAddOp () || _suffix_ctx->SubSubOp ()) {
			auto _obj2 = s_factory_cb (AstType::Expr_Op1, _suffix_ctx->start);
			_obj2->SetMembers (ParseType::Part_Member, { _obj });
			_obj2->SetValues (ParseValueType::Operator, { std::format (" {}", _suffix_ctx->getText ()) });
			_obj = _obj2;
		} else {
			throw fa::Exception (_ctx->start, "not implement");
		}
	}
	for (int i = (int) _ctx->strongExprPrefix ().size () - 1; i >= 0; --i) {
		auto _prefix_ctx = _ctx->strongExprPrefix () [i];
		if (_prefix_ctx->Cast ()) {
			throw fa::Exception (_ctx->start, "not implement");
		} else {
			auto _obj2 = s_factory_cb (AstType::Expr_Op1, _prefix_ctx->start);
			_obj2->SetMembers (ParseType::Part_Member, { _obj });
			_obj2->SetValues (ParseValueType::Operator, { GetId (_prefix_ctx) });
			_obj = _obj2;
		}
	}
	return _obj;
}

AstObj *_parse_middle2op_context (std::vector<AstObj *> _exprs, std::vector<std::string> _ops, std::vector<antlr4::Token *> _op_tokens, std::vector<int> _op_levels) {
	if (_exprs.size () == 1) {
		return _exprs [0];
	} else {
		auto _obj = s_factory_cb (AstType::Expr_Op2, _op_tokens [0]);
		_obj->SetValues (ParseValueType::Operator, { _ops [0] });
		if (_exprs.size () == 2) {
			_obj->SetMembers (ParseType::Part_Member, { _exprs [0] });
			_obj->SetMembers (ParseType::Part_Member2, { _exprs [1] });
		} else {
			size_t _sp = 0;
			for (size_t i = 1; i < _op_levels.size (); ++i) {
				if (_op_levels [i] < _op_levels [_sp])
					_sp = i;
			}
			if (_sp > 0) {
				std::vector<AstObj *> _exprs0;
				_exprs0.insert (_exprs0.begin (), _exprs.begin (), _exprs.begin () + _sp);
				std::vector<std::string> _ops0;
				_ops0.insert (_ops0.begin (), _ops.begin (), _ops.begin () + (_sp - 1));
				std::vector<antlr4::Token *> _op_tokens0;
				_op_tokens0.insert (_op_tokens0.begin (), _op_tokens.begin (), _op_tokens.begin () + (_sp - 1));
				std::vector<int> _op_levels0;
				_op_levels0.insert (_op_levels0.begin (), _op_levels.begin (), _op_levels.begin () + (_sp - 1));
				_obj->SetMembers (ParseType::Part_Member, { _parse_middle2op_context (_exprs0, _ops0, _op_tokens0, _op_levels0) });
			} else {
				_obj->SetMembers (ParseType::Part_Member, { _exprs [0] });
			}
			_sp = _sp > 0 ? _sp : 1;
			_exprs.erase (_exprs.begin (), _exprs.begin () + _sp);
			_ops.erase (_ops.begin (), _ops.begin () + _sp);
			_op_tokens.erase (_op_tokens.begin (), _op_tokens.begin () + _sp);
			_op_levels.erase (_op_levels.begin (), _op_levels.begin () + _sp);
			_obj->SetMembers (ParseType::Part_Member2, { _parse_middle2op_context (_exprs, _ops, _op_tokens, _op_levels) });
		}
		return _obj;
	}
}

template<>
AstObj *ParseContext (FaParser::Middle2OpExprContext *_ctx) {
	static std::map<std::string, int> s_op2_level {
		{ "||", 0 },
		{ "&&", 1 },
		{ ">", 2 }, { ">=", 2 }, { "<", 2 }, { "<=", 2 },
		{ "==", 3 }, { "!=", 3 },
		{ "&", 4 }, { "|", 4 }, { "^", 4 },
		{ "<<", 5 }, { ">>", 5 },
		{ "+", 6 }, { "-", 6 },
		{ "*", 7 }, { "/", 7 }, { "**", 7 }, { "%", 7 },
		{ "??", 8 },
	};

	auto _exprs = ParseContexts (_ctx->strongExpr ());
	std::vector<std::string> _ops;
	std::vector<antlr4::Token *> _op_tokens;
	std::vector<int> _op_levels;
	for (auto _op_ctx : _ctx->allOp2 ()) {
		_ops.push_back (GetId (_op_ctx));
		_op_tokens.push_back (_op_ctx->start);
		_op_levels.push_back (s_op2_level.find (*_ops.rbegin ())->second);
	}
	return _parse_middle2op_context (_exprs, _ops, _op_tokens, _op_levels);
}

template<>
AstObj *ParseContext (FaParser::MiddleAstExprContext *_ctx) {
	if (_ctx->Stmt ()) {
		auto _obj = s_factory_cb (AstType::Expr_Value, _ctx->start);
		_obj->SetMembers (ParseType::Part_ValueStmt, { ParseContext (_ctx->normalStmtPart ()) });
		return _obj;
	} else if (_ctx->Expr ()) {
		auto _obj = s_factory_cb (AstType::Expr_Value, _ctx->start);
		_obj->SetMembers (ParseType::Part_ValueExpr, { ParseContext (_ctx->middle2OpExpr ()) });
		return _obj;
	} else {
		throw fa::Exception (_ctx->start, "not implement");
	}
}

template<>
AstObj *ParseContext (FaParser::MiddleExprContext *_ctx) {
	if (_ctx->middle3OpExpr ()) {
		return ParseContext (_ctx->middle3OpExpr ());
	} else if (_ctx->middle2OpExpr ()) {
		return ParseContext (_ctx->middle2OpExpr ());
	} else if (_ctx->middleAstExpr ()) {
		return ParseContext (_ctx->middleAstExpr ());
	} else {
		throw fa::Exception (_ctx->start, "not implement");
	}
}

template<>
AstObj *ParseContext (FaParser::ExprContext *_ctx) {
	std::vector<AstObj *> _vars;
	for (auto _var_ctx : _ctx->strongExpr ())
		_vars.push_back (ParseContext (_var_ctx));
	auto _ops_ctx = _ctx->allAssignOp ();
	std::vector<std::string> _ops = GetIds (_ops_ctx);
	AstObj *_obj;
	if (_ctx->ifExpr ()) {
		_obj = ParseContext (_ctx->ifExpr ());
	} else if (_ctx->switchExpr1 ()) {
		_obj = ParseContext (_ctx->switchExpr1 ());
	} else if (_ctx->switchExpr2 ()) {
		_obj = ParseContext (_ctx->switchExpr2 ());
	} else if (_ctx->middleExpr ()) {
		_obj = ParseContext (_ctx->middleExpr ());
	} else {
		throw fa::Exception (_ctx->start, "not support code type");
	}
	for (int i = (int) (_ops.size () - 1); i >= 0; --i) {
		auto _obj2 = s_factory_cb (AstType::Expr_Op2, _ops_ctx [i]->start);
		_obj2->SetMembers (ParseType::Part_Member, { _vars[i] });
		_obj2->SetValues (ParseValueType::Operator, { _ops [i] });
		_obj2->SetMembers (ParseType::Part_Member2, { _obj });
		_obj = _obj2;
	}
	return _obj;
}
#pragma endregion



#pragma region Stmt
template<>
AstObj *ParseContext (FaParser::DefVarStmtPartContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Stmt_DefineVar, _ctx->start);
	std::vector<AstObj *> _types;
	std::vector<ParseValue_t> _names;
	std::vector<AstObj *> _values;
	for (auto _item_ctx : _ctx->idAssignOpExpr ()) {
		if (_item_ctx->type ())
			_types.push_back (_item_ctx->type () ? ParseContext (_item_ctx->type ()) : nullptr);
		_names.push_back (GetId (_item_ctx->Id ()));
		_values.push_back (ParseContext (_item_ctx->middleExpr ()));
	}
	_obj->SetMembers (ParseType::Part_Type, _types);
	_obj->SetValues (ParseValueType::VarName, _names);
	_obj->SetMembers (ParseType::Part_Value, _values);
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::DefVarStmt2PartContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Stmt_DefineVar, _ctx->start);
	std::vector<AstObj *> _types;
	std::vector<ParseValue_t> _names;
	std::vector<AstObj *> _values;
	auto _type_ctx = _ctx->type ();
	for (auto _item_ctx : _ctx->idAssignOpExpr2 ()) {
		_types.push_back (ParseContext (_type_ctx));
		_names.push_back (GetId (_item_ctx->Id ()));
		_values.push_back (ParseContext (_item_ctx->middleExpr ()));
	}
	_obj->SetMembers (ParseType::Part_Type, _types);
	_obj->SetValues (ParseValueType::Name, _names);
	_obj->SetMembers (ParseType::Part_Value, _values);
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::IfStmtContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Stmt_If, _ctx->start);
	_obj->SetMembers (ParseType::Part_Condition, ParseContexts (_ctx->middleExpr ()));
	_obj->SetMembers (ParseType::Part_Member2, ParseContexts (_ctx->quotStmtPart ()));
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::WhileStmtContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Stmt_While, _ctx->start);
	_obj->SetMembers (ParseType::Part_Condition, { ParseContext (_ctx->middleExpr ()) });
	_obj->SetMembers (ParseType::Part_Member2, ParseContexts (_ctx->stmt ()));
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::WhileStmt2Context *_ctx) {
	auto _obj = s_factory_cb (AstType::Stmt_While2, _ctx->start);
	_obj->SetMembers (ParseType::Part_Member, { ParseContext (_ctx->middleExpr ()) });
	_obj->SetMembers (ParseType::Part_Member2, ParseContexts (_ctx->stmt ()));
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::ForStmtContext *_ctx) {
	if (auto _header1 = _ctx->forHeader ()->forHeader1 ()) {
		auto _obj = s_factory_cb (AstType::Stmt_For1, _ctx->start);
		std::vector<ParseValue_t> _names;
		for (auto _id : _header1->Id ())
			_names.push_back (GetId (_id));
		_obj->SetValues (ParseValueType::VarName, _names);
		_obj->SetMembers (ParseType::Part_Member, { ParseContext (_header1->middleExpr ()) });
		_obj->SetMembers (ParseType::Part_Member2, ParseContexts (_ctx->stmt ()));
		return _obj;
	} else if (auto _header2 = _ctx->forHeader ()->forHeader2 ()) {
		auto _obj = s_factory_cb (AstType::Stmt_For2, _ctx->start);
		_obj->SetMembers (ParseType::Part_Init, { ParseContext (_header2->defVarStmt2Part ()) });
		_obj->SetMembers (ParseType::Part_Condition, { ParseContext (_header2->middleExpr ()) });
		_obj->SetMembers (ParseType::Part_Increment, { ParseContext (_header2->expr ()) });
		_obj->SetMembers (ParseType::Part_Member2, ParseContexts (_ctx->stmt ()));
		return _obj;
	} else {
		throw fa::Exception (_ctx->start, "not implement");
	}
}

template<>
AstObj *ParseContext (FaParser::QuotStmtPartContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Stmt_Stmts, _ctx->start);
	_obj->SetMembers (ParseType::Part_Member, ParseContexts (_ctx->stmt ()));
	return _obj;
}

// TODO
template<>
AstObj *ParseContext (FaParser::SwitchStmtContext *_ctx) {
	throw fa::Exception (_ctx->start, "not implement");
}

// TODO
template<>
AstObj *ParseContext (FaParser::SwitchStmt2Context *_ctx) {
	throw fa::Exception (_ctx->start, "not implement");
}

template<>
AstObj *ParseContext (FaParser::DefTypeStmtContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Type_UnsureWrap, _ctx->start);
	_obj->SetValues (fa::ParseValueType::Name, { GetId (_ctx->Id ()) });
	_obj->SetMembers (fa::ParseType::Part_Member, ParseContexts (_ctx->type ()));
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::NormalStmtPartContext *_ctx) {
	if (_ctx->expr ()) {
		if (_ctx->Return ()) {
			auto _obj = s_factory_cb (AstType::Stmt_Return, _ctx->start);
			_obj->SetMembers (ParseType::Part_Member, { ParseContext (_ctx->expr ()) });
			return _obj;
		} else {
			auto _obj = s_factory_cb (AstType::Stmt_ExprWrap, _ctx->start);
			_obj->SetMembers (ParseType::Part_Member, { ParseContext (_ctx->expr ()) });
			return _obj;
		}
	} else if (_ctx->Return ()) {
		return s_factory_cb (AstType::Stmt_Return, _ctx->start);
	} else if (_ctx->Break ()) {
		return s_factory_cb (AstType::Stmt_Break, _ctx->start);
	} else if (_ctx->Continue ()) {
		return s_factory_cb (AstType::Stmt_Continue, _ctx->start);
	} else if (_ctx->defVarStmtPart ()) {
		auto _obj = s_factory_cb (AstType::Stmt_DefineVar, _ctx->start);
		std::vector<AstObj *> _types;
		std::vector<ParseValue_t> _names;
		std::vector<AstObj *> _values;
		for (auto _item_ctx : _ctx->defVarStmtPart()->idAssignOpExpr ()) {
			if (_item_ctx->type ())
				_types.push_back (_item_ctx->type () ? ParseContext (_item_ctx->type ()) : nullptr);
			_names.push_back (GetId (_item_ctx->Id ()));
			_values.push_back (ParseContext (_item_ctx->middleExpr ()));
		}
		_obj->SetMembers (ParseType::Part_Type, _types);
		_obj->SetValues (ParseValueType::VarName, _names);
		_obj->SetMembers (ParseType::Part_Value, _values);
		return _obj;
	} else if (_ctx->defVarStmt2Part ()) {
		auto _obj = s_factory_cb (AstType::Stmt_DefineVar, _ctx->start);
		std::vector<AstObj *> _types;
		std::vector<ParseValue_t> _names;
		std::vector<AstObj *> _values;
		auto _type_ctx = _ctx->defVarStmt2Part ()->type ();
		for (auto _item_ctx : _ctx->defVarStmt2Part()->idAssignOpExpr2 ()) {
			_types.push_back (ParseContext (_type_ctx));
			_names.push_back (GetId (_item_ctx->Id ()));
			_values.push_back (ParseContext (_item_ctx->middleExpr ()));
		}
		_obj->SetMembers (ParseType::Part_Type, _types);
		_obj->SetValues (ParseValueType::Name, _names);
		_obj->SetMembers (ParseType::Part_Value, _values);
		return _obj;
	} else {
		throw fa::Exception (_ctx->start, "not implement");
	}
}

template<>
AstObj *ParseContext (FaParser::NormalStmtContext *_ctx) {
	return ParseContext (_ctx->normalStmtPart ());
}

template<>
AstObj *ParseContext (FaParser::StmtContext *_ctx) {
	if (_ctx->ifStmt ()) {
		return ParseContext (_ctx->ifStmt ());
	} else if (_ctx->whileStmt ()) {
		return ParseContext (_ctx->whileStmt ());
	} else if (_ctx->whileStmt2 ()) {
		return ParseContext (_ctx->whileStmt2 ());
	} else if (_ctx->forStmt ()) {
		return ParseContext (_ctx->forStmt ());
	} else if (_ctx->quotStmtPart ()) {
		return ParseContext (_ctx->quotStmtPart ());
	} else if (_ctx->switchStmt ()) {
		return ParseContext (_ctx->switchStmt ());
	} else if (_ctx->switchStmt2 ()) {
		return ParseContext (_ctx->switchStmt2 ());
	//} else if (_ctx->defVarStmt ()) {
	//	return ParseContext (_ctx->defVarStmt ());
	//} else if (_ctx->defVarStmt2 ()) {
	//	return ParseContext (_ctx->defVarStmt2 ());
	} else if (_ctx->normalStmt ()) {
		return ParseContext (_ctx->normalStmt ());
	} else {
		throw fa::Exception (_ctx->start, "not support stmt type");
	}
}
#pragma endregion



#pragma region Block
template<>
AstObj *ParseContext (FaParser::UseStmtContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_Use, _ctx->start);
	_obj->SetValues (ParseValueType::Name, { GetId (_ctx->Id ()) });
	_obj->SetValues (ParseValueType::Value, { GetId (_ctx->ids ()) });
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::AnnoPartContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_AnnoPart, _ctx->start);
	_obj->SetValues (ParseValueType::Name, { GetId (_ctx->Id ()).substr (1) });
	std::vector<ParseValue_t> _vnames;
	std::vector<AstObj *> _vvalues;
	for (auto _anno_arg : _ctx->annoArg ()) {
		_vnames.push_back (GetId (_anno_arg->Id ()));
		_vvalues.push_back (ParseContext (_anno_arg->middleExpr ()));
	}
	_obj->SetValues (ParseValueType::Part_Name, _vnames);
	_obj->SetMembers (ParseType::Part_Member, _vvalues);
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::AnnoBlockContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_Anno, _ctx->start);
	_obj->SetMembers (ParseType::AnnoPart, ParseContexts (_ctx->annoPart ()));
	_obj->SetValues (ParseValueType::Name, { GetId (_ctx->Id ()) });
	//
	auto _vars = ParseContexts (_ctx->classVar ());
	for (auto _var : _vars)
		_var->SetMembers (ParseType::Part_Parent, { _obj });
	_obj->SetMembers (ParseType::ClassVar, _vars);
	auto _funcs = ParseContexts (_ctx->classFunc ());
	for (auto _func : _funcs)
		_func->SetMembers (ParseType::Part_Parent, { _obj });
	_obj->SetMembers (ParseType::ClassFunc, _funcs);
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::EnumItemContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_EnumItem, _ctx->start);
	_obj->SetMembers (ParseType::AnnoPart, ParseContexts (_ctx->annoPart ()));
	_obj->SetValues (ParseValueType::Name, { GetId (_ctx->Id ()) });
	if (_ctx->type ())
		_obj->SetMembers (ParseType::Part_Member, { ParseContext (_ctx->type ()) });
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::EnumBlockContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_Enum, _ctx->start);
	_obj->SetMembers (ParseType::AnnoPart, ParseContexts (_ctx->annoPart ()));
	_obj->SetValues (ParseValueType::PublicLevel, { GetPublicLevel (_ctx->publicLevel ()) });
	_obj->SetValues (ParseValueType::Name, { GetId (_ctx->Id ()) });
	if (auto _templates_ctx = _ctx->blockTemplates (); _templates_ctx) {
		std::vector<ParseValue_t> _templates;
		for (auto _id_ctx : GetIds (_ctx->blockTemplates ()->Id ()))
			_templates.push_back (_id_ctx);
		_obj->SetValues (ParseValueType::Templates, _templates);
	}
	_obj->SetMembers (ParseType::EnumItem, ParseContexts (_ctx->enumItem ()));
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::VarAccesserContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_ClassFunc, _ctx->start);
	_obj->SetValues (ParseValueType::PublicLevel, { GetPublicLevel (_ctx->publicLevel ()) });
	_obj->SetValues (ParseValueType::Static, { false });
	bool _is_get = _ctx->Get ();
	_obj->SetValues (ParseValueType::Name, { _is_get ? "get" : "set" });
	if (auto _body_ctx = _ctx->funcBody ()) {
		std::vector<AstObj *> _body_stmts;
		if (_body_ctx->expr ()) {
			auto _ret_stmt = s_factory_cb (AstType::Stmt_Return, _ctx->start);
			_ret_stmt->SetMembers (ParseType::Part_Member, { ParseContext (_body_ctx->expr ()) });
			_body_stmts.push_back (_ret_stmt);
		} else {
			_body_stmts = ParseContexts (_body_ctx->stmt ());
		}
		_obj->SetMembers (ParseType::Part_FuncBody, _body_stmts);
	}
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::ClassVarContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_ClassVar, _ctx->start);
	_obj->SetMembers (ParseType::AnnoPart, ParseContexts (_ctx->annoPart ()));
	_obj->SetValues (ParseValueType::PublicLevel, { GetPublicLevel (_ctx->publicLevel ()) });
	_obj->SetValues (ParseValueType::Static, { !!_ctx->Static () });
	auto _ctx_item = _ctx->typeNameTuple ();
	_obj->SetValues (ParseValueType::Name, { GetId (_ctx_item->itemName ()) });
	_obj->SetMembers (ParseType::Part_Type, { ParseContext (_ctx_item->type ()) });
	if (auto _access_ctxs = _ctx->varAccesserItems ())
		_obj->SetMembers (ParseType::Part_Func, ParseContexts (_access_ctxs->varAccesser ()));
	return _obj;
}

// TODO blockTemplates
template<>
AstObj *ParseContext (FaParser::ClassFuncContext *_ctx) {
	auto _obj = s_factory_cb (_ctx->funcBody () ? AstType::Block_ClassFunc : AstType::Block_ClassFuncEmpty, _ctx->start);
	_obj->SetMembers (ParseType::AnnoPart, ParseContexts (_ctx->annoPart ()));
	_obj->SetValues (ParseValueType::PublicLevel, { GetPublicLevel (_ctx->publicLevel ()) });
	_obj->SetValues (ParseValueType::Static, { !!_ctx->Static () });
	auto _ctx_item = _ctx->typeNameArgsTuple ();
	_obj->SetValues (ParseValueType::Name, { GetId (_ctx_item->itemName ()) });
	if (auto _templates_ctx = _ctx_item->blockTemplates (); _templates_ctx) {
		std::vector<ParseValue_t> _templates;
		for (auto _id_ctx : GetIds (_ctx_item->blockTemplates ()->Id ()))
			_templates.push_back (_id_ctx);
		_obj->SetValues (ParseValueType::Templates, _templates);
	}
	_obj->SetMembers (ParseType::Part_ReturnType, { ParseContext (_ctx_item->type ()) });
	std::vector<ParseValue_t> _arg_attrs;
	std::vector<AstObj *> _arg_types;
	std::vector<ParseValue_t> _arg_names;
	if (_ctx_item->typeWrapVarList1 ()) {
		for (auto _arg_ctx : _ctx_item->typeWrapVarList1 ()->typeWrapVar1 ()) {
			_arg_attrs.push_back (GetArgAttr (_arg_ctx->argAttr ()));
			_arg_types.push_back (ParseContext (_arg_ctx->type ()));
			_arg_names.push_back (GetId (_arg_ctx->Id ()));
		}
	} else if (_ctx_item->typeWrapVarList2 ()) {
		for (auto _arg_ctx : _ctx_item->typeWrapVarList2 ()->typeWrapVar2 ()) {
			_arg_attrs.push_back (GetArgAttr (_arg_ctx->argAttr ()));
			_arg_types.push_back (ParseContext (_arg_ctx->type ()));
			_arg_names.push_back (GetId (_arg_ctx->Id ()));
		}
	}
	_obj->SetValues (ParseValueType::Part_ArgAttr, _arg_attrs);
	_obj->SetMembers (ParseType::Part_ArgType, _arg_types);
	_obj->SetValues (ParseValueType::Part_ArgName, _arg_names);
	if (auto _body_ctx = _ctx->funcBody ()) {
		std::vector<AstObj *> _body_stmts;
		if (_body_ctx->expr ()) {
			auto _ret_stmt = s_factory_cb (AstType::Stmt_Return, _ctx->start);
			_ret_stmt->SetMembers (ParseType::Part_Member, { ParseContext (_body_ctx->expr ()) });
			_body_stmts.push_back (_ret_stmt);
		} else {
			_body_stmts = ParseContexts (_body_ctx->stmt ());
		}
		_obj->SetMembers (ParseType::Part_FuncBody, _body_stmts);
	}
	return _obj;
}

// TODO importedConstructFunc
template<>
AstObj *ParseContext (FaParser::ClassBlockContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_Class, _ctx->start);
	_obj->SetMembers (ParseType::AnnoPart, ParseContexts (_ctx->annoPart ()));
	_obj->SetValues (ParseValueType::PublicLevel, { GetPublicLevel (_ctx->publicLevel ()) });
	_obj->SetValues (ParseValueType::FullName, { GetId (_ctx->Id ()) });
	_obj->SetValues (ParseValueType::Name, { GetId (_ctx->Id ()) });
	if (auto _templates_ctx = _ctx->blockTemplates (); _templates_ctx) {
		std::vector<ParseValue_t> _templates;
		for (auto _id_ctx : GetIds (_ctx->blockTemplates ()->Id ()))
			_templates.push_back (_id_ctx);
		_obj->SetValues (ParseValueType::Templates, _templates);
	}
	//
	auto _vars = ParseContexts (_ctx->classVar ());
	for (auto _var : _vars)
		_var->SetMembers (ParseType::Part_Parent, { _obj });
	_obj->SetMembers (ParseType::ClassVar, _vars);
	auto _funcs = ParseContexts (_ctx->classFunc ());
	for (auto _func : _funcs)
		_func->SetMembers (ParseType::Part_Parent, { _obj });
	_obj->SetMembers (ParseType::ClassFunc, _funcs);
	return _obj;
}

template<>
AstObj *ParseContext (FaParser::ProgramContext *_ctx) {
	auto _obj = s_factory_cb (AstType::Block_Program, _ctx->start);
	_obj->SetMembers (ParseType::Use, ParseContexts (_ctx->useStmt ()));
	std::string _namesp = GetId (_ctx->namespaceStmt ()->ids ());
	_obj->SetValues (ParseValueType::Namespace, { _namesp });
	//
	auto _types = ParseContexts (_ctx->defTypeStmt ());
	for (auto _obj_item : _types)
		_obj_item->SetValues (ParseValueType::FullName, { std::format ("{}.{}", _namesp, std::get<std::string> (_obj_item->GetValues (ParseValueType::Name) [0]))});
	_obj->SetMembers (ParseType::Type, _types);
	//
	auto _annos = ParseContexts (_ctx->annoBlock ());
	for (auto _obj_item : _annos)
		_obj_item->SetValues (ParseValueType::FullName, { std::format ("{}.{}", _namesp, std::get<std::string> (_obj_item->GetValues (ParseValueType::Name) [0]))});
	_obj->SetMembers (ParseType::Anno, _annos);
	//
	auto _enums = ParseContexts (_ctx->enumBlock ());
	for (auto _obj_item : _enums)
		_obj_item->SetValues (ParseValueType::FullName, { std::format ("{}.{}", _namesp, std::get<std::string> (_obj_item->GetValues (ParseValueType::Name) [0])) });
	_obj->SetMembers (ParseType::Enum, _enums);
	//
	auto _classes = ParseContexts (_ctx->classBlock ());
	for (auto _obj_item : _classes)
		_obj_item->SetValues (ParseValueType::FullName, { std::format ("{}.{}", _namesp, std::get<std::string> (_obj_item->GetValues (ParseValueType::Name) [0])) });
	_obj->SetMembers (ParseType::Class, _classes);
	return _obj;
}
#pragma endregion



AstObj *CompileCode (std::string _code, AstType _code_type) {
	auto _stream = std::make_shared<antlr4::ANTLRInputStream> (_code);
	auto _lexer = std::make_shared<FaLexer> (_stream.get ());
	auto _cts = std::make_shared<antlr4::CommonTokenStream> (_lexer.get ());
	_cts->fill ();
	auto _parser = std::make_shared<FaParser> (_cts.get ());
	if (_code_type == AstType::Block_Program) {
		return ParseContext (_parser->programEntry ()->program ());
	} else {
		throw fa::Exception (nullptr, "not support code type");
	}
}
}

size_t get_INTERPOLATION_FORMAT () {
	return FaLexer::INTERPOLATION_FORMAT;
}
