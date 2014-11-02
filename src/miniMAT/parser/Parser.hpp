#ifndef PARSER_HPP
#define PARSER_HPP

#include <deque>
#include <memory>

#include <Lexer.hpp>

#include <AST.hpp>
#include <Statement.hpp>
#include <ExprStmt.hpp>
#include <Expression.hpp>

namespace miniMAT {
    namespace parser {
        template<typename ArgType, typename ResultType>
        class Parser {
        private:
                lexer::Lexer             lexer;

                std::deque<lexer::Token> tokens;
        public:
                Parser(const lexer::Lexer& lexer);

                void Accept(lexer::TokenKind exp_kind);
                void Accept(lexer::TokenKind exp_kind,
                            const std::string& exp_spelling);
                void AcceptIt();

                void PutBack(const lexer::Token& t);

                lexer::Token GetCurrentToken();

                std::unique_ptr<ast::AST<ArgType, ResultType>> Parse();

                std::unique_ptr<ast::Statement<ArgType, ResultType>> ParseStatement();

                std::unique_ptr<ast::ExprStmt<ArgType, ResultType>>  ParseExprStmt();

                ast::Expression<ArgType, ResultType> ParseExpression();
                ast::Expression<ArgType, ResultType> ParseA();
                ast::Expression<ArgType, ResultType> ParseB();
                ast::Expression<ArgType, ResultType> ParseC();
        };
    }
}

#endif
