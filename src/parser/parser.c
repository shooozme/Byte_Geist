#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "token.h"
#include "../commands/registers.h"
#include "../../extern/log/log.h"

#define MAX_TOKENS 1024
#define MAX_TOKEN_SIZE 256

int appendString(char* s, size_t size, char c);
int isStringNumeric(char *s);
Token* getReservedKeyword(char *s);

Token* parseData(char *fileInput) {
    Token* tokenList = malloc(MAX_TOKENS * sizeof(Token));

    char currentToken[MAX_TOKEN_SIZE];
    memset(currentToken, 0, sizeof(currentToken));

    for (size_t i = 0; fileInput[i] != '\0'; i++) {
        switch (fileInput[i]) {
            case '[':
                tokenList[i] = *NewToken(TOKEN_LEFT_BRACE, 0, 0, NULL);
                break;
            case ']':
                tokenList[i] = *NewToken(TOKEN_RIGHT_BRACE, 0, 0, NULL);
                memset(currentToken, 0, sizeof(currentToken));
                break;
            case '\n':
                tokenList[i] = *NewToken(TOKEN_NEWLINE, 0, 0, NULL);
                break;
            case ' ':
                tokenList[i] = *NewToken(TOKEN_WHITESPACE, 0, 0, NULL);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                tokenList[i] = *NewToken(TOKEN_OPERATOR, 0, fileInput[i], NULL);
                break;
            default:
                // If we can't find any of the above characters, append each character to the current token until we find something.
                appendString(currentToken, sizeof(currentToken), fileInput[i]);

                Token* token = getReservedKeyword(currentToken);
                if (token != NULL) {
                    tokenList[i] = *token;
                    memset(currentToken, 0, sizeof(currentToken));
                }

                if (fileInput[i + 1] == ']') {
                    if (isStringNumeric(currentToken)) {
                        tokenList[i] = *NewToken(TOKEN_NUMBER_LITERAL, atoi(currentToken), 0, NULL);
                    }
                }
                break;
        }
    }

    tokenList[MAX_TOKENS - 1] = *NewToken(TOKEN_EOF, 0, 0, NULL);
    return tokenList;
}

int appendString(char* s, size_t size, char c) {
    if(strlen(s) + 1 >= size) {
        return 1;
    }

    s[strlen(s)] = c;
    s[strlen(s) + 1] = '\0';
    return 0;
}

int isStringNumeric(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }

    return 1;
}

Token* getReservedKeyword(char *s) {
    if (strcmp(s, "ALLOC") == 0) {
        return NewToken(TOKEN_ALLOCATE, 0, 0, "ALLOC");
    }
    else if (strcmp(s, "instructions") == 0) {
        return NewToken(TOKEN_MAGIC, 0, 0, "MAGIC");
    }
    else if (strcmp(s, "AS") == 0) {
        return NewToken(TOKEN_AS, 0, 0, "AS");
    }
    else if (strcmp(s, "FREE") == 0) {
        return NewToken(TOKEN_FREE, 0, 0, "FREE");
    }
    else if (isRegisterValid(s)) {
        return NewToken(TOKEN_REGISTER, 0, 0, s);
    }
    else {
        return NULL;
    }
}