
// Generated from Fa.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "FaVisitor.h"


/**
 * This class provides an empty implementation of FaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FaBaseVisitor : public FaVisitor {
public:

  virtual antlrcpp::Any visitS(FaParser::SContext *ctx) override {
    return visitChildren(ctx);
  }


};

