#ifndef MINIMAT_AST_REFERENCE_HPP
#define MINIMAT_AST_REFERENCE_HPP

#include <miniMAT/ast/AST.hpp>

#include <miniMAT/visit/Visitors.hpp>

namespace miniMAT {
    namespace ast {
        struct Reference : public AST {
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
