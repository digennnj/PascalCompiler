
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
  
  if(symbolTable[op1].type == INT && symbolTable[op2].type == INT) {
        int result = 0;
        if ( strcmp( op, "Add") == 0) {
            strcpy(tempop,"iadd" );
            result = atoi(symbolTable[op1].val.c_str()) + atoi(symbolTable[op2].val.c_str());
        }
        else if (strcmp( op, "Sub") == 0) {
            strcpy(tempop,"isub" );
            result = atoi(symbolTable[op1].val.c_str()) - atoi(symbolTable[op2].val.c_str());
        }
        else if (strcmp( op, "Mul") == 0) {
            strcpy(tempop,"imul" );
            result = atoi(symbolTable[op1].val.c_str()) * atoi(symbolTable[op2].val.c_str());
        }
        else if (strcmp( op, "Div") == 0) {
            if(0 == atoi(symbolTable[op2].val.c_str())) {error("DIVIDE BY ZERO");}
            strcpy(tempop,"idiv" );
            result = atoi(symbolTable[op1].val.c_str()) / atoi(symbolTable[op2].val.c_str());
        }
        else if (strcmp( op, "Mod") == 0) {
            if(0 >= atoi(symbolTable[op2].val.c_str())) {error("SECOND OPERAND MUST BE GREATER THAN ZERO");}
            strcpy(tempop,"imod" );
            result = atoi(symbolTable[op1].val.c_str()) % atoi(symbolTable[op2].val.c_str());
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
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
        } 
        else if ( strcmp( op, "Sub") == 0 ) {
            strcpy(tempop,"rsub" );
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
        } 
        else if ( strcmp( op, "Mul" ) == 0) {
            strcpy(tempop,"rmul" );
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
        } 
        else if (strcmp( op, "Div") == 0) {
            if(0 == atoi(symbolTable[op2].val.c_str())) {error("DIVIDE BY ZERO");}
            strcpy(tempop,"rdiv" );
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
        }
        else if (strcmp( op, "Mod") == 0) {
            error("OPERANDS MUST BE OF TYPE INT");
        }

        char *tempname = temp_real();
        symbolTable[tempname].val = result;
        outFile << tempop << " " << operandl << ", " << operand2 << ", " << tempname << std::endl;
        return (tempname);
  }
  // if data types are not the same, run operation then convert
  // For if we need to convert the first operand
  else if (symbolTable[op1].type == INT && symbolTable[op2].type == REAL) {
        char* convert = convert_to_real(symbolTable[op1].val.c_str());
        double result = 0.0;
        if ( strcmp( op, "Add") == 0 ) {
            strcpy(tempop, "radd");
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
        }
        else if ( strcmp( op, "Sub") == 0 ) {
            strcpy(tempop,"rsub" );
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
        }
        else if ( strcmp( op, "Mul") == 0 ) {
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
            strcpy(tempop,"rmul" );
        }
        else if ( strcmp( op, "Div") == 0 ) {
            if(0 == atoi(symbolTable[op2].val.c_str())) {error("DIVIDE BY ZERO");}
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
            strcpy(tempop,"rdiv" );
        }
        else if (strcmp( op, "Mod") == 0) {
            error("OPERANDS MUST BE OF TYPE INT");
        }

        char *tempname = temp_real();
        symbolTable[tempname].val = result;
        outFile << tempop << " " << operandl << ", " << operand2 << ", " << tempname << std::endl;
        return (tempname);
  }
  // If the types differ and we need to convert the second operand:
  else if (symbolTable[op1].type == REAL && symbolTable[op2].type == INT) {
        char* convert = convert_to_real(symbolTable[op2].val.c_str());
        double result = 0.0;
        if ( strcmp( op, "Add") == 0 ) {
            strcpy(tempop,"radd" );
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
        }
        else if ( strcmp( op, "Sub") == 0 ) {
            strcpy(tempop,"rsub" );
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
        }
        else if ( strcmp( op, "Mul") == 0 ) {
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
            strcpy(tempop,"rmul" );
        }
        else if ( strcmp( op, "Div") == 0 ) {
            if(0 == atoi(symbolTable[op2].val.c_str())) {error("DIVIDE BY ZERO");}
            result = atof(symbolTable[op1].val.c_str()) + atof(symbolTable[op2].val.c_str());
            strcpy(tempop,"rdiv" );
        }
        else if (strcmp( op, "Mod") == 0) {
            error("OPERANDS MUST BE OF TYPE INT");
        }

        char *tempname = temp_real();
        symbolTable[tempname].val = result;
        outFile << tempop << " " << operandl << ", " << operand2 << ", " << tempname << std::endl;
        return (tempname);
  }
  else {
      error("Data types are neither INT nor REAL.");
  }

}
