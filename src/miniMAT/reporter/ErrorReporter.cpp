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
            if (HasLexerErrors()) {
                std::cout << "LEXER ERROR(S):" << std::endl;
                for (auto error : this->lexer_errors)
                    std::cout << "\t-" << error << std::endl;
            }

            if (HasParseErrors()) {
                std::cout << "PARSE ERROR(S):" << std::endl;
                for (auto error : this->parse_errors)
                    std::cout << "\t-" << error << std::endl;
            }
        }
    }
}
