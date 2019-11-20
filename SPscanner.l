%{
#include <iostream>
#include <stdlib.h>
#include "pascal.tab.h"
extern "C" int yylex();
int line_no = 1;
std::string dbg_ctrl(char *s) {
    std::string res = "";
    int len = strlen(s);
    for (int i=0; i<len; i++) {
        switch (s[i]) {
            case '\x7f': res += "^?"; break;
            case '\r': res += "\\r"; break;
            case '\n': res += "\\n"; break;
            case '\t': res += "\\t"; break;
            default: res += "^"; res += '@'|s[i]; break;
        }
    }
    return res;
}
std::string dbg_hex(char *s) {
    std::string res = "";
    char *tmp = new char[16]; // should look like 0xFF, so this should be plenty
    int len = strlen(s);
    for (int i=0; i<len; i++) {
        snprintf(tmp, 16, "%#X", (unsigned char) s[i]);
        res += tmp;
    }
    return res;
}
std::string dbg_unicode(char *s) {
    unsigned long res = 0xdeadbeef;
    int len = strlen(s);
    if (len==2) {
        res = (unsigned char) s[0] & ~0xc0;
        res = res<<6;
        res += (unsigned char) s[1] & ~0x80;
    }
    else if (len==3) {
        res = (unsigned char) s[0] & ~0xe0;
        res = res<<6;
        res += (unsigned char) s[1] & ~0x80;
        res = res<<6;
        res += (unsigned char) s[2] & ~0x80;
    }
    else if (len==4) {
        res = (unsigned char) s[0] & ~0xf0;
        res = res<<6;
        res += (unsigned char) s[1] & ~0x80;
        res = res<<6;
        res += (unsigned char) s[2] & ~0x80;
        res = res<<6;
        res += (unsigned char) s[3] & ~0x80;
    }
    char *tmp = new char[32];
    snprintf(tmp, 32, "%lX", res);
    return "U+"+std::string(tmp);
}
void error( const char msg[] )
{
	std::cout << "LINE " << line_no << " : " << msg << std::endl;
	exit( -1 );
}
void error(const std::string msg) {
    error(msg.c_str());
}
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
intliteral      (0|([1-9]{digit}*))
realliteral      (0|([1-9]{digit}*))[\.]{digit}+
boolliteral     ([Tt][Rr][Uu][Ee]|[Ff][Aa][Ll][Ss][Ee])
strliteral      ["][^"]*["]
id              ({letter}|{underscore})({letter}|{digit}|{underscore})*
   // see https://stackoverflow.com/questions/9611682/flexlexer-support-for-unicode
PRINTABLE   [\x20-\x7E]
ASCII_CTRL  [\x00-\x1F\x7F]
ASCII       [\x00-\x7F]
UTF8_2     [\xC0-\xDF][\x80-\xBF]
UTF8_3     [\xE0-\xEF][\x80-\xBF][\x80-\xBF]
UTF8_4     [\xF0-\xF7][\x80-\xBF][\x80-\xBF][\x80-\xBF]
UTF8        ({UTF8_2}|{UTF8_3}|{UTF8_4})
   // see http://dinosaur.compilertools.net/flex/flex_11.html about lex start conditions
%s PASCAL
%x COMMENT MULTICOMMENT
%%
^[/][/]                                         {BEGIN COMMENT;}
<COMMENT>[\n]                                   {line_no++; BEGIN PASCAL;}
<COMMENT>.                                      {/* ignore comment */}
[{]                                             {BEGIN MULTICOMMENT;}
<MULTICOMMENT>[}]                               {BEGIN PASCAL;}
<MULTICOMMENT>.                                 {/* ignore comment */}
<MULTICOMMENT>[\n]                              {line_no++; /* ignore comment */}
[ \t]+                                          {/* do nothing */}
[\r]                                            {/* ignore CR */}
[\n]                                            {line_no++; /* new line*/}
[Pp][Rr][Oo][Gg][Rr][Aa][Mm]			        {return PROGRAM;}
[Vv][Aa][Rr]					                {return VAR;}
[Ii][Nn][Tt][Ee][Gg][Ee][Rr]			        {return INTTYPE;}
[Rr][Ee][Aa][Ll]                                {return REALTYPE;}
[Cc][Hh][Aa][Rr][Aa][Cc][Tt][Ee][Rr]            {return CHARTYPE;}
[Bb][Oo][Oo][Ll][Ee][Aa][Nn]                    {return BOOLTYPE;}
[Ss][Tt][Rr][Ii][Nn][Gg]                        {return STRTYPE;}
[Bb][Ee][Gg][Ii][Nn]                            {return START;}
[Ee][Nn][Dd]                                    {return END;}
[Rr][Ee][Aa][Dd]                                {return READ;}
[Ww][Rr][Ii][Tt][Ee]                            {return WRITE;}
[Ii][Ff]					{return IF;}
[Tt][Hh][Ee][Nn]				{return THEN;}
[Ee][Ll][Ss][Ee]				{return ELSE;}
[Ww][Hh][Ii][Ll][Ee]                            {return WHILE;}
[Dd][Oo]                                        {return DO;}
[Rr][Ee][Pp][Ee][Aa][Tt]                        {return REPEAT;}
[Uu][Nn][Tt][Ii][Ll]                            {return UNTIL;}
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
[%]                                             {return MODOP;}
[Aa][Nn][Dd]                                    {return ANDOP;}
[Oo][Rr]                                        {return OROP;}
[Nn][Oo][Tt]                                    {return NOTOP;}
[=]                                             {return EQOP;}
[<][>]                                          {return NEQOP;}
[<]                                             {return LTOP;}
[>]                                             {return GTOP;}
[<][=]                                          {return LEQOP;}
[>][=]                                          {return GEQOP;}
{character}                                     {yylval.sval = strdup(yytext); return CHARACTER;}
{intliteral}                                    {yylval.sval = strdup(yytext); return INTLITERAL;}
{realliteral}                                   {yylval.sval = strdup(yytext); return REALLITERAL;}
{boolliteral}                                   {yylval.sval = strdup(yytext); return BOOLLITERAL;}
{strliteral}                                   {yylval.sval = strdup(yytext); return STRLITERAL;}
{id}                                            {yylval.sval = strdup(yytext); return ID;}

{PRINTABLE}                                     {error("illegal character: '"+std::string(yytext)+"'");}
{ASCII_CTRL}                                    {error("illegal ASCII control character: '"+dbg_ctrl(yytext)+"' ("+dbg_hex(yytext)+")");}
{UTF8}                                          {error("illegal UTF-8 character: '"+std::string(yytext)+"' ("+dbg_unicode(yytext)+")");}
.                                               {error("illegal byte: ("+dbg_hex(yytext)+")");}
%%
