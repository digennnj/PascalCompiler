#include <iostream>
#include <fstream>
#include "symbol_table.h"

extern std::ofstream outFile;
extern void error(const char msg[]);
extern void error(const std::string);

extern std::map<std::string,Variable> symbolTable;

void decl_id(const char identifier[], Type type) {
    if (symbolTable.find(identifier) != symbolTable.end()) {
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
