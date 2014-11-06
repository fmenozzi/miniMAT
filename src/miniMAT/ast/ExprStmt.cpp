#include <ExprStmt.hpp>

namespace miniMAT {
    namespace ast {
        ExprStmt::ExprStmt(std::shared_ptr<Expression> expr) {
            this->expr = expr;
        }

        std::string ExprStmt::GetClassName() const {
            return "ExprStmt";
        }

        void ExprStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->expr->VisitDisplay(Indent(prefix));
        }

        double ExprStmt::VisitEvaluate() const {
            return this->expr->VisitEvaluate();
        }
    }
}
