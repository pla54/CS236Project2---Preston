#include "Token.h"
#include <string>

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    typeOfToken = type;
    tokenDescription = description;
    tokenLine = line;
}

