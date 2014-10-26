#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include <TokenKind.hpp>

namespace miniMAT {
    namespace lexer {
        class Token {

        private:
            TokenKind kind;
            std::string      spelling;

        public:
            Token(TokenKind kind, std::string spelling)
                    : kind(kind), spelling(spelling) {}

            TokenKind   GetKind();
            std::string GetSpelling();
        };
    }
}

#endif
