#include <iostream>
#include <deque>

#include <Parser.hpp>
#include <Lexer.hpp>

#include <Operator.hpp>
#include <FloatLiteral.hpp>
#include <BinaryExpr.hpp>
#include <UnaryExpr.hpp>
#include <LiteralExpr.hpp>

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

        std::unique_ptr<ast::AST> Parser::Parse() {
            // Fill up token buffer
            auto token = lexer.GetToken();
            while (token.GetKind() != lexer::TokenKind::TOK_EOF) {
                tokens.push_back(token);
                token = lexer.GetToken();
            }
            tokens.push_back(token);

            return ParseStatement();
        }

        std::unique_ptr<ast::Statement> Parser::ParseStatement() {
            return ParseExprStmt();
        }

        std::unique_ptr<ast::ExprStmt> Parser::ParseExprStmt() {
            auto expr = std::move(ParseExpression());
            Accept(lexer::TokenKind::TOK_EOF);

            return std::make_unique<ast::ExprStmt>(std::move(expr));
        }

        std::unique_ptr<ast::Expression> Parser::ParseExpression() {
            auto expr = std::move(ParseA());
            while (GetCurrentToken().GetSpelling() == "+" ||
                   GetCurrentToken().GetSpelling() == "-") {
                auto op = std::make_unique<ast::Operator>(std::make_unique<lexer::Token>(GetCurrentToken()));
                AcceptIt();
                expr = std::make_unique<ast::BinaryExpr>(std::move(expr),
                                                         std::move(op),
                                                         std::move(ParseA()));
            }
            return expr;
        }

        std::unique_ptr<ast::Expression> Parser::ParseA() {
            auto expr = std::move(ParseB());
            while (GetCurrentToken().GetSpelling() == "*" ||
                   GetCurrentToken().GetSpelling() == "/") {
                auto op = std::make_unique<ast::Operator>(std::make_unique<lexer::Token>(GetCurrentToken()));
                AcceptIt();
                expr = std::make_unique<ast::BinaryExpr>(std::move(expr),
                                                         std::move(op),
                                                         std::move(ParseB()));
            }
            return expr;
        }

        std::unique_ptr<ast::Expression> Parser::ParseB() {
            auto expr = std::move(ParseC());
            while (GetCurrentToken().GetSpelling() == "^") {
                auto op = std::make_unique<ast::Operator>(std::make_unique<lexer::Token>(GetCurrentToken()));
                AcceptIt();
                expr = std::make_unique<ast::BinaryExpr>(std::move(expr),
                                                         std::move(op),
                                                         std::move(ParseC()));
            }
            return expr;
        }

        std::unique_ptr<ast::Expression> Parser::ParseC() {
            if (GetCurrentToken().GetSpelling() == "-") {
                auto op = std::make_unique<ast::Operator>(std::make_unique<lexer::Token>(GetCurrentToken()));
                AcceptIt();
                return std::make_unique<ast::UnaryExpr>(std::move(op),
                                                        std::move(ParseC()));
            } else if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_LPAREN) {
                AcceptIt();
                auto expr = std::move(ParseExpression());
                Accept(lexer::TokenKind::TOK_RPAREN);
                return expr;
            } else {
                auto floatlit = std::make_unique<ast::FloatLiteral>(GetCurrentToken().GetSpelling());
                Accept(lexer::TokenKind::TOK_FLOATLIT);
                return std::make_unique<ast::LiteralExpr>(std::move(floatlit));
            }
        }
    }
}
