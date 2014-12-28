#ifndef MINIMAT_AST_UNARY_EXPR_HPP
#define MINIMAT_AST_UNARY_EXPR_HPP

#include <memory>

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Operator.hpp>

namespace miniMAT {
    namespace ast {
        struct UnaryExpr : public Expression {
            UnaryExpr(std::shared_ptr<Operator> op,
                      std::shared_ptr<Expression> expr);

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            std::shared_ptr<Operator>   op;
            std::shared_ptr<Expression> expr;
        };
    }
}

#endif
