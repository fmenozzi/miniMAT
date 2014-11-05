#ifndef AST_HPP
#define AST_HPP

#include <DisplayVisitor.hpp>

namespace miniMAT {
    namespace ast {
        class AST {
        public:
            virtual ~AST() {}

            virtual void visit(DisplayVisitor& v, const std::string& prefix) = 0;
        };
    }
}

#endif
