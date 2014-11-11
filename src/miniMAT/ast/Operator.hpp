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
            double VisitEvaluate() const;
            void VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            lexer::Token token;
        };
    }
}

#endif
