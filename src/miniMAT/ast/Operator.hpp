#ifndef MINIMAT_AST_OPERATOR_HPP
#define MINIMAT_AST_OPERATOR_HPP

#include <memory>
#include <string>

#include <miniMAT/ast/Terminal.hpp>

#include <miniMAT/lexer/Token.hpp>

namespace miniMAT {
    namespace ast {
        struct Operator : public Terminal 
        {
            Operator(lexer::Token token) 
                : Terminal(token.Spelling()) 
            {
                this->token = token;
            }

            std::string ClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            void PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                             ast::Matrix ans,
                             bool suppressed) const;

            lexer::Token token;
        };
    }
}

#endif
