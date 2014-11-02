#include <UnaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        UnaryExpr::UnaryExpr(const Operator& op, const Expression& expr) {
            // TODO Change this to use some kind of pointer
            this->op   = op;
            this->expr = expr;
        }

        void UnaryExpr::visit(const Visitor& v) {
            v.VisitUnaryExpr(*this);
        }
    }
}
