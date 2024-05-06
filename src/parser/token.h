#pragma once

typedef enum {
    TOKEN_MAGIC,
    TOKEN_ALLOCATE,
    TOKEN_OPERATOR,
    TOKEN_REGISTER,
    TOKEN_NUMBER_LITERAL,
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_NEWLINE,
    TOKEN_EOF,
} TokenType;

typedef struct {
    TokenType type;
    int numberLiteral;
    char op;
    char *identifier;
} Token;

Token* NewToken(TokenType type, int numberLiteral, char op, char *identifier, char *stringLiteral);