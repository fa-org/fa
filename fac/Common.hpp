#ifndef __COMMON_HPP__
#define __COMMON_HPP__



enum class PublicLevel { Public, Internal, Protected, Private };
inline PublicLevel GetPublicLevel (FaParser::PublicLevelContext *_ctx) {
	if (_ctx) {
		if (_ctx->Public ()) {
			return PublicLevel::Public;
		} else if (_ctx->Internal ()) {
			return PublicLevel::Internal;
		} else if (_ctx->Protected ()) {
			return PublicLevel::Protected;
		}
	}
	return PublicLevel::Private;
}
inline std::string GetId (FaParser::IdContext *_ctx) { return _ctx ? _ctx->getText () : ""; }
inline std::string GetId (FaParser::IdsContext *_ctx) { return _ctx ? _ctx->getText () : ""; }



#endif //__COMMON_HPP__
