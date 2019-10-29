
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "symbol_table.h"
#include <iostream>
#include <fstream>
extern std::ofstream outFile;
extern char *temp_int();
extern char *temp_real();
extern char *temp_bool();
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
  
  Type t1=symbolTable[op1].type, t2=symbolTable[op2].type;

  if (t1!=t2) {
      if (t1==INT && t2==REAL) { 
          op1 = convert_to_real(op1);
          t1=REAL;
      }
      else if (t1==REAL && t2==INT) {
          op2 = convert_to_real(op2);
          t2=REAL;
      }
      else {
          error("incompatible operand types: "+type_str(t1)+" and "+type_str(t2));
      }
  }
  Type t = t1;
  // If type of both operands is INT
  if(t==INT) {
        if ( strcmp( op, "Add") == 0) { strcpy(tempop,"iadd" ); }
        else if (strcmp( op, "Sub") == 0) { strcpy(tempop,"isub" ); }
        else if (strcmp( op, "Mul") == 0) { strcpy(tempop,"imul" ); }
        else if (strcmp( op, "Div") == 0) { strcpy(tempop,"idiv" ); }
        else { error("unsupported operation on ints: "+std::string(op)); }

        char *tempname = temp_int();
        outFile << tempop << " " << op1 << ", " << op2 << ", " << tempname << std::endl;
        return (tempname);
    }
  // If type of both operands in REAL
  else if (t==REAL) {
        if ( strcmp( op, "Add") == 0) { strcpy(tempop,"radd" ); } 
        else if ( strcmp( op, "Sub") == 0 ) { strcpy(tempop,"rsub" ); } 
        else if ( strcmp( op, "Mul" ) == 0) { strcpy(tempop,"rmul" ); } 
        else if (strcmp( op, "Div") == 0) { strcpy(tempop,"rdiv" ); }
        else { error("unsupported operation on reals: "+std::string(op)); }

        char *tempname = temp_real();
        outFile << tempop << " " << op1 << ", " << op2 << ", " << tempname << std::endl;
        return (tempname);
  }
  else if (t==BOOL) {
      if (strcmp(op, "And") == 0) {strcpy(tempop,"and");}
      else if (strcmp(op, "Or") == 0) {strcpy(tempop,"or");}
      else { error("unsupported operation on bools"+std::string(op));}

        char *tempname = temp_bool();
        outFile << tempop << " " << op1 << ", " << op2 << ", " << tempname << std::endl;
        return (tempname);
  }
  else {
      error("unsupported operand type "+type_str(t));
  }

}
