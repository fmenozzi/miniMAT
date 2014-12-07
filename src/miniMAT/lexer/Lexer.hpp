#ifndef MINIMAT_LEXER_LEXER_HPP
#define MINIMAT_LEXER_LEXER_HPP

#include <string>
#include <sstream>
#include <memory>

#include <Token.hpp>
#include <ErrorReporter.hpp>

namespace miniMAT {
    namespace lexer {
        class Lexer {
        private:
            std::string       input_line;
            char              current_char;
            std::stringstream stream;
            bool              is_done;

            std::shared_ptr<reporter::ErrorReporter> reporter;

        public:
            Lexer() {}
            Lexer(const std::string& input_line, std::shared_ptr<reporter::ErrorReporter> reporter);

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
