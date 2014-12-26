#include <iostream>
#include <deque>

#include <miniMAT/parser/Parser.hpp>
#include <miniMAT/lexer/Lexer.hpp>

#include <miniMAT/ast/Operator.hpp>
#include <miniMAT/ast/MatrixLiteral.hpp>
#include <miniMAT/ast/BinaryExpr.hpp>
#include <miniMAT/ast/UnaryExpr.hpp>
#include <miniMAT/ast/LiteralExpr.hpp>
#include <miniMAT/ast/IdRef.hpp>
#include <miniMAT/ast/RefExpr.hpp>
#include <miniMAT/ast/AssignStmt.hpp>
#include <miniMAT/ast/ExprList.hpp>
#include <miniMAT/ast/CallExpr.hpp>

namespace miniMAT {
    namespace parser {
        Parser::Parser(const lexer::Lexer& lexer, 
                       std::shared_ptr<std::map<std::string, Matrix>> vars,
                       std::shared_ptr<reporter::ErrorReporter> reporter) {
            this->lexer    = lexer;
            this->vars     = vars;
            this->reporter = reporter;

            this->tokens   = std::deque<lexer::Token>();
        }

        void Parser::ParseError(const std::string& error) {
            reporter->AddParseError(error);
            throw error;
        }

        bool Parser::SuppressedOutput() {
            return suppressed;
        }

        void Parser::Accept(lexer::TokenKind exp_kind, const std::string& exp_spelling) {
            // Check for validity of current token
            auto token = GetCurrentToken();
            if (token.GetKind() != exp_kind || token.GetSpelling() != exp_spelling) {
                auto tokspelling  = token.GetSpelling();
                auto kindspelling = lexer::GetTokenSpelling(token.GetKind());
                if (std::isalpha(kindspelling[0]))
                    ParseError("Syntax error on " + kindspelling + " " + tokspelling);
                else
                    ParseError("Syntax error on " + tokspelling);
            }

            // Advance token
            tokens.pop_front();
        }

        void Parser::Accept(lexer::TokenKind exp_kind) {
            // Check for validity of current token
            auto token = GetCurrentToken();
            if (token.GetKind() != exp_kind) {
                if (token.GetKind() == lexer::TokenKind::TOK_EOF)
                    ParseError("Error: Expression or statement is incomplete or incorrect");
                else {
                    auto tokspelling  = token.GetSpelling();
                    auto kindspelling = lexer::GetTokenSpelling(token.GetKind());
                    if (std::isalpha(kindspelling[0]))
                        ParseError("Syntax error on " + kindspelling + " " + tokspelling);
                    else
                        ParseError("Syntax error on " + tokspelling);
                }
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
            } catch (...) { // Catch ParseError exceptions
                return nullptr;
            }
        }

        std::shared_ptr<ast::Statement> Parser::ParseStatement() {
            if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_IDENTIFIER) {
                auto idtok = GetCurrentToken();
                AcceptIt();

                auto nexttok = GetCurrentToken();

                PutBack(idtok);



                if (nexttok.GetKind() == lexer::TokenKind::TOK_ASSIGN) {
                    return ParseAssignStmt();
                } else {
                    return ParseExprStmt();
                }
            } else if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_KEYWORD) {
                if (GetCurrentToken().GetSpelling() == "clear")
                    return ParseClearStmt();
                else if (GetCurrentToken().GetSpelling() == "who")
                    return ParseWhoStmt();
                else if (GetCurrentToken().GetSpelling() == "whos")
                    return ParseWhosStmt();
                else // clc
                    return ParseClcStmt();
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

        std::shared_ptr<ast::ClearStmt> Parser::ParseClearStmt() {
            std::vector<std::shared_ptr<ast::Reference>> refs;

            Accept(lexer::TokenKind::TOK_KEYWORD, "clear");
            while (GetCurrentToken().GetKind() != lexer::TokenKind::TOK_EOF) {
                auto reftok = GetCurrentToken();

                Accept(lexer::TokenKind::TOK_IDENTIFIER);
                if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_COMMA)
                    AcceptIt();
                
                refs.push_back(std::make_shared<ast::IdRef>(std::make_shared<ast::Identifier>(reftok.GetSpelling())));
            }

            Accept(lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::ClearStmt>(refs);
        }

        std::shared_ptr<ast::WhoStmt> Parser::ParseWhoStmt() {
            Accept(lexer::TokenKind::TOK_KEYWORD, "who");
            Accept(lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::WhoStmt>();
        }

        std::shared_ptr<ast::WhosStmt> Parser::ParseWhosStmt() {
            Accept(lexer::TokenKind::TOK_KEYWORD, "whos");
            Accept(lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::WhosStmt>();
        }

        std::shared_ptr<ast::ClcStmt> Parser::ParseClcStmt() {
            Accept(lexer::TokenKind::TOK_KEYWORD, "clc");
            Accept(lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::ClcStmt>();
        }

        std::shared_ptr<ast::AssignStmt> Parser::ParseAssignStmt() {
            auto id   = std::make_shared<ast::Identifier>(GetCurrentToken().GetSpelling());
            auto ref  = std::make_shared<ast::IdRef>(id);
            AcceptIt();

            Accept(lexer::TokenKind::TOK_ASSIGN);

            auto expr = ParseExpression();

            if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_SEMICOL) {
                AcceptIt();
                this->suppressed = true;
            }

            Accept(lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::AssignStmt>(ref, expr);
        }

        std::shared_ptr<ast::ExprList> Parser::ParseArgList() {
            auto args = std::make_shared<ast::ExprList>();
            args->push_back(ParseExpression());               
            while (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_COMMA) {
                Accept(lexer::TokenKind::TOK_COMMA);               
                args->push_back(ParseExpression());            
            }
            return args;
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
            auto token = GetCurrentToken();

            if (token.GetSpelling() == "-") {
                auto op = std::make_shared<ast::Operator>(token);
                AcceptIt();
                return std::make_shared<ast::UnaryExpr>(op, ParseC());
            } else if (token.GetKind() == lexer::TokenKind::TOK_LPAREN) {
                AcceptIt();
                auto expr = ParseExpression();
                Accept(lexer::TokenKind::TOK_RPAREN);
                return expr;
            } else if (token.GetKind() == lexer::TokenKind::TOK_FLOATLIT) {
                Matrix matrix(1,1);
                matrix(0) = std::stod(token.GetSpelling());

                auto floatlit = std::make_shared<ast::MatrixLiteral>(token.GetSpelling(), matrix);
                Accept(lexer::TokenKind::TOK_FLOATLIT);

                return std::make_shared<ast::LiteralExpr>(floatlit);
            } else if (token.GetKind() == lexer::TokenKind::TOK_LBRACKET) {
                AcceptIt();

                int num_rows = 1;
                int num_cols = 0;
                int current_col_num = 0;
                bool first_pass_through_first_row = true;
                std::vector<double> vals;

                // Lambda for handling dimension mismatch
                auto check_for_dimension_mismatch = [this](int current_col_num, int num_cols) {
                    if (current_col_num != num_cols)
                        ParseError("Syntax error: Dimension mismatch in matrix initialization.");
                };

                while (GetCurrentToken().GetKind() != lexer::TokenKind::TOK_RBRACKET) {
                    double val;
                    if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_FLOATLIT) {
                        val = std::stod(GetCurrentToken().GetSpelling());
                        AcceptIt();
                    } else if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_IDENTIFIER) {
                        // Check if identifier exists
                        auto varname = GetCurrentToken().GetSpelling();
                        if (vars->find(varname) == vars->end())
                            ParseError("Undefined function or variable \'" + varname + "\'.");
                        AcceptIt();

                        // Check to see if id is part of index/call expression
                        if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_LPAREN) {
                            AcceptIt();
                            auto args = std::make_shared<ast::ExprList>();
                            if (GetCurrentToken().GetKind() != lexer::TokenKind::TOK_RPAREN)
                                args = ParseArgList();
                            Accept(lexer::TokenKind::TOK_RPAREN);

                            auto id       = std::make_shared<ast::Identifier>(varname);
                            auto idref    = std::make_shared<ast::IdRef>(id);
                            auto callexpr = std::make_shared<ast::CallExpr>(idref, args);

                            try {
                                callexpr->VisitCheck(vars, reporter);  
                            } catch (const std::string& error) {
                                ParseError(error);
                            }

                            val = callexpr->VisitEvaluate(vars)(0);
                        } else {
                            // Get variable's value
                            val = vars->at(varname)(0);
                        }
                    }

                    vals.push_back(val);

                    current_col_num++;
                    if (first_pass_through_first_row)
                        num_cols++;

                    // Space or comma to separate values in rows
                    if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_COMMA)
                        AcceptIt();

                    if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_SEMICOL) {
                        AcceptIt();

                        check_for_dimension_mismatch(current_col_num, num_cols);

                        if (GetCurrentToken().GetKind() != lexer::TokenKind::TOK_RBRACKET) {
                            first_pass_through_first_row = false;
                            num_rows++;
                        }

                        if (GetCurrentToken().GetKind() != lexer::TokenKind::TOK_RBRACKET)
                            current_col_num = 0;
                    }

                    if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_RBRACKET)
                        check_for_dimension_mismatch(current_col_num, num_cols);
                }

                Accept(lexer::TokenKind::TOK_RBRACKET);

                auto spelling = std::to_string(num_rows) + " x " + std::to_string(num_cols);

                Matrix matrix(num_rows, num_cols);
                for (size_t i = 0; i < vals.size(); i++)
                    matrix(i) = vals[i];

                auto matrixlit = std::make_shared<ast::MatrixLiteral>(spelling, matrix);

                return std::make_shared<ast::LiteralExpr>(matrixlit);
            } else { // id
                auto id  = std::make_shared<ast::Identifier>(token.GetSpelling());
                Accept(lexer::TokenKind::TOK_IDENTIFIER);

                auto idref = std::make_shared<ast::IdRef>(id);

                if (GetCurrentToken().GetKind() == lexer::TokenKind::TOK_LPAREN) {
                    AcceptIt();
                    auto args = std::make_shared<ast::ExprList>();
                    if (GetCurrentToken().GetKind() != lexer::TokenKind::TOK_RPAREN)
                        args = ParseArgList();
                    Accept(lexer::TokenKind::TOK_RPAREN);

                    return std::make_shared<ast::CallExpr>(idref, args);
                } else {
                    return std::make_shared<ast::RefExpr>(idref);
                }
            }
        }
    }
}
