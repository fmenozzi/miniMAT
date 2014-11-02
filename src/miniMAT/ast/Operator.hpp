#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <Terminal.hpp>
#include <Token.hpp>

namespace miniMAT {
    namespace ast {
        class Operator : public Terminal {
        public:
            Operator(const lexer::Token& token);

            void visit(const Visitor& v);

        private:
            // TODO Change this to use some kind of pointer
            lexer::Token token;
        };
    }
}

#endif
