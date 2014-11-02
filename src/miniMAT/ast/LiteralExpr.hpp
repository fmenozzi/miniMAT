#ifndef LITERAL_EXPR_HPP
#define LITERAL_EXPR_HPP

#include <Expression.hpp>
#include <Literal.hpp>

namespace miniMAT {
    namespace ast {
        class LiteralExpr : public Expression {
        public:
            LiteralExpr(const Literal& literal);

            void visit(const Visitor& v);

        private:
            // TODO Change this to use some kind of pointer
            Literal literal;
        };
    }
}

#endif
