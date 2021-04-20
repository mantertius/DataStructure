#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack()
{
    STACK* new_head = (STACK*) malloc(sizeof(STACK));
    new_head->head = NULL;
    return new_head;
}

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element)
{
    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    new_node->element = element;
    new_node->next = NULL;
}

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack)
{
    return(stack->head == NULL);
}

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack)
{
    NODE* tmp = stack->head->next;
    int t = stack->head->element;
    free(stack->head);
    stack->head = tmp;
    return t;    
}

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element)
{
    NODE* tmp = create_node(element);
    tmp->next = stack->head;
    tmp->element = element;
    stack->head = tmp;
}

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size)
{
    char c[size];
    for (int i = 0; i < ; i++)
    {
        /* code */
    }
    
}

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
//Insira o código aqui