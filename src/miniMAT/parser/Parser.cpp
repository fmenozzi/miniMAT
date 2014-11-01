#include <iostream>
#include <deque>

#include <Parser.hpp>
#include <Lexer.hpp>

namespace miniMAT {
    namespace parser {
        Parser::Parser(const lexer::Lexer& lexer) {
            this->lexer  = lexer;
            this->tokens = std::deque<lexer::Token>();
        }

        void Parser::Accept(lexer::TokenKind exp_kind, const std::string& exp_spelling) {
            // Check for validity of current token
            auto token = GetCurrentToken();
            if (token.GetKind() != exp_kind || token.GetSpelling() != exp_spelling) {
                // TODO: Augment output with TokenKind
                std::cout << "ERROR: Expecting " << exp_spelling
                          << " but found " << token.GetSpelling()
                          << std::endl;

                // TODO: Come up with a better way of handling this
                exit(-1);
            }

            // Advance token
            tokens.pop_front();
        }

        void Parser::Accept(lexer::TokenKind exp_kind) {
            // Check for validity of current token
            auto token = GetCurrentToken();
            if (token.GetKind() != exp_kind) { // || token.GetSpelling() != exp_spelling) {
                // TODO: Once we fix that linker bug in TokenKind.hpp, we can
                //       get a better error diagnostic here
                /*
                std::cout << "ERROR: Expecting " << exp_spelling
                          << " but found " << token.GetSpelling()
                          << std::endl;
                */
                std::cout << "ERROR: Incorrect TokenKind" << std::endl;

                // TODO: Come up with a better way of handling this
                exit(-1);
            }

            // Advance token
            tokens.pop_front();
        }

        void Parser::AcceptIt() {
            Accept(GetCurrentToken().GetKind(), GetCurrentToken().GetSpelling());
        }

        lexer::Token Parser::GetCurrentToken() {
            return tokens.front();
        }

        void Parser::PutBack(const lexer::Token& t) {
            tokens.push_front(t);
        }

        void Parser::Parse() {
            // Fill up token buffer
            auto token = lexer.GetToken();
            while (token.GetKind() != lexer::TokenKind::TOK_EOF) {
                tokens.push_back(token);
                token = lexer.GetToken();
            }
            tokens.push_back(token);

            ParseStatement();
        }

        void Parser::ParseStatement() {
            ParseExprStmt();
        }

        void Parser::ParseExprStmt() {
            ParseExpression();
            Accept(lexer::TokenKind::TOK_EOF);
        }

        void Parser::ParseExpression() {
            ParseA();
            while (GetCurrentToken().GetSpelling() == "+" ||
                   GetCurrentToken().GetSpelling() == "-") {

                AcceptIt();
                ParseA();
            }
        }

        void Parser::ParseA() {
            ParseB();
            while (GetCurrentToken().GetSpelling() == "*" ||
                   GetCurrentToken().GetSpelling() == "/") {

                AcceptIt();
                ParseB();
            }
        }

        void Parser::ParseB() {
            ParseC();
            while (GetCurrentToken().GetSpelling() == "^") {
                AcceptIt();
                ParseC();
            }
        }

        void Parser::ParseC() {
            if (GetCurrentToken().GetSpelling() == "-") {
                AcceptIt();
                ParseC();
            } else if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_LPAREN) {
                AcceptIt();
                ParseExpression();
                Accept(lexer::TokenKind::TOK_RPAREN);
            } else {
                Accept(lexer::TokenKind::TOK_FLOATLIT);
            }
        }
    }
}
