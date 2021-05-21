#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define true 1
#define false 0
#define DEBUG if(0)
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
table* initTable(int base)
{
    table* newTable = (table*) malloc(sizeof(table));
    for (int i = 0; i < 100; i++)
    {
        newTable->tables[i] = initList();
        newTable->numOfData[i] = 0;
    }
    newTable->base = base;
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
        return true;
    }
    new_node->next = lista->head;
    lista->head = new_node;
    lista->size++;
    return true;
}
bool addHashed(table* ht, int value, int key)
{
    return addListHead(ht->tables[key],value);
}
bool DEL(table* S, int K,int key,int* comparCount)//remove
{
    //DEBUG printf("deletando [%d]\t",K);
    node* tmp = S->tables[key]->head; 
    while (tmp != NULL)
    {
        if(tmp->data == K){*comparCount += 1;return true;}
        tmp = tmp->next;
        *comparCount += 1;
    }
    return false;
}
bool HAS(table* S, int K, int* comparCount)//percente
{
    //DEBUG printf("\ncheguei em HAS! \n");
    int voltas = 0;
    int key = hashFunction(K,S->base);
    DEBUG printf("cheguei na chave [%d],base = [%d], k = [%d]\n",key,S->base,K);
    node* tmp = S->tables[key]->head; 
    //if (tmp == NULL) DEBUG printf("CABEÇA NULA!\n");
    while (tmp != NULL)
    {
        //DEBUG printf("oi\n");
        if(tmp->data == K)
        {
            *comparCount += 1;
            voltas++;
            DEBUG printf("voltinhas [%d]\n",voltas);
            return true;
        }
        *comparCount += 1;
        voltas++;
        //DEBUG printf("comparCount = [%d], voltas= [%d]\n",*comparCount,voltas);
        tmp = tmp->next;
    }
    return false;
}
bool ADD(table* S, int K, int key, int* comparCount)
{
    int ptr = 0;
    if (!HAS(S,K, &ptr))
    {
        DEBUG printf("======================= ADICIONANDO ->\t chave[%d],base = [%d], k = [%d]\n",key,S->base,K);
        addHashed(S,K,key);
        *comparCount = ptr;
        return true;
    }
    else
    {
        *comparCount = ptr;
        return false;
    }
}
int AtoI(char input[]) //returns an int from a string
{
    int len = strlen(input)-3;
    char *ptr = input+3;  //creates a auxiliary ptr to transverse the string
    int ans;           
    while (*ptr) { 
        if (isdigit(*ptr)) {                        //if string + x is digit 
            long val = strtol(ptr, &ptr, 10);       //transforms the characters from string into base10 ints. 
            //DEBUG printf("%ld\n", val);
            ans = val;
        } else { 
            ptr++; 
        } 
    }
    return ans;
}
int biggest(table* ht)
{
    int max = 0;
    for (int i = 0; i < 100; i++)
    {
        if(ht->numOfData[i]> max) max = ht->numOfData[i];
    }
}
table* rehash(table* ht, int numCount)
{
    int ptr = 0;
    int new_base = 2*(ht->base)-1;
    table* new_table  = initTable(new_base);
    if (numCount/ht->base >= 0.75)
    {
        DEBUG printf("%d/%d = %d\n",numCount,ht->base,numCount/ht->base);
        DEBUG printf("\n!!!!REHASH?!?!?!?\n");
        for (int i = 0; i < ht->base; i++)
        {
            node* tmp = ht->tables[i]->head;
            while (tmp != NULL)
            {
                int oldkey, value, newkey;
                oldkey = i;
                value = tmp->data;
                DEBUG printf("fazendo rehash de [%d]\t",value);
                newkey = hashFunction(value,new_base);
                ADD(new_table,value,newkey,&ptr);
                tmp = tmp->next;
            }      
        }
        free(ht);
        return new_table;
    }
    else
    {
        return ht;
    }
    
    
}
int main()
{
    int stepCount = 0;
    int numCount = 0;
    int base = 7;
    int key;
    int res;
    int lenghtOfTable = 7;
    char input[300];
    int comparCount = 0;
    table* ht  = initTable(base);
    while (gets(input))
    {
        long buffer;
        switch (input[2])
        {
        case 'D'://add
            buffer = AtoI(input);
            key = hashFunction(buffer,base);
            comparCount = 0;
            //DEBUG printf("ADICIONANDO [%d]\n",buffer);
            res = ADD(ht,buffer,key,&comparCount);  
            numCount++;
            ht = rehash(ht,numCount);
            //DEBUG printf("PASSOU! -: [%s]\n",input);
            printf("%d ",stepCount);
            printf("%d ",res);
            printf("%d\n",comparCount);
            break;

        case 'S'://has
            buffer = AtoI(input);
            key = hashFunction(buffer,base);
            comparCount = 0;
            res = HAS(ht,buffer,&comparCount);
            printf("%d ",stepCount);
            //DEBUG printf("HAS [%d] ",buffer);
            printf("%d ",res);
            printf("%d\n",comparCount);
            break;


        case 'L'://del
            buffer = AtoI(input);
            key = hashFunction(buffer,base);
            comparCount = 0;
            //DEBUG printf("DELETANDO [%d],key[%d]\n",buffer,key);
            res = DEL(ht,buffer,key,&comparCount);
            printf("%d ",stepCount);
            printf("%d ",res);
            printf("%d\n",comparCount);
            numCount--;
            break;


        case 'T'://prt
            //DEBUG printf("PRT");
            printf("%d ",stepCount);
            printf("%d ",ht->base);
            printf("%d ",numCount);
            printf("%d\n",biggest(ht));
            break;
        }
        memset(input,0,strlen(input));
        stepCount++;
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



//TODO quando chega na linha 13, e na linha 15, parece que nao há adição de 59