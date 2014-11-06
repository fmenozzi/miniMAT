#include <iostream>
#include <string>

#include <memory>

#include <Lexer.hpp>
#include <Parser.hpp>
#include <Visitors.hpp>

int main() {
    std::string input_line;

    double ans = 0;

    std::cout << "miniMAT: It's like MATLAB, but smaller." << std::endl;
    std::cout << "Copyright (C) 2014 Federico Menozzi" << std::endl;
    std::cout << std::endl;

    while (true) {
        std::cout << ">>> ";

        std::getline(std::cin, input_line);
        if (input_line == "quit" || input_line == "exit")
            break;
		if (std::cin.eof()) {
			std::cout << std::endl;
			break;
		}

        if (input_line == "ans") {
            std::cout << "ans = " << ans << std::endl;
            continue;
        }

        auto reporter = std::make_shared<miniMAT::reporter::ErrorReporter>();
        miniMAT::lexer::Lexer   lexer(input_line, reporter);
        miniMAT::parser::Parser parser(lexer, reporter);

        auto ast = parser.Parse();

        if (reporter->HasErrors())
            reporter->ReportErrors();
        else {
            ans = ast->VisitEvaluate();
            std::cout << "ans = " << ans << std::endl << std::endl;
        }
    }

    return 0;
}
