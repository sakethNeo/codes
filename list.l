
%{
#include <iostream>

#define OPEN 1
#define OPERATOR 2
#define NUM 3
#define VAR 4
#define CLOSE 5

int yylex(void);
%}

space	[ \t\n]
spaces	{space}+
digit	[0-9]
digits	-?{digit}+
frac	\.{digits}
expt	[Ee][+-]?{digits}
number	{digits}{frac}?{expt}?
comments %.*
chars	[a-zA-Z]+
ID     [a-zA-Z][a-zA-Z0-9]*
anythingElse .


%%

"+"          { return OPERATOR; }
"-"          { return OPERATOR;}
"*"          { return OPERATOR; }
"/"          { return OPERATOR; }
"%"          { return OPERATOR; }
"("          { return OPEN; }
")"          { return CLOSE; }
{digits}      { return NUM; }
{ID}         { return VAR; }
{spaces}    { /* Ignore whitespace */ }

{anythingElse}    { }

%%


int yywrap(void){
    return 1;
}
