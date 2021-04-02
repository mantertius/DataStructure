#include <string.h>
//https://thehuxley.com/problem/2341?quizId=6095
#include <stdio.h>
int foo(int n)
{
    int ans = n-3;
    int tmp = n;
    int tmp2;
    while (tmp != 0)
    {
        tmp2 = tmp;
        tmp = tmp/10;
    }
    if(tmp2%2 == 0)
    {
        ans = n-4;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",foo(n));
    return 0;
}

