#include <stdio.h>
#include <string.h>
#include "token.h"

Token* parseData(char *fileInput, size_t n) {
    fscanf(fileInput, "%d", n);

    char* currentToken;
    Token* tokenList = malloc(sizeof(Token) * n);

    for (int i = 0; i < n; i) {
        if (strcmp(fileInput[i], "[") == 0) {
            tokenList[i] = *NewToken(TOKEN_LEFT_BRACE, 0, 0, NULL, NULL);
            i++;
        }
        else if (strcmp(fileInput[i], "]") == 0) {
            // Number literals can only exist within braces. Check to see if the current token is a number literal.
            if (isStringNumeric(currentToken)) {
                // todo: we should check if this numeric literal doesn't go beyond the bounds of 8 bytes.
                tokenList[i] = *NewToken(TOKEN_NUMBER_LITERAL, atoi(currentToken), 0, NULL, NULL);
                clearString(currentToken, sizeof(currentToken));
            }

            tokenList[i] = *NewToken(TOKEN_RIGHT_BRACE, 0, 0, NULL, NULL);
            i++;
        }
        else if (strcmp(fileInput[i], "\n") == 0) {
            tokenList[i] = *NewToken(TOKEN_NEWLINE, 0, 0, NULL, NULL);
            i++;
        }
        else if (isOperator(fileInput[i])) {
            tokenList[i] = *NewToken(TOKEN_OPERATOR, 0, fileInput[i], NULL, NULL);
            i++;
        }
        else {
            if (isRegisterValid(currentToken)) {
                tokenList[i] = *NewToken(TOKEN_REGISTER, 0, 0, currentToken, NULL);
                clearString(currentToken, sizeof(currentToken));
            }
            
            Token* token = getTokenIdentifier(currentToken);
            if (token != NULL) {
                tokenList[i] = *token;
                clearString(currentToken, sizeof(currentToken));
            }

            // If we can't find a token for this, it must be a register or a number literal.
            appendString(currentToken, sizeof(currentToken), fileInput[i]);
        }    
    }
    
    return tokenList;
    //parsedata needs to terminate when reaching EOL!
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
    if (strcmp(s, "ALLOCATE") == 0) {
        return NewToken(TOKEN_ALLOCATE, 0, 0, NULL, NULL);
    }
    else if (strcmp(s, "byte_geist") == 0) {
        return NewToken(TOKEN_MAGIC, 0, 0, NULL, NULL);
    }
    else {
        return NULL;
    }
}