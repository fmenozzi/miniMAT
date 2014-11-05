#ifndef EXPR_STMT_HPP
#define EXPR_STMT_HPP

#include <memory>
#include <string>

#include <Expression.hpp>
#include <Statement.hpp>

namespace miniMAT {
    namespace ast {
        class ExprStmt : public Statement {
        public:
            ExprStmt(std::unique_ptr<Expression> expr);

            virtual ~ExprStmt() {}

            void visit(DisplayVisitor& v, const std::string& prefix);

        private:
            std::unique_ptr<Expression> expr;
        };
    }
}

#endif
