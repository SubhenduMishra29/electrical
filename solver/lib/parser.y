%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "lib/input_parser.h"
#include "lexer.yy.h"
#include "parser.tab.hpp"  // Token definitions should be here

extern int yylex();
extern void yyerror(const char *s);

InputParser parser;
%}

/* Define union for YYSTYPE */
%union {
    int number;
    char* string;
    //int ival;
    //double dval;
    char *sval;
    //struct Bus *busval;
    //struct Grid *gridval;
} 


/* Define tokens and their types */
%token <sval> STRING ID TYPE VOLTAGE_REGULATOR SHUNT_CONDUCTOR REGULATOR_SETPOINT VOLTAGE_BAND EMERGENCY_BACKUP HARMONIC_DISTORTION TAP_CHANGER COOLING TAP_STEP
%token <sval> BUSBAR_PROTECTION FROM TO TAP_RANGE TAP_POSITION RATING IMPEDANCE TEMPERATURE_RISE VECTOR_GROUP
%token <sval> LOAD_TAP_CHANGER NO_LOAD_TAP_CHANGER BASE_kV SIDE
%token <dval> NUMBER LOAD_P LOAD_Q GENERATOR_P GENERATOR_Q ANGLE
%token GRID TRANSFORMER BUS CT PT CB CONNECTED GENERATION LOAD CONTROL NONE PQ SLACK LINE
%token VERSION HELP SAVE EXIT CMD
%token CAPACITOR REACTOR RELAY 
%token  <sval> WINDING_MATERIAL INSULATION_MATERIAL HEALTH_MONITORING INSULATION_RESISTANCE THERMAL_RATING GROUND_WIRE CORROSION_PROTECTION
%token THERMAL_LIMITS SAG_ADJUSTMENTS TEMPERATURE INSTALLATION_DEPTH MANUAL_SWITCHING REACTANCE_SETTINGS MANUAL_OVERRIDE
%token CONTROL_STRATEGY RESPONSE_TIME FAULT_DETECTION CALIBRATION_RECORDS SETTINGS  
%token <ival> INTEGER
%token <dval> FLOAT
%token <string> VOLTAGE VOLTAGE_VAL







%start input
%define parse.error verbose  // Provides detailed error messages

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
    | connection_defination
    ;

cli_command:
    EXIT {
        exit(0);
    }
    | LOAD STRING {
        printf("Loading from file: %s\n", $2);
       // parser->loadFromFile($2); // Assuming loadFromFile method in InputParser
        free($2); // Free dynamically allocated memory
    }
    | SAVE STRING {
        printf("Saving to file: %s\n", $2);
       // parser->saveToFile($2); // Assuming saveToFile method in InputParser
        free($2); // Free dynamically allocated memory
    }
    | HELP {
        printf("Help command received\n");
    }
    | VERSION {
        printf("Version command received\n");
    }
    | CMD STRING {
        printf("Command received: %s\n", $2);
        free($2); // Free dynamically allocated memory
    }
    ;

bus_definition:
    BUS ID STRING TYPE STRING VOLTAGE STRING 
    {
        // Debug: Output the parsed values
        printf("Parsing BUS with values:\n");
        printf("ID: %s\n", $3 ? $3 : "null");
        printf("Type: %s\n", $6 ? $6 : "null");
        printf("Voltage: %s\n", $7 ? $7 : "null");

        try {
            // Convert voltage string to double (already stripped of 'kV')
            double voltageValue = std::stod($7);
            // Create Voltage object (imaginary part = 0.0)
            Voltage voltage(voltageValue, 0.0); // this has to be checked in voltage class 
            parser.addBus($3, $7);            
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid voltage format: " << $7 << std::endl;
            YYABORT;
        }

        printf("_______________________________\n");
        
        // Free the dynamically allocated memory
        free($3);
        free($6);
        free($7);       
    }
    ;
//Transformer id "Transformer1" from "Bus1" to "Bus2" rating "100MVA" impedance "0.05+j0.1" 
//    tap_changer "Yes" tap_range "±10%" tap_step "0.5%" tap_position "0" cooling "ONAN" temperature_rise "45°C" 
//    vector_group "Dyn11" load_tap_changer "Yes" no_load_tap_changer "No" winding_material "Copper" insulation_material "Oil"
//    insulation_resistance "500MΩ"

transformer_definition:
    TRANSFORMER ID STRING FROM STRING TO STRING RATING STRING IMPEDANCE STRING TAP_CHANGER STRING TAP_RANGE STRING TAP_STEP STRING TAP_POSITION STRING COOLING STRING TEMPERATURE_RISE STRING VECTOR_GROUP STRING LOAD_TAP_CHANGER STRING NO_LOAD_TAP_CHANGER STRING WINDING_MATERIAL STRING INSULATION_MATERIAL STRING INSULATION_RESISTANCE STRING
    {
        printf("Parsing TRANSFORMER with values:\n");

        // Correctly map the fields to the input values
        printf("ID: %s\n", $4);
        printf("From Bus: %s\n", $6);
        printf("To Bus: %s\n", $8);
        printf("Rating: %s\n", $10);
        printf("Impedance: %s\n", $12);
        printf("Tap Changer: %s\n", $14);
        printf("Tap Range: %s\n", $16);
        printf("Tap Step: %s\n", $18);
        printf("Tap Position: %s\n", $20);
        printf("Cooling: %s\n", $22);
        printf("Temperature Rise: %s\n", $24);
        printf("Vector Group: %s\n", $26);
        printf("Load Tap Changer: %s\n", $28);
        printf("No Load Tap Changer: %s\n", $30);
        printf("Winding Material: %s\n", $32);
        printf("Insulation Material: %s\n", $34);
       // printf("Health Monitoring: %s\n", $36);
        //printf("Insulation Resistance: %s\n", $38);

        // Free the dynamically allocated memory
        free($2);
        free($4);
        free($6);
        free($8);
        free($10);
        free($12);
        free($14);
        free($16);
        free($18);
        free($20);
        free($22);
        free($24);
        free($26);
        free($28);
        free($30);
        free($32);
        free($34);
       // free($36);
    }
    ;



grid_definition:
    GRID VOLTAGE NUMBER TYPE STRING {
        printf("Parsing GRID with values:\n");
        printf("Voltage: %lf\n", $2);
       // printf("Type: %s\n", $4);

        if ($2 == NULL) {
            yyerror("Invalid grid voltage");
        } else {
            // Assuming parser has addGrid method
          //  parser->addGrid($2, $4);
        }

       // free($4); // Free Type
    }
    ;

ct_definition:
    CT STRING TYPE STRING {
        printf("Parsing CT with values:\n");
        printf("Type: %s\n", $2);

        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid CT definition");
        } else {
            // Assuming parser has addCT method
           // parser->addCT($2, $4);
        }

        free($2);
        free($4);
    }
    ;

pt_definition:
    PT STRING TYPE STRING {
        printf("Parsing PT with values:\n");
        printf("Type: %s\n", $2);

        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid PT definition");
        } else {
            // Assuming parser has addPT method
           // parser->addPT($2, $4);
        }

        free($2);
        free($4);
    }
    ;

cb_definition:
    CB STRING TYPE STRING {
        printf("Parsing CB with values:\n");
        printf("Type: %s\n", $2);

        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid CB definition");
        } else {
            // Assuming parser has addCB method
           // parser->addCB($2, $4);
        }

        free($2);
        free($4);
    }
    ;

capacitor_definition:
    CAPACITOR STRING TYPE STRING NUMBER {
        printf("Parsing CAPACITOR with values:\n");
        printf("Type: %s\n", $2);
        printf("Rating: %lf\n", $4);

        // Assuming parser has addCapacitor method
       // parser->addCapacitor($2, $4);

        free($2);
        free($4);
    }
    ;

reactor_definition:
    REACTOR STRING TYPE STRING NUMBER {
        printf("Parsing REACTOR with values:\n");
        printf("Type: %s\n", $2);
        printf("Rating: %lf\n", $4);

        // Assuming parser has addReactor method
        //parser->addReactor($2, $4);

        free($2);
        free($4);
    }
    ;

relay_definition:
    RELAY STRING TYPE STRING {
        printf("Parsing RELAY with values:\n");
        printf("Type: %s\n", $2);

        if ($2 == nullptr || $4 == nullptr) {
            yyerror("Invalid RELAY definition");
        } else {
            // Assuming parser has addRelay method
           // parser->addRelay($2, $4);
        }

        free($2);
        free($4);
    }
    ;
connection_defination:
    BUS STRING LINE STRING
    {
        printf("Parsing Connection:BUS\n");
        free($2);
        free($4);
    }
    |
    LINE STRING PT STRING
    {
        printf("Parsing Connection:PT\n");
        free($2);
        free($4);
    }
    |
    LINE STRING CT STRING
    {
        free($2);
        free($4);
    }
    |
    LINE STRING RELAY STRING
    {
        free($2);
        free($4);
    }
    |
    LINE STRING TRANSFORMER STRING SIDE STRING
    {
        free($2);
        free($4);
        free($6);
    }
    |
    LINE STRING LOAD STRING
    {
        free($2);
        free($4);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}