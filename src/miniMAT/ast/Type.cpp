#include <Type.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        Type<ArgType, ResultType>::Type(TypeKind kind) {
            this->kind = kind;
        }

        template<typename ArgType, typename ResultType>
        TypeKind Type<ArgType, ResultType>::GetKind() {
            return this->kind;
        }
    }
}
