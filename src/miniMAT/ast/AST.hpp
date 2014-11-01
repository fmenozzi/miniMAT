#ifndef AST_HPP
#define AST_HPP

#include <Visitor.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class AST {
        public:
            virtual ~AST() {}

            virtual ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg) = 0;
        };
    }
}

#endif
