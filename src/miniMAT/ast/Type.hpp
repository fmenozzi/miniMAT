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

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;

        private:
            TypeKind kind;
        };
    }
}

#endif
