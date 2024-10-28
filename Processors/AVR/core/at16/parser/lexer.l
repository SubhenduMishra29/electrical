%{
#include <stdio.h>
#include "parser.tab.h"  // Include the Bison-generated header
%}

%%
[ \t\n]+            ;        // Ignore whitespace
"mov"              { return MOV; }
"movi"             { return MOVI; }
"ld"               { return LD; }
"st"               { return ST; }
"ldi"              { return LDI; }
"out"              { return OUT; }
"in"               { return IN; }
"push"             { return PUSH; }
"pop"              { return POP; }
"xch"              { return XCH; }
"sbc"              { return SBC; }
"adc"              { return ADC; }
"add"              { return ADD; }
"adiw"             { return ADIW; }
"sub"              { return SUB; }
"subi"             { return SUBI; }
"inc"              { return INC; }
"dec"              { return DEC; }
"mul"              { return MUL; }
"muls"             { return MULS; }
"mulsu"            { return MULSU; }
"div"              { return DIV; }
"divu"             { return DIVU; }
"and"              { return AND; }
"andi"             { return ANDI; }
"or"               { return OR; }
"ori"              { return ORI; }
"xor"              { return XOR; }
"xori"             { return XORI; }
"com"              { return COM; }
"cpi"              { return CPI; }
"rjmp"             { return RJMP; }
"ijmp"             { return IJMP; }
"call"             { return CALL; }
"ret"              { return RET; }
"reti"             { return RETI; }
"nop"              { return NOP; }
"sleep"            { return SLEEP; }
"break"            { return BREAK; }
"brbs"             { return BRBS; }
"brbc"             { return BRBC; }
"brne"             { return BRNE; }
"breq"             { return BREQ; }
"brge"             { return BRGE; }
"brlt"             { return BRLT; }
"brsh"             { return BRSH; }
"brlo"             { return BRLO; }
"sbi"              { return SBI; }
"cbi"              { return CBI; }
"bst"              { return BST; }
"bld"              { return BLD; }
"sei"              { return SEI; }
"cli"              { return CLI; }
"lpm"              { return LPM; }
"spm"              { return SPM; }
"clr"              { return CLR; }
"set"              { return SET; }
"jmp"              { return JMP; }
"adci"             { return ADCI; }
"tst"              { return TST; }

"[^ \t\n]+"        { return IDENTIFIER; } // Catch all identifiers
.                  { /* Ignore any other characters */ }

%%

// Error handling
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
