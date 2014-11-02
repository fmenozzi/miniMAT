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

            void visit(Visitor& v);

        private:
            std::shared_ptr<Literal> literal;
        };
    }
}

#endif
