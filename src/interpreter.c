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
    printf("We opened the file\n");
    if (fileInput == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    // Parse the file input into a list of tokens.
    Token* tokenList = parseData(fileInput, strlen(fileInput));
    printf("We parsed the file\n");
    if (tokenList == NULL) {
        printf("Error: Could not parse file %s\n", argv[1]);
        return 1;
    }

    return 0;
}