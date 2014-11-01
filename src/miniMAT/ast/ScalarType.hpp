#ifndef SCALAR_TYPE_HPP
#define SCALAR_TYPE_HPP

#include <Type.hpp>
#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class ScalarType : public Type<ArgType, ResultType> {
        public:
            ScalarType(TypeKind kind);

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);

        private:
            TypeKind kind;
        };
    }
}

#endif
