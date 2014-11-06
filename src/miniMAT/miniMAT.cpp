#include <iostream>
#include <string>

#include <Lexer.hpp>
#include <Parser.hpp>
#include <Visitors.hpp>

int main() {
    std::string input_line;

    while (true) {
        std::cout << ">>> ";

        std::getline(std::cin, input_line);
        if (input_line == "quit" || input_line == "exit")
            break;
		if (std::cin.eof()) {
			std::cout << std::endl;
			break;
		}

        miniMAT::reporter::ErrorReporter reporter;
        miniMAT::lexer::Lexer   lexer(input_line, &reporter);
        miniMAT::parser::Parser parser(lexer, &reporter);

        auto ast = parser.Parse();

        if (reporter.HasErrors())
            reporter.ReportErrors();
        else
            ast->VisitDisplay("");
    }

    return 0;
}
