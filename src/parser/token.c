#include "token.h"

Token* NewToken(TokenType type, int numberLiteral, char op, char *reserved) {
    Token* token = malloc(sizeof(Token));
    token->type = type;
    token->numberLiteral = numberLiteral;
    token->operator = op;
    token->reserved = reserved;
    return token;
}