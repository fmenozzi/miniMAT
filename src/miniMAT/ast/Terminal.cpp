#include <Terminal.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        Terminal<ArgType, ResultType>::Terminal(const std::string& spelling) {
            this->spelling = spelling;
        }

        template<typename ArgType, typename ResultType>
        std::string Terminal<ArgType, ResultType>::GetSpelling() {
            return spelling;
        }
    }
}
