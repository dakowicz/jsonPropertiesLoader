#include <iostream>
#include "Lexer.h"

void wrongParameter();

char *checkProgramArgument(int argc, char *const *argv);

using namespace std;

int main(int argc, char* argv[]) {

    char* fileName;
    fileName = checkProgramArgument(argc, argv);
    Lexer lexer(fileName);
    Token *token;
    while(!lexer.isEOF()) {
        token = lexer.getNextToken();
        if(token != nullptr)
            std::cout << token->toString() << std::endl << std::flush;
    }

    return 0;
}

char *checkProgramArgument(int argc, char *const *argv) {
    char *fileName;
    if(argc == 2) {
        fileName = argv[1];
    } else {
        wrongParameter();
    }
    return fileName;
}

void wrongParameter() {
    cout << "Wrong program arguments.\nExiting.\n";
    exit(0);
}