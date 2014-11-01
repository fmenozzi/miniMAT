#include <LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        LiteralExpr<ArgType, ResultType>::LiteralExpr(
                                    const Literal<ArgType, ResultType>& literal) {
            // TODO Change this to use some kind of pointer
            this->literal = literal;
        }
        
        template<typename ArgType, typename ResultType>
        ResultType LiteralExpr<ArgType, ResultType>::visit(
                            Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitLiteralExpr(*this, arg);
        }
    }
}
