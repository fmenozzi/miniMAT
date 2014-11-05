#include <UnaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        UnaryExpr::UnaryExpr(std::unique_ptr<Operator> op,
                             std::unique_ptr<Expression> expr) {
            this->op   = std::move(op);
            this->expr = std::move(expr);
        }

        void UnaryExpr::visit(DisplayVisitor& v, const std::string& prefix) {
            v.VisitUnaryExpr(*this, prefix);
        }

        std::string UnaryExpr::GetClassName() {
            return "UnaryExpr";
        }
    }
}
