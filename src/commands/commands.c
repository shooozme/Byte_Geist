#include <stdio.h>
#include "registers.h"

void ALLOCATE(char* regName, const unsigned int data) {
    //isRegisterValid acts as a guard clause
    isRegisterValid(regName);
    //save the returned index from initRegister (returns the *address*)
    unsigned int index = *initRegister(regName);
    //set the data in the relevant index!
    REG[index] = data;
}

void DELETE(char* regName) {
    //function needs to clean out and delete the requested register
}

//does add need a third parameter to act as a destination register?
int ADD(char* A, char* B, char *ResultREG) {
    //isRegisterValid acts as a guard clause
    isRegisterValid(A);
    isRegisterValid(B);
    //isRegisterValid(ResultReg);
    

}


int SUB () {

}