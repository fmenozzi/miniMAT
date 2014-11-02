#include <ExprStmt.hpp>

namespace miniMAT {
    namespace ast {
        ExprStmt::ExprStmt(const Expression& expr) {
            // TODO Change this to use some kind of pointer
            this->expr = expr;
        }

        void ExprStmt::visit(const Visitor& v) {
            v.VisitExprStmt(*this);
        }
    }
}
