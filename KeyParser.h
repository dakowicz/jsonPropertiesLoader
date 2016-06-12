//
// Created by tomasz on 09.06.16.
//

#ifndef LEXER_KEYPARSER_H
#define LEXER_KEYPARSER_H

#include <sstream>
#include <vector>
#include <queue>
#include "Lexer.h"
#include "KeyLexer.h"
#include "Key.h"

class KeyParser {
public:

    KeyParser(std::string key, std::queue<std::shared_ptr<Key>> &parsedKeys) : keyLexer(key), parsedKeys(parsedKeys) {
        if(validate()) {
            std::cout << PARSING_SUCCESS << std::endl;
        } else {
            throw std::invalid_argument(PARSING_ERROR);
        }
    }

private:

    bool validate();

    std::shared_ptr<Token> currentToken;

    KeyLexer keyLexer;

    std::queue<std::shared_ptr<Key>> &parsedKeys;

    bool parseKey();

    void getNextToken();

    bool isDot() const;

    std::shared_ptr<Key> parseField();

    bool isText() const;

    bool isNumber() const;

    bool isCorrectIndex(int index) const;

    int parseBrackets();

    bool isLeftSquare() const;

    bool isRightSquare() const;

    bool isCompleted() const;

    static const int WRONG_INDEX;

    static const std::string PARSING_SUCCESS;

    static const std::string PARSING_ERROR;
};


#endif //LEXER_KEYPARSER_H
