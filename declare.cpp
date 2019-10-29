#include <iostream>
#include <fstream>
#include "symbol_table.h"

extern std::ofstream outFile;
extern void error(const char msg[]);

extern std::map<std::string,Variable> symbolTable;

void decl_id(char identifier[], std::string type) {
    if (symbolTable.find(identifier) != symbolTable.end()) {
            error("SYMBOL ALREADY DEFINED");
        }
        else {
            if (type == "INTEGER") {
                symbolTable[identifier] = {INT, ""};
                outFile << "declare " << identifier << ", integer" << std::endl;
            } else if (type == "REAL") {
                symbolTable[identifier] = {REAL, ""};
                outFile << "declare " << identifier << ", real" << std::endl;
            } else if (type == "CHARACTER") {
                symbolTable[identifier] = {CHAR, ""};
                outFile << "declare " << identifier << ", char" << std::endl;
            } else if (type == "BOOL") {
                symbolTable[identifier] = {BOOL, ""};
                outFile << "declare " << identifier << ", bool" << std::endl;
            } else if (type == "STR") {
                symbolTable[identifier] = {STR, ""};
                outFile << "declare " << identifier << ", bool" << std::endl;
            }
        }
}
