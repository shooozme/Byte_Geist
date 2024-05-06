#pragma once

#define REGSIZE 16

static unsigned REG[REGSIZE];

unsigned int isRegisterValid(char *regName);
unsigned int* initRegister(char *regName);