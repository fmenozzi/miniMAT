#ifndef UNARY_EXPR_HPP
#define UNARY_EXPR_HPP

#include <string>
#include <memory>

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        class DisplayVisitor;

        class UnaryExpr : public Expression {
        public:
            UnaryExpr(std::shared_ptr<Operator> op,
                      std::shared_ptr<Expression> expr);

            virtual ~UnaryExpr() {}

            std::string GetClassName() const;

        private:
            std::shared_ptr<Operator>   op;
            std::shared_ptr<Expression> expr;
        };
    }
}

#endif
