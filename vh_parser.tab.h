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
     NEG = 259,
     IF = 260,
     ELSE = 261,
     ENDIF = 262,
     EQUALS = 263,
     AND = 264,
     OR = 265,
     LESS_THAN = 266,
     GREATER_THAN = 267,
     LESS_OR_EQUAL = 268,
     GREATER_OR_EQUAL = 269,
     NOT_EQUAL = 270,
     EQUAL_EQUAL = 271,
     PLUS = 272,
     MINUS = 273,
     TIMES = 274,
     DIVIDE = 275,
     NOT = 276,
     PLUS_PLUS = 277,
     MINUS_MINUS = 278,
     INTEGER = 279,
     STRING = 280,
     FLOAT = 281,
     BOOLEAN = 282,
     CHAR = 283,
     VAR = 284,
     COLON = 285,
     SEMI_COLON = 286,
     COMMA = 287,
     LEFT_BRACES = 288,
     RIGHT_BRACES = 289,
     LEFT_PARENTHESIS = 290,
     RIGHT_PARENTHESIS = 291,
     ID = 292,
     STRINGVAL = 293,
     TRUE = 294,
     FALSE = 295,
     CHARACTER = 296,
     NUMERALFLOAT = 297,
     NUMERALINT = 298
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
#line 112 "vh_parser.tab.h"
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
