%{
#include <iostream>
#include <cstdlib>
#include "parser.tab.hpp"
#include <string>

// Declare yylval to be used for passing values from the lexer to the parser
extern YYSTYPE yylval;
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
