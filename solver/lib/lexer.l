%{
#include <iostream>
#include <cstdlib>
#include "parser.tab.hpp"
#include <string>

extern YYSTYPE yylval; // Assuming yylval is defined in the Bison parser as YYSTYPE.
%}

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER [0-9]+
GRID "GRID"
LINE "LINE"

%%

{GRID} { 
    return GRID; 
}

{LINE} { 
    return LINE; 
}

{NUMBER} { 
    yylval.num = std::atoi(yytext); 
    return NUMBER; 
}

{IDENTIFIER} { 
    yylval.str = new std::string(yytext); 
    return IDENTIFIER; 
}

[ \t\r]+ { /* Ignore whitespace */ }

\n { /* Ignore newlines */ }

. { /* Ignore other characters */ }

%%

int yywrap() {
    return 1;
}
