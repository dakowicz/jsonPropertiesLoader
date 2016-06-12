//
// Created by tomasz on 02.06.16.
//

#include "JsonParser.h"
#include "../domain/Object.h"
#include "../domain/Array.h"

const std::string JsonParser::PARSING_ERROR("Json parsing error");

const std::string JsonParser::PARSING_SUCCESS("Json parsing completed successfully");

std::shared_ptr<Node> JsonParser::parseFile() {
    getNextToken();
    return parseObject();
}

std::shared_ptr<Node> JsonParser::parseObject() {
    std::vector<std::shared_ptr<Node>> members;
    if(isLeftCurly()){
        getNextToken();
        parseMembers(members);
        if(isRightCurly()){
            getNextToken();
            return std::make_shared<Object>(members);
        }
    }
    throw std::invalid_argument("Object parsing error");
}

void JsonParser::parseMembers(std::vector<std::shared_ptr<Node>> &members) {
    std::shared_ptr<Node> pair = parsePair();
    members.push_back(pair);
    if(isSeparator()){
        getNextToken();
        parseMembers(members);
    }
}

std::shared_ptr<Node> JsonParser::parsePair() {
    std::string key;
    std::shared_ptr<Node> value;
    if(isText()){
        key = currentToken->getValue();
        getNextToken();
        if(isColon()){
            getNextToken();
            value = parseValue();
            if(value != nullptr){
                return std::make_shared<Pair>(key, value);
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Node> JsonParser::parseValue() {
    if(isText()){
        const std::shared_ptr<Text> text = std::make_shared<Text>(currentToken->getValue());
        getNextToken();
        return text;
    }
    if(isNumber()){
        const std::shared_ptr<Number> number = std::make_shared<Number>(currentToken->getValue());
        getNextToken();
        return number;
    }
    if(isLeftSquare()){
        return parseArray();
    }
    if(isLeftCurly()){
        return parseObject();
    }
    throw std::invalid_argument("Value parsing error");
}

std::shared_ptr<Node> JsonParser::parseArray() {
    std::vector<std::shared_ptr<Node>> elements;
    if(isLeftSquare()){
        getNextToken();
        parseElements(elements);
        if(isRightSquare()){
            getNextToken();
            return std::make_shared<Array>(elements);
        }
    }
    throw std::invalid_argument("Array parsing error");
}

void JsonParser::parseElements(std::vector<std::shared_ptr<Node>> &elements) {
    std::shared_ptr<Node> value = parseValue();
    elements.push_back(value);
    if(isSeparator()){
        getNextToken();
        parseElements(elements);
    }
}

int JsonParser::getInt(std::queue<std::shared_ptr<Key>> &keys) {
    std::shared_ptr<Node> node = findNodeDFS(rootNode, keys);
    if(node->getType() == NodeType::NUMBER){
        return std::stoi(node->getName());
    }
    throw std::invalid_argument("Wrong value type of the matching node");
}

std::string JsonParser::getString(std::queue<std::shared_ptr<Key>> &keys) {
    std::shared_ptr<Node> node = findNodeDFS(rootNode, keys);
    if(node->getType() == NodeType::TEXT) {
        return node->getName();
    }
    throw std::invalid_argument("Wrong value type of the matching node");
}

std::shared_ptr<Node> JsonParser::findNodeDFS(std::shared_ptr<Node> currentNode, std::queue<std::shared_ptr<Key>> &keys) {
    if(keys.empty()){
        return currentNode;
    }
    std::shared_ptr<Key> currentKey = keys.front();
    for(auto& child : currentNode->getChildren()){
        switch (child->getType()){
            case NodeType::OBJECT:
                return findNodeDFS(child, keys);
            case NodeType::PAIR:
                if(child->getName() == currentKey->getName()){
                    const std::shared_ptr<Pair> pair = std::static_pointer_cast<Pair>(child);
                    if(isNotIndexed(currentKey)){
                        keys.pop();
                        return findNodeDFS(pair->getValue(), keys);
                    }
                    const std::shared_ptr<Node> &childArray = pair->getValue();
                    if(isCorrectArray(currentKey, childArray)){
                        keys.pop();
                        return findNodeDFS(getChildren(currentKey, childArray), keys);
                    }
                }
        }
    }
    throw std::invalid_argument("No value matches the given key");
}

void JsonParser::getNextToken() {
    currentToken = jsonLexer.getNextToken();
}

std::shared_ptr<Node> JsonParser::getChildren(const std::shared_ptr<Key> &currentKey, const std::shared_ptr<Node> &childArray) const {
    return childArray->getChildren(currentKey->getIndex());
}

bool JsonParser::isCorrectArray(const std::shared_ptr<Key> &currentKey, const std::shared_ptr<Node> &childArray) const {
    return childArray->getType() == NodeType::ARRAY && childArray->getChildren().size() > currentKey->getIndex();
}

bool JsonParser::isNotIndexed(const std::shared_ptr<Key> &currentKey) const { return currentKey->getIndex() == -1; }

bool JsonParser::isSeparator() const { return currentToken != nullptr && TokenType::SEPARATOR == currentToken->getType(); }

bool JsonParser::isRightSquare() const { return currentToken != nullptr && TokenType::RIGHT_SQUARE_BRACKET == currentToken->getType(); }

bool JsonParser::isLeftSquare() const { return currentToken != nullptr && TokenType::LEFT_SQUARE_BRACKET == currentToken->getType(); }

bool JsonParser::isNumber() const { return currentToken != nullptr && TokenType::NUMBER == currentToken->getType(); }

bool JsonParser::isColon() const { return currentToken != nullptr && TokenType::COLON == currentToken->getType(); }

bool JsonParser::isText() const { return currentToken != nullptr && TokenType::TEXT == currentToken->getType(); }

bool JsonParser::isRightCurly() const { return currentToken != nullptr && TokenType::RIGHT_CURLY_BRACKET == currentToken->getType(); }

bool JsonParser::isLeftCurly() const { return currentToken != nullptr && TokenType::LEFT_CURLY_BRACKET == currentToken->getType(); }