#ifndef TYPE_HPP
#define TYPE_HPP

#include <TokenKind.hpp>

namespace miniMAT {
    namespace ast {
        class Type : public AST {
        public:
            virtual ~Type() {}

            virtual Type(lexer::TokenKind kind);

        private:
            lexer::TypeKind kind;
        };
    }
}

#endif
