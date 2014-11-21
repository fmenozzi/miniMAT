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

#include <Util.hpp>

using namespace std;

int main() {
    string input_line;

    auto vars = make_shared<map<string, Matrix>>();
    (*vars)["ans"] = Matrix::Zero(1,1);

    miniMAT::util::Util::init(vars);

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

        if (miniMAT::util::Util::HasFunction(input_line)) {
            try {
                miniMAT::util::Util::GetFunction(input_line)();
            } catch (...) {
                break;
            }
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

        miniMAT::checker::Checker checker(vars, reporter);
        ast = checker.check(ast);

        if (reporter->HasErrors()) {
            reporter->ReportErrors();
            cout << endl;
        } else {
            Matrix ans = ast->VisitEvaluate(vars);
            if (ast->GetClassName() == "ExprStmt") {
                auto exprstmt = dynamic_pointer_cast<miniMAT::ast::ExprStmt>(ast);
                if (exprstmt->expr->GetClassName() == "RefExpr") {
                    auto refexpr = dynamic_pointer_cast<miniMAT::ast::RefExpr>(exprstmt->expr);
                    auto varname = dynamic_pointer_cast<miniMAT::ast::IdRef>(refexpr->ref)->id->GetSpelling();

                    miniMAT::util::Util::PrintResult(varname, vars->at(varname), parser.SuppressedOutput());
                } else {
                    (*vars)["ans"] = ans;

                    miniMAT::util::Util::PrintResult("ans", ans, parser.SuppressedOutput());
                }

            } else if (ast->GetClassName() == "AssignStmt") {
                auto assign_stmt = dynamic_pointer_cast<miniMAT::ast::AssignStmt>(ast);

                if (assign_stmt->ref->GetClassName() == "IdRef") {
                    auto idref   = dynamic_pointer_cast<miniMAT::ast::IdRef>(assign_stmt->ref);

                    auto varname = idref->id->GetSpelling();
                    auto val     = assign_stmt->val;

                    miniMAT::util::Util::PrintResult(varname, val, parser.SuppressedOutput());
                }
            }
        }
    }

    return 0;
}
