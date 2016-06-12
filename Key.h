//
// Created by tomasz on 11.06.16.
//

#ifndef LEXER_KEY_H
#define LEXER_KEY_H

static const int DEFAULT_INDEX = -1;

#include <string>

class Key {
public:

    Key(std::string name, int index = DEFAULT_INDEX) : name(name), index(index) {}

    const std::string &getName() const { return name; }

    int getIndex() const { return index; }

private:

    std::string name;

    int index;
};


#endif //LEXER_KEY_H
