#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG if(1)
#define MAX_SIZE 10000
//https://thehuxley.com/problem/805

typedef struct adjacent_list //glorified node
{
    int item;
    struct adjacent_list* next;
}adj_list; 
typedef struct graph
{
    adj_list* vertices[MAX_SIZE]; //lista de nós, fala pra qual nó aponta o vertice do index, exemplo: v[1] = vertices que o 1 aponta para  
    short visited[MAX_SIZE];
}graph;
typedef struct _queue
{
    adj_list* head;
    adj_list* tail;
}Queue;

graph* createGraph() //creates a graph with nullified entries and visited[] = {0}
{
    graph* g = (graph*) malloc(sizeof(graph));
    for (int i = 0; i <= MAX_SIZE-1; i++)
    {
        g->vertices[i] = NULL;
        g->visited[i] = 0;
    }
    return g;
}
void bubbleSort(adj_list* list) //list = vertices[i];
{
    if (list == NULL) return;
    adj_list* pos; //auxiliary node* that points to head
    adj_list* tmp = NULL;
    int flag = 0; //flag will switch to 1 while it's making swaps
    do
    {
        pos = list;//set the position to head.
        flag = 0;

        while (pos->next != tmp)
        {
            if (pos->item > pos->next->item)
            {
                //DEBUG printf("%d > %d\n",pos->item , pos->next->item);
                int t = pos->item;
                pos->item = pos->next->item;
                pos->next->item = t;
                flag = 1;
            }
            pos = pos->next;
        }
        tmp = pos; //stores the last pos 'cuz it's already been sorted.
    } while (flag);
    
}
adj_list* createAdjList(int origin) //creates a "node" with value
{
    adj_list* adj = (adj_list*) malloc (sizeof(adj_list));
    adj->item = origin;
    adj->next = NULL;
    return adj;
}
void addEdge(graph* g, int origin, int destination) //adds edges for an directioned graph
{
    adj_list *vertex  = createAdjList(destination);
    vertex->next = g->vertices[origin];
    g->vertices[origin] = vertex;
    //DEBUG printf("Aresta que liga %d %d\n",origin,destination);
}
Queue* initQ() //initializes the queue, nullifying the head and tail
{
    Queue* newQ = (Queue*) malloc(sizeof(Queue));
    newQ->head = NULL;
    newQ->tail = NULL;
    return newQ; 
}
int isEmptyQ(Queue* q)
{
    return(q->head == NULL);
}
void enQueue(Queue* q, int origin)
{
    adj_list* toBeQueued = createAdjList(origin);
    if (isEmptyQ(q))
    {
        q->head = toBeQueued;
        q->tail = toBeQueued;
    }
    else
    {
        q->tail->next = toBeQueued;
        q->tail = toBeQueued;   
    }
}
int deQueue(Queue* q)
{
    int deQueued = q->head->item;
    adj_list* tmp = q->head->next;
    free(q->head);
    q->head = tmp;
    return deQueued;
}
void printGraph(graph* gr, int vertexNum)
{
    for (int i = 0; i < vertexNum; i++)
    {
        adj_list* tmp = gr->vertices[i];
        printf("v[%d]: ",i);
        while (tmp)
        {
            printf("v(%d),",tmp->item);
            tmp= tmp->next;
        }
        printf("\n");
    }
}
void printQ(Queue* q)
{
    adj_list* tmp = q->head;
    while (tmp != NULL)
    {
        printf("[%d]→",tmp->item);
        tmp = tmp->next;
    }
    printf("\n");
    
}
void bfs(graph* graph,int origin, int destination, int count)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        graph->visited[i] = 0;
    }
    
    adj_list*  tmp = graph->vertices[origin];  
    Queue* queue = initQ(); 
    int dequeued;
    graph->visited[origin] = 1;
    //DEBUG printf("\tgraph->visited[%d] = %d\n",origin,graph->visited[origin]);

    enQueue(queue,origin);
    printf("Iniciando busca em largura a partir de %d\n",origin); //para a primeira entrada
    DEBUG printQ(queue);

    int lasts[MAX_SIZE];
    int found = 0;
    while (!isEmptyQ(queue))
    {
        //DEBUG printf("Fila não está vazia ainda.\n");
        dequeued = deQueue(queue);
        tmp = graph->vertices[dequeued];
        while (tmp != NULL && !graph->visited[tmp->item])
        {   
            //DEBUG printf("found == [%d], tmp = [%d]\n",found,tmp->item);
            //if(tmp->next != NULL) DEBUG printf("Visitando [%d], proximo = [%d]\n",tmp->item,tmp->next->item);
            printf("Iniciando busca em largura a partir de %d\n",tmp->item);
            if(found == 0){ lasts[count] = tmp->item; count++;}
            if(tmp->item == destination)
            {
                found = 1;
                //count++;
                //DEBUG printf("ENCONTRADO depois de %d passagens, ultimo foi [%d]\n",count,lasts[count-1]);
                //break;
            }
            if(!graph->visited[tmp->item])
            {
               // DEBUG printf("\tgraph->visited[%d] = %d\n",tmp->item,graph->visited[tmp->item]);
                graph->visited[tmp->item] = 1;
                enQueue(queue,tmp->item);
                DEBUG printQ(queue);
            }
            tmp = tmp->next;
            count++;

        }
    }

    //node_explanation(graph);

    
    if (found == 0) printf("Sem caminho entre %d e %d\n\n",origin,destination);
    else
    {
        printf("Caminho entre %d e %d: %d => ",origin,destination,origin);
        for (int i = 0; i < count; i++)
        {
            if (i == count-1)
            {
                printf("%d\n",lasts[i]);
                break;
            }     
            printf("%d => ",lasts[i]);
        }  
    }
    DEBUG printf("FIM DA BUSCA!\n");

}
int main()
{
    graph* graph = createGraph();
    int verticesNum, linkNum, testNum; //V A T
    scanf("%d",&verticesNum);
    scanf("%d",&linkNum);
    scanf("%d",&testNum);
    for (int i = 0; i < linkNum; i++)
    {
        int n1,n2;
        scanf("%d",&n1);
        scanf("%d",&n2);
        addEdge(graph,n1,n2);
    }
    
    //printGraph(graph,verticesNum);
    for (int i = 0; i < verticesNum; i++)
    {
        //DEBUG printf("indo para [%d]\n",i);
        bubbleSort(graph->vertices[i]);
    }
    printGraph(graph,verticesNum);
    
    
    for (int i = 0; i < testNum; i++)
    {
        int n1,n2;
        scanf("%d",&n1); //origin
        scanf("%d",&n2); //destination
        printf("--------\n\nCaso de Teste #%d - BFS(%d)\n\n",i+1,n1);
        DEBUG printf("Alvo: [%d]\n",n2);
        bfs(graph,n1,n2,0);
    }
    
    
    return 0;
}
// como fazer visitas de ordem crescente?