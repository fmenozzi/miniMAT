#ifndef BINARY_EXPR_HPP
#define BINARY_EXPR_HPP

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class BinaryExpr : public Expression<ArgType, ResultType> {
        public:
            BinaryExpr(const Expression<ArgType, ResultType>& left,
                       const Operator<ArgType, ResultType>& op,
                       const Expression<ArgType, ResultType>& right);

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);

        private:
            // TODO Change this to use some kind of pointer
            Expression<ArgType, ResultType> left;
            Operator<ArgType, ResultType>   op;
            Expression<ArgType, ResultType> right;
        };
    }
}

#endif
