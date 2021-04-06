//https://thehuxley.com/problem/2070?quizId=6095
#include <stdio.h>
#include <string.h>

int foo (char arr[], int size)
{
    int ans = 0;    
    for (int i = 1; i < size+1; i++)
    {  
        int tmp = (int) arr[i] - '0';
        int p = 3;
        if (tmp%2 == 0)
        {
            p = 2;
        } 
        ans = ans + (tmp*(i)*p);
    }
    return ans;
}
void get_int()
{
    char n[9];
    int q = scanf("%s", n);
    if(n[0] == '0')
    {
        return;
    }
    int counter = strlen(n);
    char inverted[counter];
    for (int i = 0; i < counter+1; i++)
    {
        inverted[i] = n[counter-i];
    }
    printf("%d\n", foo(inverted,counter));
    get_int();
}
int main()
{
    get_int();
    return 0;   
}