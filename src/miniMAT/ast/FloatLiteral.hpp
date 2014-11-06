#ifndef FLOAT_LITERAL_HPP
#define FLOAT_LITERAL_HPP

#include <string>

#include <Literal.hpp>

namespace miniMAT {
    namespace ast {
        class FloatLiteral : public Literal {
        public:
            FloatLiteral(const std::string& spelling) : Literal(spelling) {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
        };
    }
}

#endif
