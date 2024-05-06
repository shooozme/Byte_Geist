#pragma once

typedef enum {
    TOKEN_MAGIC          = 0,
    TOKEN_ALLOCATE       = 1,
    TOKEN_OPERATOR       = 2,
    TOKEN_REGISTER       = 3,
    TOKEN_NUMBER_LITERAL = 4,
    TOKEN_LEFT_BRACE     = 5,
    TOKEN_RIGHT_BRACE    = 6,
    TOKEN_NEWLINE        = 7,
    TOKEN_EOF            = 8,
    TOKEN_WHITESPACE     = 9,
    TOKEN_AS             = 10,
    TOKEN_FREE           = 11,
} TokenType;

typedef struct {
    TokenType type;
    union {
        int numberLiteral;
        char operator;
        char *reserved;
    };
} Token;

Token* NewToken(TokenType type, int numberLiteral, char op, char *reserved);