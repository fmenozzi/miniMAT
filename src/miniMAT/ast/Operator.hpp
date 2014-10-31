#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <Terminal.hpp>
#include <Token.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType typename ResultType>
        class Operator : public Terminal {
        public:
            Operator(const Token& token);

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);

        private:
            // TODO Change this to use some kind of pointer
            Token token;
        }
    }
}

#endif
