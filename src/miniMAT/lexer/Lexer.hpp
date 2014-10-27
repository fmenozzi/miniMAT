#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>

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
            Lexer() {};
            Lexer(const std::string& input_line);

            Token GetToken();

        private:
            void TakeIt();
            void NextChar();
        };
    }
}

#endif
