#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100001
#define DEBUG if(0)
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

NODE* pop(STACK* stack)
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

void calculate(STACK* a, STACK* b, STACK* res)
{
    NODE* pos1 = pop(a);
    NODE* pos2 = pop(b);
    while (pos1 != NULL && pos2 != NULL)
    {
        //DEBUG printf("entrou no while \n");
        int left = pos1->data;
        int right = pos2->data;
        int previous = 0;

        if (res->top != NULL) previous =  res->top->data;
        int ans = left+right+previous;
        
        DEBUG printf("[%d] + [%d] + [%d] = %d\t",left,right, previous,ans);
        int rest = ans%10;
        int next = ans/10;
        DEBUG printf("→ [%d] e [%d]\n", next, rest);
       // DEBUG printf("## %d e next = %d ##\n", rest, next);

       // DEBUG printf("bbbbbbb \n");
        if (res->top == NULL) 
        {
            //res->top->data =  rest;
            push(res, rest);
        }
        else
        {
            res->top->data =  rest;
        }
        push(res,  next);
        //DEBUG printf("bbbbbbb \n");

        free(pos2);
        free(pos1);
        pos1 = pop(a);
        pos2 = pop(b);
    }
    while (!(pos1 == NULL && pos2 == NULL))
    {
        //DEBUG printf("entrou no while 2 \n");
        if (pos1 == NULL)
        {
            //DEBUG printf("PRIMEIRO IF!!! \n");
            int right =  pos2->data;
            int previous = 0;
            if (res->top != NULL) previous =  res->top->data;
            int ans = right+previous;

            int rest = ans%10;
            int next = ans/10;

            res->top->data =  rest;
            push(res,  next);

            free(pos2);
        
            pos2 = pop(b);
        }
        else if (pos2 == NULL)
        {
            int right =  pos1->data;
            int previous = 0;
            if (res->top != NULL) previous =  res->top->data;
            int ans = right+previous;

            int rest = ans%10;
            int next = ans/10;

            res->top->data =  rest;
            push(res,  next);
            free(pos1);
            pos1 = pop(a);
        }
        
    }
}
void inverter (STACK* stack)
{
    NODE* current = stack->top;
    NODE* next = NULL;
    NODE* prev = NULL;
    while(current != NULL)
    {
        next = current->previous;
        current->previous = prev;
        prev = current;
        current = next;
    }
    stack->top = prev;
    
}
void printer(STACK* stack)
{
    int counter = 0;
    while (!isEmpty(stack))
    {
        int n;
        NODE* aux = pop(stack);
        n = aux->data;
        if (n == 0 && counter == 0)
        {
            continue;
        }
        
        printf("%d ",n);
        free(aux);
        counter++;
    }
    printf("\n");      
}
int main() {
    STACK* x = init_list();
    STACK* y = init_list();
    STACK* z = init_list();

    int len1= 0; //lenght -1
    int len2 = 0;//lenght -1
    char flusher;
    char X[MAX];
    char Y[MAX];

    do //gets the first number
    {
        scanf("%c", &X[len1]);
        if (X[len1] == ' ' || X[len1] == '\n'|| X[0] == '0') //X[LEN1] vai ser reescrito na proxima rodada e exclui zeros a esquerda
        {
            continue;
        }
        if (X[len1] == '+') //para o loop
        {
            DEBUG printf("X[%d] = [%c]\n",len1,X[len1]);
            break;
        }
        DEBUG printf("X[%d] = [%c]\n",len1,X[len1]);
        push(x,X[len1]-'0');
        len1++;
    } while (1);
        
    scanf("%c", &flusher); //flushs the \n
    
    DEBUG printf("\n################\n\n");
    
    do //gets the second number
    {
        scanf("%c", &Y[len2]);
        
        if (Y[len2] == ' ' || Y[len2] == '\n' || Y[0] == '0') //Y[LEN2] vai ser reescrito na proxima rodada e exclui zeros a esquerda
        {
            continue;
        }
        if (Y[len2] == '=') //para o loop
        {
            DEBUG printf("Y[%d] = [%c]\n",len2,Y[len2]);
            break;
        }
        DEBUG printf("Y[%d] = [%c]\n",len2,Y[len2]);
        push(y,Y[len2]-'0');
        len2++;
    } while (1);
    
    if (len1 == 0 && len2 == 0) //checks if the list is null
    {
        printf("Lista vazia!\n");
        return 0;
    }
    if(len2 == 0)
    {
        for(int i = 0; i < len1; i++)
        {
            printf("%c ", X[i]);
            if(i == len1-1)
            {
                printf("\n");
                break;
            }
        }
        return 0;
    }
    if(len1 == 0)
    {
        for(int i = 0; i < len2; i++)
        {
            printf("%c ", Y[i]);
            if(i == len2-1)
            {
                printf("\n");
                break;
            }
        }
        return 0;
    }
    
    calculate (x,y,z);
    DEBUG printf("TERMINOU DE CALCULAR\n");
    printer(z);
    inverter(z);    
    
	return 0;
}