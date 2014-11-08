#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include <string>

#include <Terminal.hpp>

namespace miniMAT {
    namespace ast {
        class Identifier : public Terminal {
        public:
            Identifier(const std::string& spelling) : Terminal(spelling) {}
            virtual ~Identifier() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            double VisitEvaluate() const;
        };
    }
}

#endif
