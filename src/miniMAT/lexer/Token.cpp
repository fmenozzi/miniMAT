#include <string>

#include <Token.hpp>

namespace miniMAT {
    namespace lexer {
        TokenKind Token::GetKind() {
            return kind;
        }

        std::string Token::GetSpelling() {
            return spelling;
        }
    }
}
