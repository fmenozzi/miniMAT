#ifndef MINIMAT_AST_LITERAL_EXPR_HPP
#define MINIMAT_AST_LITERAL_EXPR_HPP

#include <memory>

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Literal.hpp>

namespace miniMAT {
    namespace ast {
        class LiteralExpr : public Expression {
        public:
            LiteralExpr(std::shared_ptr<Literal> literal);

            std::string              GetClassName() const;
            std::shared_ptr<Literal> GetLiteral() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            std::shared_ptr<Literal> literal;
        };
    }
}

#endif
