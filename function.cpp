#include <fstream>
#include <string.h>
#include "symbol_table.h"
extern char *temp_label();
extern std::ofstream outFile;
extern void decl_function(char*, Type);
extern void decl_procedure(char*);
extern void error(const char []);
extern void error(std::string);
extern std::map<std::string,Variable> symbolTable;

char *gen_function(char identifier[], Type type) {
    char *endLbl = temp_label();
    outFile << "jmp " << endLbl << std::endl;
    outFile << ":" << "#" << identifier << std::endl; // # means function?
    decl_function(identifier, type);
    return endLbl;
}
char *gen_procedure(char identifier[]) {
    char *endLbl = temp_label();
    outFile << "jmp " << endLbl << std::endl;
    outFile << ":" << "#" << identifier << std::endl; // # means function?
    decl_procedure(identifier);
    return endLbl;
}
void end_function(char *endLbl) {
    outFile << "return" << std::endl;
    outFile << ":" << endLbl << std::endl;
}
void end_procedure(char *endLbl) {
    outFile << "return" << std::endl;
    outFile << ":" << endLbl << std::endl;
}

char *call_function(char identifier[]) {
    if (symbolTable.find(identifier) == symbolTable.end()) {
            error("FUNCTION NOT DEFINED: "+std::string(identifier));
    }
    else if (symbolTable[identifier].type != FUNC || symbolTable[identifier].sub_type == FUNC) {
        error("NOT A FUNCTION: "+std::string(identifier));
    }
    outFile << "call " << "#" << identifier << std::endl;
    std::string returnVar = "&#"+std::string(identifier);
    return strdup(returnVar.c_str());
}

void call_procedure(char identifier[]) {
    if (symbolTable.find(identifier) == symbolTable.end()) {
            error("FUNCTION NOT DEFINED: "+std::string(identifier));
    }
    else if (symbolTable[identifier].type != FUNC || symbolTable[identifier].sub_type != FUNC) {
        error("NOT A PROCEDURE: "+std::string(identifier));
    }
    outFile << "call " << "#" << identifier << std::endl;
}
