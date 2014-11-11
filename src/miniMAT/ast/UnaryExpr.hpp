#ifndef UNARY_EXPR_HPP
#define UNARY_EXPR_HPP

#include <memory>

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        class UnaryExpr : public Expression {
        public:
            UnaryExpr(std::shared_ptr<Operator> op,
                      std::shared_ptr<Expression> expr);

            virtual ~UnaryExpr() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            double VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table);
            void VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            std::shared_ptr<Operator>   op;
            std::shared_ptr<Expression> expr;
        };
    }
}

#endif
