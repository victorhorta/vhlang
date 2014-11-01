#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vh_tipos.h"
#include "vh_parser.tab.h"

extern int yyerror(const char *msg);

// Definindo os escalares
object int_ = { -1, NULL, SCALAR_TYPE_};
pobject pInt = &int_;

object char_ = { -1, NULL, SCALAR_TYPE_};
pobject pChar = &char_;

object boolean_ = { -1, NULL, SCALAR_TYPE_};
pobject pBoolean = &boolean_;

object string_ = { -1, NULL, SCALAR_TYPE_};
pobject pString = &string_;

object universal_ = { -1, NULL, SCALAR_TYPE_};
pobject pUniversal = &universal_;



/*

variaveis:
-tipo: 
-nome: 
-valor

*/

object new_object(char* label, pobject* type) {
   // if(object_linked_list.)
	object xxx;
	return xxx;
}



/*
 * Metodo que busca o indice (int) de uma id, retornando o valor dela.
 * Se nao houver a label, insere a label ao final da lista e retorna o
 * id da nova label criada.
 * return:
 *     -1, se excedeu o numero maximo de variaveis
 */

int last_value = -1;
char** variables;
var_object*  ALL_VARIABLES;
const_object* ALL_CONSTANTS;

int ALL_VARIABLES_SIZE = -1;
int ALL_CONSTANTS_SIZE = -1;

void init_globais() {
	 variables = (char**)malloc(sizeof(char*) * MAX_VARS + 1); 
	 ALL_VARIABLES = (var_object*)malloc(sizeof(var_object) * MAX_VARS + 1);
	 ALL_CONSTANTS = (const_object*)malloc(sizeof(const_object) * MAX_CONSTS + 1);
}


int const_append(const_object cnt) {
	 printf("const_append %d\n", cnt.my_type);

	 
	 if(ALL_CONSTANTS_SIZE >= MAX_VARS) {
	 	printf("Erro: nr maximo de constantes foi atingido\n");
	 	return -1;
	 }
	 	
	 // inserindo no final
	 ALL_CONSTANTS_SIZE++;

	 ALL_CONSTANTS[ALL_CONSTANTS_SIZE].index = ALL_CONSTANTS_SIZE;
	 ALL_CONSTANTS[ALL_CONSTANTS_SIZE].my_type = cnt.my_type;
	 ALL_CONSTANTS[ALL_CONSTANTS_SIZE].value_b = cnt.value_b;
	 ALL_CONSTANTS[ALL_CONSTANTS_SIZE].value_c = cnt.value_c;
	 ALL_CONSTANTS[ALL_CONSTANTS_SIZE].value_f = cnt.value_f;
	 ALL_CONSTANTS[ALL_CONSTANTS_SIZE].value_i = cnt.value_i;
	 
	 
	 if(cnt.value_s !=  NULL) {
	    ALL_CONSTANTS[ALL_CONSTANTS_SIZE].value_s = (char*)malloc(strlen(cnt.value_s) + 1);
	    strcpy(ALL_CONSTANTS[ALL_CONSTANTS_SIZE].value_s, cnt.value_s);
	 }

	 return ALL_CONSTANTS_SIZE;	
}


int var_scan(char* label) {
	 printf("var_scan %s\n", label);
	 int i;
	

	 for(i = 0; i <= ALL_VARIABLES_SIZE; i++) {
	 	if(!strcmp(ALL_VARIABLES[i].my_label, label)) {
	 		// eh igual
	 		return i;
	 	}
	 }

	 return -1;
}

int var_scan_or_append(struct var_object var) {
	 printf("var_scan_or_append %s\n", var.my_label);
	 int i;
	 
	 if(ALL_VARIABLES_SIZE >= MAX_VARS) {
	 	printf("Erro: nr maximo de variaveis foi atingido\n");
	 	return -1;
	 }
	 	

	 for(i = 0; i <= ALL_VARIABLES_SIZE; i++) {
	 	if(!strcmp(ALL_VARIABLES[i].my_label, var.my_label)) {
	 		// eh igual
	 		return i;
	 	}
	 }

	 // se chegou aqui, nao reconheceu! logo, tem que inserir no final
	 ALL_VARIABLES_SIZE++;
	 ALL_VARIABLES[ALL_VARIABLES_SIZE].my_label = (char*)malloc(strlen(var.my_label) + 1);
	 strcpy(ALL_VARIABLES[ALL_VARIABLES_SIZE].my_label, var.my_label);
	 
	 ALL_VARIABLES[ALL_VARIABLES_SIZE].index = ALL_VARIABLES_SIZE;
	 ALL_VARIABLES[ALL_VARIABLES_SIZE].my_type = var.my_type;
	 //ALL_VARIABLES[ALL_VARIABLES_SIZE].next = var.next;        // TODO: sera que realmente precisa? verificar.
	 ALL_VARIABLES[ALL_VARIABLES_SIZE].value_b = var.value_b;
	 ALL_VARIABLES[ALL_VARIABLES_SIZE].value_c = var.value_c;
	 ALL_VARIABLES[ALL_VARIABLES_SIZE].value_f = var.value_f;
	 ALL_VARIABLES[ALL_VARIABLES_SIZE].value_i = var.value_i;
	 

	 if(var.value_s !=  NULL) {
	   ALL_VARIABLES[ALL_VARIABLES_SIZE].value_s = (char*)malloc(strlen(var.value_s) + 1);
	   strcpy(ALL_VARIABLES[ALL_VARIABLES_SIZE].value_s, var.value_s);
	 }

	 return ALL_VARIABLES_SIZE;
}

int var_scan_or_append_old(char* label) {
	 printf("aeeee %s\n", label);
	 int i;
	 
	 if(last_value >= MAX_VARS) {
	 	printf("Errp: nr maximo de variaveis foi atingido\n");
	 	return -1;
	 }
	 	

	 for(i = 0; i <= last_value; i++) {
	 	if(!strcmp(variables[i], label)) {
	 		// eh igual
	 		return i;
	 	}
	 }

	 // se chegou aqui, nao reconheceu! logo, tem que inserir no final
	 last_value++;
	 variables[last_value] = (char*)malloc(strlen(label) + 1);
	 strcpy(variables[last_value], label);
	 return last_value;
}

/*
 * Seta o valor default na instanciacao de uma variavel.
 * Ex.: int inicializa com 0, boolean com TRUE, etc..
 */
void set_default_values(var_object* temp_id) {
	switch(temp_id->my_type) {
		case V_INT: temp_id->value_i = 0; break;
		case V_FLOAT: temp_id->value_f = 0.0; break;
		case V_CHAR: temp_id->value_c = 0x00; break;
		case V_BOOLEAN: temp_id->value_b = BOOLEANFALSE; break;
		case V_STRING: temp_id->value_s = NULL; break;
		default: printf("Erro: tipo bizarro atribuido!!"); break;
	}
	return;
}



/*
 * Faz a checagem de tipos, e indica o tipo de retorno da combinacao, ou 
 * devolve -1 caso a operacao seja ilegal.
 */
int check_types(v_type t1, int operador, v_type t2) {
	                // V_INT, FLOAT, CHAR, STRING, BOOLEAN
	// switch(operador) {
	// 	case AND:
	// 	case OR:
	// 	;
	// 	case LESS_THAN:
	// 	case LESS_OR_EQUAL:
	// 	case GREATER_THAN:
	// 	case GREATER_OR_EQUAL:
	// 	case EQUAL_EQUAL:
	// 	case NOT_EQUAL:
	// 	case PLUS:
	// 	case MINUS:
	// 	case TIMES:
	// 	case DIVIDE:
	// 	case PLUS_PLUS:
	// 	case MINUS_MINUS:
	// 	case NOT:

	// }
	// int v_int_compat[] = {V_INT, V_FLOAT, -1, -1, };


	// switch(t1) {
	// 	case V_INT: temp_id->value_i = 0; break;
	// 	case V_FLOAT: temp_id->value_f = 0.0; break;
	// 	case V_CHAR: temp_id->value_c = 0x00; break;
	// 	case V_BOOLEAN: temp_id->value_b = BOOLEANFALSE; break;
	// 	case V_STRING: temp_id->value_s = NULL; break;
	// 	default: printf("Erro: tipo bizarro na checagem!!"); break;
	// }
	return -1;
}

void debug_var(var_object v) {
	printf("--DEBUGVAR-----------\n");
	
	printf("> my_type:  %d\n", v.my_type);
	printf("> my_label: %s\n", v.my_label);
	printf("> index:    %d\n", v.index);
    printf("> value_i:  %d\n", v.value_i);
	printf("> value_f:  %f\n", v.value_f);
	printf("> value_c:  %c\n", v.value_c);
	printf("> value_s:  %s\n", v.value_s);
	printf("> value_b:  %d\n", v.value_b);
	
	printf("-------------\n");
	
	return;
}

void debug_cnt(const_object c) {
	printf("--DEBUGCNT-----------\n");
	
	printf("> my_type:  %d\n", c.my_type);
	printf("> index:    %d\n", c.index);
    printf("> value_i:  %d\n", c.value_i);
	printf("> value_f:  %f\n", c.value_f);
	printf("> value_c:  %c\n", c.value_c);
	printf("> value_s:  %s\n", c.value_s);
	printf("> value_b:  %d\n", c.value_b);
	
	printf("-------------\n");
	
	return;
}

var_object get_var_object(int index) {
	var_object temp;
	
	if(index > ALL_VARIABLES_SIZE || index < 0) {
		yyerror("Erro: index errado / nao encontrado em get_var");
		return temp;
	}

	return ALL_VARIABLES[index];
}

void copy_var_object(var_object* dest, var_object src) {
	(*dest).my_label = (char*)malloc(strlen(src.my_label) + 1);
	strcpy((*dest).my_label, src.my_label);
	(*dest).my_type = src.my_type;
	(*dest).index   = src.index;
	(*dest).value_i = src.value_i;
	(*dest).value_f = src.value_f;
	(*dest).value_c = src.value_c;
	(*dest).value_s = src.value_s;
	(*dest).value_b = src.value_b;
	return;
}