#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser/parser.h"
#include "parser/token.h"
#include "util/file.h"

void printTokens(Token* tokenList);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* fileInput = openFile(argv[1]);
    if (fileInput == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    // Parse the file input into a list of tokens.
    Token* tokenList = parseData(fileInput, strlen(fileInput));
    if (tokenList == NULL) {
        printf("Error: Could not parse file %s\n", argv[1]);
        return 1;
    }

    // Print the list of tokens.
    printTokens(tokenList);

    return 0;
}

// Write a function to print the list of tokens.
void printTokens(Token* tokenList) {
    for (int i = 0; tokenList[i].type != TOKEN_EOF; i++) {
        printf("Token %d: Type=%d, Value=%d, Operator=%c, Register=%s",
               i, tokenList[i].type, tokenList[i].numberLiteral, tokenList[i].op,
               tokenList[i].identifier);
    }
}