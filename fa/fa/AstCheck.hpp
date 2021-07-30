#ifndef __NEED_CACHE_HPP__
#define __NEED_CACHE_HPP__



#include <functional>
#include <map>
#include <optional>
#include <string>
#include <vector>

#include <antlr4-runtime/Token.h>

#include <FaParser.h>



class AstCheck {
public:
	static std::optional<std::string> GetExpectType (FaParser::StrongExprBaseContext *_expr_raw, std::string _expect_type) {
		// TODO:遍历结构，找到原始类型
		LOG_TODO (_expr_raw->start);
		return std::nullopt;
	}

	static std::optional<std::string> GetExpectType (FaParser::StrongExprContext *_expr_raw, std::string _expect_type) {
		for (auto _suffix_raw : _expr_raw->strongExprSuffix ()) {
			if (_suffix_raw->QuotYuanL ()) {
				LOG_TODO (_suffix_raw->start);
				return std::nullopt;
			} else if (_suffix_raw->QuotFangL ()) {
				LOG_TODO (_suffix_raw->start);
				return std::nullopt;
			}
		}
		// TODO
		LOG_TODO (_suffix_raw->start);
		return std::nullopt;
	}

	static std::optional<std::string> GetExpectType (FaParser::ExprContext *_expr_raw, std::string _expect_type) {
		auto _weak_suffix_raw = _expr_raw->weakExprSuffix ();
		if (_weak_suffix_raw) {
			if (_weak_suffix_raw->equalOp () || _weak_suffix_raw->notEqualOp ()) {
				return "bool";
			} else if (_weak_suffix_raw->ltOps ().size () > 0 || _weak_suffix_raw->gtOps ().size () > 0) {
				return "bool";
			} else {
				std::optional<std::string> _type1 = GetExpectType (_expr_raw->strongExpr (), _expect_type);
				if (!_type1.has_value ())
					return std::nullopt;
				std::string _tmp_type = _type1.value ();
				for (auto _expr_raw2 : _weak_suffix_raw->strongExpr ()) {
					std::optional<std::string> _type2 = GetExpectType (_expr_raw2, _expect_type);
					if (!_type2.has_value ())
						return std::nullopt;
					_type2 = _get_min_type (_tmp_type, _type2.value (), _expr_raw2->start);
					if (!_type2.has_value ())
						return std::nullopt;
					_tmp_type = _type2.value ();
				}
				return _tmp_type;
			}
		} else {
			return GetExpectType (_expr_raw->strongExpr (), _expect_type);
		}
	}

	static std::optional<std::string> GetStrongExprBaseExpectType (FaParser::StrongExprContext *_expr_raw, std::string _expect_type) {
		_expect_type = _type_not_change_when_after_wrappered (_expr_raw) ? _expect_type : "";
		return AstCheck::GetExpectType (_expr_raw->strongExprBase (), _expect_type);
	}

	static std::optional<std::string> GetStrongExprExpectType (FaParser::ExprContext *_expr_raw, std::string _expect_type) {
		_expect_type = _type_not_change_when_after_wrappered (_expr_raw) ? _expect_type : "";
		return AstCheck::GetExpectType (_expr_raw->strongExpr (), _expect_type);
	}

private:
	static bool _type_not_change_when_after_wrappered (FaParser::StrongExprContext *_expr_raw) {
		for (auto _suffix_raw : _expr_raw->strongExprSuffix ()) {
			if (_suffix_raw->QuotYuanL () || _suffix_raw->QuotFangL ())
				return false;
		}
		return true;
	}

	static bool _type_not_change_when_after_wrappered (FaParser::ExprContext *_expr_raw) {
		auto _weak_suffix_raw = _expr_raw->weakExprSuffix ();
		if (!_weak_suffix_raw) {
			return true;
		} else if (_weak_suffix_raw->equalOp () || _weak_suffix_raw->notEqualOp ()) {
			return false;
		} else if (_weak_suffix_raw->ltOps ().size () > 0 || _weak_suffix_raw->gtOps ().size () > 0) {
			return false;
		} else {
			return true;
		}
	}

	static std::optional<std::string> _get_min_type (std::string _type1, std::string _type2, antlr4::Token *_t) {
		if (_type1 == _type2) {
			return _type1;
		} else if (_type1 == "") {
			return _type2;
		} else if (_type2 == "") {
			return _type1;
		} else {
			LOG_TODO (_t);
			return std::nullopt;
	//		// 检查父子关系
	//		std::function<bool (std::string, std::string)> _is_type_contain;
	//		_is_type_contain = [&_is_type_contain] (std::string _parent, std::string _child) {
	//			if (!s_types.contains (_parent))
	//				return false;
	//			for (std::string _parent0 : s_types [_parent]) {
	//				if (_parent0 == _child)
	//					return true;
	//			}
	//			for (std::string _parent0 : s_types [_parent]) {
	//				if (_is_type_contain (_parent0, _child))
	//					return true;
	//			}
	//			return false;
	//		};
	//		if (_is_type_contain (_type1, _type2))
	//			return _type1;
	//		if (_is_type_contain (_type2, _type1))
	//			return _type2;

	//		// 检查兄弟关系
	//		std::string _current = "";
	//		for (auto &[_par, _children] : s_types) {
	//			if ((!_is_type_contain (_par, _type1)) || (!_is_type_contain (_par, _type1)))
	//				continue;
	//			if (_current == "") {
	//				_current = _par;
	//			} else if (_is_type_contain (_par, _current)) {
	//				_current = _par;
	//			}
	//		}

	//		// 假如没有任何一个类型能同时满足这俩特性
	//		if (_current == "") {
	//			LOG_ERROR (_t, "左右操作数不支持做此种运算");
	//			return std::nullopt;
	//		}
	//		return _current;
		}
	}

	//inline static std::map<std::string, std::vector<std::string>> s_types {
	//	{ "bool", { "[equable]" } },
	//	{ "int", { "[equable]", "[comparable]" } },
	//	{ "float", { "int", "[equable]", "[comparable]" } },
	//};
};



#endif //__NEED_CACHE_HPP__
