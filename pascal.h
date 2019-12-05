#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "symbol_table.h"

extern std::ofstream outFile;
extern int line_no;

char *convert_to_int(const char *val);
char *convert_to_real(const char *val);
void decl_array(char[], Type, int);
char *gen_else(char[]);
void gen_endif(char[]);
char *gen_if(char[]);
char *gen_begin_loop();
char *gen_while_loop(char *varName);
char *gen_while_end(char *startLabel, char *endLabel);
void gen_repeat(char *varName, char *startLabel);
char *temp_char();
char *temp_str();
char *temp_int();
char *temp_real();
char *temp_bool();
char *temp_label();
void assign_lit(const char[], const char[]);
void assign(const char[], const char[]);
void decl_id (const char[], Type);
void decl_function(char identifier[], Type type);
void decl_procedure(char identifier[]);
void decl_array(char identifier[], Type type, int length);
void finish();
char * gen_infix(char [], const char [], char []);
char *gen_not(char []);
char *gen_neg(char []);
void read_id (char []);
void write_expr(char []);
char *gen_function(char [], Type);
char *gen_procedure(char []);
void end_function(char *);
void end_procedure(char *);
char *call_function(char []);
void call_procedure(char []);
Variable *lookup(const char[]);
void error(const char []);
void error(std::string);
void yyerror(const char []);
void printSymbolTable();
