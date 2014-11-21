#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <map>
#include <memory>

#include <Matrix.hpp>

#include <ErrorReporter.hpp>

namespace miniMAT {
    namespace ast {
        class AST {
        public:
            virtual ~AST() {}

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;
        };
    }
}

#endif
