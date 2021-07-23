#ifndef __NEED_CACHE_HPP__
#define __NEED_CACHE_HPP__



#include <FaParser.h>



class AstCheck {
public:
	static bool NeedExternCache (FaParser::ExprContext *_expr_raw) {
		return _check_is_ifexpr (_expr_raw) && _check_expr_is_self (_expr_raw);
	}

private:
	static bool _check_is_ifexpr (FaParser::ExprContext *_expr_raw) {
		auto _expr_base_raw = _expr_raw->strongExpr ()->strongExprBase ();
		if (_expr_base_raw->quotExpr ()) {
			return _check_is_ifexpr (_expr_base_raw->quotExpr ()->expr ());
		} else {
			return !!_expr_base_raw->ifExpr ();
		}
	}

	static bool _check_expr_is_self (FaParser::ExprContext *_expr_raw) {
		// 检查weak后缀
		if (_expr_raw->weakExprSuffix ()) {
			auto _suffix_raw = _expr_raw->weakExprSuffix ();
			if (_suffix_raw->equalOp () || _suffix_raw->notEqualOp ()) {
				return false;
			} else if (_suffix_raw->allOp2 ().size () > 0 || _suffix_raw->ltOps ().size () > 0 || _suffix_raw->gtOps ().size () > 0) {
				return false;
			}
		}

		// 检查strong前缀
		if (_expr_raw->strongExpr ()->strongExprPrefix ().size () > 0) {
			for (auto _prefix_raws : _expr_raw->strongExpr ()->strongExprPrefix ()) {
				if (_prefix_raws->SubOp () || _prefix_raws->ReverseOp ())
					return false;
			}
		}

		// 检查strong后缀
		if (_expr_raw->strongExpr ()->strongExprSuffix ().size () > 0) {
			for (auto _suffix_raws : _expr_raw->strongExpr ()->strongExprSuffix ()) {
				if (_suffix_raws->QuotYuanL () || _suffix_raws->QuotFangL ())
					return false;
			}
		}

		return false;
	}
};



#endif //__NEED_CACHE_HPP__
