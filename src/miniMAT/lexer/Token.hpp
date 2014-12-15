#ifndef MINIMAT_LEXER_TOKEN_HPP
#define MINIMAT_LEXER_TOKEN_HPP

#include <string>

#include <miniMAT/lexer/TokenKind.hpp>

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
            std::string GetSpelling() const;
        };
    }
}

#endif
