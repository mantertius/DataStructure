#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//https://thehuxley.com/problem/316/code-editor/?quizId=6236
/*
Valor = (Posição no alfabeto) + (Elemento de entrada) + (Posição do elemento) 
Valor = %c - 48 + [numero da linha] + posição do elemento dentro do array de numero []
*/
#define DEBUG if(0)
int hash(char alphabet, int lineNum, int elemPos)
{
    if (alphabet == '\n') return 0;
    DEBUG printf("[%c] = %d\n",alphabet,(alphabet-65) + lineNum + elemPos);
    return (alphabet-65) + lineNum + elemPos;
}
int preHash(char input[], int lineNum, int lenght)
{
    int pass = 0;
    for (int i = 0; i < lenght; i++)
    {
        pass = pass + hash(input[i],lineNum,i);
    }
    DEBUG printf("line = [%d] | pass = [%d]\n",lineNum,pass);
    return pass; 
}
int function(int lines) //CBA 
{   int pass = 0, total = 0, len = 0;
    char input[51];
    getchar();
    for (int i = 0; i < lines; i++)
    {  
        DEBUG printf("#########################\n");
        gets(input);
        len = strlen(input);
        //if(input[len-1] != '\n') strcat(input,"\n");
        DEBUG printf("len = [%d]\n",len);
        DEBUG printf("LINHA %d = {%s}\n",i,input);
        total = preHash(input, i, len) + total;
        DEBUG printf("TOTAL = [%d]\n",total);
    }
    return total;
}
int main() {
    int cases, ans, lines;
    scanf("%d",&cases);
    for (int i = 0; i < cases; i++)
    {
        DEBUG printf("------------------------ CASO [%d] ---------------------\n",i+1);
        scanf("%d",&lines);
        DEBUG printf("lines = [%d]\n",lines);
        ans = function(lines);
        printf("%d\n",ans);
    }
    
	return 0;
}

// 5
// 2
// CBA
// DDD
// 1
// Z
// 6
// A
// B
// C
// D
// E
// F
// 6
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// 1
// ZZZZZZZZZZ
