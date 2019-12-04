#include <iostream>
#include <fstream>
#include <string.h>
#include "symbol_table.h"

extern std::ofstream outFile;
extern void error(const char msg[]);
extern void error(const std::string);

extern std::map<std::string,Variable> symbolTable;
extern Variable *lookup(const char[]);

void decl_id(const char identifier[], Type type) {
    if (lookup(identifier)!=NULL) {
            error("SYMBOL ALREADY DEFINED: "+std::string(identifier));
        }
        else {
            symbolTable[identifier] = {type, 0, type};
            outFile << "declare " << identifier << ", " << type_str(type) << std::endl;
        }
}


void decl_array(char identifier[], Type type, int length) {
    if (length<=0) {error("ARRAY LENGTH MUST BE POSITIVE");}
    for (int i=0; i<length; i++) {
        std::string elemName = std::string(identifier)+"&"+std::to_string(i);
        decl_id(elemName.c_str(), type);
    }
}

void decl_function(char identifier[], Type type) {
    if (lookup(identifier)!=NULL) {
            error("SYMBOL ALREADY DEFINED: "+std::string(identifier));
    }
    symbolTable[identifier] = {FUNC, 0, type};
    std::string returnVar = "&#"+std::string(identifier);
    decl_id(strdup(returnVar.c_str()), type);
}
void decl_procedure(char identifier[]) {
    if (lookup(identifier)!=NULL) {
            error("SYMBOL ALREADY DEFINED: "+std::string(identifier));
    }
    symbolTable[identifier] = {FUNC, 0, FUNC};
}
