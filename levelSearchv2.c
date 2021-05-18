 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 /*
6
10 2 1
14 -1 5
19 3 4
5 -1 -1
23 -1 -1
51 -1 -1
 */
#define DEBUG if(0)
#define MAX_QUEUE 10000
typedef struct _node
{
	int value;
	int height;
	int nodeNumber;
	struct _node* left;
	struct _node* right;
}binaryTree;

typedef struct _queue
{
    //fazer estrutura em queue para criar lista encadeada somente para qeue e que funcione para visited[i]
    binaryTree* head;
    binaryTree* tail;
}Queue;
Queue* initQ()
{
    Queue* new_q = (Queue*) malloc(sizeof(Queue));
    new_q->tail = NULL;
    new_q->head = NULL;
    return new_q;
}
Queue* isEmptyQ(Queue* q)
{
    return (q == NULL);
}
// Queue* enQueue (Queue* q, binaryTree* bt)
// {
//     binaryTree* newQ = (binaryTree*) malloc (sizeof(binaryTree));
//     newQ ->
//     if (isEmptyQ(q))
//     {
//         newQ->
//     }
    
// }
int max (int a, int b)
{
    return (a>b) ? a : b;
}
int height (binaryTree* bt)
{
    if (bt == NULL) return -1;
    else{
    return 1 + max(height(bt->left),height(bt->right));
    }
}
int isEmpty(binaryTree* bt)
{
	return (bt == NULL);
}
void preOrder(binaryTree* bt, int heights[][2], int* count)
{
    if (!(isEmpty(bt)))
    {
        int level = bt->height;
        int vall = bt->value;
        int tmp;
        printf(" ( %d[%d] ",bt->value,bt->height);
        if(vall > heights[level][1]) //maior do que o maior
        {
            heights[level][0] = vall;
            printf("{h[%d][0] = %d}\n",level,vall);
        }
        else if (vall < heights[level][2]) //menor do que o menor
        {
            heights[level][1] = vall;
            printf("{h[%d][1] = %d}\n",level,vall);

        }
        preOrder(bt->left,heights,count);
        preOrder(bt->right,heights,count);
        //printf(") ");
        //printf(") ");

    }
    else
    {
        //printf(" () ");
    }
}
binaryTree* createBinTree(int nodeNum, int value)
{
    binaryTree* new = (binaryTree*) malloc(sizeof(binaryTree));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    new->height = 0;
    return new; 
}
binaryTree* add(int nodeNum, int values[], int leftNumbers[], int rightNumbers[],binaryTree* bt) 
 {
    printf("\n---------- nó de numero #%d ---------\n",nodeNum);
	binaryTree* newNode;
	if (nodeNum == -1)
	{
		newNode = NULL;
	}
	else
	{
        if(nodeNum != -1)
        {
            newNode = createBinTree(nodeNum,values[nodeNum]);
            printf("criado com sucesso nodeNum = [%d]\n", nodeNum);
        }
        printf("indo para left\n");
		newNode->left = add(leftNumbers[nodeNum],values,leftNumbers,rightNumbers,newNode->left);
        printf("indo para right\n");
		newNode->right = add(rightNumbers[nodeNum],values,leftNumbers,rightNumbers,newNode->right);
	    newNode->height = height(newNode);
    }
	return newNode;
 }
binaryTree* iniT(){return NULL;}
binaryTree* heighter(binaryTree* root, int height, int max, int min)
{
    if(height == 0)
    {
        printf("Nivel 1 : Maior = %d, Menor = %d", max, min);
    }
}
// void bfs(graph* graph,int origin, int destination, int count)
// {
//     for (int i = 0; i < MAX_SIZE; i++)
//     {
//         graph->visited[i] = 0;
//     }
    
//     adj_list*  tmp = graph->vertices[origin];  
//     Queue* Queue = initQ(); 
//     int dequeued;
//     graph->visited[origin] = 1;
//     //DEBUG printf("\tgraph->visited[%d] = %d\n",origin,graph->visited[origin]);

//     enQueue(Queue,origin);
//     printf("Iniciando busca em largura a partir de %d\n",origin);
//     int lasts[MAX_SIZE];
//     int found = 0;
//     while (!isEmptyQ(Queue))
//     {
//         //DEBUG printf("Fila não está vazia ainda.\n");
//         dequeued = deQueue(Queue);
//         tmp = graph->vertices[dequeued];
//         while (tmp != NULL)
//         {   
//            // if (tmp->item < tmp->next->item && tmp->next != NULL)
//             //{
//                 //tmp = tmp->next;
//                 /* code that orders the reading */
//             //}
            






//             //DEBUG printf("Visitando [%d]\n",tmp->item);
//             lasts[count] = tmp->item;
//             if(tmp->item == destination)
//             {
//                 found = 1;
//                 count++;
//                 DEBUG printf("ENCONTRADO depois de %d passagens, ultimo foi [%d]\n",count,lasts[count-1]);
//                 break;
//             }
//             printf("Iniciando busca em largura a partir de %d\n",tmp->item);
//             if(!graph->visited[tmp->item])
//             {
//                // DEBUG printf("\tgraph->visited[%d] = %d\n",tmp->item,graph->visited[tmp->item]);
//                 graph->visited[tmp->item] = 1;
//                 enQueue(Queue,tmp->item);
//             }
//             tmp = tmp->next;
//             count++;

//         }
//     }
//     DEBUG printf("FIM DA BUSCA!\n");

// }
int main()
 {
	int numberOfNodes;
	scanf("%d",&numberOfNodes);
	int nodeValue[numberOfNodes];
	int leftNodeNumber[numberOfNodes];
	int rightNodeNumber[numberOfNodes];
	for (int i = 0; i<numberOfNodes;i++)
	{
		scanf("%d",&nodeValue[i]);
		scanf("%d",&leftNodeNumber[i]);
		scanf("%d",&rightNodeNumber[i]);
	}
	//every index will be associated with a node. it'll be the node number.
	binaryTree* bT = iniT();
	bT = add(0,nodeValue,leftNodeNumber,rightNodeNumber,bT);
    int count = 0;
	int heights[height(bT)+1][2];//heights[nivel] = {max,min};
	preOrder(bT,heights,&count);
    for (int i = 0; i < height(bT)+1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("h[%d][%d] = [%d]\n",i,j,heights[i][j]);
        }
        
    }
    
    printf("\n");
	//searcher(bT);
	return 0;
 }