#ifndef MINIMAT_LEXER_LEXER_HPP
#define MINIMAT_LEXER_LEXER_HPP

#include <string>
#include <sstream>
#include <memory>
#include <set>
#include <functional>

#include <miniMAT/lexer/Token.hpp>
#include <miniMAT/reporter/ErrorReporter.hpp>

#include <miniMAT/util/Stream.hpp>

namespace miniMAT {
    namespace lexer {
        class Lexer {
        private:
            std::string           input_line;
            std::set<std::string> keywords;
            util::Stream<char>    chars;

            std::shared_ptr<reporter::ErrorReporter> reporter;

        public:
            Lexer() {}
            Lexer(const std::string& input_line, std::shared_ptr<reporter::ErrorReporter> reporter);

            Lexer& operator=(const Lexer& lexer);

            Token GetToken();

        private:
            void LexerError(const std::string& error);
        };
    }
}

#endif
