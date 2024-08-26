%{
#include "lib/input_parser.h"
#include "parser.tab.hpp" // Ensure this matches your Bison header file
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cctype> // For tolower function

// Declare yylex and yyerror functions
extern int yylex();
extern void yyerror(const char *s);

// External variables for input stream handling
extern FILE* yyin;                      // For FILE* input
extern std::stringstream* yyin_stream;  // For std::stringstream input

// Function prototypes for input handling
void set_input_file(FILE* file);         // For FILE* input
void set_input_stream(std::stringstream* stream); // For std::stringstream input

// Helper function to convert strings to lowercase
std::string to_lower(const std::string& str) {
    std::string lower_str = str;
    for (char& c : lower_str) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return lower_str;
}
%}
%option debug
%option noyywrap
%option case-insensitive
%option prefix="yy"
%option header-file="lexer.yy.h"

%%

"grid"                  { return GRID; }
"transformer"           { return TRANSFORMER; }
"bus"                   { return BUS; }
"ct"                    { return CT; }
"pt"                    { return PT; }
"cb"                    { return CB; }
"connected"             { return CONNECTED; }
"to"                    { return TO; }
"voltage"               { return VOLTAGE; }
"type"                  { return TYPE; }
"line"                  { return LINE; }
"rating"                { return RATING; }
"impedance"             { return IMPEDANCE; }
"from"                  { return FROM; }
"generation"            { return GENERATION; }
"load"                  { return LOAD; }
"control"               { return CONTROL; }
"none"                  { return NONE; }
"pq"                    { return PQ; }
"slack"                 { return SLACK; }
"exit"                  { return EXIT; }
"version"               { return VERSION; }
"cmd"                   { return CMD; }
"help"                  { return HELP; }
"voltage_regulator"     { return VOLTAGE_REGULATOR; }
"regulator_setpoint"    { return REGULATOR_SETPOINT; }
"voltage_band"          { return VOLTAGE_BAND; }
"emergency_backup"      { return EMERGENCY_BACKUP; }
"harmonic_distortion"   { return HARMONIC_DISTORTION; }
"busbar_protection"     { return BUSBAR_PROTECTION; }
"tap_changer"           { return TAP_CHANGER; }
"tap_range"             { return TAP_RANGE; }
"tap_step"              { return TAP_STEP; }
"tap_position"          { return TAP_POSITION; }
"cooling"               { return COOLING; }
"temperature_rise"      { return TEMPERATURE_RISE; }
"vector_group"          { return VECTOR_GROUP; }
"load_tap_changer"      { return LOAD_TAP_CHANGER; }
"no_load_tap_changer"   { return NO_LOAD_TAP_CHANGER; }
"winding_material"      { return WINDING_MATERIAL; }
"insulation_material"   { return INSULATION_MATERIAL; }
"health_monitoring"     { return HEALTH_MONITORING; }
"insulation_resistance" { return INSULATION_RESISTANCE; }
"thermal_rating"        { return THERMAL_RATING; }
"ground_wire"           { return GROUND_WIRE; }
"corrosion_protection"  { return CORROSION_PROTECTION; }
"thermal_limits"        { return THERMAL_LIMITS; }
"sag_adjustments"       { return SAG_ADJUSTMENTS; }
"temperature"           { return TEMPERATURE; }
"installation_depth"    { return INSTALLATION_DEPTH; }
"manual_switching"      { return MANUAL_SWITCHING; }
"reactance_settings"    { return REACTANCE_SETTINGS; }
"manual_override"       { return MANUAL_OVERRIDE; }
"control_strategy"      { return CONTROL_STRATEGY; }
"response_time"         { return RESPONSE_TIME; }
"fault_detection"       { return FAULT_DETECTION; }
"settings"              { return SETTINGS; }
"calibration_records"   { return CALIBRATION_RECORDS; }
"capacitor"             { return CAPACITOR; }
"reactor"               { return REACTOR; }

[0-9]+\.[0-9]+          { yylval.number = atof(yytext); return NUMBER; }
[0-9]+                  { yylval.number = atoi(yytext); return NUMBER; }
\"[^\"]+\"              { 
    std::string str = yytext;
    yylval.string = strdup(str.substr(1, str.length() - 2).c_str()); // Strip quotes
    return STRING; 
}
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
