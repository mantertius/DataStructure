#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char c[50];
    int d; 
    scanf("%s",c);
    int len = strlen(c);
    for (int i = 0; i < len; i++)
    {
        d = atoi(c) - 65;
    }
    printf("%d",d);
	return 0;
}