
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
extern void error(const std::string);
extern std::map<std::string,Variable> symbolTable;

/*
float parseFloat(std::string s) {
    try {
        return stof(s);
    }
    catch (std::invalid_argument &ex) {
        error("invalid value for float: "+s);
        return -12.34f; // sentinel value
    }
}
float parseInt(std::string s) {
    try {
        return stoi(s);
    }
    catch (std::invalid_argument &ex) {
        error("invalid value for int: "+s);
        return -1234; // sentinel value
    }
}
*/
char * gen_infix(char op1[], char op[], char op2[])
{
  char tempop[8];

  // If type of both operands is INT
  if(symbolTable[op1].type == INT && symbolTable[op2].type == INT) {
        int result = 0;
        if ( strcmp( op, "Add") == 0) {
            strcpy(tempop,"iadd" );
            //result = parseInt(symbolTable[op1].val) + parseInt(symbolTable[op2].val);
        }
        else if (strcmp( op, "Sub") == 0) {
            strcpy(tempop,"isub" );
            //result = parseInt(symbolTable[op1].val) - parseInt(symbolTable[op2].val);
        }
        else if (strcmp( op, "Mul") == 0) {
            strcpy(tempop,"imul" );
            //result = parseInt(symbolTable[op1].val) * parseInt(symbolTable[op2].val);
        }
        else if (strcmp( op, "Div") == 0) {
            strcpy(tempop,"idiv" );
            //result = parseInt(symbolTable[op1].val) / parseInt(symbolTable[op2].val);
        }

        char *tempname = temp_int();
        //symbolTable[tempname].val = result;
        outFile << tempop << " " << op1 << ", " << op2 << ", " << tempname << std::endl;
        return (tempname);
    }
  // If type of both operands in REAL
  else if (symbolTable[op1].type == REAL && symbolTable[op2].type == REAL) {
        double result = 0.0;
        if ( strcmp( op, "Add") == 0) {
            strcpy(tempop,"radd" );
            //result = parseFloat(symbolTable[op1].val) + parseFloat(symbolTable[op2].val);
        } 
        else if ( strcmp( op, "Sub") == 0 ) {
            strcpy(tempop,"rsub" );
            //result = parseFloat(symbolTable[op1].val) - parseFloat(symbolTable[op2].val);
        } 
        else if ( strcmp( op, "Mul" ) == 0) {
            strcpy(tempop,"rmul" );
            //result = parseFloat(symbolTable[op1].val) * parseFloat(symbolTable[op2].val);
        } 
        else if (strcmp( op, "Div") == 0) {
            strcpy(tempop,"rdiv" );
            //result = parseFloat(symbolTable[op1].val) / parseFloat(symbolTable[op2].val);
        }

        char *tempname = temp_real();
        //symbolTable[tempname].val = result;
        outFile << tempop << " " << op1 << ", " << op2 << ", " << tempname << std::endl;
        return (tempname);
  }
  // if data types are not the same, run operation then convert
  // For if we need to convert the first operand
  else if (symbolTable[op1].type == INT && symbolTable[op2].type == REAL) {
        op1 = convert_to_real(op1);
        double res = 0.0;
        if ( strcmp( op, "Add") == 0 ) {
            strcpy(tempop, "radd");
        }
        else if ( strcmp( op, "Sub") == 0 ){
            strcpy(tempop,"rsub" );
        }
        char *tempname = temp_real();
        outFile << tempop << " " << op1 << ", " << op2 << ", " << tempname << std::endl;
        return (tempname);
  }
  // If the types differ and we need to convert the second operand:
  else if (symbolTable[op1].type == REAL && symbolTable[op2].type == INT) {
       if ( strcmp( op, "Add") == 0) {
           op2 = convert_to_real(op2);
           strcpy(tempop,"radd" );
       }
        else {
           op2 = convert_to_real(op2);
           strcpy(tempop,"rsub" );
        }
        char *tempname = temp_real();
        outFile << tempop << " " << op1 << ", " << op2 << ", " << tempname << std::endl;
        return (tempname);
  }
  else {
      error("Data types are neither INT nor REAL.");
  }

}
