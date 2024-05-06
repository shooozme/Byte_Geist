#include <stdio.h>
#include <commands.h>
#include <string.h>
#include "token.h"

#define REGSIZE 16

//static unsigned REG[REGSIZE];
#define REGARR (Reg[REGSIZE])

//Const array of all valid register names
//should REG_0 always be zero?
const char RegNames[REGSIZE][5] = {
    "REG_0", "REG_1", "REG_2", "REG_3", "REG_4", 
    "REG_5", "REG_6", "REG_7", "REG_8", "REG_9", 
    "REG10", "REG11", "REG12", "REG13", "REG14", 
    "REG15"};

Token* parseData(char *fileInput) {
    //n is thenumber of characters
    int n;
    fscanf(fileInput, "%d", n);
    
    char* currentToken;
    Token* tokenList = malloc(sizeof(Token) * n);

    //we can either scan the input here and pass it
    //or we can call the command and let it handle its own processing
    //issue then becomes we have fileInput going everywhere instead of just beind done here
    //so in this case we should handle all of fileInput here and just pass values!

    for (int i = 0; i < n; i) {
        if (strcmp(fileInput[i], "[") == 0) {
            tokenList[i] = *NewToken(TOKEN_LEFT_BRACE, 0, 0, NULL, NULL);
            i++;
        }
        else if (strcmp(fileInput[i], "]") == 0) {
            tokenList[i] = *NewToken(TOKEN_RIGHT_BRACE, 0, 0, NULL, NULL);
            i++;
        }
        else if (strcmp(fileInput[i], "\n") == 0) {
            tokenList[i] = *NewToken(TOKEN_NEWLINE, 0, 0, NULL, NULL);
            i++;
        }

        
    }
    
    return tokenList;
    //parsedata needs to terminate when reaching EOL!
}

unsigned int isRegisterValid(char *regName) {

    for(int i = 0; i < REGSIZE; i++) {
        if(strcmp(RegNames[i], regName) == 0) {
            //a valid register has been entered return 1
            return 1;
        } else {
            //a nonvalid register has been entered in the file spit out the name, and exit!
            printf("A nonvalid register has been entered %s", regName);
            exit(-1);
        }
    }
}

unsigned int initRegister(char *regName) {
    
    if(isRegisterValid(regName)) {
        return //the register
    } 
}