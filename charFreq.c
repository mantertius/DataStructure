#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define debug if(1)

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

void printer(node* head)
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

    int ch[256]; //index == ascii, value == freq

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
        if (ch[(int)str[i]] == 0) //adds frequency values to the correspondent ascii index 
        {
            //TODO #3 it's not computing the char ' ' or ',' or '.'
            ch[(int)str[i]] = freq;
            debug printf("\t\tch[%d] = %d\n",(int)str[i],ch[(int)str[i]]);
        }
                
    }
    
    for (int aux = 0; aux < max ; aux++)
    {
        if (ch[str[aux]] != 0)
        {
           lista = add(lista,(char)aux,freq);
        }
            
    }
    printer(lista);
    return 0;
}
//TODO #2 criar uma maneira de ordenar a saida na ordem anti-alfabética