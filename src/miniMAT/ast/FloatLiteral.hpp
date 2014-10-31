#ifndef FLOAT_LITERAL_HPP
#define FLOAT_LITERAL_HPP

#include <Literal.hpp>
#include <Visitor.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class FloatLiteral : public Literal {
        public:
            FloatLiteral(const std::string& spelling) : Literal(spelling);
            virtual ~FloatLiteral() {}

            ResultType visit(const Visitor<ArgType, ResultType>& v, ArgType arg);

        }
    }
}

#endif
