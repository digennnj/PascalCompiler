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

extern char *convert_to_int(const char *val);
extern char *convert_to_real(const char *val);


void assign(char[], char[]);
void assign_char(char[], char[]);
void assign_int(char[], char[]);
void assign_real(char[], char[]);
void decl_id (char[], std::string);
void decl_int(char[]);
void decl_real(char[]);
void decl_char(char[]);
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
%token PROGRAM VAR START END READ WRITE ASSIGNOP INTLITERAL REALLITERAL
%token INTTYPE REALTYPE CHARTYPE CHARACTER
%token LPAREN RPAREN COMMA SQUOTE PERIOD SEMICOLON COLON PLUSOP MINUSOP MULTIPLYOP DIVIDEOP ID

%left PLUSOP MINUSOP MULTIPLYOP DIVIDEOP

%type <sval>ident
%type <sval>expression
%type <sval>expr
%type <sval>term
%type <sval>add_op
%type <sval>CHARACTER
%type <sval>INTLITERAL
%type <sval>REALLITERAL


%start system_goal
%%


program	    :	 PROGRAM {line_no++;} VAR variables START {line_no++;} statement_list END PERIOD {line_no++;} 
		;
variables   :	SEMICOLON {line_no++;} variables
		 | SEMICOLON {line_no++;}
		 | INTTYPE i_list SEMICOLON {line_no++;} variables
		 | INTTYPE i_list SEMICOLON {line_no++;}
		 | REALTYPE r_list SEMICOLON {line_no++;} variables
		 | REALTYPE r_list SEMICOLON {line_no++;}
		 | CHARTYPE c_list SEMICOLON {line_no++;} variables
		 | CHARTYPE c_list SEMICOLON {line_no++;}
		;
c_list      :   c_decl
		 | c_list COMMA c_decl
		;
c_decl    :   ident { decl_id($1, "CHARACTER"); }
		| 	ident ASSIGNOP REALLITERAL { error("Cannot convert real to character"); }
		| 	ident ASSIGNOP INTLITERAL { error("Cannot convert integer to character"); }
        |   ident ASSIGNOP expression { decl_id($1, "CHARACTER"); } {assign_char($1,$3); }
        ;
i_list      :   i_decl
		 | i_list COMMA i_decl
		;
i_decl    :   ident { decl_id($1, "INTEGER"); }
		| 	ident ASSIGNOP CHARACTER { error("Cannot convert character to integer"); }
		|	ident ASSIGNOP REALLITERAL { decl_id($1, "INTEGER"); } {assign_int($1,convert_to_int($3)); }
        |   ident ASSIGNOP expression { decl_id($1, "INTEGER"); } {assign_int($1,$3); }
        ;
r_list      :   r_decl
		 | r_list COMMA r_decl
		;
r_decl    :   ident { decl_id($1, "REAL"); }
		| 	ident ASSIGNOP CHARACTER { error("Cannot convert character to real"); }
		|	ident ASSIGNOP INTLITERAL { decl_id($1, "REAL"); } {assign_real($1,convert_to_real($3)); }
        |   ident ASSIGNOP expression { decl_id($1, "REAL"); } {assign_real($1,$3); }
        ;
statement_list  :   statement
                 | statement_list statement
		;
statement  : 	ident ASSIGNOP expression {assign($1,$3);} SEMICOLON {line_no++;}
		|	ident ASSIGNOP INTLITERAL {assign_int($1,$3);} SEMICOLON {line_no++;}
		|	ident ASSIGNOP REALLITERAL {assign_real($1,$3);} SEMICOLON {line_no++;}
		|	ident ASSIGNOP CHARACTER {assign_char($1,$3);} SEMICOLON {line_no++;}
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
          |	REALLITERAL {$$ = strdup(yylval.sval);}
		| {error("NUMERIC VALUE EXPECTED, BUT FOUND");}
		;
term	   : CHARACTER {$$=strdup($1);}
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
add_op    :	MULTIPLYOP {$$=strdup("Mul");}
		;
add_op    :	DIVIDEOP {$$=strdup("Div");}
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
