
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "symbol_table.h"
#include <iostream>
#include <fstream>
extern std::ofstream outFile;
extern char *temp_str();
extern char *temp_int();
extern char *temp_real();
extern char *temp_bool();
extern char *convert_to_int(const char *val);
extern char *convert_to_real(const char *val);
extern void error(const char msg[]);
extern void error(const std::string);
extern std::map<std::string,Variable> symbolTable;

char *_do(const char cmd[], const char op1[], const char op2[]) {
    char *res;
    if (strcmp(cmd, "iadd")==0 || strcmp(cmd, "isub")==0 || strcmp(cmd, "imul")==0 || strcmp(cmd, "idiv")==0 || strcmp(cmd, "imod")==0) { res = temp_int();}
    else if (strcmp(cmd, "radd")==0 || strcmp(cmd, "rsub")==0 || strcmp(cmd, "rmul")==0 || strcmp(cmd, "rdiv")==0)                      { res = temp_real();}
    else if (strcmp(cmd, "and")==0 || strcmp(cmd, "or")==0 || strcmp(cmd, "equ")==0 || strcmp(cmd, "high")==0 || strcmp(cmd, "low")==0)  { res = temp_bool();}
    else if (strcmp(cmd, "concat")==0)  { res = temp_str();}
    else { error("invalid operation: "+std::string(cmd));}
    outFile << cmd << " " << op1 << ", " << op2 << ", " << res << std::endl;
    return res;
}
char *gen_neg(char op1[]) {
    Type t = symbolTable[op1].type;
    if (t==INT) {
        char *res = temp_int();
        outFile << "isub" << " " << "0" << ", " << op1 << ", " << res << std::endl;
        return res;
    }
    else if (t==REAL) {
        char *res = temp_real();
        outFile << "rsub" << " " << "0.0" << ", " << op1 << ", " << res << std::endl;
        return res;
    }
    else { error("invalid operand for not: "+std::string(op1));}
}
char *gen_not(char op1[]) {
    Type t = symbolTable[op1].type;
    if (t==BOOL) {
        char *res = temp_bool();
        outFile << "not" << " " << op1 << ", " << res << std::endl;
        return res;
    }
    else { error("invalid operand for not: "+std::string(op1));}
}
char * gen_infix(char op1[], const char op[], char op2[])
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
        if ( strcmp( op, "Add") == 0) { return _do("iadd", op1, op2);}
        else if (strcmp( op, "Sub") == 0) { return _do("isub", op1, op2);}
        else if (strcmp( op, "Mul") == 0) { return _do("imul", op1, op2);}
        else if (strcmp( op, "Div") == 0) { return _do("idiv", op1, op2);}
        else if (strcmp( op, "Mod") == 0) { return _do("imod", op1, op2);}
        else if (strcmp( op, "Eq") == 0) { return _do("equ", op1, op2);}
        else if (strcmp( op, "Neq") == 0) { return gen_not(_do("equ", op1, op2));}
        else if (strcmp( op, "Lt") == 0) { return _do("low", op1, op2);}
        else if (strcmp( op, "Gt") == 0) { return _do("high", op1, op2);}
        else if (strcmp( op, "Leq") == 0) { return _do("or", _do("low", op1, op2), _do("equ", op1,op2));}
        else if (strcmp( op, "Geq") == 0) { return _do("or", _do("high", op1, op2), _do("equ", op1,op2));}
        else { error("unsupported operation on ints: "+std::string(op)); }
  }
  // If type of both operands in REAL
  else if (t==REAL) {
        if ( strcmp( op, "Add") == 0) { return _do("radd", op1, op2);}
        else if ( strcmp( op, "Sub") == 0 ) { return _do("rsub", op1, op2);}
        else if ( strcmp( op, "Mul" ) == 0) { return _do("rmul", op1, op2);}
        else if (strcmp( op, "Div") == 0) { return _do("rdiv", op1, op2);}
        else if (strcmp( op, "Eq") == 0) { return _do("equ", op1, op2);}
        else if (strcmp( op, "Neq") == 0) { return gen_not(_do("equ", op1, op2));}
        else if (strcmp( op, "Lt") == 0) { return _do("low", op1, op2);}
        else if (strcmp( op, "Gt") == 0) { return _do("high", op1, op2);}
        else if (strcmp( op, "Leq") == 0) { return _do("or", _do("low", op1, op2), _do("equ", op1,op2));}
        else if (strcmp( op, "Geq") == 0) { return _do("or", _do("high", op1, op2), _do("equ", op1,op2));}
        else { error("unsupported operation on reals: "+std::string(op)); }
  }
  else if (t==BOOL) {
      if (strcmp(op, "And") == 0) {return _do("and", op1, op2);}
      else if (strcmp(op, "Or") == 0) {return _do("or", op1, op2);}
      else if (strcmp( op, "Eq") == 0) { return _do("equ", op1, op2);}
      else if (strcmp( op, "Neq") == 0) { return gen_not(_do("equ", op1, op2));}
      else { error("unsupported operation on bools: "+std::string(op));}
  }
  else if (t==CHAR) {
      if (strcmp( op, "Eq") == 0) { return _do("equ", op1, op2);}
      else if (strcmp( op, "Neq") == 0) { return gen_not(_do("equ", op1, op2));}
      else { error("unsupported operation on chars: "+std::string(op));}
  }
  else if (t==STR) {
      if (strcmp( op, "Eq") == 0) { return _do("equ", op1, op2);}
      else if (strcmp( op, "Neq") == 0) { return gen_not(_do("equ", op1, op2));}
      else if ( strcmp( op, "Add") == 0) { return _do("concat", op1, op2);}
      else { error("unsupported operation on strings: "+std::string(op));}
  }
  else {
      error("unsupported operand type "+type_str(t));
  }

}
