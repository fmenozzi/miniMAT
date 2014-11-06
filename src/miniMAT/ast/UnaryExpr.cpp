#include <UnaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        UnaryExpr::UnaryExpr(std::shared_ptr<Operator> op,
                             std::shared_ptr<Expression> expr) {
            this->op   = op;
            this->expr = expr;
        }

        std::string UnaryExpr::GetClassName() const {
            return "UnaryExpr";
        }

        void UnaryExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->op->VisitDisplay(Indent(prefix));
            this->expr->VisitDisplay(Indent(Indent(prefix)));
        }
    }
}
