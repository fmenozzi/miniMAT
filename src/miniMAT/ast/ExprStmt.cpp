#include <ExprStmt.hpp>

namespace miniMAT {
    namespace ast {
        ExprStmt::ExprStmt(const Expression& expr) {
            // TODO Change this to use some kind of pointer
            this->expr = expr;

        template<typename ArgType, typename ResultType>
        ResultType ExprStmt::visit(Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitExprStmt(*this, arg);
        }
    }
}
