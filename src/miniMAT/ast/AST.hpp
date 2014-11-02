#ifndef AST_HPP
#define AST_HPP

#include <Visitor.hpp>

namespace miniMAT {
    namespace ast {
        class AST {
        public:
            virtual ~AST() {}

            virtual void visit(Visitor& v) = 0;
        };
    }
}

#endif
