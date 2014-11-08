#ifndef PARSER_HPP
#define PARSER_HPP

#include <deque>
#include <memory>

#include <Lexer.hpp>

#include <AST.hpp>
#include <Statement.hpp>
#include <ExprStmt.hpp>
#include <AssignStmt.hpp>
#include <Expression.hpp>

namespace miniMAT {
    namespace parser {
        class Parser {
        private:
                lexer::Lexer              lexer;
                std::deque<lexer::Token>  tokens;
                bool                      suppressed = false;

                std::shared_ptr<reporter::ErrorReporter> reporter;

        public:
                Parser(const lexer::Lexer& lexer,
                       std::shared_ptr<reporter::ErrorReporter> reporter);

                void ParseError(const std::string& error);

                bool SuppressedOutput();

                void Accept(lexer::TokenKind exp_kind);
                void Accept(lexer::TokenKind exp_kind, const std::string& exp_spelling);
                void AcceptIt();

                void PutBack(const lexer::Token& t);

                lexer::Token GetCurrentToken();

                std::shared_ptr<ast::AST> Parse();

                std::shared_ptr<ast::Statement>  ParseStatement();

                std::shared_ptr<ast::ExprStmt>   ParseExprStmt();
                std::shared_ptr<ast::AssignStmt> ParseAssignStmt();

                std::shared_ptr<ast::Expression> ParseExpression();

                std::shared_ptr<ast::Expression> ParseA();
                std::shared_ptr<ast::Expression> ParseB();
                std::shared_ptr<ast::Expression> ParseC();
        };
    }
}

#endif
