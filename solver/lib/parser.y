%{
#include <iostream>
#include <string>

int yylex();  // Declare the yylex function

void yyerror(const char* s);  // Declare the yyerror function
%}

%union {
    int num;
    std::string* str;
}

%token <num> NUMBER
%token <str> IDENTIFIER
%token GRID LINE

%%

input:
    | input line
;

line:
    GRID
    | LINE
    | IDENTIFIER { 
        std::cout << "Identifier: " << *$1 << std::endl; 
        delete $1; // Free allocated memory
      }
    | NUMBER { 
        std::cout << "Number: " << $1 << std::endl; 
      }
;

%%

// Removed the main function from here

// Define the yyerror function
void yyerror(const char* s) {
    std::cerr << "Error: " << s << std::endl;
}
