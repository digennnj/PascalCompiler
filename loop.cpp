#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "symbol_table.h"
#include <iostream>
#include <fstream>
 
extern char *temp_label();
 
extern void error(const char msg[]);
extern void error(const std::string);
extern std::ofstream outFile;
extern std::map<std::string,Variable> symbolTable;
 
char *gen_begin_loop() {
    char *begin_label = temp_label();
    outFile << ":" << begin_label << std::endl;
    return begin_label;
}

char *gen_while_loop(char *varName) {
    if (symbolTable.find(varName) == symbolTable.end()) {
            error("SYMBOL NOT DEFINED: "+std::string(varName));
    } else {
        if(symbolTable[varName].type == BOOL) {
            char *tempLabel = temp_label();
            outFile << "jf " << varName << ", " << tempLabel << std::endl;;
            return tempLabel;
        }
        error("Expression must evaluate to boolean");
    }
}

char *gen_while_end(char *startLabel, char *endLabel) {
    outFile << "jmp " << startLabel << std::endl;
	outFile << ":" << endLabel << std::endl;
}

void gen_repeat(char *varName, char *startLabel) {
    if (symbolTable.find(varName) == symbolTable.end()) {
            error("SYMBOL NOT DEFINED: "+std::string(varName));
    } else {
        if(symbolTable[varName].type == BOOL) {
            outFile << "jf " << varName << ", " << startLabel << std::endl;
        } else {
            error("Expression must evaluate to boolean");
        }
    }
}
