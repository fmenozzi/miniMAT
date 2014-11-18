#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <map>
#include <algorithm>

#include <Matrix.hpp>

#include <Lexer.hpp>
#include <Parser.hpp>
#include <Visitors.hpp>
#include <Checker.hpp>

#include <ExprStmt.hpp>
#include <RefExpr.hpp>
#include <IdRef.hpp>

using namespace std;

void PrintResult(string varname, Matrix val, bool suppressed) {
    if (!suppressed) {
        cout << varname << " =" << endl << endl;
        cout << "    " << val << endl << endl;
    }
}

int main() {
    string input_line;

    auto id_table = make_shared<map<string, Matrix>>();
    (*id_table)["ans"] = Matrix::Zero(1,1);

    cout << "miniMAT: It's like MATLAB, but smaller." << endl;
    cout << "Copyright (C) 2014 Federico Menozzi" << endl;
    cout << endl;

    while (true) {
        cout << ">>> ";

        getline(cin, input_line);
        if (cin.eof()) {
            cout << endl;
            break;
        }
        if (input_line == "quit" || input_line == "exit" || input_line == "bye!") {
            break;
        } else if (input_line == "") {
            continue;
        } else if (input_line == "who") {
            for (auto var : *id_table)
                cout << var.first << endl;
            cout  << endl;
            continue;
        } else if (input_line == "whos") {
            // Find longest var name (for formatting)
            auto vars = *id_table;
            auto w = max_element(begin(vars), end(vars), [](pair<string, Matrix> p1, pair<string, Matrix> p2) {
                return p1.first.size() < p2.first.size();
            })->first.size();

            cout << endl;
            for (auto var : vars)
                cout << setw(w) << var.first << " = " << var.second << endl;
            cout << endl;
            continue;
        }

        auto reporter = make_shared<miniMAT::reporter::ErrorReporter>();
        miniMAT::lexer::Lexer   lexer(input_line, reporter);
        miniMAT::parser::Parser parser(lexer, reporter);

        auto ast = parser.Parse();

        if (reporter->HasErrors()) {
            reporter->ReportErrors();
            cout << endl;
            continue;
        }

        miniMAT::checker::Checker checker(id_table, reporter);
        ast = checker.check(ast);

        if (reporter->HasErrors()) {
            reporter->ReportErrors();
            cout << endl;
        } else {
            Matrix ans = ast->VisitEvaluate(id_table);
            if (ast->GetClassName() == "ExprStmt") {
                auto exprstmt = dynamic_pointer_cast<miniMAT::ast::ExprStmt>(ast);
                if (exprstmt->expr->GetClassName() == "RefExpr") {
                    auto refexpr = dynamic_pointer_cast<miniMAT::ast::RefExpr>(exprstmt->expr);
                    auto varname = dynamic_pointer_cast<miniMAT::ast::IdRef>(refexpr->ref)->id->GetSpelling();

                    PrintResult(varname, id_table->at(varname), parser.SuppressedOutput());
                } else {
                    (*id_table)["ans"] = ans;

                    PrintResult("ans", ans, parser.SuppressedOutput());
                }

            } else if (ast->GetClassName() == "AssignStmt") {
                auto assign_stmt = dynamic_pointer_cast<miniMAT::ast::AssignStmt>(ast);

                if (assign_stmt->ref->GetClassName() == "IdRef") {
                    auto idref   = dynamic_pointer_cast<miniMAT::ast::IdRef>(assign_stmt->ref);

                    auto varname = idref->id->GetSpelling();
                    auto val     = assign_stmt->val;

                    PrintResult(varname, val, parser.SuppressedOutput());
                }
            }
        }
    }

    return 0;
}
