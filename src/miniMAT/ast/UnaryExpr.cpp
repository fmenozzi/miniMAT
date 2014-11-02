#include <UnaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        UnaryExpr::UnaryExpr(std::shared_ptr<Operator> op,
                             std::shared_ptr<Expression> expr) {
            this->op   = op;
            this->expr = expr;
        }

        void UnaryExpr::visit(Visitor& v) {
            v.VisitUnaryExpr(*this);
        }
    }
}
