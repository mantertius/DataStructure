#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int decomp(int n)//recebe um número para encontrar a raiz digital
{
    if (n == 1)
    {
        return 1;
    }
    if (n < 10 && n != 1)
    {
        //printf("RESPOSTA FINAL: %d\n",n);
        return n;
    }
    int p = (int) log10(n)+1; //descobre o tamnho de n 
    if (p>2)
    {
        printf("p = [%d]\t\t", p);
    }
    
        
    int ans = 0;
    for (int i = 1; i < p; i++)
    {
        ans = ans + n%(int)pow(10,i) + n/(int)pow(10,i);
        ans = n;
       while (ans>0)
       {
           int temp = 0;
           temp = 
           /* code */
       }
       
    }
        //printf("### resposta parcial: %d ###\n",ans);
        if (ans > 100)
        {   
            printf("!!!!!!!!!!!!!!!!!!!RETORNE -1\n");
            return -1;
        }
        
    return decomp(ans);
}

int get_roots(int jobs)
{
    if(jobs == 0)
    {
        return 0;
    }

    int counter = 1;
    int pos,target;
    scanf("%d", &pos);
    scanf("%d", &target);
    
    int ans = -1;
    for (ans = 1; counter < pos; ans++) //checa a decomposição de ans a cada iteração
    {
        int tmp = decomp(ans);
        if (tmp == target)
        {
            printf("raiz_digital[%d]= %d\n",counter, ans);
            counter = counter+1;
        }
    }
    printf("%d\n",ans-1);
    return get_roots(jobs-1);
}

int main()
{
    int jobs;
    scanf("%d",&jobs);
    get_roots(jobs);
    return 0;

}
