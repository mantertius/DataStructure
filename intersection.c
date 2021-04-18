#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DEBUG if(0)
typedef struct node
{
    int data;
    struct node* next;
}NODE;

typedef struct head
{
    int size;
    NODE* head;
    NODE* tail;
}LIST;

LIST* init_list()
{   
    LIST* new_head = (LIST*) malloc(sizeof(LIST));
    new_head->head = NULL;
    new_head->size = 0;
    return new_head;
}
int compar (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
void add(LIST* list, int data)
{
    NODE* new_head = (NODE*) malloc(sizeof(NODE));
    new_head->next = list->head;
    new_head->data = data;
    DEBUG printf("\t[%d]\n",new_head->data);
    list->head = new_head;
    list->size++;
}
void bubbleSort(LIST* list)
{
    NODE* pos; //set the position to head.
    NODE* tmp = NULL;
    int flag = 0; //flag will switch to 1 while it's making swaps
    do
    {
        pos = list->head;
        flag = 0;

        while (pos->next != tmp)
        {
            if (pos->data > pos->next->data)
            {
                DEBUG printf("%d > %d\n",pos->data , pos->next->data);
                int t = pos->data;
                pos->data = pos->next->data;
                pos->next->data = t;
                flag = 1; 
            }
            pos = pos->next;
        }
        tmp = pos; //stores the last pos 'cus it's already been sorted.
    } while (flag);
    
}
bool search(LIST* list, int target)
{
    NODE* tmp = list->head;
    while (tmp != NULL)
    {
        if(tmp->data == target)
        {
            return true;
        }   
    }
    return false;
}
bool comparator(int* a, int* b, LIST* list) //gets two arrays and adds to the list
{
    int count = 20;
    int sort[20];
    int flag = 0; 
    int tmp;
    int t = 0;
    int last = 468468486;
    DEBUG printf("OI\n");
    for (int i = 0; i < count; i++)
    {
        tmp = a[i];
        //DEBUG printf("###### a[%d] = %d #######\n",i, a[i]);
        for (int j = 0; j < count; j++)
        {
            //DEBUG printf("tmp = %d e b[%d] = %d\n", tmp, j, b[j]);
            if (tmp == b[j])
            {  
                //DEBUG printf("Elemento [%d] adicionado.\n", tmp);
               /* if (search(list, tmp))
                {
                    continue;
                }
                add(list, tmp);
                 
                */
                if (tmp == last)
                {
                    continue;
                }
                
                if(i != 0 && tmp == last) continue;
                sort[t] = tmp;
                last = tmp;
                t++;
                flag++;
            }
        } 
    }

    //qsort(sort,t,sizeof(int), compar);
    for (int i = 0; i < t; i++)
    {
        add(list,sort[i]);
    }
    
    if (flag > 0)
    {
        return true;
    }
    return false;
    
        
}
void printer(LIST* head)
{
    NODE* tmp = head->head;
    while (tmp != NULL)
    {
        printf("%d\n",tmp->data);
        tmp = tmp->next;    
    }
    
}
int main()
{   
    int count = 20;
    int n;
    int a[count];
    int b[count];
    LIST* head = init_list();
    for (int i = 0; i < count; i++)
    {   
        scanf("%d",&n);
        a[i] = n; 
    }
    for (int i = 0; i < count; i++)
    {
        scanf("%d",&n);
        b[i] = n; 
    }
    n = comparator(a,b,head);
    bubbleSort(head);
    if (n) printer(head);
    else printf("VAZIO\n");
}