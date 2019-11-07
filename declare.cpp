#include <iostream>
#include <fstream>
#include "symbol_table.h"

extern std::ofstream outFile;
extern void error(const char msg[]);
extern void error(const std::string);

extern std::map<std::string,Variable> symbolTable;

void decl_id(char identifier[], Type type) {
    if (symbolTable.find(identifier) != symbolTable.end()) {
            error("SYMBOL ALREADY DEFINED: "+std::string(identifier));
        }
        else {
            symbolTable[identifier] = {type};
            outFile << "declare " << identifier << ", " << type_str(type) << std::endl;
        }
}
