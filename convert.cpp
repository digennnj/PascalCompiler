#include <stdio.h>
#include <iostream>
#include <fstream>
#include "symbol_table.h"
extern std::ofstream outFile;
extern char *temp_int();
extern char *temp_real();
extern std::map<std::string,Variable> symbolTable;

// Takes a real literal, converts to int and returns the temp variable of the location of the casted value
char *convert_to_int(const char val[]) {
    char *res = temp_int();
    char *temp = temp_real();
    outFile << "store " << val << ", " << temp << std::endl;
    outFile << "rtoi " << temp << ", " << res << std::endl;
    symbolTable[res].type = INT;
    symbolTable[res].val = atoi(val);
    return res;
}

// Takes a int literal, converts to real and returns the temp variable of the location of the casted value
char *convert_to_real(const char val[]) {
    char *res = temp_real();
    char *temp = temp_int();
    outFile << "store " << val << ", " << temp << std::endl;
    outFile << "itor " << temp << ", " << res << std::endl;
    symbolTable[res].type = REAL;
    symbolTable[res].val = atof(val);
    return res;
}

// Takes in real variable, grabs the variable value and returns a temp variable with the casted real variable value.
// char *convert_variable_to_int(const char varName[]) {
//     if (symbolTable.find(target)==symbolTable.end()) {error("VARIABLE NAME NOT FOUND");}
//     char *res = temp_int();
//     char *temp = temp_real();
//     outFile << "store " << val << ", " << temp << std::endl;
//     outFile << "rtoi " << temp << ", " << res << std::endl;
//     symbolTable[res].type = INT;
//     symbolTable[res].val = symbolTable[varName].val;
//     return res;
// }

// // Takes in int variable, grabs the variable value and returns a temp variable with the casted int variable value.
// char *convert_variable_to_real(const char varName[]) {
//     if (symbolTable.find(target)==symbolTable.end()) {error("VARIABLE NAME NOT FOUND");}
//     char *res = temp_int();
//     char *temp = temp_real();
//     outFile << "store " << symbolTable[varName].val << ", " << temp << std::endl;
//     outFile << "rtoi " << temp << ", " << res << std::endl;
//     symbolTable[res].type = REAL;
//     symbolTable[res].val = symbolTable[varName].val;
//     return res;
// }
