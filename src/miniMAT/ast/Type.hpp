#ifndef TYPE_HPP
#define TYPE_HPP

#include <AST.hpp>
#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        class Type : public AST {
        public:
            Type(TypeKind kind);
            virtual ~Type() {}

            TypeKind GetKind();

        private:
            TypeKind kind;
        };
    }
}

#endif
