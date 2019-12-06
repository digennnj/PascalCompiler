#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <stack>
#include "symbol_table.h"
extern std::ofstream outFile;
extern std::stack<std::ofstream*> methodFiles;
extern char *convert_to_int(const char[]);
extern char *convert_to_real(const char[]);
extern std::map<std::string,Variable> symbolTable;
extern void error(const char msg[]);
extern void error(const std::string);
extern void printSymbolTable();

void assign_lit(const char target[], const char source[])
{
    std::ofstream* outFile = methodFiles.top();
    *outFile << "store " << source << ", " << target << std::endl;
}
void assign (const char target[], const char source[])
{
    std::ofstream* outFile = methodFiles.top();
     /* Generate code for assignment. */
     if (symbolTable.find(target)==symbolTable.end()) {printSymbolTable(); error("TARGET SYMBOL NOT DEFINED: "+std::string(target));}
     else if (symbolTable.find(source)==symbolTable.end()) {printSymbolTable(); error("SOURCE SYMBOL NOT DEFINED FOR "+std::string(target)+": "+std::string(source));}
     else {
          if (symbolTable[target].type != symbolTable[source].type) {
              if (symbolTable[target].type == REAL) {
                  if (symbolTable[source].type == INT) {
                    char * temp = convert_to_real(source);
                    *outFile << "store " << temp << ", " << target << std::endl;
                  }
                  else {error("Can't assign "+type_str(symbolTable[source].type)+" value to a real");}
              }
              else if (symbolTable[target].type == INT) {
                  if (symbolTable[source].type == REAL) {
                    char * temp = convert_to_int(source);
                    *outFile << "store " << temp << ", " << target << std::endl;
                  }
                  else {error("Can't assign "+type_str(symbolTable[source].type)+" value to a int");}
              }
              else {
                  error("Can't assign "+type_str(symbolTable[source].type)+" value to a "+type_str(symbolTable[target].type));
              }
          } else {
               *outFile << "store " << source << ", " << target << std::endl;
          }
     }
}
