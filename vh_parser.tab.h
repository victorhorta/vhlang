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
     POP = 259,
     NEG = 260,
     IF = 261,
     ELSE = 262,
     ENDIF = 263,
     WHILE = 264,
     RETURN = 265,
     EQUALS = 266,
     AND = 267,
     OR = 268,
     LESS_THAN = 269,
     GREATER_THAN = 270,
     LESS_OR_EQUAL = 271,
     GREATER_OR_EQUAL = 272,
     NOT_EQUAL = 273,
     EQUAL_EQUAL = 274,
     PLUS = 275,
     MINUS = 276,
     TIMES = 277,
     DIVIDE = 278,
     NOT = 279,
     PLUS_PLUS = 280,
     MINUS_MINUS = 281,
     INTEGER = 282,
     STRING = 283,
     FLOAT = 284,
     BOOLEAN = 285,
     CHAR = 286,
     VAR = 287,
     COLON = 288,
     SEMI_COLON = 289,
     COMMA = 290,
     LEFT_BRACES = 291,
     RIGHT_BRACES = 292,
     LEFT_PARENTHESIS = 293,
     RIGHT_PARENTHESIS = 294,
     ID = 295,
     STRINGVAL = 296,
     TRUE = 297,
     FALSE = 298,
     CHARACTER = 299,
     NUMERALFLOAT = 300,
     NUMERALINT = 301
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 33 "vh_parser.y"

    int numeralint;
    float numeralfloat;
    int boolean;
    char character;
    char id[MAX_VAR_LENGTH];
    char* string;
    t_nonterm nonterm;
    v_type vtype;


/* Line 2053 of yacc.c  */
#line 115 "vh_parser.tab.h"
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
