#include<stdio.h>
#include<string.h>
int EXPANDING = 0; 
char a[50], b[50], c[50];
FILE *input, *expanded, *namtab, *deftab;
int macroSearch(char a[100]){
FILE *macro;
macro = fopen("NAMTAB.txt","r");
char e[100], temp[100], op[5];
temp[0] = '\0';
fscanf(macro,"%s", e);
while( strcmp(temp,e) != 0 ){
strcpy(temp,e);
if(strcmp(e, a) == 0){
fclose(macro);
return 1;
}
fscanf(macro,"%s", e);
}
fclose(macro);
return 0;
}
void substituteArguments() {
if(strcmp(c, "=X'?1'") == 0) {
strcpy(c, "='F1'");
} else if(strcmp(c, "?2,X") == 0) {
strcpy(c, "BUFFER,X");
} else if(strcmp(c, "?3") == 0) {
strcpy(c, "LENGTH");
}
}
void getLine() {
if(EXPANDING == 1) {
fscanf(deftab, "%s %s %s", a, b, c);
substituteArguments();
} else {
fscanf(input, "%s %s %s", a, b, c);
}
}
void define() {
fprintf(namtab, "%s\n", a);
while(strcmp(b, "MEND") != 0) {
fscanf(input, "%s %s %s", a, b, c);
}
}
void expand() {
EXPANDING = 1;
fprintf(expanded, ". %s %s\n", b, c);
getLine();
while(strcmp(b, "MACRO") != 0) {
getLine();
}
getLine();
while(strcmp(b, "MEND") != 0) {
fprintf(expanded, "%s %s %s\n", a, b, c);
getLine();
}
EXPANDING = 0;
}
void processLine() {
int tempInt = macroSearch(b);
}
if(tempInt == 1) {
expand();
} else if(strcmp(b, "MACRO") == 0) {
define();
} else {
fprintf(expanded, "%s %s %s\n", a, b, c);
}
int main() {
input = fopen("input.txt", "r");
expanded = fopen("expanded.txt", "w");
deftab = fopen("DEFTAB.txt", "r");
namtab = fopen("NAMTAB.txt", "r");
fscanf(input, "%s %s %s", a, b, c);
fprintf(expanded, "%s %s %s\n", a, b, c);
while(strcmp(b, "END") != 0) {
getLine();
processLine();
}
return 0;
}