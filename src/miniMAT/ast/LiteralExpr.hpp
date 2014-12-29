#ifndef MINIMAT_AST_LITERAL_EXPR_HPP
#define MINIMAT_AST_LITERAL_EXPR_HPP

#include <memory>

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Literal.hpp>

namespace miniMAT {
    namespace ast {
        struct LiteralExpr : public Expression {
            LiteralExpr(std::shared_ptr<Literal> literal);

            std::string              ClassName() const;
            std::shared_ptr<Literal> GetLiteral() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            std::shared_ptr<Literal> literal;
        };
    }
}

#endif
