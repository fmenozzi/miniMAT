#include <TokenKind.hpp>

namespace miniMAT {
    namespace lexer {
        std::string GetTokenSpelling(TokenKind kind) {
        	switch (kind) {
        		case TokenKind::TOK_EOF:
        			return "EOF";
        		case TokenKind::TOK_ERROR:
        			return "ERROR";
        		case TokenKind::TOK_IDENTIFIER:
        			return "IDENTIFIER";
        		case TokenKind::TOK_ASSIGN:
        			return "=";
        		case TokenKind::TOK_FLOATLIT:
        			return "FLOATLIT";
        		case TokenKind::TOK_DOT:
        			return ".";
        		case TokenKind::TOK_ARITHOP:
        			return "ARITHOP";
        		case TokenKind::TOK_LPAREN:
        			return "(";
        		case TokenKind::TOK_RPAREN:
        			return ")";
				case TokenKind::TOK_SEMICOL:
					return ";";
				default:
					return "How did we even get here?";
        	}
        }
    }
}