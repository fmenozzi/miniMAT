#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <sstream>

#include <Token.hpp>

namespace miniMAT {
    namespace lexer {
        class Lexer {
        private:
            std::string           input_line;
            char                  current_char;
            std::stringstream     stream;
            bool                  is_done;

        public:
            Lexer() {}
            Lexer(const std::string& input_line);

            Lexer& operator=(const Lexer& lexer);

            Token GetToken();

        private:
            void TakeIt();
            void NextChar();
        };
    }
}

#endif
