#include <ErrorReporter.hpp>
#include <iostream>

namespace miniMAT {
    namespace reporter {
        ErrorReporter::ErrorReporter() {
            this->lexer_errors = std::vector<std::string>();
            this->parse_errors = std::vector<std::string>();
        }

        void ErrorReporter::AddLexerError(const std::string& error) {
            this->lexer_errors.push_back(error);
        }

        void ErrorReporter::AddParseError(const std::string& error) {
            this->parse_errors.push_back(error);
        }

        void ErrorReporter::AddCheckError(const std::string& error) {
            this->check_errors.push_back(error);
        }

        bool ErrorReporter::HasErrors() {
            return HasLexerErrors() || HasParseErrors() || HasCheckErrors();
        }

        bool ErrorReporter::HasLexerErrors() {
            return this->lexer_errors.size() > 0;
        }

        bool ErrorReporter::HasParseErrors() {
            return this->parse_errors.size() > 0;
        }

        bool ErrorReporter::HasCheckErrors() {
            return this->check_errors.size() > 0;
        }

        void ErrorReporter::ReportErrors() {
            // For now, we just output one error at a time

            if (HasLexerErrors())
                std::cout << lexer_errors[0] << std::endl;
            if (HasParseErrors())
                std::cout << parse_errors[0] << std::endl;
            if (HasCheckErrors())
                std::cout << check_errors[0] << std::endl;
        }
    }
}
