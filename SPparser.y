%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include "symbol_table.h"

extern "C" int yylex();
extern "C" int yyparse();
extern FILE * yyin;

extern int line_no;
Type cur_type = INT;
std::ofstream outFile;

std::map<std::string,Variable> symbolTable;

extern char *convert_to_int(const char *val);
extern char *convert_to_real(const char *val);


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
void assign_lit(const char[], const char[]);
void assign(const char[], const char[]);
void decl_id (const char[], Type);
void finish();
char * gen_infix(char [], const char [], char []);
char *gen_not(char []);
char *gen_neg(char []);
void read_id (char []);
void write_expr(char []);
void error(const char []);
void error(std::string);
void yyerror(const char []);
%}
%union{
       int ival;
       char * sval;
       }
%token PROGRAM VAR START END READ WRITE ASSIGNOP WHILE DO REPEAT UNTIL
%token INTLITERAL REALLITERAL CHARACTER BOOLLITERAL STRLITERAL
%token INTTYPE REALTYPE CHARTYPE BOOLTYPE STRTYPE
%token EQOP NEQOP LTOP GTOP LEQOP GEQOP NOTOP
%token LPAREN RPAREN COMMA SQUOTE PERIOD SEMICOLON COLON PLUSOP MINUSOP MULTIPLYOP DIVIDEOP ID MODOP IF THEN ELSE
%token LSQUARE RSQUARE

%left ANDOP OROP
%left NOTOP
%left EQOP NEQOP LTOP GTOP LEQOP GEQOP
%left PLUSOP MINUSOP
%left MULTIPLYOP DIVIDEOP MODOP


%type <sval>if_condition
%type <sval>if_statement
%type <sval>if
%type <sval>ident
%type <sval>array_ident
%type <sval>plain_ident
%type <sval>expression
%type <sval>expr
%type <sval>term
%type <sval>CHARACTER
%type <sval>INTLITERAL
%type <sval>REALLITERAL
%type <sval>BOOLLITERAL
%type <sval>STRLITERAL
%type <sval>WHILE
%type <sval>REPEAT
%type <sval>do


%start system_goal
%%


program	    :	 PROGRAM VAR variables START statement_list END PERIOD 
		;
decl_type : INTTYPE {cur_type = INT;}
     | REALTYPE {cur_type = REAL;}
     | CHARTYPE {cur_type = CHAR;}
     | BOOLTYPE {cur_type = BOOL;}
     | STRTYPE  {cur_type = STR;}
     ;
variables   :	semicolon variables
		 | semicolon 
         | decl_type decl_list semicolon variables
         | decl_type decl_list semicolon 
		;
decl_list : decl
          | decl_list COMMA decl
          ;
decl : plain_ident {decl_id($1, cur_type);}
     | plain_ident LSQUARE INTLITERAL RSQUARE {decl_array($1, cur_type, std::stoi($3));}
     | plain_ident assignop expression {decl_id($1, cur_type);} {assign($1,$3);}
     ;

semicolon : SEMICOLON
          | {error("expected semicolon");}
assignop  : ASSIGNOP
          | EQOP {error("expected :=, not =");}
statement_list  :   statement
                 | statement_list statement
		;
statement  : 	plain_ident assignop expression {assign($1,$3);} semicolon
           |    plain_ident LSQUARE INTLITERAL RSQUARE assignop expression
                        {std::string elem = std::string($1)+"&"+std::string($3);
                        assign(elem.c_str(), $6);}
		;
statement  :	READ lparen id_list rparen semicolon
		;
statement  :	WRITE lparen expr_list rparen semicolon
		;
statement  :    semicolon
		;
statement  :	START statement_list END
	   	| if
		| loop
		;
if : if_statement {$1=gen_else($1);} else_statement {$$=$1; gen_endif($1);}
   | if_statement {$$=$1; gen_endif($1);}
// we need to create appropriate functions to handle these
// but this will handle the grammar and the line numbers
if_statement:	if_condition statement {$$=$1;}
	    	;
if_condition: IF expression THEN {$$=gen_if($2);}
    ;
else_statement: ELSE statement
	      	;
loop	:		while_loop
		|		repeat_loop
		;
while_loop	:	WHILE {$1=gen_begin_loop();} expression do {$4=gen_while_loop($3);}  statement {gen_while_end($1, $4);}
		;
repeat_loop	:	REPEAT {$1=gen_begin_loop();} statement_list until expression {gen_repeat($5, $1);}
		;
do : DO {$$=strdup("do");}
   | {error("expected DO");}
    ;
until : UNTIL
      | {error("expected UNTIL");}
    ;
id_list    :	ident      {read_id($1);}
  		| id_list COMMA ident {read_id($3);}
		;
expr_list  :	expression   {write_expr($1);}
                | expr_list COMMA expression {write_expr($3);}
		;
expression :	expr   {$$=strdup($1);}
                ;
// see https://perso.esiee.fr/~najmanl/compil/Bison/bison_5.html
expr       :    term {$$=strdup($1);}
		| expr PLUSOP expr {$$=strdup(gen_infix($1,"Add",$3));}
		| expr MINUSOP expr {$$=strdup(gen_infix($1,"Sub",$3));}
		| expr MULTIPLYOP expr {$$=strdup(gen_infix($1,"Mul",$3));}
		| expr DIVIDEOP expr {$$=strdup(gen_infix($1,"Div",$3));}
		| expr MODOP expr {$$=strdup(gen_infix($1,"Mod",$3));}
		| expr ANDOP expr {$$=strdup(gen_infix($1,"And",$3));}
		| expr OROP expr {$$=strdup(gen_infix($1,"Or",$3));}
		| expr EQOP expr {$$=strdup(gen_infix($1,"Eq",$3));}
		| expr NEQOP expr {$$=strdup(gen_infix($1,"Neq",$3));}
		| expr LTOP expr {$$=strdup(gen_infix($1,"Lt",$3));}
		| expr GTOP expr {$$=strdup(gen_infix($1,"Gt",$3));}
		| expr LEQOP expr {$$=strdup(gen_infix($1,"Leq",$3));}
		| expr GEQOP expr {$$=strdup(gen_infix($1,"Geq",$3));}
        | NOTOP expr {$$=strdup(gen_not($2));}
        | MINUSOP expr {$$=strdup(gen_neg($2));}
		| {error("EXPRESSION EXPECTED, BUT FOUND");}
		;
term      :	lparen expression rparen   {$$=strdup($2);}
		;
term      :	INTLITERAL {$$ = temp_int(); assign_lit($$, $1);}
          |	REALLITERAL {$$ = temp_real(); assign_lit($$, $1);}
		| {error("NUMERIC VALUE EXPECTED, BUT FOUND");}
		;
term	   : CHARACTER {$$=temp_char(); assign_lit($$, $1);}
        | BOOLLITERAL {$$=temp_bool(); assign_lit($$, $1);}
        | STRLITERAL {$$=temp_str(); assign_lit($$, $1);}
		;
term      :	ident      {if (symbolTable.find($1)==symbolTable.end()) {
                            error("SYMBOL NOT DEFINED");}
                        else {$$=strdup($1);}}
		;
lparen    :	LPAREN
		| {error("( EXPECTED , BUT FOUND");}
		;
rparen    :	RPAREN
		| {error(") EXPECTED , BUT FOUND");}
		;
ident : plain_ident {$$=$1;}
      | array_ident {$$=$1;}
    ;
plain_ident     :	ID {$$=strdup(yylval.sval);}
                ;
array_ident : plain_ident LSQUARE INTLITERAL RSQUARE
                        { std::string elem = std::string($1)+"&"+std::string($3);
                            $$ = strdup(elem.c_str());}
		| {error("IDENTIFIER EXPECTED, BUT FOUND");}
		;
system_goal :	program  { finish(); }
		;
%%
int main( int argc, char **argv )
{
	char * loc;
	if( argc != 2 )
		std::cout << "Usage: pascal inputfile\n";
	else
	{
		std::string srcFilePath = argv[1]; // assume you are not mucking with pointers
		yyin = fopen( *++argv, "r" );
		if( yyin == NULL )
		{
			std::cout << "spascal: Couldn't open " << *argv << std::endl;
			exit( 1 );
		}
		
		std::string fileName = srcFilePath.substr(0, srcFilePath.rfind('.'));
		std::string asmFileName = fileName + ".asm";

		outFile.open(asmFileName);
		yyparse();
		fclose( yyin );
		outFile.close();
	}
}

void printSymbolTable() {
    std::cout << "Symbol Table:" << std::endl;
    for (auto it = symbolTable.begin(); it!=symbolTable.end(); it++) {
        std::cout << "\t" << it->first << ": " << it->second.type << std::endl;
    }
}

void yyerror(const char s[]) {
  std::cout << "EEK, parse error!  Message: " << s << " on line: " << line_no << std::endl;
  // might as well halt now:
  exit(-1);
} 
