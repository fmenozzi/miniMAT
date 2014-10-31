#include <Type.hpp>

namespace miniMAT {
    namespace ast {
        Type::Type(lexer::TokenKind kind) {
            this->kind = kind;
        }

        TypeKind GetKind() {
            return this->kind;
        }
    }
}
