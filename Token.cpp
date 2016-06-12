//
// Created by tomasz on 23.05.16.
//

#include <iostream>
#include "Token.h"

Token::Token(TokenType tokenType) {
    this->type = tokenType;
}

Token::Token(TokenType tokenType, std::string value) {
    this->type = tokenType;
    this->value = value;
}

Token::~Token() {

}

std::string Token::toString() {
    switch (type) {
        case TokenType::TEXT:
        case TokenType::NUMBER:
            return value;
        default:
            return std::string(1, (char)type);
    }
}











