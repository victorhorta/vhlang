#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_TIPOS
#define MAX_CONSTS 30
#define MAX_VARS 30
#define MAX_VAR_LENGTH 20
#define MAX_LABELS 999

#define BOOLEANTRUE 1
#define BOOLEANFALSE 0

typedef enum {
	NO_KIND_DEF = -1,
	VAR_,
	SCALAR_TYPE_,
	UNIVERSAL_
} t_kind;

typedef enum {
	V_INT = 1,
	V_FLOAT,
	V_CHAR,
	V_STRING,
	V_BOOLEAN
} v_type;

/*
 * A ser usado como definicao de uma variavel.
 */
typedef struct var_object {
	v_type my_type;
	char*  my_label;
	int    index;
	int    value_i;
	float  value_f;
	char   value_c;
	char*  value_s;
	int    value_b;
	struct var_object* next;
} var_object;


/*
 * A ser usado como definicao de uma constante.
 */
typedef struct const_object {
	v_type my_type;
	int index;
	int    value_i;
	float  value_f;
	char   value_c;
	char*  value_s;
	int    value_b;
} const_object;


typedef struct t_nonterm{
	union {
		struct 	{
			char* name;
		} P;

		struct 	{
			char* my_label;
			int index;
		} IDU;
		
		struct 	{
		  struct var_object my_ID;
		} IDD;

		struct 	{
			v_type type;
		} T;

				
		struct 	{
			struct const_object my_const;
		} NUM;
		
		struct 	{
			int is_var;
			var_object var;
			const_object cnt;
		} R;
		
		struct 	{
			int is_var;	
			int index;
			v_type my_type;
			struct t_nonterm* next;
		} E;
		
		struct 	{
		} S;
		
		struct  {
		  struct var_object* ids_list;
		} LI;
		
		struct 	{
		} LS;
		
		
		
		struct 	{
		} B;
		
		struct 	{
			struct var_object* ids_list;
		} DV;  // declaracao de variavel
		
		struct 	{
		} DE;
		
		struct 	{
		} LDE;
	}_;
} t_nonterm;



typedef struct object {
	int nName;
	struct object * pNext;
	t_kind eKind;

    union {
    	struct {
    		struct object *pType;
    	} Var;
    }_;
} object, *pobject;

// Definindo os escalares
// object int_ = { -1, NULL, SCALAR_TYPE_};
// pobject pInt = &int_;

// object char_ = { -1, NULL, SCALAR_TYPE_};
// pobject pChar = &char_;

// object boolean_ = { -1, NULL, SCALAR_TYPE_};
// pobject pBoolean = &boolean_;

// object string_ = { -1, NULL, SCALAR_TYPE_};
// pobject pString = &string_;

// object universal_ = { -1, NULL, SCALAR_TYPE_};
// pobject pUniversal = &universal_;



/*

variaveis:
-tipo: 
-nome: 
-valor

*/
//static object object_linked_list;

object new_object(char* label, pobject* type);



/*
 * Metodo que busca o indice (int) de uma id, retornando o valor dela.
 * Se nao houver a label, insere a label ao final da lista e retorna o
 * id da nova label criada.
 * return:
 *     -1, se excedeu o numero maximo de variaveis
 */

// int last_value = -1;
// char** variables;
void init_globais();

int var_scan(char* label);
int var_scan_or_append(var_object var);
int var_scan_or_append_old(char* label);

int const_append(const_object cnt);

/*
 * Seta o valor default na instanciacao de uma variavel.
 * Ex.: int inicializa com 0, boolean com TRUE, etc..
 */
void set_default_values(var_object* temp_id);

/*
 * Faz a checagem de tipos, e indica o tipo de retorno da combinacao, ou 
 * devolve -1 caso a operacao seja ilegal.
 */
int check_types(v_type t1, int operador, v_type t2);
int check_R_type(t_nonterm R, int operador);

var_object get_var_object(int index);
void copy_var_object(var_object* dest, var_object src);
void copy_cnt_object(const_object* dest, const_object src);

char* get_type_name(v_type t);

void debug_var(var_object v);
void debug_cnt(const_object v);
char* give_me_a_label();

void generate_OP(int op);
void generate_LOAD_CONST(int n, char* s);
void generate_STORE_REF(int n, char* label);
void generate_LOAD_REF(int n, char* label);