%{

#include "vh_parser.tab.h"
#include "vh_tipos.h"
#include <stdio.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_num;
int MODO_DEBUG = 1;

int yyerror(const char *msg) {
    printf("BARRO::: linha: %d -- mensagem: %s\n", line_num, msg);
    return 0;
}
 
%}
 


%union {
    int numeralint;
    float numeralfloat;
    int boolean;
    char character;
    char id[50];
    char* string;
}
 


%token IF
%right ELSE
%token ENDIF

%token TYPE

%left EQUALS
%left AND
%left OR
%left LESS_THAN
%left GREATER_THAN
%left LESS_OR_EQUAL
%left GREATER_OR_EQUAL
%left NOT_EQUAL
%left EQUAL_EQUAL
%left PLUS
%left MINUS
%left TIMES
%left DIVIDE
%left NOT
%left PLUS_PLUS
%left MINUS_MINUS


%token BOOLEAN
%token CHAR
%token DO




%token INTEGER
%token STRING
%token FLOAT
%token <boolean> TRUE
%token <boolean> FALSE

%token VAR
%token WHILE
%token <string> STRINGVAL
%token <id> ID

%token COLON
%token SEMI_COLON
%token COMMA
%token LEFT_SQUARE
%token RIGHT_SQUARE
%token LEFT_BRACES
%token RIGHT_BRACES
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS


%token <character> CHARACTER
%token <numeralfloat> NUMERALFLOAT
%token <numeralint> NUMERALINT

%type <t_nonterm>  
P
LDE
DE
DV
B
T
LS
LI
S
E
R
NUM
IDD
IDU

%%
P:      LDE
;

LDE:    LDE  DE
      | DE
;

DE:     DV
      | B
;

DV:     VAR LI COLON T SEMI_COLON
;

B:      LEFT_BRACES LS RIGHT_BRACES
;


T:      INTEGER
      | FLOAT
      | CHAR
      | BOOLEAN
      | STRING
;



LS:     LS S 
      | S
;


LI:     LI COMMA IDD
      | IDD
;

S:      IF LEFT_PARENTHESIS E RIGHT_PARENTHESIS S ENDIF
      | IF LEFT_PARENTHESIS E RIGHT_PARENTHESIS S ELSE S ENDIF
      | IDU EQUALS E SEMI_COLON
      | B
      | E SEMI_COLON
;

E:      E AND R
      | E OR R
      | E LESS_THAN R
      | E GREATER_THAN R
      | E LESS_OR_EQUAL R
      | E GREATER_OR_EQUAL R
      | E EQUAL_EQUAL R
      | E NOT_EQUAL R
      | E PLUS R
      | E MINUS R
      | E TIMES R
      | E DIVIDE R
      | E EQUALS R
      | R
;

R:      PLUS_PLUS R
      | R PLUS_PLUS
      | MINUS_MINUS R
      | R MINUS_MINUS
      | MINUS R
      | NOT R
      | TRUE
      | FALSE
      | CHARACTER
      | STRINGVAL
      | NUM
;


NUM:    NUMERALFLOAT
      | NUMERALINT
;

IDD:    ID
;

IDU:    ID
;


%%

int main() {
  FILE *myfile = fopen("teste.file", "r");

  if(!myfile) {
    printf("Erro abrindo arquivo\n");
    return -1;
  }

  if(MODO_DEBUG)
    printf("MODO_DEBUG ativado!\n-----------------\n");

  yyin = myfile;
  do {
    yyparse();
  } while(!feof(yyin));
  
  printf("---------------\nFIM DO PROGRAMA\n");
}