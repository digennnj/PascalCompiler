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
 
char *gen_if(char *varName) {
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
char *gen_else(char *elseLbl) {
	std::cerr << "else label: '" << elseLbl << "'" << std::endl;
	char *endIfLbl = temp_label();
	outFile << "jmp " << endIfLbl << std::endl;
	outFile << ":" << elseLbl << std::endl;
	return endIfLbl;
}
void gen_endif(char *endIfLbl) {
	std::cerr << "endif label: '" << endIfLbl << "'" << std::endl;
	outFile << ":" << endIfLbl << std::endl;
}
