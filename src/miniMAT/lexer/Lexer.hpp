#ifndef LEXER_HPP
#define LEXER_HPP

#include <Token.hpp>

namespace miniMAT {
    namespace lexer {
        class Lexer {
        private:
            std::string           input_line;
            char                  current_char;
            std::string::iterator iterator;
            bool                  is_done;

        public:
            Lexer(const std::string& input_line) : input_line(input_line) {
                current_char = ' ';
                iterator     = this->input_line.begin();
                is_done      = false;
            }

            Token GetToken();

        private:
            void TakeIt();
            void NextChar();
        };
    }
}

#endif
