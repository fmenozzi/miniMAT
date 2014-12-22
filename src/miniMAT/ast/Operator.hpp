#ifndef MINIMAT_AST_OPERATOR_HPP
#define MINIMAT_AST_OPERATOR_HPP

#include <memory>
#include <string>

#include <miniMAT/ast/Terminal.hpp>

#include <miniMAT/lexer/Token.hpp>

namespace miniMAT {
    namespace ast {
        class Operator : public Terminal {
        public:
            Operator(lexer::Token token) : Terminal(token.GetSpelling()) {
                this->token = token;
            }

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            lexer::Token token;
        };
    }
}

#endif
