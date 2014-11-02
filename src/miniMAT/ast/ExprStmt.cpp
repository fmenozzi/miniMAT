#include <ExprStmt.hpp>

namespace miniMAT {
    namespace ast {
        ExprStmt::ExprStmt(std::shared_ptr<Expression> expr) {
            this->expr = expr;
        }

        void ExprStmt::visit(Visitor& v) {
            v.VisitExprStmt(*this);
        }
    }
}
