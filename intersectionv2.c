#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DEBUG if(1)
typedef struct node
{
    char data;
    struct node* next;
    struct node* previous
}NODE;

typedef struct lista
{
    NODE* head;
    NODE* tail;
}LIST;

LIST* init_list()
{   
    LIST* new_head = (LIST*) malloc(sizeof(LIST));
    new_head->head = NULL;
    new_head->tail = NULL;
    return new_head;
}