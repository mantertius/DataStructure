 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 //https://thehuxley.com/problem/949/oracle?quizId=6236
 /*
6
10 2 1
14 -1 5
19 3 4
5 -1 -1
23 -1 -1
51 -1 -1
 */
#define DEBUG if(1)
#define MAX_QUEUE 10000
typedef struct _node
{
	int value;
	int height;
	int nodeNumber;
	struct _node* left;
	struct _node* right;
}binaryTree;

typedef struct node
{
    int item;
    struct node* next;
}NODE;
typedef struct _queue
{
    //fazer estrutura em queue para criar lista encadeada somente para qeue e que funcione para visited[i]
    NODE* head;
    NODE* tail;
}Queue;
Queue* initQ()
{
    Queue* new_q = (Queue*) malloc(sizeof(Queue));
    new_q->tail = NULL;
    new_q->head = NULL;
    return new_q;
}

int isEmptyQ(Queue* q)
{
    return (q->head == NULL);
}
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
NODE* createNode(int origin) //creates a "node" with value
{
    NODE* adj = (NODE*) malloc (sizeof(NODE));
    adj->item = origin;
    adj->next = NULL;
    return adj;
}
int isEmptyList(NODE *head)
{
    return (head == NULL);
}
void printLinkedList(NODE *head)
{
    NODE* tmp = head;
    if(tmp == NULL) printf(" hea d=== null\t");
    while (tmp != NULL)
    {
        printf("[%d]-> ", tmp->item);
        tmp = tmp->next;
    }
    DEBUG printf(" fim da lista.\n");
    return;  
}
NODE* addNode (NODE* head, int value)
{   NODE* new = createNode(value);
    if(head == NULL) 
    {
        head = new;
        //printf("new creado [%d]\n",new->item);
    }
    else 
    {
        NODE* tmp = head;
        new->next = tmp;
        head = new;
    }
    return head;
}
int isEmpty(binaryTree* bt)
{
	return (bt == NULL);
}
void preOrder(binaryTree* bt, NODE* height[])
{
    if (!(isEmpty(bt)))
    {
        int level = bt->height;
        int vall = bt->value;
        int tmp;
        DEBUG printf("%d[%d]\t",bt->value,bt->height);
        height[level] = addNode(height[level],vall);
        DEBUG printLinkedList(height[level]);
        preOrder(bt->left,height);
        preOrder(bt->right,height);
        //printf(")");
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
binaryTree* add(int nodeNum, int values[], int leftNumbers[], int rightNumbers[],binaryTree* bt,int NumOfNodes) 
 {
    DEBUG printf("\n---------- nó de numero #%d ---------\n",nodeNum);
	binaryTree* newNode;
	if (nodeNum == -1 || nodeNum > NumOfNodes-1)
	{
		newNode = NULL;
	}
	else 
	{
        if(nodeNum != -1)
        {
            newNode = createBinTree(nodeNum,values[nodeNum]);
           DEBUG printf("criado com sucesso nodeNum = [%d]\n", nodeNum);
        }
        DEBUG printf("indo para left\n");
		newNode->left = add(leftNumbers[nodeNum],values,leftNumbers,rightNumbers,newNode->left,NumOfNodes);
        DEBUG printf("indo para right\n");
		newNode->right = add(rightNumbers[nodeNum],values,leftNumbers,rightNumbers,newNode->right,NumOfNodes);
	    newNode->height = height(newNode);
    }
	return newNode;
 }
 int deQueue(Queue* q)
{
    int deQueued = q->head->item;
    NODE* tmp = q->head->next;
    free(q->head);
    q->head = tmp;
    return deQueued;
}
void enQueue(Queue* q, int origin)
{
    NODE* toBeQueued = createNode(origin);
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
binaryTree* iniT(){return NULL;}
binaryTree* heighter(binaryTree* root, int height, int max, int min)
{
    if(height == 0)
    {
        printf("Nivel 1 : Maior = %d, Menor = %d", max, min);
    }
}
void altureiro(int level, NODE* list, int maxH)
{
    int trueLevel = maxH-level;
    int max, min;
        max = list->item;
        min = list->item;
        NODE* tmp = list;
        while (tmp != NULL)
        {
            if (tmp->item > max)
            {
                max = tmp->item;
            }
            if (tmp->item < min)
            {
               min = tmp->item;
            }
            tmp = tmp->next;
        }
    printf("Nivel %d: Maior = %d, Menor = %d\n",trueLevel,max,min);
 
}
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
	bT = add(0,nodeValue,leftNodeNumber,rightNodeNumber,bT,numberOfNodes);
    int count = 0;
    int max_h = height(bT)+1;
    NODE* new[max_h];
    for (int i = 0; i < max_h; i++)
    {
        new[i] = NULL;
    }
	preOrder(bT,new);
    for (int i = max_h-1; i>= 0; i--)
    {
        DEBUG printf("indo para o nivel [%d]\n",i);
        altureiro(i,new[i],max_h);//passo o nível, passo os valores dos nós do nivel i
    }
	return 0;
 }