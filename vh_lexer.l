%{

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vh_tipos.h"
#include "vh_parser.tab.h"
extern YYSTYPE yylval;
extern int MODO_DEBUG;
int line_num = 1;
%}
 
%option noyywrap




L_IF                 "if"
L_ELSE               "else"
L_ENDIF              "endif"
L_WHILE              "while"
L_RETURN             "return"

L_CHAR               "char"
L_BOOLEAN            "boolean"
L_INTEGER            "int"
L_FLOAT              "float"
L_STRING             "string"
L_VAR                "var"

L_TRUE               "true"
L_FALSE              "false"

L_COLON              ":"
L_SEMI_COLON         ";"
L_COMMA              ","
L_EQUALS             "="

L_LEFTBRACES         "{"
L_RIGHTBRACES        "}"
L_LEFTPARENTHESIS    "("
L_RIGHTPARENTHESIS   ")"
L_AND                "&&"
L_OR                 "||"
L_LESS_THAN          "<"
L_GREATER_THAN       ">"
L_LESS_OR_EQUAL      "<="
L_GREATER_OR_EQUAL   ">="
L_NOT_EQUAL          "!="
L_EQUAL_EQUAL        "=="
L_PLUS               "+"
L_PLUS_PLUS          "++"
L_MINUS              "-"
L_MINUS_MINUS        "--"
L_TIMES              "*"
L_DIVIDE             "/"
L_NOT                "!"

L_CHARACTER         ['][^'][']
L_NUMERALFLOAT      [0-9]*[\.][0-9]+
L_NUMERALINT        [0-9]+
L_STRINGVAL         ["][[:alpha:]]*["]
L_ID                [a-zA-Z]+[a-zA-Z]*[0-9]*
L_WS                [ \r\t]*
L_LINEFEED          [\n]
 

%%


{L_LINEFEED}           { ++line_num; }
{L_WS}                 { /* Skip blanks. */ }

{L_IF}                 {if(MODO_DEBUG) printf("passou no %s\n", yytext); return IF;}
{L_ELSE}               {if(MODO_DEBUG) printf("passou no %s\n", yytext); return ELSE;}
{L_ENDIF}              {if(MODO_DEBUG) printf("passou no %s\n", yytext); return ENDIF;}
{L_WHILE}              {if(MODO_DEBUG) printf("passou no %s\n", yytext); return WHILE;}
{L_RETURN}             {if(MODO_DEBUG) printf("passou no %s\n", yytext); return RETURN;}


{L_CHAR}               {if(MODO_DEBUG) printf("passou no %s\n", yytext); yylval.vtype = V_CHAR; return CHAR;}
{L_BOOLEAN}            {if(MODO_DEBUG) printf("passou no %s\n", yytext); yylval.vtype = V_BOOLEAN; return BOOLEAN;}
{L_INTEGER}            {if(MODO_DEBUG) printf("passou no %s\n", yytext); yylval.vtype = V_INT; return INTEGER;}
{L_FLOAT}              {if(MODO_DEBUG) printf("passou no %s\n", yytext); yylval.vtype = V_FLOAT; return FLOAT;}
{L_STRING}             {if(MODO_DEBUG) printf("passou no %s\n", yytext); yylval.vtype = V_STRING; return STRING;}
{L_VAR}                {if(MODO_DEBUG) printf("passou no %s\n", yytext); return VAR;}

{L_TRUE}               {if(MODO_DEBUG) printf("passou no %s\n", yytext); return TRUE;}
{L_FALSE}              {if(MODO_DEBUG) printf("passou no %s\n", yytext); return FALSE;}

{L_COLON}              {if(MODO_DEBUG) printf("passou no %s\n", yytext); return COLON;}
{L_SEMI_COLON}         {if(MODO_DEBUG) printf("passou no %s\n", yytext); return SEMI_COLON;}
{L_COMMA}              {if(MODO_DEBUG) printf("passou no %s\n", yytext); return COMMA;}
{L_EQUALS}             {if(MODO_DEBUG) printf("passou no %s\n", yytext); return EQUALS;}

{L_LEFTBRACES}         {if(MODO_DEBUG) printf("passou no %s\n", yytext); return LEFT_BRACES;}
{L_RIGHTBRACES}        {if(MODO_DEBUG) printf("passou no %s\n", yytext); return RIGHT_BRACES;}
{L_LEFTPARENTHESIS}    {if(MODO_DEBUG) printf("passou no %s\n", yytext); return LEFT_PARENTHESIS;}
{L_RIGHTPARENTHESIS}   {if(MODO_DEBUG) printf("passou no %s\n", yytext); return RIGHT_PARENTHESIS;}
{L_AND}                {if(MODO_DEBUG) printf("passou no %s\n", yytext); return AND;}
{L_OR}                 {if(MODO_DEBUG) printf("passou no %s\n", yytext); return OR;}
{L_LESS_THAN}          {if(MODO_DEBUG) printf("passou no %s\n", yytext); return LESS_THAN;}
{L_GREATER_THAN}       {if(MODO_DEBUG) printf("passou no %s\n", yytext); return GREATER_THAN;}
{L_LESS_OR_EQUAL}      {if(MODO_DEBUG) printf("passou no %s\n", yytext); return LESS_OR_EQUAL;}
{L_GREATER_OR_EQUAL}   {if(MODO_DEBUG) printf("passou no %s\n", yytext); return GREATER_OR_EQUAL;}
{L_NOT_EQUAL}          {if(MODO_DEBUG) printf("passou no %s\n", yytext); return NOT_EQUAL;}
{L_EQUAL_EQUAL}        {if(MODO_DEBUG) printf("passou no %s\n", yytext); return EQUAL_EQUAL;}
{L_PLUS}               {if(MODO_DEBUG) printf("passou no %s\n", yytext); return PLUS;}
{L_PLUS_PLUS}          {if(MODO_DEBUG) printf("passou no %s\n", yytext); return PLUS_PLUS;}
{L_MINUS}              {if(MODO_DEBUG) printf("passou no %s\n", yytext); return MINUS;}
{L_MINUS_MINUS}        {if(MODO_DEBUG) printf("passou no %s\n", yytext); return MINUS_MINUS;}
{L_TIMES}              {if(MODO_DEBUG) printf("passou no %s\n", yytext); return TIMES;}
{L_DIVIDE}             {if(MODO_DEBUG) printf("passou no %s\n", yytext); return DIVIDE;}
{L_NOT}                {if(MODO_DEBUG) printf("passou no %s\n", yytext); return NOT;}

{L_CHARACTER}          {if(MODO_DEBUG) printf("passou no char %c\n", yytext[1]); yylval.character = yytext[1]; return CHARACTER;}
{L_NUMERALFLOAT}       {if(MODO_DEBUG) printf("passou no %s\n", yytext); sscanf(yytext, "%f", &yylval.numeralfloat); return NUMERALFLOAT;}
{L_NUMERALINT}         {if(MODO_DEBUG) printf("passou no %s\n", yytext); sscanf(yytext, "%d", &yylval.numeralint); return NUMERALINT;}
{L_STRINGVAL}          {if(MODO_DEBUG) printf("passou em STRINGVAL: %s\n", yytext); char* str_temp = yytext; str_temp++; str_temp[strlen(str_temp)-1] = 0; yylval.string = strdup(str_temp); return STRINGVAL;}
{L_ID}                 {if(MODO_DEBUG) printf("passou no ID: %s\n", yytext);  strcpy(yylval.id, yytext); return ID;}

%%

