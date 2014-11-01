#ifndef FLOAT_LITERAL_HPP
#define FLOAT_LITERAL_HPP

#include <Literal.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class FloatLiteral : public Literal<ArgType, ResultType> {
        public:
            FloatLiteral(const std::string& spelling)
                : Literal<ArgType, ResultType>(spelling) {}

            ResultType visit(Visitor<ArgType, ResultType> v, ArgType arg);
        };
    }
}

#endif
