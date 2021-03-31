#include <stdio.h>
#include <stdlib.h>

/* 
L in k e d L i s t . h 
TAD para r e p r e s e n t a r uma L i s t a Encadeada . 
*/ 
typedef struct node{     // define o tipo nó;
    int item;       
    void *next;         
}Node;                  //o apelido desse tipo é Node

Node* createLinkedList() 
{
    return NULL;//pq tem que ser null????
}

int isEmpty( Node *head)
{
    return (head == NULL);
}

/*
malloc retorna um endereço de um espaço de memória alocado
ponteiro é um referenciador, se ele não for inicializado, ele aponta para qualquer lugar
quando eu crio um novo ponteiro, ele precisa de um lugar para apontar
se um faço um ponteiro que nao aponta pra lugar nenhum.... memory leak
(Node*) malloc(sizeof(Node)) é um endereço para tipo Node
*/

Node* insertNode (Node *head, int item) //insere um nó na cabeça
{
    Node* new_node = (Node*) malloc(sizeof(Node)); //crio um novo ponteiro(endereço do tipo Node) com o nome de new_node... esse endereço é igual a outro endereço
    new_node->item = item;
    new_node->next = head;
    return new_node; //aqui new_node para de existir
}

void printLinkedList(Node *head)
{
    while (isEmpty(head) != 1)
    {
        printf("%d\n", head->item);
        head = head->next;
    }
    return;  
}

Node* search(Node *head, int item)
{
    while (head != NULL)
    {
        if (head->item == item)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

Node* removeNode(Node *head, int item)
{   
    Node* itemplace = search(head,item);
    /*int* x;//cria ponteiro para int 
    *x;//pega o valor do ponteiro para int */
    


}







Node* search(Node *head, int item) ; 
Node* removeNode( Node *head, int item) ; 



int main()
{   

    Node* lista1 = createLinkedList();


   /* insertNode(Node *head , int item ); 
    void printLinkedList( Node *head ); 
    int isEmpty (Node *head ); 
    search(Node *head , int item ); 
    removeNode( Node *head , int item ); */
}