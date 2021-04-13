#include <stdio.h>
#include <stdlib.h>
//https://thehuxley.com/problem/261?quizId=6096
#define DEBUG if(0)
typedef struct node
{
    int item;
    struct node *next;
}NODE;


NODE* create_list()
{
    return NULL;
}

NODE* add(NODE* head, int item)
{
    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    new_node->item = item;
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
int belongs(NODE* head1, NODE* head2, int size1, int size2)
{
    int reps = 0;
    DEBUG printf("vou começar o while\n");
    DEBUG printf("%p\n",(void*)&head2);
    while (head2 != NULL)
    { 
        DEBUG printf("[%d]\n", head2->item);
        NODE* temp = search(head1,head2->item);
        DEBUG printf("ainda to no while\n");
        if (temp!=NULL) reps++;
        head2 = head2->next;  
    }
    DEBUG printf("acabou o while, vou ver se encontrei a quantidade certa de repetições\n");
    if(reps == size2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int size1,size2;
    scanf("%d", &size1); 
    NODE* lista1 = create_list(); //nó que aponta para nulo
    NODE* lista2 = create_list(); //nó que aponta para nulo
    for (int i = 0; i < size1; i++)
    {
        int n;
        scanf("%d", &n);
        lista1 = add(lista1,n); //fazemos lista1 receber o retorno de add(lista1,n), quando ele recebe esse valor, atualizamos a cabeça da lista!
    }
    scanf("%d",&size2);
    for (int i = 0; i < size2; i++)
    {
        int n;
        scanf("%d", &n);
        lista2 = add(lista2,n); 
    }
    //printer(lista2);
    DEBUG {printf("Agora que peguei os números, vou fazer a comparação:\n");}
    int ans = belongs(lista1,lista2,size1,size2);
    printf("%d\n",ans);
    return 0;
}