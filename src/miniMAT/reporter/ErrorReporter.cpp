#include <ErrorReporter.hpp>
#include <iostream>

namespace miniMAT {
    namespace reporter {
        ErrorReporter::ErrorReporter() {
            this->lexer_errors = std::vector<std::string>();
            this->parse_errors = std::vector<std::string>();
        }

        void ErrorReporter::AddLexerError(std::string error) {
            this->lexer_errors.push_back(error);
        }

        void ErrorReporter::AddParseError(std::string error) {
            this->parse_errors.push_back(error);
        }

        bool ErrorReporter::HasErrors() {
            return HasLexerErrors() || HasParseErrors();
        }

        bool ErrorReporter::HasLexerErrors() {
            return this->lexer_errors.size() > 0;
        }

        bool ErrorReporter::HasParseErrors() {
            return this->parse_errors.size() > 0;
        }

        void ErrorReporter::ReportErrors() {
            // For now, we just output one error at a time

            if (HasLexerErrors())
                std::cout << lexer_errors[0] << std::endl;
            if (HasParseErrors())
                std::cout << parse_errors[0] << std::endl;
        }
    }
}
