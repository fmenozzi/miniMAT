#ifndef TOKENKIND_HPP
#define TOKENKIND_HPP

#include <string>
#include <map>

namespace miniMAT {
    namespace lexer {
        enum class TokenKind {
            TOK_EOF,
            TOK_ERROR,
            TOK_IDENTIFIER,
            TOK_FLOATLIT,
            TOK_DOT,
            TOK_ARITHOP,
            TOK_LPAREN,
            TOK_RPAREN
        };

        // Uncomment to fail linking
        //std::map<std::string, lexer::TokenKind> token_spellings;
    }
}

#endif
