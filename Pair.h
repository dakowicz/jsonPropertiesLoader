//
// Created by tomasz on 09.06.16.
//

#ifndef LEXER_PAIR_H
#define LEXER_PAIR_H


#include "Node.h"

class Pair : public Node {
public:

    Pair(std::string key, std::shared_ptr<Node> value) : Node(key, NodeType::PAIR), value(value){}

    const virtual std::shared_ptr<Node> &getValue() const {
        return value;
    }

private:
    std::shared_ptr<Node> value;
};


#endif //LEXER_PAIR_H
