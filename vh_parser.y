%{
#include <stdio.h>

#include "vh_tipos.h"



extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_num;
int MODO_DEBUG = 1;

int yyerror(const char *msg) {
    printf("BARRO::: linha: %d -- mensagem: %s\n", line_num, msg);
    return 0;
}

extern void init_globais();
%}
 


%union {
    int numeralint;
    float numeralfloat;
    int boolean;
    char character;
    char id[MAX_VAR_LENGTH];
    char* string;
    t_nonterm nonterm;
    v_type vtype;
}
 


%token IF
%right ELSE
%token ENDIF

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






%token <vtype> INTEGER
%token <vtype> STRING
%token <vtype> FLOAT
%token <vtype> BOOLEAN
%token <vtype> CHAR

%token VAR


%token COLON
%token SEMI_COLON
%token COMMA
%token LEFT_BRACES
%token RIGHT_BRACES
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS

%token <id> ID

%token <string> STRINGVAL
%token <boolean> TRUE
%token <boolean> FALSE
%token <character> CHARACTER
%token <numeralfloat> NUMERALFLOAT
%token <numeralint> NUMERALINT

%type <nonterm> P LDE DE DV B T LS LI S E R NUM IDD IDU

%%
P:      LDE
;

LDE:    LDE  DE
      | DE
;

DE:     DV
      | B
;

DV:     VAR LI COLON T SEMI_COLON {
                                    // Primeiro, vamos recuperar o tipo que foi definido
                                    v_type defined_type = $4._.T.type;
                                    
                                    // Vamos agora iterar sobre todas as variaveis declaradas em LI
                                    var_object* temp_id = $2._.LI.ids_list;
                                    temp_id->next = $2._.LI.ids_list->next;
                                    while(temp_id != NULL) {
                                      // Setando o tipo e valores default
                                      temp_id->my_type = defined_type;
                                      set_default_values(temp_id);

                                      // Inserindo as variaveis em nosso array de variaveis e retornando o indice de cada uma delas
                                      temp_id->index = var_scan_or_append(*temp_id);
                                      
                                      debug_var(*temp_id);

                                      temp_id = temp_id->next;
                                    }
                                    
                                    // Guardando referencia para o inicio da lista
                                    $$._.DV.ids_list = (var_object*)malloc(sizeof(var_object));
                                    $$._.DV.ids_list = $2._.LI.ids_list;
                                  }
;

B:      LEFT_BRACES LS RIGHT_BRACES
;


T:      INTEGER    { $$._.T.type = $1; printf("meu tipo: %d\n", $$._.T.type);}
      | FLOAT      { $$._.T.type = $1; printf("meu tipo: %d\n", $$._.T.type);}
      | CHAR       { $$._.T.type = $1; printf("meu tipo: %d\n", $$._.T.type);}
      | BOOLEAN    { $$._.T.type = $1; printf("meu tipo: %d\n", $$._.T.type);}
      | STRING     { $$._.T.type = $1; printf("meu tipo: %d\n", $$._.T.type);}
;



LS:     LS S 
      | S
;


LI:     LI COMMA IDD {
                       $3._.IDD.my_ID.next = (var_object*)malloc(sizeof(var_object));
                       $3._.IDD.my_ID.next = $1._.LI.ids_list;

                       $1._.LI.ids_list = &$3._.IDD.my_ID;

                       $$._.LI.ids_list = (var_object*)malloc(sizeof(var_object));
                       $$._.LI.ids_list = &$1._.IDD.my_ID;
                     }

      | IDD          {
                       $$._.LI.ids_list = (var_object*)malloc(sizeof(var_object));
                       $$._.LI.ids_list = &$1._.IDD.my_ID;
                       
                       if(MODO_DEBUG)
                         printf("my_label: %s\n", $$._.LI.ids_list->my_label);
                     }
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
      | R
;

R:      PLUS_PLUS R
      | MINUS_MINUS R
      | MINUS R
      | NOT R
      | TRUE            {
                          $$._.R.is_var = 0;
                          $$._.R.cnt.my_type = V_BOOLEAN;
                          $$._.R.cnt.value_b = BOOLEANTRUE;
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                        }
      | FALSE           {
                          $$._.R.is_var = 0;
                          $$._.R.cnt.my_type = V_BOOLEAN;
                          $$._.R.cnt.value_b = BOOLEANFALSE;
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                        }
      | CHARACTER       {
                          $$._.R.is_var = 0;
                          $$._.R.cnt.my_type = V_CHAR;
                          $$._.R.cnt.value_c = $1;
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                        }
      | STRINGVAL       {
                          printf("string que veio: %s\n", $1);
                          $$._.R.is_var = 0;
                          $$._.R.cnt.my_type = V_STRING;
                          $$._.R.cnt.value_s = (char*)malloc(strlen($1) + 1);
                          strcpy($$._.R.cnt.value_s, $1);
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                        }
      | NUM             {
                          $$._.R.is_var = 0;
                          $$._.R.cnt = $$._.NUM.my_const;
                        }
      | IDU             {
                          $$._.R.is_var = 1;
                          //TODO: deep copy (maybe using the copy_var_object...)
                          //$$._.R.var = $1._.IDU.my_ID;
                        }
;


NUM:    NUMERALFLOAT {
                       $$._.NUM.my_const.my_type = V_FLOAT;
                       $$._.NUM.my_const.value_f = $1;
                     }
      | NUMERALINT   {
                       $$._.NUM.my_const.my_type = V_INT;
                       $$._.NUM.my_const.value_i = $1;
                     }
;

IDD:    ID    {
                $$._.IDD.my_ID.my_label = (char*)malloc(sizeof(char) * MAX_VAR_LENGTH + 1);
                $$._.IDD.my_ID.next = NULL;
                strcpy($$._.IDD.my_ID.my_label, $1);
                //if(MODO_DEBUG)
                //  printf("labelwwww: %d\n", strlen($1));
              }
;

IDU:    ID {
             $$._.IDU.my_label = (char*)malloc(sizeof(char) * MAX_VAR_LENGTH + 1);
             strcpy($$._.IDU.my_label, $1);
             $$._.IDU.index = var_scan($$._.IDU.my_label);
             if($$._.IDU.index < 0)
               yyerror("Identificador nao encontrado!");
           }
;


%%

int main() {
  // Inicializando variaveis globais!!!
  init_globais();

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