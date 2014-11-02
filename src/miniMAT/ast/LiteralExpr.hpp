#ifndef LITERAL_EXPR_HPP
#define LITERAL_EXPR_HPP

#include <memory>

#include <Expression.hpp>
#include <Literal.hpp>

namespace miniMAT {
    namespace ast {
        class LiteralExpr : public Expression {
        public:
            LiteralExpr(std::unique_ptr<Literal> literal);

            void visit(Visitor& v);

        private:
            std::unique_ptr<Literal> literal;
        };
    }
}

#endif
