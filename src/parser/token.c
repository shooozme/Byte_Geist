#include "token.h"

Token* NewToken(TokenType type, int numberLiteral, char op, char *identifier, char *stringLiteral) {
    Token* token = malloc(sizeof(Token));
    token->type = type;
    token->numberLiteral = numberLiteral;
    token->operator = op;
    token->identifier = identifier;
    return token;
}