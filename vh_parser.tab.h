/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_VH_PARSER_TAB_H_INCLUDED
# define YY_YY_VH_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DUP = 258,
     IF = 259,
     ELSE = 260,
     ENDIF = 261,
     EQUALS = 262,
     AND = 263,
     OR = 264,
     LESS_THAN = 265,
     GREATER_THAN = 266,
     LESS_OR_EQUAL = 267,
     GREATER_OR_EQUAL = 268,
     NOT_EQUAL = 269,
     EQUAL_EQUAL = 270,
     PLUS = 271,
     MINUS = 272,
     TIMES = 273,
     DIVIDE = 274,
     NOT = 275,
     PLUS_PLUS = 276,
     MINUS_MINUS = 277,
     INTEGER = 278,
     STRING = 279,
     FLOAT = 280,
     BOOLEAN = 281,
     CHAR = 282,
     VAR = 283,
     COLON = 284,
     SEMI_COLON = 285,
     COMMA = 286,
     LEFT_BRACES = 287,
     RIGHT_BRACES = 288,
     LEFT_PARENTHESIS = 289,
     RIGHT_PARENTHESIS = 290,
     ID = 291,
     STRINGVAL = 292,
     TRUE = 293,
     FALSE = 294,
     CHARACTER = 295,
     NUMERALFLOAT = 296,
     NUMERALINT = 297
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 32 "vh_parser.y"

    int numeralint;
    float numeralfloat;
    int boolean;
    char character;
    char id[MAX_VAR_LENGTH];
    char* string;
    t_nonterm nonterm;
    v_type vtype;


/* Line 2053 of yacc.c  */
#line 111 "vh_parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_VH_PARSER_TAB_H_INCLUDED  */
