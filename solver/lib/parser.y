%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "lib/input_parser.h"
#include "lexer.yy.h"
#include "parser.tab.hpp"  // This is where the token definitions should be 

extern int yylex();
extern void yyerror(const char *s);

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
%token <number> VOLTAGE
%token GRID TRANSFORMER BUS CT PT CB TYPE RATING IMPEDANCE FROM TO CONNECTED GENERATION LOAD CONTROL NONE PQ SLACK LINE
%token VERSION HELP SAVE EXIT CMD
%token CAPACITOR REACTOR RELAY TAP_STEP TAP_POSITION COOLING TEMPERATURE_RISE VECTOR_GROUP LOAD_TAP_CHANGER NO_LOAD_TAP_CHANGER
%token VOLTAGE_REGULATOR REGULATOR_SETPOINT VOLTAGE_BAND EMERGENCY_BACKUP HARMONIC_DISTORTION BUSBAR_PROTECTION TAP_CHANGER TAP_RANGE
%token WINDING_MATERIA INSULATION_MATERIAL HEALTH_MONITORING INSULATION_RESISTANCE THERMAL_RATING GROUND_WIRE CORROSION_PROTECTION
%token THERMAL_LIMITS SAG_ADJUSTMENTS TEMPERATURE INSTALLATION_DEPTH MANUAL_SWITCHING REACTANCE_SETTINGS MANUAL_OVERRIDE
%token CONTROL_STRATEGY RESPONSE_TIME FAULT_DETECTION CALIBRATION_RECORDS WINDING_MATERIAL 
%token SETTINGS

%start input

%% 

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
    | capacitor_definition
    | reactor_definition
    | relay_definition
    ;

cli_command:
    EXIT {
        exit(0);
    }
    | LOAD STRING {
        printf("Loading from file: %s\n", $2);
        free($2);
    }
    | SAVE STRING {
        printf("Saving to file: %s\n", $2);
        free($2);
    }
    | HELP {
        printf("Help command received\n");
    }
    | VERSION {
        printf("Version command received\n");
    }
    | CMD STRING {
        printf("Command received: %s\n", $2);
        free($2);
    }
    ;

bus_definition:
    BUS STRING VOLTAGE NUMBER GENERATION NUMBER TYPE STRING CONTROL STRING {
        std::cout << "Parsing BUS with values: ";
        if ($3 <= 0 || $6 < 0) {
            yyerror("Invalid bus attributes");
        }
        free($2);  // Free allocated string memory
        free($8);  // Free allocated string memory
        free($10); // Free allocated string memory
    }
    ;

transformer_definition:
    TRANSFORMER STRING FROM STRING TO STRING RATING NUMBER IMPEDANCE NUMBER {
        std::cout << "Parsing TRANSFORMER with values: ";
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
        free($6);  // Free allocated string memory
    }
    ;

grid_definition:
    GRID VOLTAGE NUMBER TYPE STRING {
        std::cout << "Parsing GRID with values: ";
        if ($2 <= 0) {
            yyerror("Invalid grid voltage");
        }
       // free($4); // Free allocated string memory
    }
    ;

ct_definition:
    CT STRING TYPE STRING {
        std::cout << "Parsing CT with values: ";
        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid CT definition");
        }
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

pt_definition:
    PT STRING TYPE STRING {
        std::cout << "Parsing PT with values: ";
        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid PT definition");
        }
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

cb_definition:
    CB STRING TYPE STRING {
        std::cout << "Parsing CB with values: ";
        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid CB definition");
        }
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

capacitor_definition:
    CAPACITOR STRING TYPE STRING NUMBER {
        std::cout << "Parsing CAPACITOR with values: ";
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

reactor_definition:
    REACTOR STRING TYPE STRING NUMBER {
        std::cout << "Parsing REACTOR with values: ";
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

relay_definition:
    RELAY STRING TYPE STRING {
        std::cout << "Parsing RELAY with values: ";
        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid RELAY definition");
        }
        free($2);  // Free allocated string memory
        free($4);  // Free allocated string memory
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
