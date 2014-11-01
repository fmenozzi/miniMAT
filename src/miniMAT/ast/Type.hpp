#ifndef TYPE_HPP
#define TYPE_HPP

#include <AST.hpp>
#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class Type : public AST<ArgType, ResultType> {
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
