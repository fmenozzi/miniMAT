#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <string>

#include <AST.hpp>

namespace miniMAT {
    namespace ast {
        class Terminal : public AST {
        public:
            Terminal(const std::string& spelling);
            virtual ~Terminal() {}

            std::string GetSpelling();

            virtual std::string GetClassName() const = 0;

        private:
            std::string spelling;
        };
    }
}

#endif
