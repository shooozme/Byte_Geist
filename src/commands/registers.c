#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REGSIZE 16

//#define REG(REGNUMBER) (Reg[REGNUMBER])

unsigned int isRegisterValid(char *regName);
unsigned int* initRegister(char *regName);

static char RegNames[REGSIZE][5] = {
    "REG_0", "REG_1", "REG_2", "REG_3", "REG_4", 
    "REG_5", "REG_6", "REG_7", "REG_8", "REG_9", 
    "REG10", "REG11", "REG12", "REG13", "REG14", 
    "REG15"};

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

unsigned int* initRegister(char *regName) {
    //does is Register valid exit the initRegister function?
    isRegisterValid(regName);
    //go through the array and find the matching string in RegNames[]
    //once found return the i at that number [0-15], this effecitvely gives us
    //our *address*, any function that calls initRegister must handle
    //the return integers properly!
    for(int i = 0; i < REGSIZE; i++) {
        if(strcmp(RegNames[i], regName) == 0) {
            return &i;
        }
    }
    printf("Failed to intialize register!");
    exit(-1);
}