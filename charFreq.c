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
    char str[1000]; //input
    int i = 0;
    fgets(str,1000,stdin);
    int max = strlen(str); //tamanho da string input
    char* pch;
    int freq;
    
    node* lista = init();

    int ch[256] = {0}; //index == ascii, value == freq
    
    for (int i = 0; i < 256 ; i++)
    {   
        freq = 0;
        char tmp = i; //str[i] = 'a' 
        for (int j = 0; j < max; j++)
        {

            if (tmp == str[j])
            {
                freq++;
            }
        }// 
        ch[i] = freq;
        debug printf("[%c] [%d]\n",(char)i,freq);
        // if (ch[(int)str[i]] == 0) //adds frequency values to the correspondent ascii index 
        // {
        //     //TODO #3 it's not computing the char ' ' or ',' or '.'
        //     ch[(int)str[i]] = freq;
        //     debug printf("\t\tch[%d] = %d\n",(int)str[i],ch[(int)str[i]]);
        // } 
    }
    
    for (int aux = 0; aux < 256 ; aux++)
    {
         
        if (ch[aux] > 0)
        {
            lista = add(lista,(char)aux,ch[aux]);
        }
            
    }
    printer(lista);
    return 0;
}