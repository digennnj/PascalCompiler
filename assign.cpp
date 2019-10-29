#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include "symbol_table.h"
extern std::ofstream outFile;
extern char *convert_to_int(const char[]);
extern char *convert_to_real(const char[]);
extern std::map<std::string,Variable> symbolTable;
extern void error(const char msg[]);
extern void error(const std::string);
extern void printSymbolTable();

void assign_lit(char target[], char source[])
{
    outFile << "store " << source << ", " << target << std::endl;
}
void assign (char target[], char source[])
{
     /* Generate code for assignment. */
     if (symbolTable.find(target)==symbolTable.end()) {printSymbolTable(); error("TARGET SYMBOL NOT DEFINED: "+std::string(target));}
     else if (symbolTable.find(source)==symbolTable.end()) {printSymbolTable(); error("SOURCE SYMBOL NOT DEFINED: "+std::string(source));}
     else {
          if (symbolTable[target].type != symbolTable[source].type) {
              if (symbolTable[target].type == REAL) {
                  if (symbolTable[source].type == INT) {
                    char * temp = convert_to_real(source);
                    outFile << "store " << temp << ", " << target << std::endl;
                  }
                  else {error("Can't assign value to a real");}
              }
              else if (symbolTable[target].type == INT) {
                  if (symbolTable[source].type == REAL) {
                    char * temp = convert_to_int(source);
                    outFile << "store " << temp << ", " << target << std::endl;
                  }
                  else {error("Can't assign value to an int");}
              }
              else if (symbolTable[target].type == CHAR) {
                  error("Can't assign value to a char");
              }
          } else {
               outFile << "store " << source << ", " << target << std::endl;
          }
     }
}
