#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <Terminal.hpp>
#include <Token.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class Operator : public Terminal<ArgType, ResultType> {
        public:
            Operator(const lexer::Token& token);

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);

        private:
            // TODO Change this to use some kind of pointer
            lexer::Token token;
        };
    }
}

#endif
