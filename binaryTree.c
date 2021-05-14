#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct _Node* left;
    struct _Node* right;
}Node;
typedef struct _binaryTree
{
    int height;
    Node* root;
}binaryTree;

binaryTree* iniT()
{
    binaryTree* newTree = (binaryTree*) malloc(sizeof(binaryTree));
    newTree->height = 0;
    newTree->root = NULL;
    return newTree;
}
void left(int value)
{

}
void right(int value)
{

}
void add(int value, binaryTree* rootz)
{
    if (rootz->height == 0)
    {
        addRoot(value,rootz);
    }
    
    rootz->height++;
}
int main()
{
    int n;
    binaryTree* bT = iniT();
    while (scanf("%d",&n) != EOF)
    {
        printf("----\nAdicionando %d\n",n);
        add(n,bT);
        printTree();

    }   
    return 0;
}