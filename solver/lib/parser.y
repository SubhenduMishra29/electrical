%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

#include "lib/input_parser.h"

extern int yylex();
extern void yyerror(const char *s);

// Initialize the InputParser object
InputParser* parser = nullptr;
%}

/* Define union for YYSTYPE */
%union {
    double number;
    char* string;
}

/* Define tokens and their types */
%token <string> STRING
%token <number> NUMBER
%token GRID TRANSFORMER BUS CT PT CB VOLTAGE TYPE RATING IMPEDANCE FROM TO CONNECTED GENERATION LOAD CONTROL NONE PQ SLACK EXIT

/* Define additional tokens if needed */
%token ST

%%

/* Define the grammar rules */
input:
    | input line
    | input cli_command
    ;

line:
    bus_definition
    | transformer_definition
    | grid_definition
    | ct_definition
    | pt_definition
    | cb_definition
    ;

cli_command:
    EXIT {
        // Handle the exit command here
        exit(0);
    }
    ;

bus_definition:
    BUS STRING VOLTAGE NUMBER GENERATION NUMBER TYPE STRING CONTROL STRING {
        if ($4 <= 0 || $6 < 0) {
            yyerror("Invalid bus attributes");
        }
        free($2);  // Free allocated string memory
        free($8);  // Free allocated string memory
        free($10); // Free allocated string memory
    }
    ;

transformer_definition:
    TRANSFORMER STRING FROM STRING TO STRING RATING NUMBER IMPEDANCE NUMBER {
       // if ($6 == nullptr || $8 == nullptr) {
       //     yyerror("Invalid transformer connections");
       // }
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
        free($6);  // Free allocated string memory
    }
    ;

grid_definition:
    GRID VOLTAGE NUMBER TYPE STRING {
        if ($3 <= 0) {
            yyerror("Invalid grid voltage");
        }
        free($5);  // Free allocated string memory
    }
    ;

ct_definition:
    CT STRING TYPE STRING {
        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid CT definition");
        }
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

pt_definition:
    PT STRING TYPE STRING {
        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid PT definition");
        }
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

cb_definition:
    CB STRING TYPE STRING {
        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid CB definition");
        }
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}
