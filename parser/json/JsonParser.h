//
// Created by tomasz on 02.06.16.
//

#ifndef LEXER_PARSER_H
#define LEXER_PARSER_H

#include <queue>
#include <vector>
#include "../../lexer/json/JsonLexer.h"
#include "../domain/Node.h"
#include "../domain/Key.h"
#include "../domain/Pair.h"
#include "../domain/Text.h"
#include "../domain/Number.h"

class JsonParser {
public:

    JsonParser(std::string fileName) : jsonLexer(fileName){
        rootNode = parseFile();
        if(isCompleted()){
            std::cout << PARSING_SUCCESS << std::endl;
        } else {
            throw std::invalid_argument(PARSING_ERROR);
        }
    }

    bool isCompleted() const { return jsonLexer.isEOF(); }

    std::shared_ptr<Node> parseFile();

    int getInt(std::queue<std::shared_ptr<Key>> &keys);

    std::string getString(std::queue<std::shared_ptr<Key>> &keys);

private:

    JsonLexer jsonLexer;

    std::shared_ptr<Token> currentToken;

    std::shared_ptr<Node> rootNode;

    std::shared_ptr<Node> parseObject();

    void getNextToken();

    bool isSeparator() const;

    bool isRightSquare() const;

    bool isLeftSquare() const;

    bool isNumber() const;

    bool isColon() const;

    bool isText() const;

    bool isRightCurly() const;

    bool isLeftCurly() const;

    static const std::string PARSING_ERROR;

    static const std::string PARSING_SUCCESS;

    void parseMembers(std::vector<std::shared_ptr<Node>> &members);

    std::shared_ptr<Node> parsePair();

    std::shared_ptr<Node> parseValue();

    std::shared_ptr<Node> parseArray();

    void parseElements(std::vector<std::shared_ptr<Node>> &vector);

    std::shared_ptr<Node> findNodeDFS(std::shared_ptr<Node> currentNode, std::queue<std::shared_ptr<Key>> &keys);

    bool isNotIndexed(const std::shared_ptr<Key> &currentKey) const;

    bool isCorrectArray(const std::shared_ptr<Key> &currentKey, const std::shared_ptr<Node> &childArray) const;

    std::shared_ptr<Node> getChildren(const std::shared_ptr<Key> &currentKey, const std::shared_ptr<Node> &childArray) const;
};


#endif //LEXER_PARSER_H
