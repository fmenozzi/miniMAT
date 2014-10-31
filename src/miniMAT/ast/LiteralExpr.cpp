#include <LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(const Literal& literal) {
            // TODO Change this to use some kind of pointer
            this->literal = literal;

        template<typename ArgType, typename ResultType>
        ResultType LiteralExpr::visit(Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitLiteralExpr(*this, arg);
        }
    }
}
