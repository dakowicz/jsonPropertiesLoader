//
// Created by tomasz on 23.05.16.
//

#include <iostream>
#include "Token.h"

Token::Token(TokenType tokenType) {
    this->type = tokenType;
}

Token::Token(TokenType tokenType, std::string text) {
    this->type = tokenType;
    this->text = text;
}

Token::Token(TokenType tokenType, int number) {
    this->type = tokenType;
    this->number = number;
}

Token::~Token() {

}

std::string Token::toString() {
    switch (type) {
        case TokenType::TEXT:
            return text;
        case TokenType::NUMBER:
            return std::to_string(number);
        default:
            return std::string(1, (char)type);
    }
}











