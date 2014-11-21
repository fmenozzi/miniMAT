#ifndef REFERENCE_HPP
#define REFERENCE_HPP

#include <AST.hpp>
#include <Visitors.hpp>

namespace miniMAT {
    namespace ast {
        class Reference : public AST {
        public:
            virtual ~Reference() {}

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;
        };
    }
}

#endif
