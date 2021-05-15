//https://thehuxley.com/problem/546?quizId=6236
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define DEBUG if(0)
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}binaryTree;

binaryTree* iniT()
{
    return NULL;
}
binaryTree* createBinTree(int item, binaryTree* left, binaryTree* right)
{
    binaryTree* new = (binaryTree*) malloc(sizeof(binaryTree));
    new->data = item;
    new->left = left;
    new->right = right;
    return new;
}
binaryTree* add(int item, binaryTree* bt)
{
    if (bt == NULL)
    {
        bt = createBinTree(item,NULL,NULL);
    }
    else if (item < bt->data) //11>2
    {
        bt->left = add(item, bt->left);
    }
    else 
    {
        bt->right = add(item, bt->right);
    }
    return bt;
}
int isEmpty(binaryTree* bt)
{
    return (bt == NULL);
}
void preOrder(binaryTree* bt,int num[], int *count, char out[])
{   
    char buffer[30];
    if (!(isEmpty(bt)))
    {
        //sprintf pega o que imprimiria se fosse printf e salva no buffer
        int n = sprintf(buffer, "(%d", bt->data);
        strcat(out,buffer);
        //adiciona bt->data ao num[]

        num[*count] = bt->data;
        *count += 1;
        
        preOrder(bt->left,num,count,out);
        preOrder(bt->right,num,count,out);
    
        //zera buffer e adiciona ) a out[]
        memset(buffer,0,strlen(buffer));
        sprintf(buffer,")");
        strcat(out,buffer);
        memset(buffer,0,strlen(buffer));
    }
    else
    {
        //zera buffer e adiciona () a out[]
        sprintf(buffer,"()");
        strcat(out,buffer);
    }  
}
int main()
{
    
    //gets the input: numbers and symbols
    char input[10000]; //gets(input);
    int t = 0; 
    while (scanf("%c",&input[t]) != EOF)
    {
        if(input[t] == ' ') continue;
        t++;
    }
    DEBUG printf("%s",input);
    
    int len = strlen(input), numOfValues = 0;
    int inputTree[len];
   
    //gets only the inputTree from the input
    char *ptr = input;
    while (*ptr) { 
        if (isdigit(*ptr)) { 
            long val = strtol(ptr, &ptr, 10); 
            DEBUG printf("%ld\n", val);
            inputTree[numOfValues] = val;
            numOfValues++; 
        } else { 
            ptr++; 
        } 
    }
    //creates a binaryTree from scratch
    //uses i for creating the tree
    int i = 0;
    binaryTree* bT = iniT();
    while (i < numOfValues)
    {
        bT = add(inputTree[i],bT);
        i++;
    }
    //gets an array formed by the rightTree in the preOrder variation
    int rightTree[10000];
    int ptr2 = 0;
    char output[10000];
    preOrder(bT,rightTree,&ptr2,output);

    int flag = 0;
    //compares both trees, if they are equal, it is valid.
    DEBUG printf("INPUT = {%s}\n",input);
    DEBUG printf("OUTPUT = {%s}\n",output);
    //checks for the preOrder value print order
    for (int i = 0; i < numOfValues; i++)
    {
        if(rightTree[i] != inputTree[i])
        {
            flag += 1;
            break;
        }
    }
    //checks for the preOrder print with the parenthesis as another reference.
    int flag2 = strcmp(input,output);

    if (flag != 0 || flag2 != 0)
    {
        printf("FALSO\n");
        return 0;
    }
    printf("VERDADEIRO\n");
    return 0;
}