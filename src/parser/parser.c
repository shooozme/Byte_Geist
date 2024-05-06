#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "token.h"
#include "../commands/registers.h"

int appendString(char* s, size_t size, char c);
int clearString(char* s, size_t size);
int isStringNumeric(char *s);
int isOperator(char c);
Token* getTokenIdentifier(char *s);

Token* parseData(char *fileInput, size_t n) {
    printf("Parsing data\n");
    printf("File input length: %zu\n", n);
    printf("File input: ```\n%s\n```\n\n", fileInput);

    char currentToken[256]; 
    Token* tokenList = malloc(n * sizeof(Token)); 
    size_t tokensFound = 0;

    for (size_t i = 0; i < n; i++) {
        if (fileInput[i] == '[') {
            tokenList[i] = *NewToken(TOKEN_LEFT_BRACE, 0, 0, NULL);
        }
        else if (fileInput[i] == ']') {
            // Number literals can only exist within braces. Check to see if the current token is a number literal.
            if (isStringNumeric(currentToken)) {
                // todo: we should check if this numeric literal doesn't go beyond the bounds of 8 bytes.
                tokenList[i] = *NewToken(TOKEN_NUMBER_LITERAL, atoi(currentToken), 0, NULL);
                clearString(currentToken, sizeof(currentToken));
            }

            tokenList[i] = *NewToken(TOKEN_RIGHT_BRACE, 0, 0, NULL);
        }
        else if (fileInput[i] == '\n') {
            tokenList[i] = *NewToken(TOKEN_NEWLINE, 0, 0, NULL);
        }
        else if (isOperator(fileInput[i])) {
            tokenList[i] = *NewToken(TOKEN_OPERATOR, 0, fileInput[i], NULL);
        }
        else {
            if (isRegisterValid(currentToken)) {
                tokenList[i] = *NewToken(TOKEN_REGISTER, 0, 0, currentToken);
                clearString(currentToken, sizeof(currentToken));
            }
            
            appendString(currentToken, sizeof(currentToken), fileInput[i]);

            Token* token = getTokenIdentifier(currentToken);
            if (token != NULL) {
                tokenList[i] = *token;
    
                tokensFound++;
                printf("Token %zu: Type=%d, Value=%d, Operator=%c, Reserved=%s\n",
                    tokensFound, tokenList[i].type, tokenList[i].numberLiteral, tokenList[i].operator, tokenList[i].reserved);

                clearString(currentToken, sizeof(currentToken));
            }

            continue;
        }  

        tokensFound++;
        printf("Token %zu: Type=%d, Value=%d, Operator=%c, Reserved=%s\n",
               tokensFound, tokenList[i].type, tokenList[i].numberLiteral, tokenList[i].operator, tokenList[i].reserved);  
    }
    
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

int clearString(char* s, size_t size) {
    for (int i = 0; i < size; i++) {
        s[i] = '\0';
    }

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

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }

    return 0;
}

Token* getTokenIdentifier(char *s) {
    if (strcmp(s, "ALLOC") == 0) {
        return NewToken(TOKEN_ALLOCATE, 0, 0, "ALLOC");
    }
    else if (strcmp(s, "instructions") == 0) {
        return NewToken(TOKEN_MAGIC, 0, 0, "MAGIC");
    }
    else {
        return NULL;
    }
}