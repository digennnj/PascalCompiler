#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include "symbol_table.h"
extern std::ofstream outFile;
extern char *convert_to_int(const char[]);
extern char *convert_to_real(const char[]);
extern void error(const char msg[]);
extern void error(const std::string);
extern void printSymbolTable();
extern Variable *lookup(const char[]);

void assign_lit(const char target[], const char source[])
{
    outFile << "store " << source << ", " << target << std::endl;
}
void assign (const char target[], const char source[])
{
     /* Generate code for assignment. */
    Variable *targetVar = lookup(target);
    Variable *sourceVar = lookup(source);
     if (targetVar==NULL) {printSymbolTable(); error("TARGET SYMBOL NOT DEFINED: "+std::string(target));}
     else if (sourceVar==NULL) {printSymbolTable(); error("SOURCE SYMBOL NOT DEFINED FOR "+std::string(target)+": "+std::string(source));}
     else {
          if (targetVar->type != sourceVar->type) {
              if (targetVar->type == REAL) {
                  if (sourceVar->type == INT) {
                    char * temp = convert_to_real(source);
                    outFile << "store " << temp << ", " << target << std::endl;
                  }
                  else {error("Can't assign "+type_str(sourceVar->type)+" value to a real");}
              }
              else if (targetVar->type == INT) {
                  if (sourceVar->type == REAL) {
                    char * temp = convert_to_int(source);
                    outFile << "store " << temp << ", " << target << std::endl;
                  }
                  else {error("Can't assign "+type_str(sourceVar->type)+" value to a int");}
              }
              else {
                  error("Can't assign "+type_str(sourceVar->type)+" value to a "+type_str(targetVar->type));
              }
          } else {
               outFile << "store " << source << ", " << target << std::endl;
          }
     }
}
