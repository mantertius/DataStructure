//https://thehuxley.com/problem/862/oracle?quizId=6096
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if (1)
#define MAX 100001
typedef struct node
{
    char item;
    struct node *next;
} NODE;

NODE *  create_list()
{
    return NULL;
}

NODE *add(NODE *head, char item)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->item = item;
    new_node->next = head;
    //DEBUG printf("adicionado[[[%d]]]\t",new_node->item);
    return new_node;
}

int is_empty(NODE *head)
{
    return (head == NULL);
}

void printer(NODE *head)
{
    if (head == NULL)
    {
        printf("Lista vazia!\n");
    }
    while (head != NULL)
    {
        printf("[%d]", head->item);
        head = head->next;
    }
    printf("Fim da Lista!\n");
}

NODE *search(NODE *head, int item)
{
    // printf("to dentro do search\n");
    while (head != NULL)
    {
        if (head->item == item)
        {
            // printf("ENCONTREI MAIS UM!!! [%d]\n", item);
            return head; //retorna o endereço que contém o item
        }
        head = head->next;
    }
    return NULL;
}

int search_2(NODE *head, int item)//função para procurar a melhor sequencia
{
    int count = 0;
    while (head != NULL)
    {
        if (head->item == item)
        {
            // printf("ENCONTREI MAIS UM!!! [%d]\n", item);
            return count; //retorna o endereço que contém o item
        }
        head = head->next;
        count++;
    }
    return 0;
}

void func(NODE *head, int size, int beg, int end)
{
    NODE* first_zero = search(head,0);//recebo o endereço do primeiro zero.
    beg = search_2(head,0);
    int size1 = search_2(first_zero,1); //a partir do endereço do primeiro zero, procuro o proximo 1 e recebo o tamanho deste intervalo
    end = size1
    if(first_zero == NULL)//break
    {
        printf("0 0\n");
        return;
    }
    NODE* first_one = search(first_zero, 1);
}
int main()
{
    char input[MAX];
    scanf("%s", input);
    int q = strlen(input);
    NODE *lista1 = create_list(); //nó que aponta para nulo

    for (int i = 0; i < q; i++)
    {
        lista1 = add(lista1, input[i]);
        
    }

    func(lista1);  
    do
    {
        scanf("%s", input);
        int q = strlen(input);
        
        for (int i = 0; i < q; i++)
        {
            lista1 = add(lista1, input[i]);
        }
    } while (1);


    return 0;
}