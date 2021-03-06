all: vhlang

vh_parser.tab.c vh_parser.tab.h:	vh_parser.y
	bison -d vh_parser.y

lex.yy.c: vh_lexer.l vh_parser.tab.h
	flex vh_lexer.l

vhlang: vh_tipos.c lex.yy.c vh_parser.tab.c vh_parser.tab.h
	gcc -o vhlang vh_tipos.c vh_parser.tab.c lex.yy.c -ll

clean:
	rm vh_parser.tab.c lex.yy.c vh_parser.tab.h vhlang