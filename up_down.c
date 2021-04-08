//https://thehuxley.com/problem/2133?quizId=6095
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGHT 1000

typedef struct node
{
    char linha[MAX_LENGHT];
    struct node *next;  
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
    //printf("%s\n", item);
    NODE *new_top = (NODE*) malloc(sizeof(NODE));//aloca espaço para um novo nó                     
    strcpy(new_top->linha, item); //acessa o endereço de new_top->linha e escreve o item lá
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

NODE* pop(STACK *stack)
{
    NODE *pooped = stack->top; 
    stack->top = stack->top->next; //atualizar o topo + remoção logica do topo
    pooped->next = NULL;
    return pooped;
}

int main()
{
    char linha1[MAX_LENGHT];
   
    STACK* stack = init_stack();
    //printf("AAAAAa#\n");
    int counter = 0;
    while(1)
    {    
        void* p = fgets(linha1,MAX_LENGHT,stdin);
        if (!p)
        {
            break;
        }
        ++counter;
        push(stack, linha1);
    }
    strcat(stack->top->linha,"\n");
    //printf("%s \t %s",stack->top->linha, stack->top->next->linha);
   while (is_empty(stack)!= 1)
    {
        char out[MAX_LENGHT];
        NODE* aux = pop(stack);
        printf("%s",aux->linha);
        free(aux);
    }
    return 0;
    
}