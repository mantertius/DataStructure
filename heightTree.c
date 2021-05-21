//https://www.thehuxley.com/problem/547
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
// void preOrder(binaryTree* bt,int num[], int *count, char out[])
// {   
//     char buffer[30];
//     if (!(isEmpty(bt)))
//     {
//         //sprintf gets what would be printed 
//         int n = sprintf(buffer, "(%d", bt->data);
//         strcat(out,buffer);
//         //adds bt->data to num[]

//         num[*count] = bt->data;
//         *count += 1;
        
//         preOrder(bt->left,num,count,out);
//         preOrder(bt->right,num,count,out);
    
//         //cleans buffer and adds ) to out[]
//         memset(buffer,0,strlen(buffer));
//         sprintf(buffer,")");
//         strcat(out,buffer);
//         memset(buffer,0,strlen(buffer));
//     }
//     else
//     {
//         //cleans buffer and adds () to out[]
//         sprintf(buffer,"()");
//         strcat(out,buffer);
//     }  
// }
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
    //gets the input: numbers and symbols
    char input[10000];
    int numberToBeFound; 
    int t = 0; 
    while (scanf("%c",&input[t]) != EOF)
    {
        if(input[t] == ' ') continue;
        if(input[t] == '\n') {input[t] = '\0'; break;}
        t++;
    }
    scanf("%d",&numberToBeFound);
    DEBUG printf("{{%s}}\n",input);
    DEBUG printf("a procura de [%d]\n",numberToBeFound);
   
    //gets only the inputTree from the input
    int len = strlen(input);        //lenght of the input
    int numOfValues = 0;            //number of ints in the input
    int inputTree[len];             //the tree from the input in the int form
    char *ptr = input;              //creates a auxiliary ptr to transverse the string
    while (*ptr) { 
        if (isdigit(*ptr)) {                        //if string + x is digit 
            long val = strtol(ptr, &ptr, 10);       //transforms the characters from string into base10 ints. 
            DEBUG printf("%ld\n", val);
            inputTree[numOfValues] = val;
            numOfValues++; 
        } else { 
            ptr++; 
        } 
    }

    //creates a binaryTree from scratch using the input from user
    int i = 0;                  //uses i for creating the tree
    binaryTree* bT = iniT();    //initiliazes the binaryTree that will be right constructed.
    while (i < numOfValues)
    {
        bT = add(inputTree[i],bT);  
        i++;
    }

    // //gets an array formed by the rightTree in the preOrder variation
    // int rightTree[10000];                   //its the tree! (the right one :D in the int format)
    // int ptr2 = 0;                           //auxiliary pointer to initialize preOrder
    // char output[10000];                     //its the tree! (the right one :D in the char format)
    // preOrder(bT,rightTree,&ptr2,output);
    // DEBUG printf("[%s]\n",output);
    
    binaryTree* targetFound = search(bT,numberToBeFound);
    if(targetFound == NULL) printf("NAO ESTA NA ARVORE\n-1\n");
    else{
        printf("ESTA NA ARVORE\n");
        printf("%d\n",height(bT) - height(targetFound));
    }
    return 0;
}


/*
    //gets an array formed by the rightTree in the preOrder variation
    int rightTree[10000];                   //its the tree! (the right one :D in the int format)
    int ptr2 = 0;                           //auxiliary pointer to initialize preOrder
    char output[10000];                     //its the tree! (the right one :D in the char format)
    preOrder(bT,rightTree,&ptr2,output);
    int flag = 0;

    //compares both trees, if they are equal, it is valid.
    for (int i = 0; i < numOfValues; i++)   //checks for the preOrder value print order
    {
        if(rightTree[i] != inputTree[i])
        {
            flag += 1;
            break;
        }
    }
    int flag2 = strcmp(input,output);       //checks for the preOrder print with the parenthesis as another reference.
    if (flag != 0 || flag2 != 0)
    {
        printf("FALSO\n");
        return 0;
    }
    printf("VERDADEIRO\n");
*/

