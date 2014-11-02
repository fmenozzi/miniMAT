#ifndef EXPR_STMT_HPP
#define EXPR_STMT_HPP

#include <memory>

#include <Expression.hpp>
#include <Statement.hpp>

namespace miniMAT {
    namespace ast {
        class ExprStmt : public Statement {
        public:
            ExprStmt(std::unique_ptr<Expression> expr);

            void visit(Visitor& v);

        private:
            std::unique_ptr<Expression> expr;
        };
    }
}

#endif
