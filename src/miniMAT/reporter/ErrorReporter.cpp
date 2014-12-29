#include <miniMAT/reporter/ErrorReporter.hpp>

#include <iostream>
#include <cstdio>

namespace miniMAT {
    namespace reporter {
        void ErrorReporter::AddLexerError(const std::string& error) {
            lexer_errors.push_back(error);
        }

        void ErrorReporter::AddParseError(const std::string& error) {
            parse_errors.push_back(error);
        }

        void ErrorReporter::AddCheckError(const std::string& error) {
            check_errors.push_back(error);
        }

        bool ErrorReporter::HasErrors() {
            return HasLexerErrors() or HasParseErrors() or HasCheckErrors();
        }

        bool ErrorReporter::HasLexerErrors() {
            return lexer_errors.size() > 0;
        }

        bool ErrorReporter::HasParseErrors() {
            return parse_errors.size() > 0;
        }

        bool ErrorReporter::HasCheckErrors() {
            return check_errors.size() > 0;
        }

        void ErrorReporter::ReportErrors() {
            // For now, we just output one error at a time

            if (HasLexerErrors())
                std::cout << lexer_errors[0] << std::endl;
            if (HasParseErrors())
                std::cout << parse_errors[0] << std::endl;
            if (HasCheckErrors())
                std::cout << check_errors[0] << std::endl;
            
            /*
            if (HasLexerErrors())
                std::printf("%c[1;31m%s\n", 27, lexer_errors[0].c_str()); // red
            if (HasParseErrors())
                std::printf("%c[1;31m%s\n", 27, parse_errors[0].c_str()); // red
            if (HasCheckErrors())
                std::printf("%c[1;31m%s\n", 27, check_errors[0].c_str()); // red
            */
        }
    }
}
