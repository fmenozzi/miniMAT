#ifndef EXPR_STMT_HPP
#define EXPR_STMT_HPP

#include <Expression.hpp>
#include <Statement.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class ExprStmt : public Statement<ArgType, ResultType> {
        public:
            ExprStmt(const Expression<ArgType, ResultType>& expr);

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);

        private:
            // TODO Change this to use some kind of pointer
            Expression<ArgType, ResultType> expr;
        };
    }
}

#endif
