#ifndef EXPR_STMT_HPP
#define EXPR_STMT_HPP

#include <Expression.hpp>
#include <Statement.hpp>

namespace miniMAT {
    namespace ast {
        class ExprStmt : public Statement {
        public:
            ExprStmt(const Expression& expr);

            void visit(const Visitor& v);

        private:
            // TODO Change this to use some kind of pointer
            Expression expr;
        };
    }
}

#endif
