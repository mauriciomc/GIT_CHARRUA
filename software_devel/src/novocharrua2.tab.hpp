
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     IDENTIFIER = 259,
     INSTR_NOP = 260,
     INSTR_STO = 261,
     INSTR_LD = 262,
     INSTR_LDI = 263,
     INSTR_ADD = 264,
     INSTR_ADDI = 265,
     INSTR_SUB = 266,
     INSTR_SUBI = 267,
     INSTR_BEQ = 268,
     INSTR_BNE = 269,
     INSTR_BGT = 270,
     INSTR_BGE = 271,
     INSTR_BLT = 272,
     INSTR_BLE = 273,
     INSTR_JMP = 274,
     INSTR_NOT = 275,
     INSTR_AND = 276,
     INSTR_ANDI = 277,
     INSTR_OR = 278,
     INSTR_ORI = 279,
     INSTR_XOR = 280,
     INSTR_XORI = 281,
     INSTR_SLL = 282,
     INSTR_SRL = 283,
     INSTR_STOV = 284,
     INSTR_LDV = 285,
     INSTR_RETURN = 286,
     INSTR_RETINT = 287,
     INSTR_CALL = 288,
     INSTR_UMUL = 289,
     INSTR_UMULI = 290,
     INSTR_SMUL = 291,
     INSTR_SMULI = 292,
     INSTR_UDIV = 293,
     INSTR_UDIVI = 294,
     INSTR_SDIV = 295,
     INSTR_SDIVI = 296,
     INSTR_ADDV = 297,
     INSTR_SUBV = 298,
     INSTR_ANDV = 299,
     INSTR_ORV = 300,
     INSTR_XORV = 301,
     INSTR_UMULV = 302,
     INSTR_SMULV = 303,
     INSTR_UDIVV = 304,
     INSTR_SDIVV = 305,
     INSTR_INDWR = 306,
     INSTR_COREWR = 307,
     INSTR_BC = 308,
     INSTR_BNC = 309,
     INSTR_BOV = 310,
     INSTR_BNO = 311,
     COMMA = 312,
     COLON = 313,
     SEMICOLON = 314,
     HIFEN = 315,
     INIC_DADOS = 316,
     INIC_INST = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 46 "novocharrua2.ypp"

        int ival;
        float fval;
        char *sval;
        char sym;



/* Line 1676 of yacc.c  */
#line 123 "novocharrua2.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


