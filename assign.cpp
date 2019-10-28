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

void assign (char target[], char source[])
{
     /* Generate code for assignment. */
     if (symbolTable.find(target)==symbolTable.end()) {error("TARGET SYMBOL NOT DEFINED");}
     else if (symbolTable.find(source)==symbolTable.end()) {error("SOURCE SYMBOL NOT DEFINED");}
     else {
          if (symbolTable[target].type != symbolTable[source].type) {
               if(symbolTable[target].type == REAL && symbolTable[source].type == INT) {
                    char * tempname = convert_to_real(symbolTable[source].val.c_str());
                    outFile << "store " << tempname << ", " << target << std::endl;
                    symbolTable[target].val = symbolTable[tempname].val;
               } else if(symbolTable[target].type == INT && symbolTable[source].type == REAL) {
                    char * tempname = convert_to_int(symbolTable[source].val.c_str());
                    outFile << "store " << tempname << ", " << target << std::endl;
                    symbolTable[target].val = symbolTable[source].val;
               } else if(symbolTable[target].type == CHAR) {
                    error("Assignment value is not a character");
               } else {
                    error("Assignment value is not a number");
               }
          } else {
               outFile << "store " << source << ", " << target << std::endl;
               symbolTable[target].val = symbolTable[source].val;
          }
     }
}

void assign_char (char target[], char source[])
{
     if (symbolTable.find(target)==symbolTable.end()) {error("SYMBOL NOT DEFINED");}
     else {
          if(symbolTable[target].type == CHAR) {
               outFile << "store " << source << ", " << target << std::endl;
               symbolTable[target].val = source;
          } else {
               switch (symbolTable[target].type) {
                    case 0:
                         error("Cannot assign character to integer");
                         break;
                    case 1:
                         error("Cannot assign character to real");
                         break;
               }
          }
     }
}

void assign_int(char target[], char source[]) {
     if (symbolTable.find(target)==symbolTable.end()) {error("SYMBOL NOT DEFINED");}
     else {
          if(symbolTable[target].type == INT) {
               outFile << "store " << source << ", " << target << std::endl;
               symbolTable[target].val = source;
          } else if (symbolTable[target].type == REAL) {
               char * temp = convert_to_real(source);
               outFile << "store " << temp << ", " << target << std::endl;
               symbolTable[target].val = symbolTable[temp].val;
          } else {
               error("Cannot assign integer to character");
          }
     }
}

void assign_real(char target[], char source[]) {
     if (symbolTable.find(target)==symbolTable.end()) {error("SYMBOL NOT DEFINED");}
     else {
          if(symbolTable[target].type == REAL) {
               outFile << "store " << source << ", " << target << std::endl;
               symbolTable[target].val = source;
          } else if (symbolTable[target].type == INT) {
               char * temp = convert_to_int(source);
               outFile << "store " << temp << ", " << target << std::endl;
               symbolTable[target].val = source;
          } else {
               error("Cannot assign real to character");
          }
     }
}

  
  
  
