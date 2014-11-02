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
        template <typename ArgType, typename ResultType>
        Parser<ArgType, ResultType>::Parser(const lexer::Lexer& lexer) {
            this->lexer  = lexer;
            this->tokens = std::deque<lexer::Token>();
        }

        template <typename ArgType, typename ResultType>
        void Parser<ArgType, ResultType>::Accept(lexer::TokenKind exp_kind, const std::string& exp_spelling) {
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

        template <typename ArgType, typename ResultType>
        void Parser<ArgType, ResultType>::Accept(lexer::TokenKind exp_kind) {
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

        template <typename ArgType, typename ResultType>
        void Parser<ArgType, ResultType>::AcceptIt() {
            Accept(GetCurrentToken().GetKind(), GetCurrentToken().GetSpelling());
        }

        template <typename ArgType, typename ResultType>
        lexer::Token Parser<ArgType, ResultType>::GetCurrentToken() {
            return tokens.front();
        }

        template <typename ArgType, typename ResultType>
        void Parser<ArgType, ResultType>::PutBack(const lexer::Token& t) {
            tokens.push_front(t);
        }

        template <typename ArgType, typename ResultType>
        std::unique_ptr<ast::AST<ArgType, ResultType>> Parser<ArgType, ResultType>::Parse() {
            // Fill up token buffer
            auto token = lexer.GetToken();
            while (token.GetKind() != lexer::TokenKind::TOK_EOF) {
                tokens.push_back(token);
                token = lexer.GetToken();
            }
            tokens.push_back(token);

            return ParseStatement();
        }

        template <typename ArgType, typename ResultType>
        std::unique_ptr<ast::Statement<ArgType, ResultType>> Parser<ArgType, ResultType>::ParseStatement() {
            return ParseExprStmt();
        }

        template <typename ArgType, typename ResultType>
        std::unique_ptr<ast::ExprStmt<ArgType, ResultType>> Parser<ArgType, ResultType>::ParseExprStmt() {
            auto expr = ParseExpression();
            Accept(lexer::TokenKind::TOK_EOF);

            return std::unique_ptr<ExprStmt>(new ExprStmt(expr));
        }

        template <typename ArgType, typename ResultType>
        ast::Expression<ArgType, ResultType> Parser<ArgType, ResultType>::ParseExpression() {
            auto expr = ParseA();
            while (GetCurrentToken().GetSpelling() == "+" ||
                   GetCurrentToken().GetSpelling() == "-") {
                auto op = ast::Operator<ArgType, ResultType>(GetCurrentToken());
                AcceptIt();
                expr = ast::BinaryExpr<ArgType, ResultType>(expr, op, ParseA());
            }
            return expr;
        }

        template <typename ArgType, typename ResultType>
        ast::Expression<ArgType, ResultType> Parser<ArgType, ResultType>::ParseA() {
            auto expr = ParseB();
            while (GetCurrentToken().GetSpelling() == "*" ||
                   GetCurrentToken().GetSpelling() == "/") {
                auto op = ast::Operator<ArgType, ResultType>(GetCurrentToken());
                AcceptIt();
                expr = ast::BinaryExpr<ArgType, ResultType>(expr, op, ParseB());
            }
            return expr;
        }

        template <typename ArgType, typename ResultType>
        ast::Expression<ArgType, ResultType> Parser<ArgType, ResultType>::ParseB() {
            auto expr = ParseC();
            while (GetCurrentToken().GetSpelling() == "^") {
                auto op = ast::Operator<ArgType, ResultType>(GetCurrentToken());
                AcceptIt();
                expr = ast::BinaryExpr<ArgType, ResultType>(expr, op, ParseC());
            }
            return expr;
        }

        template <typename ArgType, typename ResultType>
        ast::Expression<ArgType, ResultType> Parser<ArgType, ResultType>::ParseC() {
            if (GetCurrentToken().GetSpelling() == "-") {
                auto op = ast::Operator<ArgType, ResultType>(GetCurrentToken());
                AcceptIt();
                return ast::UnaryExpr<ArgType, ResultType>(op, ParseC());
            } else if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_LPAREN) {
                AcceptIt();
                auto expr = ParseExpression();
                Accept(lexer::TokenKind::TOK_RPAREN);
                return expr;
            } else {
                auto floatlit = ast::FloatLiteral<ArgType, ResultType>(GetCurrentToken().GetSpelling());
                Accept(lexer::TokenKind::TOK_FLOATLIT);
                return ast::LiteralExpr<ArgType, ResultType>(floatlit);
            }
        }
    }
}
