#ifndef MINIMAT_AST_TERMINAL_HPP
#define MINIMAT_AST_TERMINAL_HPP

#include <miniMAT/ast/AST.hpp>

#include <miniMAT/visit/Visitors.hpp>

namespace miniMAT {
    namespace ast {
        struct Terminal : public AST {
            Terminal(const std::string& spelling);
            virtual ~Terminal() {}

            std::string Spelling() const;

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;

        private:
            std::string spelling;
        };
    }
}

#endif
