#include <iostream>
#include <vector>
#include <string>

#include <Lexer.hpp>

int main() {

    std::string input_line;

    while (true) {
        std::cout << ">>> ";

        // Get input line and check for exit
        std::getline(std::cin, input_line);
        if (input_line == "quit" || input_line == "exit")
            break;
		if (std::cin.eof()) {
			std::cout << std::endl;
			break;
		}

		// Print all tokens received
        miniMAT::lexer::Lexer lexer(input_line);
        miniMAT::lexer::Token token = lexer.GetToken();
        while (token.GetKind() != miniMAT::lexer::TokenKind::TOK_EOF) {
            std::cout << token.GetSpelling() << std::endl;

            token = lexer.GetToken();
        }
    }

    return 0;
}
