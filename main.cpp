#include <iostream>
#include "Lexer.h"
#include "JsonParser.h"
#include "JsonConfigLoader.h"

std::string checkProgramArgument(int argc, char *const *argv);

int main(int argc, char* argv[]) {
    std::string fileName = checkProgramArgument(argc, argv);
    JsonConfigLoader jsonConfigLoader(fileName);

    int number = jsonConfigLoader.getInt("size");
    std::string text = jsonConfigLoader.getString("glossary.GlossDiv.GlossList.GlossEntry.GlossDef.GlossSeeAlso[1]");

    return 0;
}

std::string checkProgramArgument(int argc, char *const *argv) {
    if(argc == 2) {
        return argv[1];
    }
    throw std::invalid_argument("Wrong program arguments");
}