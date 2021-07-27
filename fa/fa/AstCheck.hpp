#ifndef __NEED_CACHE_HPP__
#define __NEED_CACHE_HPP__



#include <optional>
#include <string>

#include <FaParser.h>



class AstCheck {
public:
	static std::optional<std::string> TryGetStrongExpectType (FaParser::ExprContext *_expr_raw, std::string _expect_type) {
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
	static std::string _get_short_type (std::string _type1, std::string _type2) {
		if (_type1 == "") {
			return _type2;
		} else if (_type2 == "") {
			return _type1;
		} else {
			bool _type1_range = _type1 [0] == '[';
			bool _type2_range = _type2 [0] == '[';
			// TODO: 检查类型和范围是否匹配
			if (_type1_range && (!_type2_range)) {
				return _type2;
			} else if ((!_type1_range) && _type2_range) {
				return _type1;
			} else if (_type1_range && _type2_range) {
				// 俩范围
			} else {
				// 俩类型
			}
		}
	}
};



#endif //__NEED_CACHE_HPP__
