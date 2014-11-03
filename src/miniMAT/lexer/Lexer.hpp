#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <sstream>

#include <Token.hpp>
#include <ErrorReporter.hpp>

namespace miniMAT {
    namespace lexer {
        class Lexer {
        private:
            std::string              input_line;
            reporter::ErrorReporter* reporter;
            char                     current_char;
            std::stringstream        stream;
            bool                     is_done;

        public:
            Lexer() {}
            Lexer(const std::string& input_line, reporter::ErrorReporter* reporter);

            Lexer& operator=(const Lexer& lexer);

            Token GetToken();

        private:
            void TakeIt();
            void NextChar();
            void LexerError(const std::string& error);
        };
    }
}

#endif
