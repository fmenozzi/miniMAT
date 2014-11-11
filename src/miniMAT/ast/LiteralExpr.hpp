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

            virtual ~LiteralExpr() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            double VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table) const;
            void VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            std::shared_ptr<Literal> literal;
        };
    }
}

#endif
