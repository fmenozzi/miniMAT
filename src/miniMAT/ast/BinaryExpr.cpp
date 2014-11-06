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

        std::string BinaryExpr::GetClassName() const {
            return "BinaryExpr";
        }

        void BinaryExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->op->VisitDisplay(Indent(prefix));
            this->left->VisitDisplay(Indent(Indent(prefix)));
            this->right->VisitDisplay(Indent(Indent(prefix)));
        }
    }
}
