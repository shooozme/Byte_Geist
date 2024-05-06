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

//three parameters which are all registers
int ADD(char* regA, char* regB, char* regResult) {
    //isRegisterValid acts as a guard clause
    isRegisterValid(regA);
    isRegisterValid(regB);
    isRegisterValid(regResult);
    
    //returns the address of each passed register!
    int A = *initRegister(A);
    int B = *initRegister(B);
    int result = *initRegister(regResult);

    //does simple addition with the registers
    result = REG[A] + REG[B];
    return result;
}


int SUB () {

}