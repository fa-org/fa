#ifndef __CODE_VISITOR_HPP__
#define __CODE_VISITOR_HPP__



#include "FaBaseVisitor.h"



class CodeVisitor: public FaVisitor {
public:
    virtual antlrcpp::Any visitUseExpr (FaParser::UseExprContext *ctx) override {
        return (ctx->ID () ? ctx->ID () : ctx->IDs ())->getText ();
    }

    virtual antlrcpp::Any visitProgram (FaParser::ProgramContext *ctx) override {
        auto _v = ctx->useExpr ();
        return visitUseExpr (_v [2]);
    }
};



#endif //__CODE_VISITOR_HPP__
