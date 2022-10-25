#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    COMMENT,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    UNDEFINED,
    Eof
};

class Token
{
private:
    int tokenLine = 0;
    std::string tokenDescription = "";
    TokenType typeOfToken = TokenType::UNDEFINED;
    // TODO: add member variables for information needed by Token

public:
    Token(TokenType type, std::string description, int line);

    std::string getDescription(){return tokenDescription;}
    TokenType getType(){return typeOfToken;}
    int getLine(){return tokenLine;}

};

#endif // TOKEN_H

