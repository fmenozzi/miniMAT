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

        }
    }
}
