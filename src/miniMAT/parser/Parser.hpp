#ifndef PARSER_HPP
#define PARSER_HPP

#include <deque>

#include <Lexer.hpp>

namespace miniMAT {
    namespace parser {
        class Parser {
        private:
                lexer::Lexer             lexer;

                std::deque<lexer::Token> tokens;
        public:
                Parser(const lexer::Lexer& lexer);

                void Parse();

                void Accept(lexer::TokenKind exp_kind);
                void Accept(lexer::TokenKind exp_kind,
                            const std::string& exp_spelling);
                void AcceptIt();

                void PutBack(const lexer::Token& t);

                lexer::Token GetCurrentToken();

                void ParseStatement();
                void ParseExprStmt();

                void ParseExpression();
                void ParseA();
                void ParseB();
                void ParseC();
        };
    }
}

#endif
