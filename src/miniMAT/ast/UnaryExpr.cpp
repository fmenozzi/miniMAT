#include <UnaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        UnaryExpr::UnaryExpr(const Operator& op, const Expression& expr) {
            // TODO Change this to use some kind of pointer
            this->op   = op;
            this->expr = expr;
        }

        template<typename ArgType, typename ResultType>
        ResultType UnaryExpr::visit(Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitUnaryExpr(*this, arg);
        }
    }
}
