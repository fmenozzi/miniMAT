#ifndef MINIMAT_AST_IDENTIFIER_HPP
#define MINIMAT_AST_IDENTIFIER_HPP

#include <string>

#include <miniMAT/ast/Terminal.hpp>

namespace miniMAT {
    namespace ast {
        struct Identifier : public Terminal {
            Identifier(const std::string& spelling) : Terminal(spelling) {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;
        };
    }
}

#endif
