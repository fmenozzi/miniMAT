#ifndef SCALAR_TYPE_HPP
#define SCALAR_TYPE_HPP

#include <string>

#include <Type.hpp>
#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        class ScalarType : public Type {
        public:
            ScalarType(TypeKind kind) : Type(kind) {}

            virtual ~ScalarType() {}

            void visit(DisplayVisitor& v, const std::string& prefix);

            std::string GetClassName() const;

        private:
            TypeKind kind;
        };
    }
}

#endif
