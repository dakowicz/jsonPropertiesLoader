//
// Created by tomasz on 05.06.16.
//

#ifndef LEXER_NODE_H
#define LEXER_NODE_H

#include <vector>
#include <string>
#include <memory>
#include "NodeType.h"

class Node {
public:

    Node(std::string name, NodeType type, std::vector<std::shared_ptr<Node>> children = {}) :
            name(name), type(type), children(children) {}

    std::vector<std::shared_ptr<Node>> getChildren() const { return children; }

    std::shared_ptr<Node> getChildren(int index) const { return children[index]; }

    const std::string &getName() const { return name; }

    NodeType getType() const { return type; }

private:

    std::string name;

    std::vector<std::shared_ptr<Node>> children;

    bool visited;

    NodeType type;
};


#endif //LEXER_NODE_H
