#include <BinaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        BinaryExpr::BinaryExpr(const Expression& left,
                               const Operator& op,
                               const Expression& right) {
            // TODO Change this to use some kind of pointer
            this->left  = left;
            this->op    = op;
            this->right = right;
        }

        void BinaryExpr::visit(const Visitor& v) {
            v.VisitBinaryExpr(*this);
        }
    }
}
