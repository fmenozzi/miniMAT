#ifndef SCALAR_TYPE_HPP
#define SCALAR_TYPE_HPP

#include <Type.hpp>
#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        class ScalarType : public Type {
        public:
            ScalarType(TypeKind kind) : Type(kind) {}

            void visit(Visitor& v);

        private:
            TypeKind kind;
        };
    }
}

#endif
