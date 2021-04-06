//https://thehuxley.com/problem/2133?quizId=6095
#include <stdio.h>
#include <string.h>
#define MAX_LENGHT 1000

typedef struct node
{
    int current;
    char linha[MAX_LENGHT];
    NODE* next;
}NODE;

typedef struct stack
{
    NODE* top;
}STACK;

STACK* init_stack()//é chamado sem argumentos e cria um stack
{
    STACK* new_stack = (STACK*) malloc(sizeof(STACK));

    new_stack->top = NULL;  
    return new_stack;   //retorna um novo_stack para ser usado
}

void push(STACK *stack, char *item)//como o topo é unico para todo o stack, só preciso mostrar o topo
{
    NODE *new_top = (NODE*) malloc(sizeof(NODE)); //aloca espaço para um novo nó
    if(is_empty(stack))
    {
        stack->top->current = 0;
    }
    new_top->linha[stack->top->current++] = item; //faz o ponteiro new_top apontar receber em linha o seu novo item
    new_top->next = stack->top;
    stack->top = new_top;
}

int is_empty(STACK* stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}

char pop(STACK *stack)
{
    char pooped = stack->top->linha[stack->top->current];
        
}


int main()
{
    char linha1[MAX_LENGHT];
    scanf("%s", linha1);
}