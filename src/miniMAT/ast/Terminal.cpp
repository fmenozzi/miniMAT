#include <Terminal.hpp>

namespace miniMAT {
    namespace ast {
        Terminal::Terminal(const std::string& spelling) {
            this->spelling = spelling;
        }

        std::string Terminal::GetSpelling() {
            return spelling;
        }
    }
}
