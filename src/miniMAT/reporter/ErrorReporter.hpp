#ifndef ERROR_REPORTER_HPP
#define ERROR_REPORTER_HPP

#include <vector>
#include <string>

namespace miniMAT {
    namespace reporter {
        class ErrorReporter {
        public:
            ErrorReporter();

            void AddLexerError(std::string error);
            void AddParseError(std::string error);

            bool HasErrors();

            void ReportErrors();

        private:
            std::vector<std::string> lexer_errors;
            std::vector<std::string> parse_errors;

            bool HasLexerErrors();
            bool HasParseErrors();
        };
    }
}

#endif
