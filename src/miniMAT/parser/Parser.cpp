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

            tokens = util::Stream<lexer::Token>();

            AcceptKind = [this](lexer::TokenKind expkind) {
                // Check for validity of current token
                auto token = tokens.Current();
                if (token.GetKind() != expkind) {
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
            };

            AcceptKindAndSpelling = [this](lexer::TokenKind expkind, const std::string& expspelling) {
                // Check for validity of current token
                auto token = tokens.Current();
                if (token.GetKind() != expkind || token.GetSpelling() != expspelling) {
                    auto tokspelling  = token.GetSpelling();
                    auto kindspelling = lexer::GetTokenSpelling(token.GetKind());
                    if (std::isalpha(kindspelling[0]))
                        ParseError("Syntax error on " + kindspelling + " " + tokspelling);
                    else
                        ParseError("Syntax error on " + tokspelling);
                }
            };

            AcceptIt = [this]() {
                AcceptKindAndSpelling(tokens.Current().GetKind(), tokens.Current().GetSpelling());
            };
        }

        void Parser::ParseError(const std::string& error) {
            reporter->AddParseError(error);
            throw error;
        }

        bool Parser::SuppressedOutput() {
            return suppressed;
        }

        std::shared_ptr<ast::AST> Parser::Parse() {
            // Fill up token buffer
            auto token = lexer.GetToken();
            while (token.GetKind() != lexer::TokenKind::TOK_EOF) {
                tokens.Add(token);
                token = lexer.GetToken();
            }
            tokens.Add(token);

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
            if (tokens.Current().GetKind() == lexer::TokenKind::TOK_IDENTIFIER) {
                auto idtok = tokens.Current();
                tokens.Take(AcceptIt);

                auto nexttok = tokens.Current();

                tokens.PutBack(idtok);

                if (nexttok.GetKind() == lexer::TokenKind::TOK_ASSIGN) {
                    return ParseAssignStmt();
                } else {
                    return ParseExprStmt();
                }
            } else if (tokens.Current().GetKind() == lexer::TokenKind::TOK_KEYWORD) {
                if (tokens.Current().GetSpelling() == "clear")
                    return ParseClearStmt();
                else if (tokens.Current().GetSpelling() == "who")
                    return ParseWhoStmt();
                else if (tokens.Current().GetSpelling() == "whos")
                    return ParseWhosStmt();
                else // clc
                    return ParseClcStmt();
            } else {
                return ParseExprStmt();
            }
        }

        std::shared_ptr<ast::ExprStmt> Parser::ParseExprStmt() {
            auto expr = ParseExpression();
            if (tokens.Current().GetKind() == lexer::TokenKind::TOK_SEMICOL) {
                tokens.Take(AcceptIt);
                suppressed = true;
            }
            tokens.Take(AcceptKind, lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::ExprStmt>(expr);
        }

        std::shared_ptr<ast::ClearStmt> Parser::ParseClearStmt() {
            std::vector<std::shared_ptr<ast::Reference>> refs;

            tokens.Take(AcceptKindAndSpelling, lexer::TokenKind::TOK_KEYWORD, "clear");
            while (tokens.Current().GetKind() != lexer::TokenKind::TOK_EOF) {
                auto reftok = tokens.Current();

                tokens.Take(AcceptKind, lexer::TokenKind::TOK_IDENTIFIER);
                if (tokens.Current().GetKind() == lexer::TokenKind::TOK_COMMA)
                    tokens.Take(AcceptIt);
                
                refs.push_back(std::make_shared<ast::IdRef>(std::make_shared<ast::Identifier>(reftok.GetSpelling())));
            }

            tokens.Take(AcceptKind, lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::ClearStmt>(refs);
        }

        std::shared_ptr<ast::WhoStmt> Parser::ParseWhoStmt() {
            tokens.Take(AcceptKindAndSpelling, lexer::TokenKind::TOK_KEYWORD, "who");
            tokens.Take(AcceptKind, lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::WhoStmt>();
        }

        std::shared_ptr<ast::WhosStmt> Parser::ParseWhosStmt() {
            tokens.Take(AcceptKindAndSpelling, lexer::TokenKind::TOK_KEYWORD, "whos");
            tokens.Take(AcceptKind, lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::WhosStmt>();
        }

        std::shared_ptr<ast::ClcStmt> Parser::ParseClcStmt() {
            tokens.Take(AcceptKindAndSpelling, lexer::TokenKind::TOK_KEYWORD, "clc");
            tokens.Take(AcceptKind, lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::ClcStmt>();
        }

        std::shared_ptr<ast::AssignStmt> Parser::ParseAssignStmt() {
            auto id   = std::make_shared<ast::Identifier>(tokens.Current().GetSpelling());
            auto ref  = std::make_shared<ast::IdRef>(id);
            tokens.Take(AcceptIt);

            tokens.Take(AcceptKind, lexer::TokenKind::TOK_ASSIGN);

            auto expr = ParseExpression();

            if (tokens.Current().GetKind() == lexer::TokenKind::TOK_SEMICOL) {
                tokens.Take(AcceptIt);
                suppressed = true;
            }

            tokens.Take(AcceptKind, lexer::TokenKind::TOK_EOF);

            return std::make_shared<ast::AssignStmt>(ref, expr);
        }

        std::shared_ptr<ast::ExprList> Parser::ParseArgList() {
            auto args = std::make_shared<ast::ExprList>();
            args->push_back(ParseExpression());               
            while (tokens.Current().GetKind() == lexer::TokenKind::TOK_COMMA) {
                tokens.Take(AcceptKind, lexer::TokenKind::TOK_COMMA);               
                args->push_back(ParseExpression());            
            }
            return args;
        }

        std::shared_ptr<ast::Expression> Parser::ParseExpression() {
            auto expr = ParseA();
            while (tokens.Current().GetSpelling() == "+" ||
                   tokens.Current().GetSpelling() == "-") {
                auto op = std::make_shared<ast::Operator>(tokens.Current());
                tokens.Take(AcceptIt);
                expr = std::make_shared<ast::BinaryExpr>(expr, op, ParseA());
            }
            return expr;
        }

        std::shared_ptr<ast::Expression> Parser::ParseA() {
            auto expr = ParseB();
            while (tokens.Current().GetSpelling() == "*" ||
                   tokens.Current().GetSpelling() == "/") {
                auto op = std::make_shared<ast::Operator>(tokens.Current());
                tokens.Take(AcceptIt);
                expr = std::make_shared<ast::BinaryExpr>(expr, op, ParseB());
            }
            return expr;
        }

        std::shared_ptr<ast::Expression> Parser::ParseB() {
            auto expr = ParseC();
            while (tokens.Current().GetSpelling() == "^") {
                auto op = std::make_shared<ast::Operator>(tokens.Current());
                tokens.Take(AcceptIt);
                expr = std::make_shared<ast::BinaryExpr>(expr, op, ParseC());
            }
            return expr;
        }

        std::shared_ptr<ast::Expression> Parser::ParseC() {
            auto token = tokens.Current();

            if (token.GetSpelling() == "-") {
                auto op = std::make_shared<ast::Operator>(token);
                tokens.Take(AcceptIt);
                return std::make_shared<ast::UnaryExpr>(op, ParseC());
            } else if (token.GetKind() == lexer::TokenKind::TOK_LPAREN) {
                tokens.Take(AcceptIt);
                auto expr = ParseExpression();
                tokens.Take(AcceptKind, lexer::TokenKind::TOK_RPAREN);
                return expr;
            } else if (token.GetKind() == lexer::TokenKind::TOK_FLOATLIT) {
                Matrix matrix(1,1);
                matrix(0) = std::stod(token.GetSpelling());

                auto floatlit = std::make_shared<ast::MatrixLiteral>(token.GetSpelling(), matrix);
                tokens.Take(AcceptKind, lexer::TokenKind::TOK_FLOATLIT);

                return std::make_shared<ast::LiteralExpr>(floatlit);
            } else if (token.GetKind() == lexer::TokenKind::TOK_LBRACKET) {
                tokens.Take(AcceptIt);

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

                while (tokens.Current().GetKind() != lexer::TokenKind::TOK_RBRACKET) {
                    double val;
                    if (tokens.Current().GetKind() == lexer::TokenKind::TOK_FLOATLIT) {
                        val = std::stod(tokens.Current().GetSpelling());
                        tokens.Take(AcceptIt);
                    } else if (tokens.Current().GetKind() == lexer::TokenKind::TOK_IDENTIFIER) {
                        // Check if identifier exists
                        auto varname = tokens.Current().GetSpelling();
                        if (vars->find(varname) == vars->end())
                            ParseError("Undefined function or variable \'" + varname + "\'.");
                        tokens.Take(AcceptIt);

                        // Check to see if id is part of index/call expression
                        if (tokens.Current().GetKind() == lexer::TokenKind::TOK_LPAREN) {
                            tokens.Take(AcceptIt);
                            auto args = std::make_shared<ast::ExprList>();
                            if (tokens.Current().GetKind() != lexer::TokenKind::TOK_RPAREN)
                                args = ParseArgList();
                            tokens.Take(AcceptKind, lexer::TokenKind::TOK_RPAREN);

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
                    if (tokens.Current().GetKind() == lexer::TokenKind::TOK_COMMA)
                        tokens.Take(AcceptIt);

                    if (tokens.Current().GetKind() == lexer::TokenKind::TOK_SEMICOL) {
                        tokens.Take(AcceptIt);

                        check_for_dimension_mismatch(current_col_num, num_cols);

                        if (tokens.Current().GetKind() != lexer::TokenKind::TOK_RBRACKET) {
                            first_pass_through_first_row = false;
                            num_rows++;
                        }

                        if (tokens.Current().GetKind() != lexer::TokenKind::TOK_RBRACKET)
                            current_col_num = 0;
                    }

                    if (tokens.Current().GetKind() == lexer::TokenKind::TOK_RBRACKET)
                        check_for_dimension_mismatch(current_col_num, num_cols);
                }

                tokens.Take(AcceptKind, lexer::TokenKind::TOK_RBRACKET);

                auto spelling = std::to_string(num_rows) + " x " + std::to_string(num_cols);

                Matrix matrix(num_rows, num_cols);
                for (size_t i = 0; i < vals.size(); i++)
                    matrix(i) = vals[i];

                auto matrixlit = std::make_shared<ast::MatrixLiteral>(spelling, matrix);

                return std::make_shared<ast::LiteralExpr>(matrixlit);
            } else { // id
                auto id  = std::make_shared<ast::Identifier>(token.GetSpelling());
                tokens.Take(AcceptKind, lexer::TokenKind::TOK_IDENTIFIER);

                auto idref = std::make_shared<ast::IdRef>(id);

                if (tokens.Current().GetKind() == lexer::TokenKind::TOK_LPAREN) {
                    tokens.Take(AcceptIt);
                    auto args = std::make_shared<ast::ExprList>();
                    if (tokens.Current().GetKind() != lexer::TokenKind::TOK_RPAREN)
                        args = ParseArgList();
                    tokens.Take(AcceptKind, lexer::TokenKind::TOK_RPAREN);

                    return std::make_shared<ast::CallExpr>(idref, args);
                } else {
                    return std::make_shared<ast::RefExpr>(idref);
                }
            }
        }
    }
}