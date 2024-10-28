%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"  // Include the token definitions

// Declare the lexer function
extern int yylex();
void yyerror(const char *s);
%}

%union {
    char* str;
}

%token <str> IDENTIFIER
%token MOV MOVI LD ST LDI OUT IN PUSH POP XCH SBC ADC ADD ADIW SUB SUBI INC DEC
%token MUL MULS MULSU DIV DIVU AND ANDI OR ORI XOR XORI COM CPI RJMP IJMP
%token CALL RET RETI NOP SLEEP BREAK BRBS BRBC BRNE BREQ BRGE BRLT BRSH BRLO
%token SBI CBI BST BLD SEI CLI LPM SPM CLR SET JMP ADCI TST

%type <str> instruction

%%

// Grammar rules
program:
    | program instruction
    ;

instruction:
      MOV IDENTIFIER IDENTIFIER { printf("MOV instruction: %s <- %s\n", $2, $3); }
    | MOVI IDENTIFIER IDENTIFIER { printf("MOVI instruction: %s <- %s\n", $2, $3); }
    | LD IDENTIFIER IDENTIFIER { printf("LD instruction: %s <- %s\n", $2, $3); }
    | ST IDENTIFIER IDENTIFIER { printf("ST instruction: %s <- %s\n", $2, $3); }
    | LDI IDENTIFIER IDENTIFIER { printf("LDI instruction: %s <- %s\n", $2, $3); }
    | OUT IDENTIFIER IDENTIFIER { printf("OUT instruction: %s <- %s\n", $2, $3); }
    | IN IDENTIFIER IDENTIFIER { printf("IN instruction: %s <- %s\n", $2, $3); }
    | PUSH IDENTIFIER { printf("PUSH instruction: %s\n", $2); }
    | POP IDENTIFIER { printf("POP instruction: %s\n", $2); }
    | XCH IDENTIFIER IDENTIFIER { printf("XCH instruction: %s <- %s\n", $2, $3); }
    | SBC IDENTIFIER IDENTIFIER { printf("SBC instruction: %s <- %s\n", $2, $3); }
    | ADC IDENTIFIER IDENTIFIER { printf("ADC instruction: %s <- %s\n", $2, $3); }
    | ADD IDENTIFIER IDENTIFIER { printf("ADD instruction: %s <- %s\n", $2, $3); }
    | ADIW IDENTIFIER IDENTIFIER { printf("ADIW instruction: %s <- %s\n", $2, $3); }
    | SUB IDENTIFIER IDENTIFIER { printf("SUB instruction: %s <- %s\n", $2, $3); }
    | SUBI IDENTIFIER IDENTIFIER { printf("SUBI instruction: %s <- %s\n", $2, $3); }
    | INC IDENTIFIER { printf("INC instruction: %s\n", $2); }
    | DEC IDENTIFIER { printf("DEC instruction: %s\n", $2); }
    | MUL IDENTIFIER IDENTIFIER { printf("MUL instruction: %s <- %s\n", $2, $3); }
    | MULS IDENTIFIER IDENTIFIER { printf("MULS instruction: %s <- %s\n", $2, $3); }
    | MULSU IDENTIFIER IDENTIFIER { printf("MULSU instruction: %s <- %s\n", $2, $3); }
    | DIV IDENTIFIER IDENTIFIER { printf("DIV instruction: %s <- %s\n", $2, $3); }
    | DIVU IDENTIFIER IDENTIFIER { printf("DIVU instruction: %s <- %s\n", $2, $3); }
    | AND IDENTIFIER IDENTIFIER { printf("AND instruction: %s <- %s\n", $2, $3); }
    | ANDI IDENTIFIER IDENTIFIER { printf("ANDI instruction: %s <- %s\n", $2, $3); }
    | OR IDENTIFIER IDENTIFIER { printf("OR instruction: %s <- %s\n", $2, $3); }
    | ORI IDENTIFIER IDENTIFIER { printf("ORI instruction: %s <- %s\n", $2, $3); }
    | XOR IDENTIFIER IDENTIFIER { printf("XOR instruction: %s <- %s\n", $2, $3); }
    | XORI IDENTIFIER IDENTIFIER { printf("XORI instruction: %s <- %s\n", $2, $3); }
    | COM IDENTIFIER { printf("COM instruction: %s\n", $2); }
    | CPI IDENTIFIER { printf("CPI instruction: %s\n", $2); }
    | RJMP IDENTIFIER { printf("RJMP instruction: %s\n", $2); }
    | IJMP { printf("IJMP instruction\n"); }
    | CALL IDENTIFIER { printf("CALL instruction: %s\n", $2); }
    | RET { printf("RET instruction\n"); }
    | RETI { printf("RETI instruction\n"); }
    | NOP { printf("NOP instruction\n"); }
    | SLEEP { printf("SLEEP instruction\n"); }
    | BREAK { printf("BREAK instruction\n"); }
    | BRBS IDENTIFIER { printf("BRBS instruction: %s\n", $2); }
    | BRBC IDENTIFIER { printf("BRBC instruction: %s\n", $2); }
    | BRNE IDENTIFIER { printf("BRNE instruction: %s\n", $2); }
    | BREQ IDENTIFIER { printf("BREQ instruction: %s\n", $2); }
    | BRGE IDENTIFIER { printf("BRGE instruction: %s\n", $2); }
    | BRLT IDENTIFIER { printf("BRLT instruction: %s\n", $2); }
    | BRSH IDENTIFIER { printf("BRSH instruction: %s\n", $2); }
    | BRLO IDENTIFIER { printf("BRLO instruction: %s\n", $2); }
    | SBI IDENTIFIER IDENTIFIER { printf("SBI instruction: %s <- %s\n", $2, $3); }
    | CBI IDENTIFIER IDENTIFIER { printf("CBI instruction: %s <- %s\n", $2, $3); }
    | BST IDENTIFIER IDENTIFIER { printf("BST instruction: %s <- %s\n", $2, $3); }
    | BLD IDENTIFIER IDENTIFIER { printf("BLD instruction: %s <- %s\n", $2, $3); }
    | SEI { printf("SEI instruction\n"); }
    | CLI { printf("CLI instruction\n"); }
    | LPM { printf("LPM instruction\n"); }
    | SPM { printf("SPM instruction\n"); }
    | CLR IDENTIFIER { printf("CLR instruction: %s\n", $2); }
    | SET IDENTIFIER { printf("SET instruction: %s\n", $2); }
    | JMP IDENTIFIER { printf("JMP instruction: %s\n", $2); }
    | ADCI IDENTIFIER IDENTIFIER { printf("ADCI instruction: %s <- %s\n", $2, $3); }
    | TST IDENTIFIER { printf("TST instruction: %s\n", $2); }
    ;

%%

// Error handling
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
