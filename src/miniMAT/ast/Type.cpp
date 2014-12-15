#include <miniMAT/ast/Type.hpp>

namespace miniMAT {
    namespace ast {
        Type::Type(TypeKind kind) {
            this->kind = kind;
        }

        TypeKind Type::GetKind() const {
            return this->kind;
        }
    }
}
