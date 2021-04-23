#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LENGHT 100011
#define DEBUG if(0)
//https://thehuxley.com/problem/548/code-editor/?quizId=6124
typedef struct _node
{
    char data[MAX_LENGHT];
    struct _node* next;
}node;

typedef struct _stack
{
    node* top;
}stack;

stack* init()
{
    stack* tito = (stack*) malloc(sizeof(stack));
    tito->top = NULL;
    return tito;
}
void push(stack* stack, char data[])
{
    node* new_node = (node*) malloc (sizeof(node));
    strcpy(new_node->data,data);
    new_node->next = stack->top;
    stack->top = new_node;

}
void pop(stack* stack)
{
    if(stack->top == NULL){printf("EMPTY STACK\n"); return;}
    node* tmp = stack->top->next;
    DEBUG printf("next = [%p]",tmp);
    printf("%s", stack->top->data);
    free(stack->top);
    stack->top = tmp;

}
int main() {
    
    stack* pile = init();
    char input[MAX_LENGHT];
    strcmp("PUSH",input);
    char* flag;
    do
    {
        flag = fgets(input,MAX_LENGHT,stdin);
        DEBUG printf("%s",input);
        //fflush(stdin);
        //int len = strlen(input);
        //if(input[len] != '\n') strcat(input,"\n");
        if (!(strcmp("PUSH\n",input)))
        {
            DEBUG printf("entrou aqui\n");
            fgets(input,MAX_LENGHT,stdin);
            push(pile,input);
            fflush(stdin);
        }
        else if ((!(strcmp("POP\n",input)))) // || (!(strcmp("POP",input)))
        {
            DEBUG printf("entrou ali\n");
            pop(pile);
            
        }
        if (!(strcmp("POP",input)))
        {
            //printf("blue\n");
            pop(pile);
            break;
        }
        if (!(strcmp("PUSH",input)))
        {
            //printf("ueeasdasgg\n");

            fgets(input,MAX_LENGHT,stdin);
            push(pile,input);
            break;
        }
        
    } while (flag != NULL);
    

	return 0;
}

// PUSH
// 5 2 2 2 3 1
// PUSH
// 1 2 3
// PUSH
// 9 8 7 6 5 4 3 2 1
// POP
// POP
// PUSH
// 0 0 0 0 0 1
// PUSH
// 10 22 11 4 2 3
// POP