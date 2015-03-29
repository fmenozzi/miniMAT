#include <cctype>
#include <iostream>

#include <miniMAT/lexer/Lexer.hpp>

namespace miniMAT {
    namespace lexer {
        Lexer& Lexer::operator=(const Lexer& lexer) {
            if (this != &lexer) {
                this->input_line   = lexer.input_line;
                this->reporter     = lexer.reporter;
                this->chars        = lexer.chars;
                this->AndDoNothing = lexer.AndDoNothing;
                this->keywords     = keywords;

                this->stream.str(input_line);
                this->stream >> std::noskipws;
            }

            return *this;
        }

        Lexer::Lexer(const std::string& input_line, std::shared_ptr<reporter::ErrorReporter> reporter) {
            this->input_line   = input_line;
            this->reporter     = reporter;

            this->stream.str(input_line);
            this->stream >> std::noskipws;

            keywords.insert("clear");
            keywords.insert("who");
            keywords.insert("whos");
            keywords.insert("clc");

            // Fill up character stream
            chars = util::Stream<char>();
            while (true) {
                char temp;
                if (stream >> temp) {
                    chars.Add(temp);
                } else {
                    chars.Add('\0');
                    break;
                }
            }

            // Blank lambda (no additional checking necessary)
            AndDoNothing = [](){};
        }

        Token Lexer::GetToken() {
           // Pass through whitespace
            while (chars.Current() == ' ' or chars.Current() == '\t' or chars.Current() == '\n')
                chars.Take(AndDoNothing);

            // Check for end of line
            if (chars.Current() == '\0')
                return Token(TokenKind::TOK_EOF, "EOF");

            // Identifiers
            if (std::isalpha(chars.Current())) {
                std::string idstr;
                while (std::isalnum(chars.Current()) or chars.Current() == '_') {
                    idstr += chars.Current();
                    chars.Take(AndDoNothing);
                }

                if (keywords.find(idstr) != keywords.end())
                    return Token(TokenKind::TOK_KEYWORD, idstr);
                else
                    return Token(TokenKind::TOK_IDENTIFIER, idstr);
            }

            // Non-identifiers
            char temp;
            std::string numstr;
            switch (chars.Current()) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    temp = chars.Current();
                    chars.Take(AndDoNothing);

                    // Reject -- and ++
                    if ((temp == '+' and chars.Current() == '+') or (temp == '-' and chars.Current() == '-')) {
                        chars.Take(AndDoNothing);
                        std::string wrong_tok = std::string(1, temp) + std::string(1, temp);
                        LexerError(wrong_tok + " not allowed in miniMAT!");
                        return Token(TokenKind::TOK_ERROR, wrong_tok + " not allowed in miniMAT!");
                    }

                    return Token(TokenKind::TOK_ARITHOP, std::string(1, temp));

                case '(':
                    chars.Take(AndDoNothing);
                    return Token(TokenKind::TOK_LPAREN, "(");
                case ')':
                    chars.Take(AndDoNothing);
                    return Token(TokenKind::TOK_RPAREN, ")");

                case '[':
                    chars.Take(AndDoNothing);
                    return Token(TokenKind::TOK_LBRACKET, "[");
                case ']':
                    chars.Take(AndDoNothing);
                    return Token(TokenKind::TOK_RBRACKET, "]");

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
                    while (std::isdigit(chars.Current())) {
                        numstr += chars.Current();
                        chars.Take(AndDoNothing);
                    }

                    // The decimal point
                    if (chars.Current() == '.') {
                        numstr += chars.Current();
                        chars.Take(AndDoNothing);

                        // To the right of the decimal point
                        while (std::isdigit(chars.Current())) {
                            numstr += chars.Current();
                            chars.Take(AndDoNothing);
                        }
                    }

                    // The 'e' (scientific notation)
                    if (chars.Current() == 'e') {
                        numstr += chars.Current();
                        chars.Take(AndDoNothing);
                        if (chars.Current() == '+' or chars.Current() == '-') {
                            numstr += chars.Current();
                            chars.Take(AndDoNothing);
                        }
                        if (std::isdigit(chars.Current())) {
                            // To the left of the decimal point
                            while (std::isdigit(chars.Current())) {
                                numstr += chars.Current();
                                chars.Take(AndDoNothing);
                            }

                            // The decimal point
                            if (chars.Current() == '.') {
                                numstr += chars.Current();
                                chars.Take(AndDoNothing);

                                // To the right of the decimal point
                                while (std::isdigit(chars.Current())) {
                                    numstr += chars.Current();
                                    chars.Take(AndDoNothing);
                                }
                            }
                        } else {
                            std::string error = "Character \'" +
                                                std::string(1, chars.Current()) +
                                                "\' not allowed after 'e' in scientific notation";
                            LexerError(error);
                            return Token(TokenKind::TOK_ERROR, error);
                        }
                    }

                    return Token(TokenKind::TOK_FLOATLIT, numstr);

                case '.':
                    numstr = "";
                    numstr += chars.Current();
                    chars.Take(AndDoNothing);
                    if (std::isdigit(chars.Current())) {
                        while (std::isdigit(chars.Current())) {
                            numstr += chars.Current();
                            chars.Take(AndDoNothing);
                        }
                        return Token(TokenKind::TOK_FLOATLIT, numstr);
                    } else {
                        // TODO: Fix this error message
                        LexerError("Single . not allowed!");
                        return Token(TokenKind::TOK_ERROR, "Single . not allowed!");
                    }

                case ',':
                    chars.Take(AndDoNothing);
                    return Token(TokenKind::TOK_COMMA, ",");

                case '=':
                    chars.Take(AndDoNothing);
                    return Token(TokenKind::TOK_ASSIGN, "=");

                case ';':
                    chars.Take(AndDoNothing);
                    return Token(TokenKind::TOK_SEMICOL, ";");

                default:
                    temp = chars.Current();
                    chars.Take(AndDoNothing);
                    std::string unknownChar = std::string(1, temp);
                    LexerError("Unrecognized character '" + unknownChar + "' in input");
                    return Token(TokenKind::TOK_ERROR, "Unrecognized character '" + unknownChar + "' in input");
            }
        }

        void Lexer::LexerError(const std::string& error) {
            reporter->AddLexerError(error);
        }
    }
}
