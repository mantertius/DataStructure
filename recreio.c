#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define DEBUG if(0)
//https://thehuxley.com/problem/414/code-editor/?quizId=6124
typedef struct _node
{
    int person;
    int priority;
    struct _node* next;
}node;
typedef struct queue
{
    int size;
    node* head;
}Q;
Q* initQ(){
    Q* new_q = (Q*) malloc(sizeof(Q));
    new_q->size = 0;
    new_q->head = NULL;
    return new_q;
}
int isEmpty(Q* q)
{
    return (q->head == NULL);
}
void priorityEnqueue(Q* q, int person, int priority)
{
    node* newT = (node*) malloc(sizeof(node));
    newT->person = person;
    newT->priority = priority;
    if ((isEmpty(q)) || (priority > q->head->priority))
    {
        newT->next = q->head;
        q->head = newT;
        //printf("primeiro caso\n");
    }
    else
    {
        node* tmp = q->head;
        while ((tmp->next != NULL) && (tmp->next->priority >= priority))
        {
            tmp = tmp->next;    
        }
        newT->next = tmp->next;
        tmp->next = newT;
    }
    //printf("pessoa: [%d] | prioridade [%d]\n",person,priority);
}
void printer(Q* q)
{
    node* tmp = q->head;
    while (tmp != NULL)
    {
        printf("[%d,%d]→",tmp->priority,tmp->person);
        tmp = tmp->next;
    } 
}
void flusher(Q* q)
{
    while (q->head != NULL)
    {
        node* current = q->head->next;
        free(q->head);
        q->head = current;
    }
    
}
int comp(Q* q, int n[], int size)
{
    //printf("começo da comp\n");
    int ans = 0;
    int i = 0;
    node* tmp = q->head;
    while (tmp != NULL && i<size)
    {
        if (tmp->person == i)
        {
            //printf("[%d] != [%d]\n", tmp->person, i);
            ans++;
        } 
        i++;
        tmp = tmp->next;
    }
    return ans;
}
int main() {
    int cases,du,zi;
    scanf("%d",&cases); //gets the number of tests
    Q* q = initQ();
    for (int i = 0; i < cases ; i++)
    {
        scanf("%d",&zi); //number of students
        int input[zi];   
        for (int i = 0; i < zi; i++)
        {
            scanf("%d",&input[i]);
            priorityEnqueue(q,i,input[i]);
            DEBUG printer(q);
            DEBUG printf("\n");
        } 
        du = comp(q,input,zi);
        printf("%d\n",du);
        flusher(q);
    }
	return 0;
}