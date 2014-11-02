#include <iostream>
#include <string>

#include <Lexer.hpp>
#include <Parser.hpp>

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

        miniMAT::lexer::Lexer   lexer(input_line);
        miniMAT::parser::Parser parser(lexer);

        parser.Parse();

    }

    return 0;
}
