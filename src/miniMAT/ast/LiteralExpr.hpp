#ifndef LITERAL_EXPR_HPP
#define LITERAL_EXPR_HPP

#include <Literal.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class LiteralExpr : public Expression {
        public:
            LiteralExpr(const Literal& literal);

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);

        private:
            // TODO Change this to use some kind of pointer
            Literal literal;
        };
    }
}

#endif
