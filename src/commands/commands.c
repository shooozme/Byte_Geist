#include <stdio.h>
#include "registers.h"

void ALLOCATE(const char* regName, const unsigned int data) {
    //isRegisterValid acts as a guard clause
    if (isRegisterValid(regName)) {
        //save the returned index from initRegister (returns the *address*)
        unsigned int index = *initRegister(regName);
        //set the data in the relevant index!
        REG[index] = data;
    }
}

void FREE(const char* regName) {
    //function needs to clean out and FREE the requested register
    //what do we set the freed register too? could do NULL or 0
    if (isRegisterValid(regName)) {
        unsigned int index = *initRegister(regName);
        //effectively frees the register by resetting its value to 0
        REG[index] = 0;
    }
}

//three parameters which are all registers
int ADD(const char* regA, const char* regB, const char* regResult) {
    //isRegisterValid acts as a guard clause
    if (isRegisterValid(regA) && isRegisterValid(regB) && isRegisterValid(regResult) )  {
        //returns the address of each passed register!
        //potentially unwanted pointer in initRegister and here!
        unsigned int A = *initRegister(A);
        unsigned int B = *initRegister(B);
        unsigned int result = *initRegister(regResult);
        
        //does simple addition with the registers
        result = REG[A] + REG[B];
        return result;
    }
}

//needs to handle negative numbers!
int SUB(const char* regA, const char* regB, const char* regResult) {
    if (isRegisterValid(regA) && isRegisterValid(regB) && isRegisterValid(regResult)) {
        unsigned int A = *initRegister(A);
        unsigned int B = *initRegister(B);
        unsigned int result = *initRegister(regResult);
        
        //does simple subtraction with the registers
        result = REG[A] - REG[B];
        return result;
    }
}

int MULT(const char* regA, const char* regB, const char* regResult) {
    if (isRegisterValid(regA) && isRegister(regB) && isRegisterValid(regResult)) {
        unsigned int A = *initRegister(A);
        unsigned int B = * initRegister(A);
        unsigned int result = *initRegister(regResult);

        //does multiplication 
        result = REG[A] * REG[B];
        return result;
    }
}

int DIVIDE(const char* regA, const char* regB, const char* regResult) {
    if (isRegisterValid(regA) && isRegister(regB) && isRegisterValid(regResult)) {
        unsigned int A = *initRegister(A);
        unsigned int B = * initRegister(A);
        unsigned int result = *initRegister(regResult);
    
        //does divide
        result = REG[A] / REG[B];
        return result;
    }
}