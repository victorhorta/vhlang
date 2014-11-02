#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vh_tipos.h"
#include "vh_parser.tab.h"

extern int yyerror(const char *msg);
FILE* output;

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
int ALL_LABELS = 0;
int ALL_VARIABLES_SIZE = -1;
int ALL_CONSTANTS_SIZE = -1;

void init_globais() {
	 variables = (char**)malloc(sizeof(char*) * MAX_VARS + 1); 
	 ALL_VARIABLES = (var_object*)malloc(sizeof(var_object) * MAX_VARS + 1);
	 ALL_CONSTANTS = (const_object*)malloc(sizeof(const_object) * MAX_CONSTS + 1);
	 output = fopen("teste.output", "w");
}


int const_append(const_object cnt) {
	 printf("const_append %s\n", get_type_name(cnt.my_type));

	 
	 if(ALL_CONSTANTS_SIZE >= MAX_VARS) {
	 	printf("Erro: nr maximo de constantes foi atingido\n");
	 	return -1;
	 }
	 	
	 // inserindo no final
	 ALL_CONSTANTS_SIZE++;

	 ALL_CONSTANTS[ALL_CONSTANTS_SIZE].index = ALL_CONSTANTS_SIZE;
	 printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> %d\n", ALL_CONSTANTS[ALL_CONSTANTS_SIZE].index);
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
	 switch(operador) {
	 	case PLUS_PLUS:
	 	case MINUS_MINUS:
	 		if(t1==V_INT || t1 == V_FLOAT)
	 			return t1;
	 		else
	 			return -1;
 		break;
	 	
	 	case IF:
	 		if(t1 == V_BOOLEAN)
	 			return t1;
	 		else
	 			return -1;
 		break;
	 	
	 	case EQUALS:
	 		if(t1==t2)
	 			return t1;
	 		else if(t1==V_FLOAT && t2==V_INT)
	 			return V_FLOAT;
	 		else
	 			return -1;
 		break;

		case NOT:
	 	case AND:
	 	case OR:
	 		if(t1==V_BOOLEAN && t2==V_BOOLEAN)
	 			return V_BOOLEAN;
	 		else
	 			return -1;
	 	break;
		
		case PLUS:
		case MINUS:
		case TIMES:
		case DIVIDE:
			if(t1==V_INT && t2==V_INT)
				return V_INT;
		    else if((t1==V_FLOAT && t2==V_FLOAT) ||
			        (t1==V_INT && t2==V_FLOAT)   ||
			        (t1==V_FLOAT && t2==V_INT)   )
				return V_FLOAT;
			else
	 			return -1;
		break;
		
		case LESS_THAN:
		case LESS_OR_EQUAL:
		case GREATER_THAN:
		case GREATER_OR_EQUAL:
			if( (t1==V_INT && t2==V_INT)     ||
			    (t1==V_FLOAT && t2==V_FLOAT) ||
			    (t1==V_INT && t2==V_FLOAT)   ||
			    (t1==V_FLOAT && t2==V_INT)   )
				return V_BOOLEAN;
			else
	 			return -1;
		break;
		
		case EQUAL_EQUAL:
		case NOT_EQUAL:
			if( (t1==V_INT && t2==V_INT)          ||
			    (t1==V_FLOAT && t2==V_FLOAT)      ||
			    (t1==V_INT && t2==V_FLOAT)        ||
			    (t1==V_FLOAT && t2==V_INT)        ||
			    (t1==V_CHAR && t2==V_CHAR)        ||
			    (t1==V_STRING && t2==V_STRING)    ||
			    (t1==V_BOOLEAN && t2==V_BOOLEAN)  )
				return V_BOOLEAN;
			else
	 			return -1;
		break;

		default:
			return -1;
		break;
	}
}

void debug_var(var_object v) {
	printf("--DEBUGVAR-----------\n");
	
	printf("> my_type:  %s\n", get_type_name(v.my_type));
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
	
	printf("> my_type:  %s\n", get_type_name(c.my_type));
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

const_object get_const_object(int index) {
	const_object temp;
	
	if(index > ALL_CONSTANTS_SIZE || index < 0) {
		yyerror("Erro: index errado / nao encontrado em get_const");
		return temp;
	}

	return ALL_CONSTANTS[index];
}

void copy_var_object(var_object* dest, var_object src) {
	(*dest).my_label = (char*)malloc(strlen(src.my_label) + 1);
	strcpy((*dest).my_label, src.my_label);
	(*dest).my_type = src.my_type;
	(*dest).index   = src.index;
	(*dest).value_i = src.value_i;
	(*dest).value_f = src.value_f;
	(*dest).value_c = src.value_c;
	(*dest).value_b = src.value_b;
	
	if(src.value_s != NULL) {
		(*dest).value_s = (char*)malloc(strlen(src.value_s) + 1);
		strcpy((*dest).value_s, src.value_s);	
	}
	return;
}

void copy_cnt_object(const_object* dest, const_object src) {
	(*dest).my_type = src.my_type;
	(*dest).index   = src.index;
	(*dest).value_i = src.value_i;
	(*dest).value_f = src.value_f;
	(*dest).value_c = src.value_c;
	(*dest).value_b = src.value_b;
	
	if(src.value_s != NULL) {
		(*dest).value_s = (char*)malloc(strlen(src.value_s) + 1);
		strcpy((*dest).value_s, src.value_s);
	}

	printf("ORIGEM:  %s\n", get_type_name(src.my_type));
	printf("DESTINO: %s\n", get_type_name((*dest).my_type));
	return;
}

char* get_type_name(v_type t) {
	switch(t){
		case V_INT:     return "INT"; break;
		case V_FLOAT:   return "FLOAT"; break;
		case V_CHAR:    return "CHAR"; break;
		case V_STRING:  return "STRING"; break;
		case V_BOOLEAN: return "BOOLEAN"; break;
		default:        return "????"; break;
	}
};


char* label_creator(int i) {
	//snprintf(label, 4, "%04d", ALL_LABELS);
	// int pos1, pos2, pos3;
	char* label = (char*)malloc(6*sizeof(char)+1);

	// pos1 = (i - i%100)/100;
	// pos3 = (i%10);
	// pos2 = (i - 100*pos1 - pos3)/10;

	// label[0] = 'L';
	// label[1] = (char)(((int)'0')+pos1);
	// label[2] = (char)(((int)'0')+pos2);
	// label[3] = (char)(((int)'0')+pos3);
	snprintf(label, 6, "\nL%d:", i);

	return label;
}

int give_me_a_label() {
	return ALL_LABELS++;
}

void generate_OP(int op) {
	output = fopen("teste.output", "a");
	char command[100];
	switch(op) {
		case NOT:         strncpy(command, "NOT", 100); break;
		case DUP:         strncpy(command, "DUP", 100); break;
		case NEG:         strncpy(command, "NEG", 100); break;
		
		case MINUS:       strncpy(command, "NEG", 100); break;
		case PLUS:        strncpy(command, "ADD", 100); break;
		case TIMES:       strncpy(command, "MUL", 100); break;
		case DIVIDE:      strncpy(command, "DIV", 100); break;

		case AND:              strncpy(command, "AND", 100); break;
		case OR:               strncpy(command, "OR", 100); break;
		case LESS_THAN:        strncpy(command, "LT", 100); break;
		case GREATER_THAN:     strncpy(command, "GT", 100); break;
		case LESS_OR_EQUAL:    strncpy(command, "LE", 100); break;
		case GREATER_OR_EQUAL: strncpy(command, "GE", 100); break;
		case EQUAL_EQUAL:      strncpy(command, "EQ", 100); break;
		case NOT_EQUAL:        strncpy(command, "NE", 100); break;
	}
	
	fprintf(output, "%s\n", command);
	fclose(output);
	return;
}

void generate_LOAD_CONST(int n, char* s) {
	output = fopen("teste.output", "a");
	fprintf(output, "LOAD_CONST\t%d\t(%s)\n", n, s);
	fclose(output);
	return;	
}

void generate_LOAD_VAR(int n, char* s) {
	output = fopen("teste.output", "a");
	fprintf(output, "LOAD_VAR\t%d\t(%s)\n", n, s);
	fclose(output);
	return;	
}

void generate_STORE_VAR(int n, char* s) {
	output = fopen("teste.output", "a");
	fprintf(output, "STORE_VAR\t%d\t(%s)\n", n, s);
	fclose(output);
	return;	
}

void generate_LOAD_REF(int n, char* label) {
	output = fopen("teste.output", "a");
	fprintf(output, "LOAD_REF\t%d\t(%s)\n", n, label);
	fclose(output);
	return;		
}

void generate_STORE_REF(int n, char* label) {
	output = fopen("teste.output", "a");
	fprintf(output, "STORE_REF\t%d\t(%s)\n", n, label);
	fclose(output);
	return;			
}

void generate_TJMP_FW(int n) {
	output = fopen("teste.output", "a");
	fprintf(output, "TJMP_FW\t\tL%d\n", n);
	fclose(output);
	return;				
}

void generate_JMP_FW(int n) {
	output = fopen("teste.output", "a");
	fprintf(output, "JMP_FW\t%d\n", n);
	fclose(output);
	return;
}

void generate_STRING_LF(char* s) {
	output = fopen("teste.output", "a");
	fprintf(output, "%s\n", s);
	fclose(output);
	return;
}