#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    for (int i = 0; i < 30; i++)
    {
        printf("%d ",rand()%1000);
    }
	return 0;
}