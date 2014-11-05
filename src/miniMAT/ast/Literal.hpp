#ifndef LITERAL_HPP
#define LITERAL_HPP

#include <string>

#include <Terminal.hpp>

namespace miniMAT {
    namespace ast {
        class Literal : public Terminal {
        public:
            Literal(const std::string& spelling) : Terminal(spelling) {}
            virtual ~Literal() {}

            virtual std::string GetClassName() = 0;
        };
    }
}

#endif
