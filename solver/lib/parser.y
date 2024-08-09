%{
/*
 * File: parser.y
 * Author: Subhendu Mishra
 * Description: Parser file for analyzing the input and constructing the SLD (Single Line Diagram) components.
 * License: GPL
 */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

// Include the headers for the InputParser class
#include "lib/input_parser.h"

// Declare external functions
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
%token GRID TRANSFORMER BUS VOLTAGE TYPE RATING IMPEDANCE FROM TO CONNECTED GENERATION LOAD CONTROL NONE PQ SLACK

%%

/* Define the grammar rules */
input:
    | input line
    ;

line:
    bus_definition
    | transformer_definition
    | grid_definition
    ;

bus_definition:
    BUS STRING VOLTAGE NUMBER GENERATION NUMBER TYPE STRING CONTROL STRING {
       // parser->addBusDefinition($2, $4, $6, $8, $10);
        free($2);  // Free the allocated string memory
        free($8);  // Free the allocated string memory
        free($10); // Free the allocated string memory
    }
    ;

transformer_definition:
    TRANSFORMER STRING FROM STRING TO STRING RATING NUMBER IMPEDANCE NUMBER {
       // parser->addTransformerDefinition($2, $4, $6, $8, $10);
        free($2);  // Free the allocated string memory
        free($4);  // Free the allocated string memory
        free($6);  // Free the allocated string memory
    }
    ;

grid_definition:
    GRID VOLTAGE NUMBER TYPE STRING {
       // parser->addGridDefinition($3, $5);
        free($5);  // Free the allocated string memory
    }
    ;

%%

