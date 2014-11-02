#include <BinaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        BinaryExpr::BinaryExpr(std::shared_ptr<Expression> left,
                               std::shared_ptr<Operator> op,
                               std::shared_ptr<Expression> right) {
            this->left  = left;
            this->op    = op;
            this->right = right;
        }

        void BinaryExpr::visit(Visitor& v) {
            v.VisitBinaryExpr(*this);
        }
    }
}
