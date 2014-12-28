#include <miniMAT/ast/Terminal.hpp>

namespace miniMAT {
    namespace ast {
        Terminal::Terminal(const std::string& spelling) {
            this->spelling = spelling;
        }

        std::string Terminal::Spelling() const {
            return spelling;
        }
    }
}
