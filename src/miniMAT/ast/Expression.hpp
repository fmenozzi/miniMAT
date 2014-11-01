#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <AST.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class Expression : public AST<ArgType, ResultType> {
        public:
            virtual ~Expression() {}
        };
    }
}

#endif
