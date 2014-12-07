#ifndef MINIMAT_LEXER_TOKENKIND_HPP
#define MINIMAT_LEXER_TOKENKIND_HPP

#include <string>
#include <map>

namespace miniMAT {
    namespace lexer {
        enum class TokenKind {
            TOK_EOF,
            TOK_ERROR,
            TOK_IDENTIFIER,
            TOK_ASSIGN,
            TOK_FLOATLIT,
            TOK_DOT,
            TOK_COMMA,
            TOK_ARITHOP,
            TOK_LPAREN,
            TOK_RPAREN,
            TOK_LBRACKET,
            TOK_RBRACKET,
            TOK_SEMICOL
        };

        std::string GetTokenSpelling(TokenKind kind);
    }
}

#endif
