#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node
{
    int data;
    struct _node* next;
}node;
typedef struct _list
{
    int size;
    node* head;
}list;

int hashFunction(int x)
{
    return x%13;
}

int main()
{
    int testNumber;
    scanf("%d",&testNumber);
    for (int i = 0; i < testNumber; i++)
    {
        int baseNumber;
        scanf("%d",&baseNumber);
        int keysNumber;
        scanf("%d",&keysNumber);
        get(baseNumber,keysNumber);
        print(table);
    }
    
}