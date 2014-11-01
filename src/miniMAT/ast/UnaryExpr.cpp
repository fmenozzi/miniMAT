#include <UnaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        UnaryExpr<ArgType, ResultType>::UnaryExpr(
                            const Operator<ArgType, ResultType>& op,
                            const Expression<ArgType, ResultType>& expr) {
            // TODO Change this to use some kind of pointer
            this->op   = op;
            this->expr = expr;
        }

        template<typename ArgType, typename ResultType>
        ResultType UnaryExpr<ArgType, ResultType>::visit(
                                Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitUnaryExpr(*this, arg);
        }
    }
}
