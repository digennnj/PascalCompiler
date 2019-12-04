#include <stdio.h>
#include <iostream>
#include <fstream>
#include "symbol_table.h"
extern std::ofstream outFile;
extern Variable *lookup(const char[]);
extern void error(const char msg[]);
extern void error(std::string);

void read_id (char id_name[])
{
    Variable *var = lookup(id_name);
    if (var==NULL) {
            error("SYMBOL NOT DEFINED: "+std::string(id_name));
    }
    else {outFile << "read " << id_name << ", " << type_str(var->type) << std::endl;}
}
