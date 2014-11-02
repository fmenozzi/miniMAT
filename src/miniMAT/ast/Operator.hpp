#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <memory>

#include <Terminal.hpp>
#include <Token.hpp>

namespace miniMAT {
    namespace ast {
        class Operator : public Terminal {
        public:
            Operator(std::shared_ptr<lexer::Token> token) : Terminal(token->GetSpelling()) {
                this->token = token;
            }

            void visit(Visitor& v);

        private:
            std::shared_ptr<lexer::Token> token;
        };
    }
}

#endif
