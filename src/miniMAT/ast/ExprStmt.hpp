#ifndef MINIMAT_AST_EXPR_STMT_HPP
#define MINIMAT_AST_EXPR_STMT_HPP

#include <memory>
#include <string>

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Statement.hpp>

namespace miniMAT {
    namespace ast {
        struct ExprStmt : public Statement {
            ExprStmt(std::shared_ptr<Expression> expr);

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            std::shared_ptr<Expression> expr;
        };
    }
}

#endif
