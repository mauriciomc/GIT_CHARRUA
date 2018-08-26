%{

#include "novocharrua2.tab.hpp"

#define YY_DECL extern "C" int yylex()

extern void yyerror(const char *);  /* prints grammar violation message */

extern void int2bin(char str1[],int dec);
extern int procura_var (char str[]);
extern char procura_label_str (char str[]);
extern int procura_label (char str[]);
extern int linha_atual;
extern char *yytext;

int linha_atual2 = 1;

/* ORIGINAL RULES TO BE ADDED */
/*("UMUL"|"umul")         { yylval.sval = strdup("011101"); return INSTR_UMUL;   }*/
/*("INDWR"|"indwr")       { yylval.sval = strdup("101110"); return INSTR_INDWR;  }*/
%}

%option noyywrap
%option pointer

CT       "//"[^\n]*
WS       [\r\t]+
ID       [_a-zA-Z][_a-zA-Z0-9]*
NUM      [0-9]+
NV       [ \n]+

%%

{CT}     {}
{WS}     {}
{NV}     {linha_atual2 ++;}

("NOP"|"nop")           { yylval.sval = strdup("000000"); return INSTR_NOP;    }
("STO"|"sto")           { yylval.sval = strdup("000001"); return INSTR_STO;    }
("LD"|"ld")             { yylval.sval = strdup("000010"); return INSTR_LD;     } 
("LDI"|"ldi")           { yylval.sval = strdup("000011"); return INSTR_LDI;    }
("ADD"|"add")           { yylval.sval = strdup("000100"); return INSTR_ADD;    }
("ADDI"|"addi")         { yylval.sval = strdup("000101"); return INSTR_ADDI;   }
("SUB"|"sub")           { yylval.sval = strdup("000110"); return INSTR_SUB;    }
("SUBI"|"subi")         { yylval.sval = strdup("000111"); return INSTR_SUBI;   }
("BEQ"|"beq")           { yylval.sval = strdup("001000"); return INSTR_BEQ;    }
("BNE"|"bne")           { yylval.sval = strdup("001001"); return INSTR_BNE;    }
("BGT"|"bgt")           { yylval.sval = strdup("001010"); return INSTR_BGT;    }
("BGE"|"bge")           { yylval.sval = strdup("001011"); return INSTR_BGE;    }
("BLT"|"blt")           { yylval.sval = strdup("001100"); return INSTR_BLT;    }
("BLE"|"ble")           { yylval.sval = strdup("001101"); return INSTR_BLE;    }
("JMP"|"jmp")           { yylval.sval = strdup("001110"); return INSTR_JMP;    }
("NOT"|"not")           { yylval.sval = strdup("001111"); return INSTR_NOT;    }
("AND"|"and")           { yylval.sval = strdup("010000"); return INSTR_AND;    }
("ANDI"|"andi")         { yylval.sval = strdup("010001"); return INSTR_ANDI;   }
("OR"|"or")             { yylval.sval = strdup("010010"); return INSTR_OR;     }
("ORI"|"ori")           { yylval.sval = strdup("010011"); return INSTR_ORI;    }
("XOR"|"xor")           { yylval.sval = strdup("010100"); return INSTR_XOR;    }
("XORI"|"xori")         { yylval.sval = strdup("010101"); return INSTR_XORI;   }
("SLL"|"sll")           { yylval.sval = strdup("010110"); return INSTR_SLL;    }
("SRL"|"srl")           { yylval.sval = strdup("010111"); return INSTR_SRL;    }
("STOV"|"stov")         { yylval.sval = strdup("011000"); return INSTR_STOV;   }
("LDV"|"ldv")           { yylval.sval = strdup("011001"); return INSTR_LDV;    }
("RETURN"|"return")     { yylval.sval = strdup("011010"); return INSTR_RETURN; }
("RETINT"|"retint")     { yylval.sval = strdup("011011"); return INSTR_RETINT; }
("CALL"|"call")         { yylval.sval = strdup("011100"); return INSTR_CALL;   }
("INDWR"|"indwr")       { yylval.sval = strdup("011101"); return INSTR_INDWR;  }
("UMULI"|"umuli")       { yylval.sval = strdup("011110"); return INSTR_UMULI;  }
("SMUL"|"smul")         { yylval.sval = strdup("011111"); return INSTR_SMUL;   }
("SMULI"|"smuli")       { yylval.sval = strdup("100000"); return INSTR_SMULI;  }
("UDIV"|"udiv")         { yylval.sval = strdup("100001"); return INSTR_UDIV;   }
("UDIVI"|"udivi")       { yylval.sval = strdup("100010"); return INSTR_UDIVI;  }
("SDIV"|"sdiv")         { yylval.sval = strdup("100011"); return INSTR_SDIV;   }
("SDIVI"|"sdivi")       { yylval.sval = strdup("100100"); return INSTR_SDIVI;  }
("ADDV"|"addv")         { yylval.sval = strdup("100101"); return INSTR_ADDV;   }
("SUBV"|"subv")         { yylval.sval = strdup("100110"); return INSTR_SUBV;   }
("ANDV"|"andv")         { yylval.sval = strdup("100111"); return INSTR_ANDV;   }
("ORV"|"orv")           { yylval.sval = strdup("101000"); return INSTR_ORV;    }
("XORV"|"xorv")         { yylval.sval = strdup("101001"); return INSTR_XORV;   }
("UMULV"|"umulv")       { yylval.sval = strdup("101010"); return INSTR_UMULV;  }
("SMULV"|"smulv")       { yylval.sval = strdup("101011"); return INSTR_SMULV;  }
("UDIVV"|"udivv")       { yylval.sval = strdup("101100"); return INSTR_UDIVV;  }
("SDIVV"|"sdivv")       { yylval.sval = strdup("101101"); return INSTR_SDIVV;  }
("COREWR"|"corewr")     { yylval.sval = strdup("101111"); return INSTR_COREWR; }
("BC"|"bc")             { yylval.sval = strdup("110000"); return INSTR_BC;     }
("BNC"|"bnc")           { yylval.sval = strdup("110001"); return INSTR_BNC;    }
("BOV"|"bov")           { yylval.sval = strdup("110010"); return INSTR_BOV;    }
("BNO"|"bno")           { yylval.sval = strdup("110011"); return INSTR_BNO;    }

".data"                 { return INIC_DADOS; } 
".inst"                 { return INIC_INST; } 

{ID}                    {  yylval.sval = strdup(yytext);return IDENTIFIER; }
{NUM}                   {  yylval.ival = atoi(yytext);return NUMBER; }

","                     { return COMMA; }
":"                     { return COLON; }
";"                     { return SEMICOLON; }
"-"                     { return HIFEN; }

.                       { yyerror("syntax error => "); }
