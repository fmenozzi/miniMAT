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

        template<typename ArgType, typename ResultType>
        ResultType BinaryExpr::visit(Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitBinaryExpr(*this, arg);
        }
    }
}
