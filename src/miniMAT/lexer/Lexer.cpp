#include <cctype>
#include <iostream>

#include <Lexer.hpp>

namespace miniMAT {
    namespace lexer {
        Lexer& Lexer::operator=(const Lexer& lexer) {
            if (this != &lexer) {
                this->input_line   = lexer.input_line;
                this->reporter     = lexer.reporter;
                this->current_char = lexer.current_char;

                this->stream.str(input_line);
                this->stream >> std::noskipws;

                this->is_done = false;
            }

            return *this;
        }

        Lexer::Lexer(const std::string& input_line, reporter::ErrorReporter* reporter) {
            this->input_line   = input_line;
            this->reporter     = reporter;
            this->current_char = ' ';

            this->stream.str(input_line);
            this->stream >> std::noskipws;

            this->is_done = false;
        }

        Token Lexer::GetToken() {
           // Pass through whitespace
            while (current_char == ' ' || current_char == '\t' || current_char == '\n')
                TakeIt();

            // Check for end of line
            if (is_done)
                return Token(TokenKind::TOK_EOF, "EOF");

            // Non-identifiers
            char temp;
            std::string numstr;
            switch (current_char) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    temp = current_char;
                    TakeIt();

                    // Reject -- and ++
                    if ((temp == '+' && current_char == '+') || (temp == '-' && current_char == '-')) {
                        TakeIt();
                        std::string wrong_tok = std::string(1, temp) + std::string(1, temp);
                        LexerError(wrong_tok + " not allowed in miniMAT!");
                        return Token(TokenKind::TOK_ERROR, wrong_tok + " not allowed in miniMAT!");
                    }

                    return Token(TokenKind::TOK_ARITHOP, std::string(1, temp));

                case '(':
                    TakeIt();
                    return Token(TokenKind::TOK_LPAREN, "(");
                case ')':
                    TakeIt();
                    return Token(TokenKind::TOK_RPAREN, ")");

                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    numstr = "";

                    // To the left of the decimal point
                    while (std::isdigit(current_char)) {
                        numstr += current_char;
                        TakeIt();
                    }

                    // The decimal point
                    if (current_char == '.') {
                        numstr += current_char;
                        TakeIt();

                        // To the right of the decimal point
                        while (std::isdigit(current_char)) {
                            numstr += current_char;
                            TakeIt();
                        }
                    }

                    return Token(TokenKind::TOK_FLOATLIT, numstr);

                case '.':
                    numstr = "";
                    numstr += current_char;
                    TakeIt();
                    if (std::isdigit(current_char)) {
                        while (std::isdigit(current_char)) {
                            numstr += current_char;
                            TakeIt();
                        }
                        return Token(TokenKind::TOK_FLOATLIT, numstr);
                    } else {
                        //return Token(TokenKind::TOK_DOT, ".");
                        LexerError("Single . not allowed!");
                        return Token(TokenKind::TOK_ERROR, "Single . not allowed!");
                    }

                default:
                    temp = current_char;
                    TakeIt();
                    std::string unknownChar = std::string(1, temp);
                    LexerError("Unrecognized character '" + unknownChar + "' in input");
                    return Token(TokenKind::TOK_ERROR, "Unrecognized character '" + unknownChar + "' in input");
            }
        }

        /*
         * Get next character from input stream
         */
        void Lexer::NextChar() {
            char temp;
            if (stream >> temp) {
                current_char = temp;
            } else {
                is_done = true;
                current_char = '\0';
            }
        }

        void Lexer::TakeIt() {
            NextChar();
        }

        void Lexer::LexerError(const std::string& error) {
            reporter->AddLexerError(error);
        }
    }
}
