#include <iostream>
#include <string>

#include <memory>
#include <map>

#include <Lexer.hpp>
#include <Parser.hpp>
#include <Visitors.hpp>

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
            std::cout << "ans = " << std::endl << std::endl;
            std::cout << "     " << ans << std::endl << std::endl;
            continue;
        } else if (input_line == "")
            continue;

        auto reporter = std::make_shared<miniMAT::reporter::ErrorReporter>();
        miniMAT::lexer::Lexer   lexer(input_line, reporter);
        miniMAT::parser::Parser parser(lexer, reporter);

        auto ast = parser.Parse();

        if (reporter->HasErrors()) {
            reporter->ReportErrors();
            std::cout << std::endl;
        } else {
            ans = ast->VisitEvaluate();
            if (!parser.SuppressedOutput()) {
                std::cout << "ans = " << std::endl << std::endl;
                std::cout << "     " << ans << std::endl << std::endl;
            }
        }
    }

    return 0;
}
