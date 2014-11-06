#ifndef BINARY_EXPR_HPP
#define BINARY_EXPR_HPP

#include <memory>

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        class BinaryExpr : public Expression {
        public:
            BinaryExpr(std::shared_ptr<Expression> left,
                       std::shared_ptr<Operator> op,
                       std::shared_ptr<Expression> right);

            virtual ~BinaryExpr() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;

        private:
            std::shared_ptr<Expression> left;
            std::shared_ptr<Operator>   op;
            std::shared_ptr<Expression> right;
        };
    }
}

#endif
