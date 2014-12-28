#ifndef MINIMAT_PARSER_PARSER_HPP
#define MINIMAT_PARSER_PARSER_HPP

#include <deque>
#include <memory>
#include <functional>

#include <miniMAT/lexer/Lexer.hpp>

#include <miniMAT/ast/AST.hpp>
#include <miniMAT/ast/ClearStmt.hpp>
#include <miniMAT/ast/Statement.hpp>
#include <miniMAT/ast/ExprList.hpp>
#include <miniMAT/ast/ExprStmt.hpp>
#include <miniMAT/ast/AssignStmt.hpp>
#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/WhoStmt.hpp>
#include <miniMAT/ast/WhosStmt.hpp>
#include <miniMAT/ast/ClcStmt.hpp>

#include <miniMAT/util/Stream.hpp>

namespace miniMAT {
    namespace parser {
        class Parser {
        private:
            lexer::Lexer lexer;
            
            bool suppressed = false;

            std::shared_ptr<std::map<std::string, ast::Matrix>> vars;

            std::shared_ptr<reporter::ErrorReporter> reporter;

            util::Stream<lexer::Token> tokens;

            std::function<void(lexer::TokenKind expkind)>                                 AcceptKind;
            std::function<void(lexer::TokenKind expkind, const std::string& expspelling)> AcceptKindAndSpelling;
            std::function<void()>                                                         AcceptIt;

        public:
            Parser(const lexer::Lexer& lexer, 
                   std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                   std::shared_ptr<reporter::ErrorReporter> reporter);

            void ParseError(const std::string& error);

            bool SuppressedOutput();

            std::shared_ptr<ast::AST> Parse();

            std::shared_ptr<ast::Statement>  ParseStatement();

            std::shared_ptr<ast::ExprStmt>   ParseExprStmt();
            std::shared_ptr<ast::AssignStmt> ParseAssignStmt();
            std::shared_ptr<ast::ClearStmt>  ParseClearStmt();
            std::shared_ptr<ast::WhoStmt>    ParseWhoStmt();
            std::shared_ptr<ast::WhosStmt>   ParseWhosStmt();
            std::shared_ptr<ast::ClcStmt>    ParseClcStmt();

            std::shared_ptr<ast::ExprList>   ParseArgList();

            std::shared_ptr<ast::Expression> ParseExpression();

            std::shared_ptr<ast::Expression> ParseA();
            std::shared_ptr<ast::Expression> ParseB();
            std::shared_ptr<ast::Expression> ParseC();
        };
    }
}

#endif