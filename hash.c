#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//https://thehuxley.com/problem/242?quizId=6236
#define DEBUG if(0)
typedef struct _node
{
    int data;
    struct _node* next;
}node;
typedef struct _list
{
    int size;
    node* tail;
    node* head;
}list;
typedef struct table
{
    list* tables[100];
}table;
int hashFunction(int value, int base)
{
    return value%base;
}
list* initList()
{
    list* new_list = (list*) malloc (sizeof(list));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}
table* initTable()
{
    table* newTable = (table*) malloc(sizeof(table));
    for (int i = 0; i < 100; i++)
    {
        newTable->tables[i] = initList();
    }
    return newTable;
}
void addListTail(list* lista, int value)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    if (lista->size == 0)
    {
        lista->head = new_node;
        lista->tail = new_node;
        lista->size++;
        return;
    }
    lista->tail->next = new_node;
    lista->tail = new_node;
    lista->size++;
}
void addHashed(table* ht, int value, int key)
{
    addListTail(ht->tables[key],value);
}
void get(int baseNum, int keysNum, table* ht)
{
    int value, key;
    for (int i = 0; i < keysNum; i++)
    {
        scanf("%d",&value);
        key = hashFunction(value,baseNum);
        addHashed(ht,value,key);
    }
}
void printao(list* list, int key)
{
    printf("%d -> ", key);
    node* tmp = list->head;
    while (tmp != NULL)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\\");
    printf("\n");
}
void print(table* ht, int keysNum)
{
    for (int i = 0; i < keysNum; i++)
    {
        printao(ht->tables[i],i);
    }
    printf("\n");
    
}
int main()
{
    int testNumber;
    scanf("%d",&testNumber);
    for (int i = 0; i < testNumber; i++)
    {
        DEBUG printf("----------- Caso de teste #%d ----------\n",i);
        int baseNumber, keysNumber;
        scanf("%d",&baseNumber);
        scanf("%d",&keysNumber);   
        DEBUG printf("Base = [%d], Chaves [%d]\n",baseNumber,keysNumber);
        table* ht = initTable(); 
        get(baseNumber,keysNumber,ht);
        print(ht,baseNumber);
    }
    
}