#ifndef AST_HPP
#define AST_HPP

#include <string>

namespace miniMAT {
    namespace ast {
        class AST {
        public:
            virtual ~AST() {}

            virtual std::string GetClassName() const = 0;
        };
    }
}

#endif
