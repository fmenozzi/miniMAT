#include <iostream>
#include <string>
#include <memory>
#include <map>

#include <miniMAT/ast/Matrix.hpp>

#include <miniMAT/lexer/Lexer.hpp>
#include <miniMAT/parser/Parser.hpp>
#include <miniMAT/visit/Visitors.hpp>
#include <miniMAT/checker/Checker.hpp>

#include <miniMAT/ast/ExprStmt.hpp>
#include <miniMAT/ast/RefExpr.hpp>
#include <miniMAT/ast/IdRef.hpp>

#include <miniMAT/util/PrintResult.hpp>

using namespace std;

int main() 
{
    string input_line;

    auto vars = make_shared<map<string, miniMAT::ast::Matrix>>();
    (*vars)["ans"] = miniMAT::ast::Matrix::Zero(1,1);

    cout << "miniMAT: It's like MATLAB, but smaller." << endl;
    cout << "Copyright (C) 2014 Federico Menozzi" << endl;
    cout << endl;

    while (true) {
        cout << ">> ";

        getline(cin, input_line);
        if (input_line == "quit" or input_line == "exit" or input_line == "bye!")
            break;
        if (cin.eof()) { // Ctrl-D to quit
            cout << endl;
            break;
        }
        if (input_line == "")
            continue;

        auto reporter = make_shared<miniMAT::reporter::ErrorReporter>();
        miniMAT::lexer::Lexer   lexer(input_line, reporter);
        miniMAT::parser::Parser parser(lexer, vars, reporter);

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
            ast->PrintResult(vars, ast->VisitEvaluate(vars), parser.SuppressedOutput());
        }
    }

    return EXIT_SUCCESS;
}
