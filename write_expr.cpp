#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "symbol_table.h"
#include <iostream>
#include <fstream>
extern std::ofstream outFile;
extern void error(const char msg[]);
extern std::map<std::string,Variable> symbolTable;

char * write_expr()
{

}