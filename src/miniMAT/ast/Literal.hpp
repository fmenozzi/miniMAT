#ifndef MINIMAT_AST_LITERAL_HPP
#define MINIMAT_AST_LITERAL_HPP

#include <string>

#include <miniMAT/ast/Terminal.hpp>

namespace miniMAT {
    namespace ast {
        struct Literal : public Terminal {
            Literal(const std::string& spelling) : Terminal(spelling) {}
            virtual ~Literal() {}

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;
        };
    }
}

#endif
