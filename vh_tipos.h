#define NULL 0

typedef enum {
	NO_KIND_DEF = -1,
	VAR_,
	SCALAR_TYPE_,
	UNIVERSAL_
} t_kind;


typedef struct {
	union {
		struct 	{
			char* name;
		} P;

		struct 	{
		} IDU;
		
		struct 	{
		} IDD;

		struct 	{
			int type;
			
		} T;


		struct 	{
		} NUMERALF;
		
		struct 	{
		} NUMERALI;
		
		struct 	{
		} STR;
		
		struct 	{
		} CHR;
		
		struct 	{
		} FALSE_P;
		
		struct 	{
		} TRUE_P;
		
		
		
		struct 	{
		} NUM;
		
		struct 	{
		} R;
		
		struct 	{
		} E;
		
		struct 	{
		} S;
		
		struct 	{
		} LI;
		
		struct 	{
		} LS;
		
		
		
		struct 	{
		} B;
		
		struct 	{
		} DV;
		
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