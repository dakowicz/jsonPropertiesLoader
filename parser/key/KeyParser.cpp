//
// Created by tomasz on 09.06.16.
//

#include "KeyParser.h"

const int KeyParser::WRONG_INDEX = -1;

const std::string KeyParser::PARSING_SUCCESS("Key parsing completed successfully");

const std::string KeyParser::PARSING_ERROR("Key parsing error");

bool KeyParser::validate() {
    getNextToken();
    return (parseKey() && isCompleted());
}

bool KeyParser::parseKey() {
    std::shared_ptr<Key> key = parseField();
    if(key != nullptr) {
        parsedKeys.push(key);
        if(isDot()) {
            getNextToken();
            return parseKey();
        }
        return true;
    }
    return false;
}

std::shared_ptr<Key> KeyParser::parseField() {
    std::string text;
    int index;
    if(isText()) {
        text = currentToken->getValue();
        getNextToken();
        index = parseBrackets();
        if(isCorrectIndex(index)) {
            return std::make_shared<Key>(text, index);
        }
        return std::make_shared<Key>(text);
    }
    return nullptr;
}

int KeyParser::parseBrackets() {
    if(isLeftSquare()) {
        getNextToken();
        if(isNumber()) {
            int index = std::stoi(currentToken->getValue());
            getNextToken();
            if(isRightSquare()) {
                getNextToken();
                return index;
            }
        }
        throw std::invalid_argument("Array index parsing error");
    }
    return WRONG_INDEX;
}

bool KeyParser::isRightSquare() const { return currentToken != nullptr && currentToken->getType() == TokenType::RIGHT_SQUARE_BRACKET; }

bool KeyParser::isLeftSquare() const { return currentToken != nullptr && currentToken->getType() == TokenType::LEFT_SQUARE_BRACKET; }

bool KeyParser::isCorrectIndex(int index) const { return index >= 0; }

bool KeyParser::isNumber() const { return currentToken != nullptr && currentToken->getType() == TokenType::NUMBER; }

bool KeyParser::isText() const { return currentToken != nullptr && currentToken->getType() == TokenType::TEXT; }

bool KeyParser::isDot() const { return currentToken != nullptr && currentToken->getType() == TokenType::DOT; }

void KeyParser::getNextToken() { currentToken = keyLexer.getNextToken(); }

bool KeyParser::isCompleted() const { return keyLexer.isEOF(); }
