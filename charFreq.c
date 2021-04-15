#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define debug if(0)

typedef struct node{
    char a;
    int freq;
    struct node* next;
}node;

node* init()
{
    return NULL;
}

node* add(node* head, char item, int freq)
{
    node* new_node = (node*) malloc(sizeof(node*));

    new_node->a = item;
    new_node->freq = freq;
    new_node->next = head;

    return new_node;
}

void printer(node*head)
{
    while (head != NULL)
    {
        printf("%c %d\n", head->a, head->freq);
        head = head->next;
    }
}
node* search(node* head, char data)
{
    while (head != NULL)
    {
        if (head->a == data)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
int main()
{
    char str[1000];
    int i = 0;
    fgets(str,1000,stdin);
    int max = strlen(str);
    char* pch;
    int freq;
    node* lista = init();
    for (int i = 0; i < max  ; i++)
    {   
        freq = 0;
        char tmp = str[i];
        for (int j = 0; j < max; j++)
        {
            if (tmp == str[j])
            {
                freq++;
            }
        }
        debug printf("[%c] [%d]\n",str[i],freq);
        if (search(lista,tmp) == NULL)
        {
            lista = add(lista,tmp,freq);
        }        
    }
    printer(lista);
    return 0;
}
//TODO #2 criar uma maneira de ordenar a saida na ordem anti-alfabética