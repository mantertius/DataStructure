#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if(1)
#define MAX 100001
/*
01100010
10000001
11111111
00000000
10101010
0
*/
typedef struct node
{
    char item;
    int pos;
    struct node* next;
}NODE;

typedef struct head
{
    int size;
    NODE* head;
}LIST;

LIST* initList()
{
    LIST* new_list = (LIST*) malloc(sizeof(LIST));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

int is_empty(NODE *head)
{
    return (head == NULL);
}

void add(LIST *head, char item, int posi)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->item = item;
    new_node->next = head->head;
    
    new_node->pos = posi;
    
    head->head = new_node;
    head->size++;
    //DEBUG printf("adicionado[[[%d]]]\t",new_node->item);
    //DEBUG printf("Posição adicionada: %d\n",new_node->pos);
    return;
}
NODE* search(NODE* list, char target)
{
    NODE* tmp = list;
    while (tmp != NULL)
    {
        if(tmp->item == target)
        {
            return tmp;
        }
        tmp = tmp->next;   
    }
    return NULL;
}

void bestSeq(LIST* list, int len)
{
    NODE* tmp = list->head;
    int size = 0;
    int pos1 = 0;
    int pos2 = 0;
    int Bpos1 = 0;
    int Bpos2 = 0;
    int Bsize = 0;
    int flag = 0;
    
    do
    {
        tmp = search(tmp,'0');
        if (tmp == NULL) break;
        else pos1 = tmp->pos;
        DEBUG printf("pos1 = [%d]\t",pos1);


        tmp = search(tmp,'1');
        if (tmp == NULL) 
        {
            pos2 = len-1;
            // size = pos2 - pos1;
            // if (size > Bsize)
            // {
            //     Bsize = size;
            //     Bpos1 = pos1;
            //     Bpos2 = pos2;
            // }
            // if (size == Bsize && flag == 0)
            // {
            //     Bpos1 = pos1;
            //     Bpos2 = pos2;
            //     flag = 1;
                 DEBUG printf("----------------:\n");
            // }
            break;
        }
        else pos2 = tmp->pos-1;
        DEBUG printf("tmp->pos = [%d]  ", tmp->pos);
        DEBUG printf("pos2 = [%d]\t",pos2);
        if(pos2<0) break;

        size = pos2 - pos1;
        DEBUG printf("size = [%d]\n", size);
        if (size > Bsize)
        {
            Bsize = size;
            Bpos1 = pos1;
            Bpos2 = pos2;
        }
        if (size == Bsize && flag == 0)
        {
            Bpos1 = pos1;
            Bpos2 = pos2;
            flag = 1;
            DEBUG printf("este caso:\n");
        }
        else if (size == Bsize)
        {
            continue;
        }
        
        
        

        tmp = tmp->next;
    } while (1);
    
    printf("%d %d\n", Bpos1, Bpos2);
    return;
}
void printer(LIST *list)
{
    NODE* head = list->head;
    if (head == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    while (head != NULL)
    {
        printf("[%c]", head->item);
        head = head->next;
    }
    printf("\nFim da Lista!\n");
    return;
}   
void inverter (LIST* stack)
{
    NODE* current = stack->head;
    NODE* next = NULL;
    NODE* prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    stack->head = prev;
    return;
}
void delete (NODE *head)
{
    NODE* p, *store;
    p = head;
    while (p != NULL)
    {
        store = p->next;
        free(p);
        p=store;
    }
    
}

int main()
{
    char input[MAX] = {};
    LIST *lista1 = initList();
    int q = 0;
    DEBUG printf("começou a lista\n"); 
    do
    {
        scanf("%s", input);
        q = strlen(input);
        DEBUG printf("[%s]\n",input);
        if(q == 1 && input[0] == '0') break;
        for (int i = q-1; i >= 0 ; i--)
        {
            //DEBUG printf("Adicionado [%c].\n",input[i]);
            if(input[i] == '\n') continue;
            add(lista1, input[i],i); 
        }
       bestSeq(lista1, q);
       //delete(lista1->head);  
       DEBUG printf("Sucesso!\n\n");
    } while (1);
    //inverter(lista1);
    //printer(lista1);
    

    return 0;
}