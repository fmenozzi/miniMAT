#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <map>
#include <algorithm>

#include <Lexer.hpp>
#include <Parser.hpp>
#include <Visitors.hpp>
#include <Checker.hpp>

#include <ExprStmt.hpp>
#include <RefExpr.hpp>
#include <IdRef.hpp>

void PrintResult(std::string varname, double val, bool suppressed) {
    if (!suppressed) {
        std::cout << varname << " =" << std::endl << std::endl;
        std::cout << "    " << val << std::endl << std::endl;
    }
}

int main() {
    std::string input_line;

    auto id_table = std::make_shared<std::map<std::string, double>>();
    (*id_table)["ans"] = 0;

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
        if (input_line == "quit" || input_line == "exit") {
            break;
        } else if (input_line == "") {
            continue;
        } else if (input_line == "who") {
            for (auto var : *id_table)
                std::cout << var.first << std::endl;
            std::cout  << std::endl;
            continue;
        } else if (input_line == "whos") {
            // Find longest var name (for formatting)
            /*
            std::size_t max_var_length = 0;
            for (auto var : *id_table)
                if (var.first.size() > max_var_length)
                    max_var_length = var.first.size();
            */
            auto max_var_length = std::max_element(std::begin(*id_table),
                                                   std::end(*id_table),
                                                   [] (std::pair<std::string, double> p1, 
                                                       std::pair<std::string, double> p2) {
                return p1.first.size() < p2.first.size();
            })->first.size();

            for (auto var : *id_table)
                std::cout << std::setw(max_var_length) << var.first << " = " << var.second << std::endl;
            std::cout << std::endl;
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
            double ans = ast->VisitEvaluate(id_table);
            if (ast->GetClassName() == "ExprStmt") {
                auto exprstmt = std::dynamic_pointer_cast<miniMAT::ast::ExprStmt>(ast);
                if (exprstmt->expr->GetClassName() == "RefExpr") {
                    auto refexpr = std::dynamic_pointer_cast<miniMAT::ast::RefExpr>(exprstmt->expr);
                    auto varname = std::dynamic_pointer_cast<miniMAT::ast::IdRef>(refexpr->ref)->id->GetSpelling();

                    PrintResult(varname, id_table->at(varname), parser.SuppressedOutput());
                } else {
                    (*id_table)["ans"] = ans;

                    PrintResult("ans", ans, parser.SuppressedOutput());
                }

            } else if (ast->GetClassName() == "AssignStmt") {
                auto assign_stmt = std::dynamic_pointer_cast<miniMAT::ast::AssignStmt>(ast);

                if (assign_stmt->ref->GetClassName() == "IdRef") {
                    auto idref   = std::dynamic_pointer_cast<miniMAT::ast::IdRef>(assign_stmt->ref);

                    auto varname = idref->id->GetSpelling();
                    auto val     = assign_stmt->val;

                    PrintResult(varname, val, parser.SuppressedOutput());
                }
            }
        }
    }

    return 0;
}
