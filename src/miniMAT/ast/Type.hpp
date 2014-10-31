#ifndef TYPE_HPP
#define TYPE_HPP

#include <AST.hpp>
#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        class Type : public AST {
        public:
            Type(ast::TokenKind kind);
            virtual ~Type() {}

            ast::TypeKind GetKind();

        private:
            lexer::TypeKind kind;
        };
    }
}

#endif
