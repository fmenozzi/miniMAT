#include <ExprStmt.hpp>

namespace miniMAT {
    namespace ast {
        ExprStmt::ExprStmt(std::unique_ptr<Expression> expr) {
            this->expr = std::move(expr);
        }

        void ExprStmt::visit(Visitor& v) {
            v.VisitExprStmt(*this);
        }
    }
}
