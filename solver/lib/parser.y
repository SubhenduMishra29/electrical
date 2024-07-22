%{
#include <iostream>
#include <cstdlib>
void yyerror(const char* s);
extern int yylex();
%}

%union {
    std::string* str;
    int num;
}

%token <str> IDENTIFIER
%token <num> NUMBER
%token GRID LINE

%%

input:
    | input line
    ;

line:
    GRID IDENTIFIER '\n' {
        std::cout << "Grid: " << *($2) << std::endl;
        delete $2;
    }
    ;

%%

void yyerror(const char* s) {
    std::cerr << "Error: " << s << std::endl;
    exit(1);
}
