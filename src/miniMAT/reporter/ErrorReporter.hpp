#ifndef ERROR_REPORTER_HPP
#define ERROR_REPORTER_HPP

#include <vector>
#include <string>

namespace miniMAT {
    namespace reporter {
        class ErrorReporter {
        public:
            ErrorReporter();

            void AddLexerError(const std::string& error);
            void AddParseError(const std::string& error);
            void AddCheckError(const std::string& error);

            bool HasErrors();

            void ReportErrors();

        private:
            std::vector<std::string> lexer_errors;
            std::vector<std::string> parse_errors;
            std::vector<std::string> check_errors;

            bool HasLexerErrors();
            bool HasParseErrors();
            bool HasCheckErrors();
        };
    }
}

#endif
