//https://thehuxley.com/problem/862/oracle?quizId=6096
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if (1)
#define MAX 100001
typedef struct node
{
    char item;
    struct node *next;
} NODE;

NODE *  create_list()
{
    return NULL;
}

NODE *add(NODE *head, char item)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->item = item;
    new_node->next = head;
    //DEBUG printf("adicionado[[[%d]]]\t",new_node->item);
    return new_node;
}

int is_empty(NODE *head)
{
    return (head == NULL);
}

void printer(NODE *head)
{
    if (head == NULL)
    {
        printf("Lista vazia!\n");
    }
    while (head != NULL)
    {
        printf("[%d]", head->item);
        head = head->next;
    }
    printf("Fim da Lista!\n");
}

NODE *search(NODE *head, char item)
{
    // printf("to dentro do search\n");
    while (head != NULL)
    {
        if (head->item == item)
        {
            // printf("ENCONTREI MAIS UM!!! [%d]\n", item);
            return head; //retorna o endereço que contém o item
        }
        head = head->next;
    }
    return NULL;
}

int search_2(NODE *head, char item)//função para procurar a melhor sequencia
{
    DEBUG printf("######### Procurando por: [%c] ##########\n", item);
    int count = 0;
    while (head != NULL)
    {
        DEBUG printf("head->item = [%c]\t",head->item);
        if (head->item == item)
        {
            DEBUG printf("checagem: [%d]\n",count);
            return count; //retorna o endereço que contém o item
        }

        head = head->next;
        count = count+1;
        DEBUG printf("voltas: [%d]\n",count);
    }
    return 0;
}

int search_3(NODE *head, char item)//devolve a contagem até o fim, nao importa oq for
{
    //DEBUG printf("######### Procurando por: [%c] ##########\n", item);
    int count = 0;
    while (head != NULL)
    {
        //DEBUG printf("head->item = [%c]\t",head->item);
        if (head->item == item)
        {
            count++;
            //DEBUG printf("ENCONTREI MAIS UM!!! [%d]\n", item);
            //DEBUG printf("voltas: [%d]\n",count);
            return count; //retorna o endereço que contém o item
        }
        head = head->next;
        count++;
        //DEBUG printf("voltas: [%d]\n",count);
    }
    return count;
}
void func(NODE *head, int size, int beg, int end)//beg e end são o começo e o fim da melhor sequencia
{
    NODE* first_zero = search(head,'0');//recebo o endereço do primeiro zero.
    int pos_inicial = search_2(head,'0')+beg;//recebe a posição do primeiro zero
    DEBUG printf("\tComeço encontrado: [%d]\n",pos_inicial);

    NODE* first_one = search(first_zero,'1'); //will be my new head
    int size1 = search_2(first_zero, '1');
    int pos_final = size1+pos_inicial-1; //posição final do primeiro intervalo
    // if(first_one == NULL)
    // {
    //     pos_final = pos_inicial + search_3(first_zero,'1')-1;
    //     size1 = pos_final - pos_inicial; 
    // }
    // else
    // {
    //     size1 = search_2(first_zero,'1')-1; //a partir do endereço do primeiro zero, procuro o proximo 1 e recebo o tamanho deste intervalo
    //     pos_final = pos_inicial+size1-1;//end é a posição final
    // }
    DEBUG printf("\tFim encontrado: [%d]\n",pos_final);
    DEBUG printf("TAMANHO: [%d]\n",size1);
    
    if(first_zero == NULL || first_one == NULL)//break
    {
        if (first_zero == NULL)
        {
            printf("%d %d\n",pos_inicial,pos_final);
        }
        printf("%d %d\n",pos_inicial, pos_final);  
        return;
    }
    
    if (size1>size)
    {
        DEBUG printf("\n------- FUNC 1 --------\n");
        func(first_one, size1, pos_inicial, pos_final);
    }
    else{
        DEBUG printf("\n------- FUNC 2 --------\n\n");
        func(first_zero,size,beg,end);
    }
    
}
// void func2 (NODE* head)
// {
//     int size; 
//     int pos = 0; //posição da iteração
//     int beg = 0; 
//     int end = 0;

//     int state = -1;

//     NODE* temp;
//     while (head != NULL)
//     {
//         if(head->item == '0')
//         {
//             state = 0;
//             beg = pos;
//         }
//         if(head->next->item == '1')
//         {

//         }

//         pos++
//     }
    
// }
int main()
{
    char input[MAX];
    NODE *lista1 = create_list(); //nó que aponta para nulo
    do
    {
        scanf("%s", input);
        int q = strlen(input);
        if(q == 1 && input[0] == '0') break;
        for (int i = q-1; i >= 0 ; i--)
        {
            //DEBUG printf("Adicionado [%c].\n",input[i]);
            lista1 = add(lista1, input[i]); 
        }
        func(lista1, 0,0,0);  
    } while (1);


    return 0;
}