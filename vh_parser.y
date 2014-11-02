%{
#include <stdio.h>
#include <stdlib.h>

#include "vh_tipos.h"



extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *output;
extern int line_num;
int MODO_DEBUG = 1;

int yyerror(const char *msg) {
    printf("BARRO::: linha: %d -- mensagem: %s\n", line_num, msg);
    return 0;
}

int yyerror_type(v_type t1, v_type t2) {
    printf("BARRO::: linha: %d -- mensagem: ", line_num);
    printf("Type error ao atribuir tipo %s a variavel tipo %s!\n", get_type_name(t2), get_type_name(t1));
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
 

%token DUP

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

%type <nonterm> P LDE DE DV B T LS LI S E R NUM IDD IDU MTHEN MELSE

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

S:      IF LEFT_PARENTHESIS E RIGHT_PARENTHESIS MTHEN S ENDIF {
                                                                if(check_types($3._.E.my_type, IF, 0) == -1) {
                                                                  yyerror("Condicao do IF nao eh um boolean");
                                                                } else {
                                                                  generate_STRING_LF(label_creator($5._.MTHEN.label_index));
                                                                }
                                                              }
      | IF LEFT_PARENTHESIS E RIGHT_PARENTHESIS MTHEN S ELSE MELSE S ENDIF {
                                                                             if(check_types($3._.E.my_type, IF, 0) == -1) {
                                                                               yyerror("Condicao do IF nao eh um boolean");
                                                                             } else {
                                                                               generate_STRING_LF(label_creator($8._.MELSE.label_index));
                                                                             }
                                                                           }
      | IDU MASSIGN EQUALS E SEMI_COLON {
                                          int result_type = check_types(get_var_object($1._.IDU.index).my_type, EQUALS, $4._.E.my_type);
                                          if(result_type == -1) {
                                            yyerror_type($4._.E.my_type, get_var_object($1._.IDU.index).my_type);
                                          } else {
                                            printf("OK -- %s = %s\n",  get_type_name($4._.E.my_type), get_type_name(get_var_object($1._.IDU.index).my_type)); 
                                          }
                                          generate_STORE_REF($1._.IDU.index, $1._.IDU.my_label);
                                        }
      | B
      | E SEMI_COLON
;

MASSIGN: {generate_OP(DUP);}

MTHEN: {
         $$._.MTHEN.label_index = give_me_a_label();
         generate_TJMP_FW($$._.MTHEN.label_index);
       }
;
MELSE: {
         $$._.MELSE.label_index = give_me_a_label();
         generate_JMP_FW($$._.MELSE.label_index);
         generate_STRING_LF(label_creator($$._.MELSE.label_index - 1));
       }
;

E:      E AND R                 {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, AND, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(AND);
                                  }
                                }
      | E OR R                 {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, OR, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(OR);
                                  }
                                }
      | E LESS_THAN R           {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, LESS_THAN, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(LESS_THAN);
                                  }
                                }
      | E GREATER_THAN R        {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, GREATER_THAN, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(GREATER_THAN);
                                  }
                                }
      | E LESS_OR_EQUAL R       {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, LESS_OR_EQUAL, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(LESS_OR_EQUAL);
                                  }
                                }
      | E GREATER_OR_EQUAL R    {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, GREATER_OR_EQUAL, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(GREATER_OR_EQUAL);
                                  }
                                }
      | E EQUAL_EQUAL R         {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, EQUAL_EQUAL, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(EQUAL_EQUAL);
                                  }
                                }
      | E NOT_EQUAL R           {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, NOT_EQUAL, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(NOT_EQUAL);
                                  }
                                }
      | E PLUS R                {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, PLUS, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(PLUS);
                                  }
                                }
      | E MINUS R               {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, MINUS, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(MINUS);
                                  }
                                }
      | E TIMES R               {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, TIMES, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(TIMES);
                                  }
                                }
      | E DIVIDE R              {
                                  $$._.E.is_var = 0;
                                  v_type t1 = $1._.E.my_type;
                                  v_type t2 = ($3._.R.is_var == 1 ? $3._.R.var.my_type : $3._.R.cnt.my_type);
                                  
                                  int r_type = check_types(t1, DIVIDE, t2);
                                  if(r_type == -1)
                                      yyerror("Type error!");
                                  else {
                                    $$._.E.my_type = r_type;
                                    generate_OP(DIVIDE);
                                  }
                                }
      | R                       {
                                  $$._.E.is_var = $1._.R.is_var;
                                  $$._.E.index   = ($1._.R.is_var == 1 ? $1._.R.var.index : $1._.R.cnt.index);
                                  $$._.E.my_type = ($1._.R.is_var == 1 ? $1._.R.var.my_type : $1._.R.cnt.my_type);
                                  //TODO: jogar E no topo da pilha
                                }
;

R:      PLUS_PLUS R     {
                          v_type t1 = ($2._.R.is_var == 1 ? $2._.R.var.my_type : $2._.R.cnt.my_type);
                          int r_type = check_types(t1, PLUS_PLUS, t1);
                          if(r_type == -1)
                              yyerror("Type error!");
                          else {
                            if($2._.R.is_var == 1) {
                                copy_var_object(&$$._.R.var, $2._.R.var);
                                $$._.R.var.my_type = check_types(t1, NOT, t1);
                              } else {
                                copy_cnt_object(&$$._.R.cnt, $2._.R.cnt);
                                $$._.R.cnt.my_type = check_types(t1, NOT, t1);
                              }
                          }
                          //TODO: fprintf comando
                        }   
      | MINUS_MINUS R   {
                          v_type t1 = ($2._.R.is_var == 1 ? $2._.R.var.my_type : $2._.R.cnt.my_type);
                          int r_type = check_types(t1, MINUS_MINUS, t1);
                          if(r_type == -1)
                              yyerror("Type error!");
                          else {
                            if($2._.R.is_var == 1) {
                                copy_var_object(&$$._.R.var, $2._.R.var);
                                $$._.R.var.my_type = check_types(t1, NOT, t1);
                              } else {
                                copy_cnt_object(&$$._.R.cnt, $2._.R.cnt);
                                $$._.R.cnt.my_type = check_types(t1, NOT, t1);
                              }
                          }
                          //TODO: fprintf comando
                        }   
      | MINUS R         {
                          v_type t1 = ($2._.R.is_var == 1 ? $2._.R.var.my_type : $2._.R.cnt.my_type);
                          int r_type = check_types(t1, MINUS, t1);
                          if(r_type == -1)
                              yyerror("Type error!");
                          else {
                            if($2._.R.is_var == 1) {
                                copy_var_object(&$$._.R.var, $2._.R.var);
                                $$._.R.var.my_type = check_types(t1, NOT, t1);
                              } else {
                                copy_cnt_object(&$$._.R.cnt, $2._.R.cnt);
                                $$._.R.cnt.my_type = check_types(t1, NOT, t1);
                              }
                          }
                          //TODO: fprintf comando
                        }   
      | NOT R           {
                          // checking type
                          v_type t1 = ($2._.R.is_var == 1 ? $2._.R.var.my_type : $2._.R.cnt.my_type);
                          int r_type = check_types(t1, NOT, t1);
                          if(r_type == -1)
                              yyerror("Type error!");
                          else {
                            if($2._.R.is_var == 1) {
                                copy_var_object(&$$._.R.var, $2._.R.var);
                                $$._.R.var.my_type = check_types(t1, NOT, t1);
                              } else {
                                copy_cnt_object(&$$._.R.cnt, $2._.R.cnt);
                                $$._.R.cnt.my_type = check_types(t1, NOT, t1);
                              }
                          }
                          generate_OP(NOT);
                        }   
      | TRUE            {
                          $$._.R.is_var = 0;
                          $$._.R.cnt.my_type = V_BOOLEAN;
                          $$._.R.cnt.value_b = BOOLEANTRUE;
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                          generate_LOAD_CONST($$._.R.cnt.index, "TRUE");
                        }
      | FALSE           {
                          $$._.R.is_var = 0;
                          $$._.R.cnt.my_type = V_BOOLEAN;
                          $$._.R.cnt.value_b = BOOLEANFALSE;
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                          generate_LOAD_CONST($$._.R.cnt.index, "FALSE");
                        }
      | CHARACTER       {
                          $$._.R.is_var = 0;
                          $$._.R.cnt.my_type = V_CHAR;
                          $$._.R.cnt.value_c = $1;
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                          
                          char* buffer = (char*)malloc(4*sizeof(char)+1);
                          snprintf(buffer, 4, "'%c'", $$._.R.cnt.value_c);
                          generate_LOAD_CONST($$._.R.cnt.index, buffer);
                        }
      | STRINGVAL       {
                          printf("string que veio: %s\n", $1);
                          $$._.R.is_var = 0;
                          $$._.R.cnt.my_type = V_STRING;
                          $$._.R.cnt.value_s = (char*)malloc(strlen($1) + 1);
                          strcpy($$._.R.cnt.value_s, $1);
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                          generate_LOAD_CONST($$._.R.cnt.index, $$._.R.cnt.value_s);
                        }
      | NUM             {
                          $$._.R.is_var = 0;
                          copy_cnt_object(&$$._.R.cnt, $1._.NUM.my_const);
                          $$._.R.cnt.index = const_append($$._.R.cnt);
                          debug_cnt($$._.R.cnt);
                          char* buffer = (char*)malloc(30 * sizeof(char) +1);
                          if($$._.R.cnt.my_type == V_FLOAT)
                            snprintf(buffer,50,"%f",$$._.R.cnt.value_f);
                          else 
                            snprintf(buffer,50,"%d",$$._.R.cnt.value_i);
                          
                          generate_LOAD_CONST($$._.R.cnt.index, buffer);
                        }
      | IDU             {
                          $$._.R.is_var = 1;
                          copy_var_object(&$$._.R.var, get_var_object($1._.IDU.index));
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
              }
;

IDU:    ID {
             $$._.IDU.my_label = (char*)malloc(sizeof(char) * MAX_VAR_LENGTH + 1);
             strcpy($$._.IDU.my_label, $1);
             $$._.IDU.index = var_scan($$._.IDU.my_label);
             if($$._.IDU.index < 0)
               yyerror("Identificador nao encontrado!");

             generate_LOAD_REF($$._.IDU.index, $$._.IDU.my_label);
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