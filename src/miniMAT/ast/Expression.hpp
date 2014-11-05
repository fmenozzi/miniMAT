#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <AST.hpp>

namespace miniMAT {
    namespace ast {
        class Expression : public AST {
        public:
            virtual ~Expression() {}

            virtual std::string GetClassName() = 0;
        };
    }
}

#endif
