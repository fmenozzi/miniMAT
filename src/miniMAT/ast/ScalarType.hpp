#ifndef SCALAR_TYPE_HPP
#define SCALAR_TYPE_HPP

#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class ScalarType : public Type {
        public:
            ScalarType(TypeKind kind);

            ResultType visit(const Visitor<ArgType, ResultType>& v, ArgType arg);

        private:
            TypeKind kind;
        };
    }
}

#endif
