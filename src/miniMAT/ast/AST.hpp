#ifndef MINIMAT_AST_AST_HPP
#define MINIMAT_AST_AST_HPP

#include <string>
#include <map>
#include <memory>

#include <miniMAT/ast/Matrix.hpp>

#include <miniMAT/reporter/ErrorReporter.hpp>

namespace miniMAT {
    namespace ast {
        struct AST 
        {
            virtual ~AST() {}

            virtual std::string ClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;

            virtual void PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                     ast::Matrix ans,
                                     bool suppressed) const = 0;
        };
    }
}

#endif
