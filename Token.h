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

    Token(TokenType tokenType, std::string value);

    ~Token();

    TokenType getType() const {
        return type;
    }

    const std::string &getValue() const {
        return value;
    }

    std::string toString();

private:

    TokenType type;

    std::string value;
};


#endif //LEXER_TOKEN_H
