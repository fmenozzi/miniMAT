#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <AST.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class Statement : public AST<ArgType, ResultType> {
        public:
            virtual ~Statement() {}
        };
    }
}

#endif
