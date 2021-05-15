#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
 
int main() 
{ 
    int h = 30;
    char buffer[30];
    char out[30] = "O resultado é";
    int n = sprintf(buffer, "(%d", h);
    strcat(out,buffer);
    printf("%s %s",out, buffer);
    return 0; 
}