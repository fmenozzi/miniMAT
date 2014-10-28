#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include <TokenKind.hpp>

namespace miniMAT {
    namespace lexer {
        class Token {

        private:
            TokenKind   kind;
            std::string spelling;

        public:
            Token() {}
            Token(TokenKind kind, const std::string& spelling);

            TokenKind   GetKind();
            std::string GetSpelling();
        };
    }
}

#endif
