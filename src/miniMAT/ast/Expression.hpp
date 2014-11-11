#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <AST.hpp>
#include <Visitors.hpp>

namespace miniMAT {
    namespace ast {
        class Expression : public AST {
        public:
            virtual ~Expression() {}

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual double VisitEvaluate() const = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;
        };
    }
}

#endif
