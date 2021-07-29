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
	static std::optional<std::string> TryGetExpectType (FaParser::ExprContext *_expr_raw, std::string _expect_type) {
		// TODO:遍历结构，找到原始类型
	}

	static std::optional<std::string> TryGetStrongExpectType (FaParser::ExprContext *_expr_raw, std::string _expect_type) {
		// TODO: 判断的很不全，可能有问题
		auto _weak_suffix_raw = _expr_raw->weakExprSuffix ();
		if (!_weak_suffix_raw)
			return _expect_type;
		if (_weak_suffix_raw->allAssign ()) {
			return _expect_type;
		} else if (_weak_suffix_raw->equalOp () || _weak_suffix_raw->notEqualOp ()) {
			return "[equable]";
		} else if (_weak_suffix_raw->allOp2 ().size () > 0) {
			return _expect_type;
		} else if (_weak_suffix_raw->ltOps ().size () > 0 || _weak_suffix_raw->gtOps ().size () > 0) {
			return "[comparable]";
		} else {
			LOG_TODO (_expr_raw->start);
			return std::nullopt;
		}
	}

private:
	static std::optional<std::string> _get_min_type (std::string _type1, std::string _type2, antlr4::Token *_t) {
		if (_type1 == _type2) {
			return _type1;
		} else if (_type1 == "") {
			return _type2;
		} else if (_type2 == "") {
			return _type1;
		} else {
			// 检查父子关系
			std::function<bool (std::string, std::string)> _is_type_contain;
			_is_type_contain = [&_is_type_contain] (std::string _parent, std::string _child) {
				if (!s_types.contains (_parent))
					return false;
				for (std::string _parent0 : s_types [_parent]) {
					if (_parent0 == _child)
						return true;
				}
				for (std::string _parent0 : s_types [_parent]) {
					if (_is_type_contain (_parent0, _child))
						return true;
				}
				return false;
			};
			if (_is_type_contain (_type1, _type2))
				return _type1;
			if (_is_type_contain (_type2, _type1))
				return _type2;

			// 检查兄弟关系
			std::string _current = "";
			for (auto &[_par, _children] : s_types) {
				if ((!_is_type_contain (_par, _type1)) || (!_is_type_contain (_par, _type1)))
					continue;
				if (_current == "") {
					_current = _par;
				} else if (_is_type_contain (_par, _current)) {
					_current = _par;
				}
			}

			// 假如没有任何一个类型能同时满足这俩特性
			if (_current == "") {
				LOG_ERROR (_t, "左右操作数不支持做此种运算");
				return std::nullopt;
			}
			return _current;
		}
	}

	inline static std::map<std::string, std::vector<std::string>> s_types {
		{ "bool", { "[equable]" } },
		{ "int", { "[equable]", "[comparable]" } },
		{ "float", { "int", "[equable]", "[comparable]" } },
	};
};



#endif //__NEED_CACHE_HPP__
