#include <stdio.h>
#include <iostream>
#include <fstream>
#include "symbol_table.h"
extern std::ofstream outFile;
extern std::map<std::string,Variable> symbolTable;
extern void error(const char msg[]);

void read_id (char id_name[])
{
     if (symbolTable.find(id_name)==symbolTable.end()) {error("SYMBOL NOT DEFINED");}
     else {outFile << "read " << id_name << ", " << type_str(symbolTable[id_name].type) << std::endl;}
}
