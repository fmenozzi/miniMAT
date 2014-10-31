#ifndef BINARY_EXPR_HPP
#define BINARY_EXPR_HPP

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class BinaryExpr : public Expression {
        public:
            BinaryExpr(const Expression& left, const Operator& op, const Expression& right);

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);

        private:
            // TODO Change this to use some kind of pointer
            Expression left;
            Operator   op;
            Expression right;
        };
    }
}

#endif
