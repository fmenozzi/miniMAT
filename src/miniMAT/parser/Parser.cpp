#include <iostream>
#include <deque>

#include <Parser.hpp>
#include <Lexer.hpp>

#include <Operator.hpp>
#include <FloatLiteral.hpp>
#include <BinaryExpr.hpp>
#include <UnaryExpr.hpp>
#include <LiteralExpr.hpp>
#include <IdRef.hpp>
#include <RefExpr.hpp>
#include <AssignStmt.hpp>

namespace miniMAT {
    namespace parser {
        Parser::Parser(const lexer::Lexer& lexer,
                       std::shared_ptr<reporter::ErrorReporter> reporter) {
            this->lexer    = lexer;
            this->tokens   = std::deque<lexer::Token>();
            this->reporter = reporter;
        }

        void Parser::ParseError(const std::string& error) {
            reporter->AddParseError(error);
            throw 1;
        }

        bool Parser::SuppressedOutput() {
            return suppressed;
        }

        void Parser::Accept(lexer::TokenKind exp_kind, const std::string& exp_spelling) {
            // Check for validity of current token
            auto token = GetCurrentToken();
            if (token.GetKind() != exp_kind || token.GetSpelling() != exp_spelling) {

                // TODO: Augment output with TokenKind
                ParseError("ERROR: Expecting "+exp_spelling+" but found "+token.GetSpelling());
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

                ParseError("ERROR: Incorrect TokenKind");
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

        std::shared_ptr<ast::AST> Parser::Parse() {
            // Fill up token buffer
            auto token = lexer.GetToken();
            while (token.GetKind() != lexer::TokenKind::TOK_EOF) {
                tokens.push_back(token);
                token = lexer.GetToken();
            }
            tokens.push_back(token);

            // Don't parse if we have lexer errors
            if (reporter->HasErrors())
                return nullptr;

            try {
                return ParseStatement();
            } catch (...) {
                return nullptr;
            }
        }

        std::shared_ptr<ast::Statement> Parser::ParseStatement() {
            if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_IDENTIFIER) {
                auto id_token = GetCurrentToken();
                AcceptIt();

                auto next_token = GetCurrentToken();

                PutBack(id_token);

                if (next_token.GetKind() == lexer::TokenKind::TOK_ASSIGN) {
                    return ParseAssignStmt();
                } else /*if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_ARITHOP)*/ {
        			return ParseExprStmt();
        		}
            } else {
                return ParseExprStmt();
            }
        }

        std::shared_ptr<ast::ExprStmt> Parser::ParseExprStmt() {
            auto expr = ParseExpression();
            if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_SEMICOL) {
                AcceptIt();
                this->suppressed = true;
            }
            Accept(lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::ExprStmt>(expr);
        }

        std::shared_ptr<ast::AssignStmt> Parser::ParseAssignStmt() {
            auto id   = std::make_shared<ast::Identifier>(GetCurrentToken().GetSpelling());
            auto ref  = std::make_shared<ast::IdRef>(id);
            AcceptIt();

            Accept(lexer::TokenKind::TOK_ASSIGN);

            auto expr = ParseExpression();

            return std::make_shared<ast::AssignStmt>(ref, expr);
        }

        std::shared_ptr<ast::Expression> Parser::ParseExpression() {
            auto expr = ParseA();
            while (GetCurrentToken().GetSpelling() == "+" ||
                   GetCurrentToken().GetSpelling() == "-") {
                auto op = std::make_shared<ast::Operator>(GetCurrentToken());
                AcceptIt();
                expr = std::make_shared<ast::BinaryExpr>(expr, op, ParseA());
            }
            return expr;
        }

        std::shared_ptr<ast::Expression> Parser::ParseA() {
            auto expr = ParseB();
            while (GetCurrentToken().GetSpelling() == "*" ||
                   GetCurrentToken().GetSpelling() == "/") {
                auto op = std::make_shared<ast::Operator>(GetCurrentToken());
                AcceptIt();
                expr = std::make_shared<ast::BinaryExpr>(expr, op, ParseB());
            }
            return expr;
        }

        std::shared_ptr<ast::Expression> Parser::ParseB() {
            auto expr = ParseC();
            while (GetCurrentToken().GetSpelling() == "^") {
                auto op = std::make_shared<ast::Operator>(GetCurrentToken());
                AcceptIt();
                expr = std::make_shared<ast::BinaryExpr>(expr, op, ParseC());
            }
            return expr;
        }

        std::shared_ptr<ast::Expression> Parser::ParseC() {
            if (GetCurrentToken().GetSpelling() == "-") {
                auto op = std::make_shared<ast::Operator>(GetCurrentToken());
                AcceptIt();
                return std::make_shared<ast::UnaryExpr>(op, ParseC());
            } else if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_LPAREN) {
                AcceptIt();
                auto expr = ParseExpression();
                Accept(lexer::TokenKind::TOK_RPAREN);
                return expr;
            } else if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_FLOATLIT) {
                auto floatlit = std::make_shared<ast::FloatLiteral>(GetCurrentToken().GetSpelling());
                Accept(lexer::TokenKind::TOK_FLOATLIT);
                return std::make_shared<ast::LiteralExpr>(floatlit);
            } else { // TOK_IDENTIFIER
                // For now, identifiers are not allowed
            //    ParseError("Undefined function or variable \'" +
            //               GetCurrentToken().GetSpelling() + "\'.");
            //    return nullptr;

                auto id  = std::make_shared<ast::Identifier>(GetCurrentToken().GetSpelling());
                AcceptIt();

                auto idref = std::make_shared<ast::IdRef>(id);

                return std::make_shared<ast::RefExpr>(idref);
            }
        }
    }
}
