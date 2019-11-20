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


char *gen_else(char[]);
void gen_endif(char[]);
char *gen_if(char[]);
char *temp_char();
char *temp_str();
char *temp_int();
char *temp_real();
char *temp_bool();
void assign_lit(char[], char[]);
void assign(char[], char[]);
void decl_id (char[], Type);
void finish();
char * gen_infix(char [], const char [], char []);
char *gen_not(char []);
char *gen_neg(char []);
void read_id (char []);
void write_expr(char []);
void error(const char []);
void yyerror(const char []);
%}
%union{
       int ival;
       char * sval;
       }
%token PROGRAM VAR START END READ WRITE ASSIGNOP
%token INTLITERAL REALLITERAL CHARACTER BOOLLITERAL STRLITERAL
%token INTTYPE REALTYPE CHARTYPE BOOLTYPE STRTYPE
%token EQOP NEQOP LTOP GTOP LEQOP GEQOP NOTOP
%token LPAREN RPAREN COMMA SQUOTE PERIOD SEMICOLON COLON PLUSOP MINUSOP MULTIPLYOP DIVIDEOP ID MODOP IF THEN ELSE

%left ANDOP OROP
%left NOTOP
%left EQOP NEQOP LTOP GTOP LEQOP GEQOP
%left PLUSOP MINUSOP
%left MULTIPLYOP DIVIDEOP MODOP


%type <sval>if_condition
%type <sval>if_statement
%type <sval>if
%type <sval>ident
%type <sval>expression
%type <sval>expr
%type <sval>term
%type <sval>CHARACTER
%type <sval>INTLITERAL
%type <sval>REALLITERAL
%type <sval>BOOLLITERAL
%type <sval>STRLITERAL


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
variables   :	SEMICOLON variables
		 | SEMICOLON 
         | decl_type decl_list SEMICOLON variables
         | decl_type decl_list SEMICOLON 
		;
decl_list : decl
          | decl_list COMMA decl
          ;
decl : ident {decl_id($1, cur_type);}
     | ident ASSIGNOP expression {decl_id($1, cur_type);} {assign($1,$3);}
     ;

statement_list  :   statement
                 | statement_list statement
		;
statement  : 	ident ASSIGNOP expression {assign($1,$3);} SEMICOLON
		;
statement  :	READ lparen id_list rparen SEMICOLON
		;
statement  :	WRITE lparen expr_list rparen SEMICOLON
		;
statement  :    SEMICOLON
		;
statement  :	START statement_list END
	   	| if
		;
if : if_statement {$1=gen_else($1);} else_statement {$$=$1; gen_endif($1);}
   | if_statement {$$=$1; gen_endif($1);}
// we need to create appropriate functions to handle these
// but this will handle the grammar and the line numbers
if_condition: IF expression THEN {$$=gen_if($2);}
    ;
if_statement:	if_condition statement {$$=$1;}
	    	;
else_statement: ELSE statement
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
ident     :	ID {$$=strdup(yylval.sval);}
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

void error( const char msg[] )
{
	std::cout << "LINE " << line_no << " : " << msg << std::endl;
	exit( -1 );
}
void error(const std::string msg) {
    error(msg.c_str());
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
