#include <ExprStmt.hpp>

namespace miniMAT {
    namespace ast {
        ExprStmt::ExprStmt(std::unique_ptr<Expression> expr) {
            this->expr = std::move(expr);
        }

        void ExprStmt::visit(DisplayVisitor& v, const std::string& prefix) {
            v.VisitExprStmt(*this, prefix);
        }

        std::string ExprStmt::GetClassName() const {
            return "ExprStmt";
        }
    }
}
