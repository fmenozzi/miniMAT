#ifndef SCALAR_TYPE_HPP
#define SCALAR_TYPE_HPP

#include <Type.hpp>
#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        class ScalarType : public Type {
        public:
            ScalarType(TypeKind kind) : Type(kind) {}

            virtual ~ScalarType() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            double VisitEvaluate() const;

        private:
            TypeKind kind;
        };
    }
}

#endif
