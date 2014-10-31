#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vh_tipos.h"




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
void init_globais() {
	 variables = (char**)malloc(sizeof(char*) * MAX_VARS + 1); 
}

int var_scan_or_append(char* label) {
	 printf("aeeee %s\n", label);
	 int i;
	 
	 if(last_value >= MAX_VARS)
	 	return -1;

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
		default: printf("Erro: tipo bizarro atribuido!!");
	}
	return;
}