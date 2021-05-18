#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define true 1
#define false 0
#define DEBUG if(1)
#define MAX_SIZE 10000
/*
1. ADD(S, k) = adiciona o int k ao conjunto S, retornando True se o int foi corretamente adicionado ou false se o int já pertencia ao conjunto.
2. DEL(S, k) = remove o int k do conjunto S, retornando True se o int foi corretamente removido ou False se o int não pertencia ao conjunto.
3. HAS(S, k) = retorna True se o int k pertence ao conjunto S ou false se o int não pertence ao conjunto.
*/
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
    int base;
    int numOfData[100]; //every index will be one table, the value of this array on the index will be the number of data written in it
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
        newTable->numOfData[i] = 0;
    }
    newTable->base = 7;
    return newTable;
}
bool addListHead(list* lista, int value)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = value;
    if (lista->size == 0)
    {
        lista->head = new_node;
        lista->tail = new_node;
        lista->size++;
        return;
    }
    new_node->next = lista->head;
    lista->head = new_node;
    lista->size++;
}
bool addHashed(table* ht, int value, int key)
{
    return addListHead(ht->tables[key],value);
}
bool ADD(table* S, int K)
{
    return true;
}
bool DEL(table* S, int K)//remove
{
    return true;
}
bool HAS(table* S, int K)//percente
{
    int key = hashFunction(K,S->base);
    while (S->tables[key] != NULL)
    {
        
    }
    
    
    return true;
}
int AtoI(char input[]) //returns an int from a string
{
    int len = strlen(input)-3;
    char *ptr = input+3;  //creates a auxiliary ptr to transverse the string
    int ans;           
    while (*ptr) { 
        if (isdigit(*ptr)) {                        //if string + x is digit 
            long val = strtol(ptr, &ptr, 10);       //transforms the characters from string into base10 ints. 
            DEBUG printf("%ld\n", val);
            ans = val;
        } else { 
            ptr++; 
        } 
    }
    return ans;
}
int main()
{
    int count = 0;
    int base = 7;
    int key;
    char input[300];
    table* ht  = initTable();
    while (gets(input))
    {
        int buffer;
        switch (input[2])
        {
        case 'D'://add
            //DEBUG printf("[%s]\n",input);
            buffer = AtoI(input);
            //ADD(ht,buffer);
            key = hashFunction(buffer,base);
            addHashed(ht,buffer,key);
            //rehash?
            break;

        case 'S'://has
            buffer = AtoI(input);
            key = hashFunction(buffer,base);
            HAS(ht,buffer);
            break;
        case 'L'://del
            buffer = AtoI(input);
            key = hashFunction(buffer,base);

            DEL(ht, buffer);
            break;
        case 'T'://prt
            DEBUG printf("PRT");
            break;
        }
        memset(input,0,strlen(input));
        count++;
    }
    
    
}

/*
ADD 61145465456215
HAS 68
ADD 99
ADD 51
HAS 61
HAS 3
DEL 99
ADD 90
HAS 42
ADD 94
ADD 51
ADD 70
ADD 59
ADD 80
HAS 59
ADD 35
ADD 3
PRT
HAS 94
DEL 70
DEL 34
DEL 84
HAS 53
HAS 97
ADD 65
ADD 79
ADD 66
ADD 64
HAS 64
HAS 15
DEL 65
ADD 82
ADD 68
ADD 77
ADD 22
ADD 2
DEL 81
HAS 55
HAS 1
HAS 85
DEL 51
ADD 70
HAS 35
PRT
HAS 90
ADD 43
PRT
ADD 70
HAS 92
ADD 58
DEL 61
PRT
ADD 95
HAS 100
HAS 10
DEL 76
HAS 64
ADD 41
PRT
HAS 90
HAS 84
HAS 58
DEL 43
ADD 68
HAS 80
HAS 30
PRT
PRT
ADD 71
PRT
HAS 2
DEL 66
HAS 70
ADD 30
ADD 70
ADD 30
DEL 98
HAS 35
ADD 7
ADD 62
HAS 30
HAS 68
ADD 73
DEL 68
HAS 27
ADD 50
HAS 7
ADD 47
HAS 90
ADD 21
PRT
HAS 35
DEL 77
ADD 0
DEL 70
HAS 79
HAS 95
HAS 50
HAS 71
PRT
*/