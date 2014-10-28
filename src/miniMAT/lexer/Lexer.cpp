#include <cctype>
#include <iostream>

#include <Lexer.hpp>

namespace miniMAT {
    namespace lexer {
        Lexer::Lexer(const std::string& input_line) {
            this->input_line   = input_line;
            this->current_char = ' ';
            //this->iterator     = this->input_line.begin();
            this->is_done      = false;

            this->stream.str(input_line);
            this->stream >> std::noskipws;
        }

        Token Lexer::GetToken() {
           // Pass through whitespace
            while (current_char == ' ' || current_char == '\t' || current_char == '\n')
                TakeIt();

            // Check for end of line
            if (is_done)
                return Token(TokenKind::TOK_EOF, "__EOF__");

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
                        return Token(TokenKind::TOK_ERROR, wrong_tok + " not allowed in miniMat!");
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
                        return Token(TokenKind::TOK_DOT, ".");
                    }

                default:
                    temp = current_char;
                    TakeIt();
                    std::string unknownChar = std::string(1, temp);
                    return Token(TokenKind::TOK_ERROR, "Unrecognized character '" + unknownChar + "' in input");
            }
        }

        /*
         * Get next character from input stream
         */
        void Lexer::NextChar() {
            /*
            if (iterator == input_line.end()) {
                is_done = true;
                current_char = '\0';
                iterator++;
            } else {
                current_char = *iterator;
                iterator++;
            }
            */
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
    }
}
