#include <string>

#include <miniMAT/lexer/Token.hpp>

namespace miniMAT {
    namespace lexer {
        Token::Token(TokenKind kind, const std::string& spelling) {
            this->kind     = kind;
            this->spelling = spelling;
        }

        TokenKind Token::Kind() {
            return kind;
        }

        std::string Token::Spelling() const {
            return std::string(spelling);
        }
    }
}
