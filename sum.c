#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100001
typedef struct node
{
    int data;
    struct node* previous;
}NODE;

typedef struct head
{
    int size;
    NODE* top;
}STACK;

STACK* init_list()
{   
    STACK* new_head = (STACK*) malloc(sizeof(STACK));
    new_head->top = NULL;
    new_head->size = 0;
    return new_head;
}
int isEmpty(STACK* top)
{
    return(top->size == 0);
}
void push(STACK* stack, int item)
{
    NODE* new_top = (NODE*) malloc(sizeof(NODE*));
    new_top->data = item;
    if(isEmpty(stack))
    {
        new_top->previous = NULL;
    }
    else
    {
        new_top->previous = stack->top;
    }
    stack->size++;
    stack->top = new_top;
}
STACK* pop(STACK* stack)
{
    NODE* popped = stack->top;
    if(isEmpty(stack))
    {
        return NULL;
    }
    popped->previous == NULL;
    stack->top = stack->top->previous;
    stack->size--;

    return popped;
}

int main() {
    STACK* x = init_list();
    STACK* y = init_list();
    STACK* z = init_list();
    int eof_seeker;
    int len1= 0;
    int len2 = 0;
    int X[MAX];
    int Y[MAX];
    do //gets the first number
    {
        eof_seeker = scanf("%d", &X[len1]);
        if (eof_seeker != EOF)
        {
            push(x,X[len1]);
            len1++;
        }
         
    } while (eof_seeker != EOF);
    do //gets the second number
    {
        eof_seeker = scanf("%d", &Y[len2]);
        if (eof_seeker != EOF)
        {
            push(y,Y[len2]);
            len2++;
        }
         
    } while (eof_seeker != EOF);
    
    
	return 0;
}