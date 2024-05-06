#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser/parser.h"
#include "parser/token.h"
#include "util/file.h"
#include "../extern/log/log.h"

void printTokens(Token* tokenList);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        log_error("Usage: %s <filename>", argv[0]);
        return 1;
    }

    char* fileInput = openFile(argv[1]);
    log_info("We opened the file");
    if (fileInput == NULL) {
        log_error("Error: Could not open file %s", argv[1]);
        return 1;
    }

    // Parse the file input into a list of tokens.
    log_info("We are parsing the data");
    Token* tokenList = parseData(fileInput);
    if (tokenList == NULL) {
        log_error("Error: Could not parse file %s", argv[1]);
        return 1;
    }

    log_info("We parsed the data");
    log_info("Token list size: %zu", sizeof(tokenList) / sizeof(Token));

    printTokens(tokenList);

    free(fileInput);
    free(tokenList);
    return 0;
}

void printTokens(Token* tokenList) {
    size_t tokensFound = 0;
    for (size_t i = 0; i < sizeof(tokenList); i++) {
        tokensFound++;
        log_info("Token %zu: Type=%d, Value=%d, Operator=%c, Reserved=%s",
            tokensFound, tokenList[i].type, tokenList[i].numberLiteral, tokenList[i].operator, tokenList[i].reserved);
    }
}