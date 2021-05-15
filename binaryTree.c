#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//https://thehuxley.com/problem/783?quizId=6236
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
void preOrder(binaryTree* bt)
{
    if (!(isEmpty(bt)))
    {
        printf(" ( %d ",bt->data);
        preOrder(bt->left);
        preOrder(bt->right);
        //printf(") ");
        printf(") ");

    }
    else
    {
        printf(" () ");
    }
    
    
}
int main()
{
    int n;
    binaryTree* bT = iniT();
    while (scanf("%d",&n) != EOF)
    {
        printf("----\nAdicionando %d\n",n);
        bT = add(n,bT);
        printf("  ");
        preOrder(bT);
        printf("\n");
    }
    printf("----\n");   
    return 0;
}