//
// Created by tomasz on 23.05.16.
//

#include <iostream>
#include "Token.h"

std::string Token::toString() {
    switch (type) {
        case TokenType::TEXT:
        case TokenType::NUMBER:
            return value;
        default:
            return std::string(1, (char)type);
    }
}