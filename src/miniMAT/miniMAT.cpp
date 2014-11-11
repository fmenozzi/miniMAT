#include <iostream>
#include <string>

#include <memory>
#include <map>

#include <Lexer.hpp>
#include <Parser.hpp>
#include <Visitors.hpp>
#include <Checker.hpp>

#include <ExprStmt.hpp>
#include <RefExpr.hpp>
#include <IdRef.hpp>

/*
 * WHERE I LEFT OFF: vars can be referenced on their own.
 *
 * WHAT I NEED TO ADD:
 *      - id checking to ALL expression types
 *      - ability to reference vars
 *
 */

int main() {
    std::string input_line;

    double ans = 0;

    auto id_table = std::make_shared<std::map<std::string, double>>();

    std::cout << "miniMAT: It's like MATLAB, but smaller." << std::endl;
    std::cout << "Copyright (C) 2014 Federico Menozzi" << std::endl;
    std::cout << std::endl;

    while (true) {
        std::cout << ">>> ";

        std::getline(std::cin, input_line);
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
        if (input_line == "quit" || input_line == "exit")
            break;
        else if (input_line == "ans") {
            std::cout << "ans =" << std::endl << std::endl;
            std::cout << "     " << ans << std::endl << std::endl;
            continue;
        } else if (input_line == "") {
            continue;
        } else if (input_line == "who") {
            // TODO: I'll format this nicer later
             for (auto var : *id_table)
                 std::cout << var.first << " = " << var.second << std::endl;
             continue;
        }

        auto reporter = std::make_shared<miniMAT::reporter::ErrorReporter>();
        miniMAT::lexer::Lexer   lexer(input_line, reporter);
        miniMAT::parser::Parser parser(lexer, reporter);

        auto ast = parser.Parse();

        if (reporter->HasErrors()) {
            reporter->ReportErrors();
            std::cout << std::endl;
            continue;
        }

        miniMAT::checker::Checker checker(id_table, reporter);
        ast = checker.check(ast);

        if (reporter->HasErrors()) {
            reporter->ReportErrors();
            std::cout << std::endl;
        } else {
            //ast->VisitDisplay("");
            ans = ast->VisitEvaluate();
            if (!parser.SuppressedOutput()) {
                if (ast->GetClassName() == "ExprStmt") {
                    auto exprstmt = std::dynamic_pointer_cast<miniMAT::ast::ExprStmt>(ast);
                    if (exprstmt->expr->GetClassName() == "RefExpr") {
                        auto refexpr = std::dynamic_pointer_cast<miniMAT::ast::RefExpr>(exprstmt->expr);
                        auto varname = std::dynamic_pointer_cast<miniMAT::ast::IdRef>(refexpr->ref)->id->GetSpelling();

                        std::cout << varname << " =" << std::endl << std::endl;
                        std::cout << "    " << id_table->at(varname) << std::endl << std::endl;
                    } else {
                        std::cout << "ans =" << std::endl << std::endl;
                        std::cout << "     " << ans << std::endl << std::endl;
                    }

                } else if (ast->GetClassName() == "AssignStmt") {
                    auto assign_stmt = std::dynamic_pointer_cast<miniMAT::ast::AssignStmt>(ast);

                    if (assign_stmt->ref->GetClassName() == "IdRef") {
                        ;
                    }
                }
            }
        }
    }

    return 0;
}
