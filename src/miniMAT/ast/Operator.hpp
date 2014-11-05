#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <memory>
#include <string>

#include <Terminal.hpp>
#include <Token.hpp>

namespace miniMAT {
    namespace ast {
        class DisplayVisitor;

        class Operator : public Terminal {
        public:
            Operator(lexer::Token token) : Terminal(token.GetSpelling()) {
                this->token = token;
            }

            virtual ~Operator() {}

            std::string GetClassName() const;

        private:
            lexer::Token token;
        };
    }
}

#endif
