#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <memory>

#include <Terminal.hpp>
#include <Token.hpp>

namespace miniMAT {
    namespace ast {
        class Operator : public Terminal {
        public:
            Operator(std::unique_ptr<lexer::Token> token) : Terminal(token->GetSpelling()) {
                this->token = std::move(token);
            }

            void visit(Visitor& v);

        private:
            std::unique_ptr<lexer::Token> token;
        };
    }
}

#endif
