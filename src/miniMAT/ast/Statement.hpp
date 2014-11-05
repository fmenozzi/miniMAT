#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <AST.hpp>

namespace miniMAT {
    namespace ast {
        class Statement : public AST {
        public:
            virtual ~Statement() {}

            virtual std::string GetClassName() = 0;
        };
    }
}

#endif
