//https://thehuxley.com/problem/266?quizId=6096
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG if (0)
#define MAX 100001

typedef struct node
{
    int item;
    struct node *next;
}NODE;

NODE *  create_list()
{
    return NULL;
}
NODE *add(NODE *head, int item)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->item = item;
    new_node->next = head;
    return new_node;
}
int is_empty(NODE *head)
{
    return (head == NULL);
}
NODE* bubbleSort(NODE* head, int num)
{
    NODE* pos;
    NODE* tmp = NULL;
    int swap,t; 
    
    if (is_empty(head))
    {
        return NULL;
    }
    
    do
    {
        DEBUG printf("COMEÇAAAAAAAAAAAAA\n");
        swap = 0;
        pos = head;
        
        // if (pos->next == NULL)
        // {
        //     printf("FIM\n");
        //     continue;
        // }
        DEBUG printf("o proximo nao é nulo\n");

        while(pos->next != tmp)
        {
            if(pos->item > pos->next->item)
            {
                //tmp = pos; // isso aqui copia os structs ou só copia os endereços?
               
                DEBUG printf("%d > %d\n",pos->item , pos->next->item);
                t = pos->item;
                pos->item = pos->next->item;
                pos->next->item = t;

                swap = 1;


                DEBUG printf("swap rolando \t");
            }
            pos = pos->next;
            DEBUG printf("analisando o proximo\n");   
        }
        tmp = pos;
    }while(swap);

    return pos;
}
void printer(NODE *head)
{
    if (head == NULL)
    {
        DEBUG printf("Lista vazia!\n");
    }
    while (head != NULL)
    {
        printf("[%d]->", head->item);
        head = head->next;
    }
    printf("\n");
    DEBUG printf("\nFim da Lista!\n");
}
int main()
{
    NODE* lista = create_list();
    int n;
    int i = 0;
    while (scanf("%d",&n)!= EOF)
    {
        lista = add(lista,n);
        DEBUG printf("Elemento %d adicionado\n",n);
        i++;
    }
    order(lista, i);
    //bubbleSort(lista);
    printer(lista);
    return 0;
}