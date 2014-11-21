#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <memory>
#include <string>

#include <Terminal.hpp>
#include <Token.hpp>

namespace miniMAT {
    namespace ast {
        class Operator : public Terminal {
        public:
            Operator(lexer::Token token) : Terminal(token.GetSpelling()) {
                this->token = token;
            }

            virtual ~Operator() {}

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
