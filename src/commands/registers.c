#define REGSIZE 16

//static unsigned REG[REGSIZE];
#define REG(REGNUMBER) (Reg[REGNUMBER])

//Const array of all valid register names
//should REG_0 always be zero?
const char RegNames[REGSIZE][5] = {
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

//#define REG(REGNUMBER) (Reg[REGNUMBER])
unsigned int initRegister(char *regName, unsigned REG) {
    //does is Register valid exit the initRegister function?
    isRegisterValid(regName);

    //go through the array, find the correct register name matching, and determine the index number
    //then that number needs to be passed to the preprocessor macro in order to initialize the correct 
    //register
    int regIndex = -1;

    for(int i = 0; i < REGSIZE; i++) {
        if(strcmp(RegNames[i], regName) == 0) {
            regIndex = i;
            //*REG = regIndex;
        }
    }
}