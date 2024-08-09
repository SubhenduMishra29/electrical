%{
/*
 * File: lexer.l
 * Author: Subhendu Mishra
 * Description: Lexer for tokenizing input for the SLD parser.
 * License: GPL
 */

#include "parser.tab.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>

// Declare yylex and yyerror functions
#define YY_DECL int yylex()

extern int yylex();
extern void yyerror(const char *s);

/* Input stream for the lexer */
extern std::stringstream* yyin_stream;

%}

/* Disable yywrap function */
%option noyywrap

%%

GRID                    { return GRID; }
TRANSFORMER             { return TRANSFORMER; }
BUS                     { return BUS; }
CONNECTED               { return CONNECTED; }
TO                      { return TO; }
VOLTAGE                 { return VOLTAGE; }
TYPE                    { return TYPE; }
RATING                  { return RATING; }
IMPEDANCE               { return IMPEDANCE; }
FROM                    { return FROM; }
GENERATION              { return GENERATION; }
LOAD                    { return LOAD; }
CONTROL                 { return CONTROL; }
NONE                    { return NONE; }
PQ                      { return PQ; }
SLACK                   { return SLACK; }

[0-9]+\.[0-9]+          { yylval.number = atof(yytext); return NUMBER; }
[0-9]+                  { yylval.number = atoi(yytext); return NUMBER; }
\"[^\"]+\"              { yylval.string = strdup(yytext); return STRING; }
[ \t\n]+                { /* Ignore whitespace */ }
.                       { return yytext[0]; }

%%

void yyerror(const char *s) {
    // Error handling can be enhanced if needed
}
