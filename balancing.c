#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LENGHT 100011
#define DEBUG if(0)
//https://thehuxley.com/problem/415?quizId=6124
typedef struct _node
{
    char data;
    struct _node* next;
}node;

typedef struct _stack
{
    int size;
    node* top;
}stack;

stack* init()
{
    stack* tito = (stack*) malloc(sizeof(stack));
    tito->top = NULL;
    tito->size = 0;
    return tito;
}
void push(stack* stack, char data)
{
    node* new_node = (node*) malloc (sizeof(node));
    new_node->data = data;
    new_node->next = stack->top;
   //DEBUG printf("Pushado: ' %c '\n",data);
    stack->top = new_node;
    stack->size++;
}
char pop(stack* stack)
{
    if(stack->top == NULL){
        //printf("EMPTY STACK\n"); 
        return '\0';
    }
    node* tmp = stack->top->next;
    char aux = stack->top->data;
    //DEBUG printf("Popado: ' %c '\t", aux);
    free(stack->top);
    stack->top = tmp;
    stack->size--;
    return aux;
}
void flusher(stack* q)
{
    while (q->top != NULL)
    {
        node* current = q->top->next;
        free(q->top);
        q->top = current;
    }
    q->size = 0;
    
}
void f (stack* q, int size)
{
    char c[MAX_LENGHT];
    int z = 0;
    char* b;
    getchar();
    do
    {   
        int status = 1;
        char tmp;
        b = fgets(c,MAX_LENGHT,stdin);
        DEBUG printf("%s",c);
        int len = strlen(c);
        if(len == 1 && (c[0] == '\n' || c[0]== ' ')){printf("Yes\n");z++;continue;}
        for (int i = 0; i < len; i++)
        {
            if(c[i] == ' ' || c[i] == '\n'){continue;}
            //DEBUG printf("%c", c[i]);
            switch (c[i])
            {
            case '(':
                push(q,'(');
                DEBUG printf("qsize [%d]\n",q->size);

                break;
            case '[':
                push(q,'[');
                DEBUG printf("qsize [%d]\n",q->size);

                break;
           
            case ')':
                tmp = pop(q);
                if(tmp == '\0' || tmp != '(') {status = 0;DEBUG printf("caiuu i=[%d]\t",i);}
                DEBUG printf("qsize [%d]\n",q->size);
                DEBUG printf("tmp:'%c' == c[%d]:  '%c'\n",tmp,i,c[i]);
                break;
            case ']':
                tmp = pop(q);
                if(tmp == '\0' || tmp != '['){status = 0; DEBUG printf("caiuu i=[%d]\t",i);}
                DEBUG printf("qsize [%d]\n",q->size);
                DEBUG printf("tmp:'%c' == c[%d]:  '%c'\n",tmp,i,c[i]);
                break;
            }
        }
        //DEBUG printf("\n");
        if (q->size != 0)
        {
            DEBUG printf("qsize [%d]\n",q->size);
            status = 0;
        }
        switch (status)
        {
        case 0:
            printf("No\n");
            break;
        
        default:
            printf("Yes\n");
            break;
        }
        flusher(q);
        z++;
    } while (z < size);
}
int main()
{
    stack* pile = init();
    int n;
    scanf("%d",&n);
    f(pile, n);
    return 0;
}
