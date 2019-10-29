#include <iostream>
#include <fstream>
#include "symbol_table.h"

extern std::ofstream outFile;
extern void error(const char msg[]);

extern std::map<std::string,Variable> symbolTable;

void decl_id(char identifier[], Type type) {
    if (symbolTable.find(identifier) != symbolTable.end()) {
            error("SYMBOL ALREADY DEFINED");
        }
        else {
            std::string typeStr = "";
            switch (type) {
                case INT: typeStr = "integer"; break;
                case CHAR: typeStr = "character"; break;
                case REAL: typeStr = "real"; break;
            }
            symbolTable[identifier] = {type};
            outFile << "declare " << identifier << ", " << typeStr << std::endl;
        }
}
