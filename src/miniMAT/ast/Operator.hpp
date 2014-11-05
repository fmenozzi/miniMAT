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
            Operator(std::unique_ptr<lexer::Token> token) : Terminal(token->GetSpelling()) {
                this->token = std::move(token);
            }

            virtual ~Operator() {}

            void visit(DisplayVisitor& v, const std::string& prefix);

            std::string GetClassName();

        private:
            std::unique_ptr<lexer::Token> token;
        };
    }
}

#endif
