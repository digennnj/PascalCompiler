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

int line_no = 1;
std::ofstream outFile;

std::map<std::string,Variable> symbolTable;

void assign (char [], char []);
void decl_id ( char [] );
void finish();
char * gen_infix(char [], char [], char []);
void read_id (char []);
void write_expr(char []);
void error(const char []);
void yyerror(const char []);
%}
%union{
       int ival;
       char * sval;
       }
%token PROGRAM VAR START END READ WRITE ASSIGNOP INTEGER INTLITERAL
%token REAL CHARACTER
%token LPAREN RPAREN COMMA PERIOD SEMICOLON COLON PLUSOP MINUSOP ID

%left PLUSOP MINUSOP

%type <sval>ident
%type <sval>expression
%type <sval>expr
%type <sval>term
%type <sval>add_op

%start system_goal
%%


program	    :	 PROGRAM {line_no++;} variables START {line_no++;} statement_list END PERIOD {line_no++;} 
		;
variables   :	SEMICOLON {line_no++;}
		 | VAR i_list COLON INTEGER SEMICOLON {line_no++;}
		 | VAR i_list COLON INTEGER SEMICOLON {line_no++;} variables
		 | VAR r_list COLON REAL SEMICOLON {line_no++;}
		 | VAR r_list COLON REAL SEMICOLON {line_no++;} variables
		 | VAR c_list COLON CHARACTER SEMICOLON {line_no++;}
		 | VAR c_list COLON CHARACTER SEMICOLON {line_no++;} variables
		;
i_list      :   i_decl
		 | i_list COMMA i_decl
		;
i_decl    :   ident { decl_int($1); }
        |   ident ASSIGNOP expression { decl_int($1); } {assign($1,$3);}
        ;
r_list      :   r_decl
		 | r_list COMMA r_decl
		;
r_decl    :   ident { decl_real($1); }
        |   ident ASSIGNOP expression { decl_real($1); } {assign($1,$3);}
        ;
c_list      :   c_decl
		 | c_list COMMA c_decl
		;
c_decl    :   ident { decl_char($1); }
        |   ident ASSIGNOP expression { decl_char($1); } {assign($1,$3);}
        ;
statement_list  :   statement
                 | statement_list statement
		;
statement  :	ident ASSIGNOP expression {assign($1,$3);} SEMICOLON {line_no++;}
		;
statement  :	READ lparen id_list rparen SEMICOLON {line_no++;}
		;
statement  :	WRITE lparen expr_list rparen SEMICOLON {line_no++;}
		;
statement  :    SEMICOLON {line_no++;}
		;
id_list    :	ident      {read_id($1);}
  		| id_list COMMA ident {read_id($3);}
		;
expr_list  :	expression   {write_expr($1);}
                | expr_list COMMA expression {write_expr($3);}
		;
expression :	expr   {$$=strdup($1);}
                ;
expr       :    term {$$=strdup($1);}
		| expr add_op term {$$=strdup(gen_infix($1,$2,$3));}
		| {error("EXPRESSION EXPECTED, BUT FOUND");}
		;
term      :	lparen expression rparen   {$$=strdup($2);}
		;
term      :	ident      {if (symbolTable.find($1)==symbolTable.end()) {
                            error("SYMBOL NOT DEFINED");}
                        else {$$=strdup($1);}}
		;
term      :	INTLITERAL {$$ = strdup(yylval.sval);}
		| {error("NUMERIC VALUE EXPECTED, BUT FOUND");}
		;
lparen    :	LPAREN
		| {error("( EXPECTED , BUT FOUND");}
		;
rparen    :	RPAREN
		| {error(") EXPECTED , BUT FOUND");}
		;
add_op    :	PLUSOP {$$=strdup("Add");}
		;
add_op    :	MINUSOP {$$=strdup("Sub");}
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

void yyerror(const char s[]) {
  std::cout << "EEK, parse error!  Message: " << s << std::endl;
  // might as well halt now:
  exit(-1);
} 
