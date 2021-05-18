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
    NODE* pos; //auxiliary node* that points to head
    NODE* tmp = NULL;
    int flag = 0; //flag will switch to 1 while it's making swaps
    do
    {
        pos = list->head;//set the position to head.
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
        tmp = tmp->next;   
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
    for (int i = 0; i < count; i++)
    {
        tmp = a[i];
        for (int j = 0; j < count; j++)
        {
            DEBUG printf("OI [%d]\n", j);
            if (tmp == b[j])
            {  
                if (tmp == last) continue;
                if(i != 0 && tmp == last) continue;
                sort[t] = tmp;
                last = tmp;
                t++;
                flag++;
            }
        } 
    }
    DEBUG printf("XAU\n");
    if (flag == 0) return false;
    for (int i = 0; i < t; i++)
    {
        tmp = sort[i];
        DEBUG printf("tMP = [%d]\n", tmp);
        if (search(list, tmp) && i != 0)
        {
            continue;
        }
        add(list,sort[i]);
    }
    return true;    
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
        DEBUG printf("a[%d] = %d\n",i,n); 
    }
    for (int i = 0; i < count; i++)
    {
        scanf("%d",&n);
        b[i] = n;
        DEBUG printf("b[%d] = %d\n",i,n); 
    }
    DEBUG printf("CADE CADE VAI PRO COMPARADOR OU NAO\n");
    n = comparator(a,b,head);
    if(!n) {printf("VAZIO\n");return 0;} 
    bubbleSort(head);
    if (n) printer(head);
    else 
    return 0;
}