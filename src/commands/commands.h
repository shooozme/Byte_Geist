#pragma once

/// @brief Allocates a given value to a specific register.
/// @param regName string of a register name used to find the correct register to allocate
/// @param data some data that we are allocating to a given register
void ALLOCATE(const char* regName, const unsigned int data);

/// @brief Frees a given register based on a register name.
/// @param regName string of a register name used to find the correct register to free
void FREE(const char* regName);

/// @brief Performs addition using registers. Uses three seperate registers to do this! 
/// @param regA register A for performing arithmetic
/// @param regB register B for performing arithmetic
/// @param regResult register for storing result of arithmetic
int ADD(const char* regA, const char* regB, const char* regResult);

/// @brief Performs subtraction using registers. Uses three seperate registers to do this! Will eventually 
/// have a need to handle negative values but at this current time is unable to.
/// @param regA register A for performing arithmetic
/// @param regB register B for performing arithmetic
/// @param regResult register for storing result of arithmetic
int SUB(const char* regA, const char* regB, const char* regResult);

/// @brief  Performs multiplication using registers. Uses three seperate registers to do this! WIll eventually
/// have a need to handle negative values but at this current time is unable to.
/// @param regA register A for performing arithmetic
/// @param regB register B for performing arithmetic
/// @param regResult register for storing result of arithmetic
int MULT(const char* regA, const char* regB, const char* regResult);

/// @brief  Performs division using registers. Uses three seperate registers to do this! WIll eventually
/// have a need to handle negative values but at this current time is unable to.
/// @param regA register A for performing arithmetic
/// @param regB register B for performing arithmetic
/// @param regResult register for storing result of arithmetic
int DIVIDE(const char* regA, const char* regB, const char* regResult);