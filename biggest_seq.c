#include <stdio.h>
#include <stdlib.h>
//https://thehuxley.com/problem/261?quizId=6096
#define DEBUG if(0)
#define MAX 100001
typedef struct node
{
    char item;
    struct node *next;
}NODE;

NODE* create_list()
{
    return NULL;
}

NODE* add(NODE* head, char item[])
{
    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    strcpy();
    new_node->next = head;  
    DEBUG printf("[[[%d]]]\t",new_node->item);
    return new_node;
}

int is_empty(NODE* head)
{return(head == NULL);}

void printer(NODE* head)
{   
    if(head == NULL) {printf("Lista vazia!\n");}
    while (head != NULL)
    {
        printf("[%d]",head->item);
        head = head->next;
    }
    printf("Fim da Lista!\n");
}

NODE* search(NODE* head, int item)
{
    DEBUG printf("to dentro do search\n");
    while (head != NULL)
    {
        if (head->item == item)
        {
            DEBUG printf("ENCONTREI MAIS UM!!! [%d]\n", item);
            return head;//retorna o endereço que contém o item
        }
        head = head->next;
    }
    return NULL;
}

int main()
{
    char input[MAX];
    int p = scanf("%s", input); 
    NODE* lista1 = create_list(); //nó que aponta para nulo
    while (p != EOF)
    {
        lista1 = add(lista1,input);
    }
    


    return 0;
}