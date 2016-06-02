//
// Created by tomasz on 23.05.16.
//

#ifndef LEXER_TOKEN_H
#define LEXER_TOKEN_H

#include <string>
#include "TokenType.h"

class Token {
public:

    Token(TokenType tokenType);

    Token(TokenType tokenType, std::string text);

    Token(TokenType tokenType, int number);

    ~Token();

    TokenType getType() const {
        return type;
    }

    int getNumber() const {
        return number;
    }

    const std::string &getText() const {
        return text;
    }

    std::string toString();

private:

    TokenType type;

    int number;

    std::string text;
};


#endif //LEXER_TOKEN_H
