#include <ExprStmt.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        ExprStmt<ArgType, ResultType>::ExprStmt(
                                const Expression<ArgType, ResultType>& expr) {
            // TODO Change this to use some kind of pointer
            this->expr = expr;
        }
        
        template<typename ArgType, typename ResultType>
        ResultType ExprStmt<ArgType, ResultType>::visit(
                                Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitExprStmt(*this, arg);
        }
    }
}
