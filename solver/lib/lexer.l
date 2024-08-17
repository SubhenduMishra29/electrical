%{
#include "lib/input_parser.h"
#include "parser.tab.hpp" // Ensure this matches your Bison header file
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>

// Declare yylex and yyerror functions
extern int yylex();
extern void yyerror(const char *s);

// External variables for input stream handling
extern FILE* yyin;                      // For FILE* input
extern std::stringstream* yyin_stream;  // For std::stringstream input

// Function prototypes for input handling
void set_input_file(FILE* file);         // For FILE* input
void set_input_stream(std::stringstream* stream); // For std::stringstream input
%}

%option noyywrap

%%

GRID                    { return GRID; }
TRANSFORMER             { return TRANSFORMER; }
BUS                     { return BUS; }
CT                      { return CT; }
PT                      { return PT; }
CB                      { return CB; }
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
EXIT                    { return EXIT; }

[0-9]+\.[0-9]+          { yylval.number = atof(yytext); return NUMBER; }
[0-9]+                  { yylval.number = atoi(yytext); return NUMBER; }
\"[^\"]+\"              { yylval.string = strdup(yytext); return STRING; }
[ \t\n]+                { /* Ignore whitespace */ }
.                       { fprintf(stderr, "Unexpected character: %s\n", yytext); }

%%

// Function implementations

// For std::stringstream:
void set_input_stream(std::stringstream* stream) {
    if (stream) {
        std::string str = stream->str();
        // Create a temporary file for Flex
        FILE* temp_file = tmpfile();
        if (temp_file) {
            fwrite(str.c_str(), 1, str.size(), temp_file);
            rewind(temp_file);
            yyin = temp_file;
        }
    }
}

// For FILE*:
void set_input_file(FILE* file) {
    yyin = file;
    if (file) {
        fseek(file, 0, SEEK_SET);  // Rewind file
    }
}
