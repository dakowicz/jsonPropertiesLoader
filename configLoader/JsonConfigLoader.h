//
// Created by tomasz on 09.06.16.
//

#ifndef LEXER_JSONCONFIGLOADER_H
#define LEXER_JSONCONFIGLOADER_H

#include "../parser/json/JsonParser.h"
#include "../parser/key/KeyParser.h"


class JsonConfigLoader {
public:

    JsonConfigLoader(std::string filename) : jsonParser(filename) {}

    std::string getString(std::string key);

    int getInt(std::string key);

private:

    JsonParser jsonParser;

    void printKey(const std::string &key) const;

    void printValue(int value) const;

    void printValue(std::string &value) const;
};


#endif //LEXER_JSONCONFIGLOADER_H
