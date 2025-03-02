%{
#include <iostream>
#include <cstring>

struct Element {
    char identifier[1005];
    int occurrences;
};

Element cmdList[1005];
Element envList[1005];
int cmdCount = 0;
int envCount = 0;
int inlineMathCount = 0;
int displayMathCount = 0;

void addToTable(Element list[], int &count, const char *identifier) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(list[i].identifier, identifier) == 0) {
            list[i].occurrences++;
            return;
        }
    }
    if (count < 1005) {
        strncpy(list[count].identifier, identifier, 1004);
        list[count].identifier[1004] = '\0';
        list[count].occurrences = 1;
        count++;
    }
}
%}

%x INLINE_MATH
%x DISPLAY_MATH
%%

\\([a-zA-Z]+) {
    addToTable(cmdList, cmdCount, yytext + 1);
}

\\([^\na-zA-Z]) {
    if (yytext[1] == '~') {
        addToTable(cmdList, cmdCount, "~");
    }
    addToTable(cmdList, cmdCount, yytext);
}

\\begin\{([a-zA-Z][a-zA-Z0-9]*)\} {
    addToTable(envList, envCount, yytext + 7);
}

\\end\{([a-zA-Z][a-zA-Z0-9]*)\} {
    addToTable(envList, envCount, yytext + 5);
}

\$\$[^$]*\$\$ {
    displayMathCount++;
    BEGIN(DISPLAY_MATH);
}

\$\([^$]*\$\) {
    inlineMathCount++;
    BEGIN(INLINE_MATH);
}

<INLINE_MATH>\\([a-zA-Z]+) {
    addToTable(cmdList, cmdCount, yytext + 1);
}

<INLINE_MATH>\\([^\n\\]) {
    if (yytext[1] == '~') {
        addToTable(cmdList, cmdCount, "~");
    } else {
        addToTable(cmdList, cmdCount, yytext);
    }
}

<DISPLAY_MATH>\\([a-zA-Z]+) {
    addToTable(cmdList, cmdCount, yytext + 1);
}

<DISPLAY_MATH>\\([^\n\\]) {
    if (yytext[1] == '~') {
        addToTable(cmdList, cmdCount, "~");
    } else {
        addToTable(cmdList, cmdCount, yytext);
    }
}

%[^\n]* {
    // Ignore line
}

.|\n {
    // Ignore character
}

%%

int yywrap() {
    return 1;
}
