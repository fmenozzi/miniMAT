#ifndef UNARY_EXPR_HPP
#define UNARY_EXPR_HPP

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class UnaryExpr : public Expression<ArgType, ResultType> {
        public:
            UnaryExpr(const Operator<ArgType, ResultType>& op,
                      const Expression<ArgType, ResultType>& expr);

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);

        private:
            // TODO Change this to use some kind of pointer
            Operator<ArgType, ResultType>   op;
            Expression<ArgType, ResultType> expr;
        };
    }
}

#endif
