
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "symbol_table.h"
#include <iostream>
#include <fstream>
extern std::ofstream outFile;
extern char *temp_int();
extern char *temp_real();
extern char *convert_to_int(const char *val);
extern char *convert_to_real(const char *val);
extern void error(const char msg[]);
extern std::map<std::string,Variable> symbolTable;

char * gen_infix(char operandl[], char op[], char operand2[])
{
  char tempop[8];
  char * op1 = operandl;
  char * op2 = operand2;

  // If type of both operands is INT
  if(symbolTable[op1].type == INT && symbolTable[op2].type == INT) {
        int result = 0;
        if ( strcmp( op, "Add") == 0) {
            strcpy(tempop,"iadd" );
            result = stoi(symbolTable[op1].val) + stoi(symbolTable[op2].val);
        }
        else if (strcmp( op, "Sub") == 0) {
            strcpy(tempop,"isub" );
            result = stoi(symbolTable[op1].val) - stoi(symbolTable[op2].val);
        }
        else if (strcmp( op, "Mul") == 0) {
            strcpy(tempop,"imul" );
            result = stoi(symbolTable[op1].val) * stoi(symbolTable[op2].val);
        }
        else if (strcmp( op, "Div") == 0) {
            strcpy(tempop,"idiv" );
            result = stoi(symbolTable[op1].val) / stoi(symbolTable[op2].val);
        }

        char *tempname = temp_int();
        symbolTable[tempname].val = result;
        outFile << tempop << " " << operandl << ", " << operand2 << ", " << tempname << std::endl;
        return (tempname);
    }
  // If type of both operands in REAL
  else if (symbolTable[op1].type == REAL && symbolTable[op2].type == REAL) {
        double result = 0.0;
        if ( strcmp( op, "Add") == 0) {
            strcpy(tempop,"radd" );
            result = stof(symbolTable[op1].val) + stof(symbolTable[op2].val);
        } 
        else if ( strcmp( op, "Sub") == 0 ) {
            strcpy(tempop,"rsub" );
            result = stof(symbolTable[op1].val) - stof(symbolTable[op2].val);
        } 
        else if ( strcmp( op, "Mul" ) == 0) {
            strcpy(tempop,"rmul" );
            result = stof(symbolTable[op1].val) * stof(symbolTable[op2].val);
        } 
        else if (strcmp( op, "Div") == 0) {
            strcpy(tempop,"rdiv" );
            result = stof(symbolTable[op1].val) / stof(symbolTable[op2].val);
        }

        char *tempname = temp_real();
        symbolTable[tempname].val = result;
        outFile << tempop << " " << operandl << ", " << operand2 << ", " << tempname << std::endl;
        return (tempname);
  }
  // if data types are not the same, run operation then convert
  // For if we need to convert the first operand
  else if (symbolTable[op1].type == INT && symbolTable[op2].type == REAL) {
        char* convert = convert_to_real(op1);
        double res = 0.0;
        if ( strcmp( op, "Add") == 0 ) {
            strcpy(tempop, "radd");
        }
        else if ( strcmp( op, "Sub") == 0 ){
            strcpy(tempop,"rsub" );
        }
        char *tempname = temp_real();
        outFile << tempop << " " << operandl << ", " << operand2 << ", " << tempname << std::endl;
        return (tempname);
  }
  // If the types differ and we need to convert the second operand:
  else if (symbolTable[op1].type == REAL && symbolTable[op2].type == INT) {
       if ( strcmp( op, "Add") == 0) {
           convert_to_real(op2);
           strcpy(tempop,"radd" );
       }
        else {
           convert_to_real(op2);
           strcpy(tempop,"rsub" );
        }
        char *tempname = temp_real();
        outFile << tempop << " " << operandl << ", " << operand2 << ", " << tempname << std::endl;
        return (tempname);
  }
  else {
      error("Data types are neither INT nor REAL.");
  }

}
