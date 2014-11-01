#ifndef LITERAL_HPP
#define LITERAL_HPP

#include <string>

#include <Terminal.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class Literal : public Terminal<ArgType, ResultType> {
        public:
            Literal(const std::string& spelling)
                        : Terminal<ArgType, ResultType>(spelling) {}
            virtual ~Literal() {}
        };
    }
}

#endif
