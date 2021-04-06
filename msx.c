#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 75
//https://thehuxley.com/problem/13?quizId=6095
/*Within software engineering, programming (the implementation)
is regarded as one phase in a software development process.
There is an ongoing debate on the extent to which the writing
of programs is an art, a craft or an engineering discipline.
the end!

*/

void get_string()
{
    //printf("####################################\n");
    char a[MAX];
    char end[] = "the end!";
    char end2[] = "the end! ";
    char end3[] = "the end!\n";


    void* p = fgets(a,75,stdin);
    //printf("tamanho do string:[%ld]\n",strlen(a));
    //printf("INPUT: %s",a);
    int ret = strcmp(a,end);
    int ret2 = strcmp(a,end2);
    int ret3 = strcmp(a,end3);

    //printf("resultado strncmp:[%d]\t",ret);

    if(ret == 0 || ret2 == 0 || p == NULL || ret3 == 0)
    {
        //printf("\n");
        return;
    }
    
    int size = strlen(a);
    //printf("SIZE: %d\t",size);

        int i=0;
        while (i<size)
        {
            char c;
            c = a[i];
            printf("%c",toupper(c));
            i++;
        }
        
        //printf("\n");
    
    return get_string();
}
int main()
{
    get_string();
    return 0;
}