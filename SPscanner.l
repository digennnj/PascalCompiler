%{
#include <iostream>
#include <stdlib.h>
#include "pascal.tab.h"
extern "C" int yylex();
%}
character ['][a-zA-Z0-9][']
letter  [a-zA-Z]
digit   [0-9]
semicolon	[;]
colon		[:]
underscore	[_]
lparen		[(]
rparen		[)]
comma           [,]
squote      [']
period		[\.]
assignop        [:][=]
plusop		[+]
minusop  	[-]
multiplyop  [*]
divideop    [/]
sngllncomment           [/][/]
mutlilncommentopen      [{]
mutlilncommentclose     [}]
intliteral      (0|([1-9]{digit}*))
realliteral      (0|([1-9]{digit}*))[\.]{digit}+
id              ({letter}|{underscore})({letter}|{digit}|{underscore})*
%%
[ \t]+                                          {/* do nothing */}
[\n]                                            {/* new line*/}
[Pp][Rr][Oo][Gg][Rr][Aa][Mm]			        {return PROGRAM;}
[Vv][Aa][Rr]					                {return VAR;}
[Ii][Nn][Tt][Ee][Gg][Ee][Rr]			        {return INTTYPE;}
[Rr][Ee][Aa][Ll]                                {return REALTYPE;}
[Cc][Hh][Aa][Rr][Aa][Cc][Tt][Ee][Rr]            {return CHARTYPE;}
[Bb][Ee][Gg][Ii][Nn]                            {return START;}
[Ee][Nn][Dd]                                    {return END;}
[Rr][Ee][Aa][Dd]                                {return READ;}
[Ww][Rr][Ii][Tt][Ee]                            {return WRITE;}
[Mm][Oo][Dd]                                    {return MODOP;}
{comma}                                         {return COMMA;}
{squote}                                        {return SQUOTE;}
{period}					                    {return PERIOD;}
{semicolon}                                     {return SEMICOLON;}
{colon}						                    {return COLON;}
{lparen}                                        {return LPAREN;}
{rparen}                                        {return RPAREN;}
{assignop}                                      {return ASSIGNOP;}
{plusop}                                        {return PLUSOP;}
{minusop}                                       {return MINUSOP;}
{multiplyop}                                    {return MULTIPLYOP;}
{divideop}                                      {return DIVIDEOP;}
{sngllncomment}                                 {return SNGLLNCOMMENT;}
{mutlilncommentopen}                            {return MULTILNCOMMENTOPEN;}
{mutlilncommentclose}                           {return MULTILNCOMMENTCLOSE;}
{character}                                     {yylval.sval = strdup(yytext); return CHARACTER;}
{intliteral}                                    {yylval.sval = strdup(yytext); return INTLITERAL;}
{realliteral}                                   {yylval.sval = strdup(yytext); return REALLITERAL;}
{id}                                            {yylval.sval = strdup(yytext); return ID;}

[^,]		{std::cout << "SYNTAX ERROR: " << yytext << " IS ILLEGAL" << std::endl;}
%%

