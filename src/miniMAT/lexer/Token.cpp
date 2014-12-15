#include <string>

#include <miniMAT/lexer/Token.hpp>

namespace miniMAT {
    namespace lexer {
        Token::Token(TokenKind kind, const std::string& spelling) {
            this->kind     = kind;
            this->spelling = spelling;
        }

        TokenKind Token::GetKind() {
            return kind;
        }

        std::string Token::GetSpelling() const {
            return std::string(spelling);
        }
    }
}
