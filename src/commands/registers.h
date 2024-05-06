#pragma once

#define REGSIZE 16

static unsigned REG[REGSIZE];
const char RegNames[REGSIZE][5];

unsigned int isRegisterValid(char *regName);
unsigned int* initRegister(char *regName);