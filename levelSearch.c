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
    int height;
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
    new->height = 0;
    return new; 
}
int max (int a, int b)
{
    return (a>b) ? a : b;
}
int height (binaryTree* bt)
{
    if (bt == NULL) return -1;
    else{
    return 1 + max(height(bt->left),height(bt->right));
    }
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

    bt->height = height(bt);
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
        //sprintf gets what would be printed 
        int n = sprintf(buffer, "(%d", bt->data);
        strcat(out,buffer);
        //adds bt->data to num[]

        num[*count] = bt->data;
        *count += 1;
        
        preOrder(bt->left,num,count,out);
        preOrder(bt->right,num,count,out);
    
        //cleans buffer and adds ) to out[]
        memset(buffer,0,strlen(buffer));
        sprintf(buffer,")");
        strcat(out,buffer);
        memset(buffer,0,strlen(buffer));
    }
    else
    {
        //cleans buffer and adds () to out[]
        sprintf(buffer,"()");
        strcat(out,buffer);
    }  
}
binaryTree* search(binaryTree* root, int target)
{
    if (root == NULL || root->data == target)
    {
        DEBUG printf("-- %d --\n",root->data);
        return root;
    }
    else if (root->data > target)
    {
        return search(root->left,target);
    }
    else
    {
        return search(root->right,target);
    }
}
int main()
{
    int linesOfInput;
    scanf("%d",&linesOfInput);
    binaryTree* bT = iniT();
    int listOfValuesOfNodes[linesOfInput];
    int 
    for (int i = 0; i < linesOfInput; i++)
    {
        int valueOfiNode, left, right;
        scanf("%d",&valueOfiNode);
        scanf("%d",&left);
        scanf("%d",&right);
        bT = adde(i,value, left,right,bT);
    }
    
    return 0;
}