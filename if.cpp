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
extern Variable *lookup(const char[]);
 
char *gen_if(char *varName) {
    Variable *var = lookup(varName);
    if (var==NULL) {error("SYMBOL NOT DEFINED: "+std::string(varName));}
    if(var->type == BOOL) {
        char *tempLabel = temp_label();
        outFile << "jf " << varName << ", " << tempLabel << std::endl;;
        return tempLabel;
    }
    else {
        error("Expression must evaluate to boolean");
    }
}
char *gen_else(char *elseLbl) {
	char *endIfLbl = temp_label();
	outFile << "jmp " << endIfLbl << std::endl;
	outFile << ":" << elseLbl << std::endl;
	return endIfLbl;
}
void gen_endif(char *endIfLbl) {
	outFile << ":" << endIfLbl << std::endl;
}
