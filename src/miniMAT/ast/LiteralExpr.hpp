#ifndef LITERAL_EXPR_HPP
#define LITERAL_EXPR_HPP

#include <memory>

#include <Expression.hpp>
#include <Literal.hpp>

namespace miniMAT {
    namespace ast {
        class LiteralExpr : public Expression {
        public:
            LiteralExpr(std::shared_ptr<Literal> literal);

            virtual ~LiteralExpr() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;

        //private:
            std::shared_ptr<Literal> literal;
        };
    }
}

#endif
