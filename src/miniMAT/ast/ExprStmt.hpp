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
            ExprStmt(std::shared_ptr<Expression> expr);

            virtual ~ExprStmt() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;

        //private:
            std::shared_ptr<Expression> expr;
        };
    }
}

#endif
