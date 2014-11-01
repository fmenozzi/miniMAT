#include <BinaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        BinaryExpr<ArgType, ResultType>::BinaryExpr(
                               const Expression<ArgType, ResultType>& left,
                               const Operator<ArgType, ResultType>& op,
                               const Expression<ArgType, ResultType>& right) {
            // TODO Change this to use some kind of pointer
            this->left  = left;
            this->op    = op;
            this->right = right;
        }

        template<typename ArgType, typename ResultType>
        ResultType BinaryExpr<ArgType, ResultType>::visit(
                                                Visitor<ArgType, ResultType> v,
                                                ArgType arg) {
            return v.VisitBinaryExpr(*this, arg);
        }
    }
}
