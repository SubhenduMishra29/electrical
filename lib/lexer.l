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
%option prefix="yy"
%option header-file="lexer.yy.h"

%%

"GRID"                  { std::cout << "Token: GRID" << std::endl; return GRID; }
"TRANSFORMER"           { std::cout << "Token: TRANSFORMER" << std::endl; return TRANSFORMER; }
"BUS"                   { std::cout << "Token: BUS" << std::endl; return BUS; }
"CT"                    { std::cout << "Token: CT" << std::endl; return CT; }
"PT"                    { std::cout << "Token: PT" << std::endl; return PT; }
"CB"                    { std::cout << "Token: CB" << std::endl; return CB; }
"CONNECTED"             { std::cout << "Token: CONNECTED" << std::endl; return CONNECTED; }
"TO"                    { std::cout << "Token: TO" << std::endl; return TO; }
"VOLTAGE"               { std::cout << "Token: VOLTAGE" << std::endl; return VOLTAGE; }
"TYPE"                  { std::cout << "Token: TYPE" << std::endl; return TYPE; }
"LINE"                  { std::cout << "Token: LINE" << std::endl; return TYPE; }
"RATING"                { std::cout << "Token: RATING" << std::endl; return RATING; }
"IMPEDANCE"             { std::cout << "Token: IMPEDANCE" << std::endl; return IMPEDANCE; }
"FROM"                  { std::cout << "Token: FROM" << std::endl; return FROM; }
"GENERATION"            { std::cout << "Token: GENERATION" << std::endl; return GENERATION; }
"LOAD"                  { std::cout << "Token: LOAD" << std::endl; return LOAD; }
"CONTROL"               { std::cout << "Token: CONTROL" << std::endl; return CONTROL; }
"NONE"                  { std::cout << "Token: NONE" << std::endl; return NONE; }
"PQ"                    { std::cout << "Token: PQ" << std::endl; return PQ; }
"SLACK"                 { std::cout << "Token: SLACK" << std::endl; return SLACK; }
"EXIT"                  { std::cout << "Token: EXIT" << std::endl; return EXIT; }
"VERSION"               { std::cout << "Token: VERSION" << std::endl; return VERSION; }
"HELP"                  { std::cout << "Token: HELP" << std::endl; return HELP; }


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
