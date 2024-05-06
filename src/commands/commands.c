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
//three parameters which are all registers
int ADD(char* regA, char* regB, char* regResult) {
    //isRegisterValid acts as a guard clause
    isRegisterValid(regA);
    isRegisterValid(regB);
    isRegisterValid(regResult);
    
    //returns the address of each pass register!
    int A = *initRegister(A);
    int B = *initRegister(B);
    int result = *initRegister(regResult);

    //does simply edition with the registers
    result = REG[A] + REG[B];
    return result;
}


int SUB () {

}