#include <BinaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        BinaryExpr::BinaryExpr(std::unique_ptr<Expression> left,
                               std::unique_ptr<Operator> op,
                               std::unique_ptr<Expression> right) {
            this->left  = std::move(left);
            this->op    = std::move(op);
            this->right = std::move(right);
        }

        void BinaryExpr::visit(DisplayVisitor& v, const std::string& prefix) {
            v.VisitBinaryExpr(*this, prefix);
        }

        std::string BinaryExpr::GetClassName() {
            return "BinaryExpr";
        }
    }
}
