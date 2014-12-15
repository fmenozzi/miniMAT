#ifndef MINIMAT_PARSER_PARSER_HPP
#define MINIMAT_PARSER_PARSER_HPP

#include <deque>
#include <memory>

#include <miniMAT/lexer/Lexer.hpp>

#include <miniMAT/ast/AST.hpp>
#include <miniMAT/ast/Statement.hpp>
#include <miniMAT/ast/ExprStmt.hpp>
#include <miniMAT/ast/AssignStmt.hpp>
#include <miniMAT/ast/Expression.hpp>

namespace miniMAT {
    namespace parser {
        class Parser {
        private:
            lexer::Lexer              lexer;
            std::deque<lexer::Token>  tokens;
            bool                      suppressed = false;

            std::shared_ptr<reporter::ErrorReporter> reporter;

        public:
            Parser(const lexer::Lexer& lexer, std::shared_ptr<reporter::ErrorReporter> reporter);

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
