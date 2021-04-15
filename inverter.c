//https://thehuxley.com/problem/264?quizId=6096
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG if(1)
typedef struct node
{
    int data;
    struct node* previous;
    struct node* next;
}Node;

Node* init()
{
    return NULL;
}

int isEmpty(Node* head)
{
    return (head == NULL);
}

Node* add(Node* head, int data) //insere na cabeça, sempre :)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
   
    new_node->data = data;
    new_node->next = head;
    new_node->previous = NULL;           //como o novo nó sempre vai estar na cabeça, seu anterior é sempre nulo!
    
    if (head != NULL)
    {
        head->previous = new_node;
    }
    return new_node;   
}

void printer(Node* head, int fluxo)
{
    if (fluxo == 1)
    {
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

Node* getLastNode(Node* node)
{
    if(node==NULL)
    {
        return NULL;
    }
    else if(node->next ==NULL)
    {
        return node;
    }
    else
    {
        return getLastNode(node->next);
    } 
}

int main()
{
    int n;
    Node* lista = init();
    Node* tail;
    int i = 0;
    while (scanf("%d",&n) != EOF)
    {
        lista = add(lista,n);
        //DEBUG printf("Elemento %d adicionado\n",n);
    }
    //DEBUG printf("Começando a imprimir a lista normal!\n");
    printer(lista,1);//fluxo normal
    //DEBUG printf("Começando a imprimir a lista reversa!\n");
    //printer(lista,-1);//fluxo reverso

}