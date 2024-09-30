/* Escreva um programa com rotinas para colocar elementos em uma pilha dinâmica e posteriormente desempilhar os elementos e coloca-los em uma fila. No final mostre a fila na tela.
Obs: Use os critérios de fila e pilha. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>


typedef struct nodo
{
    int number;
    struct nodo *next;
} Nodo;

typedef struct queue
{
    Nodo *begin;
    Nodo *end;
} Queue;

typedef struct stack
{
    Nodo *top;
} Stack;


Queue *startQueue();
Stack *startStack();
Nodo *getNewNodo();
void showQueue(Queue *);
void insertQueue(int, Queue *);
void insertStack(int, Stack *);
int unstack(Stack *);


main() {
    setlocale(LC_ALL, "Portuguese");

    Stack *stack = startStack();
    Queue *queue = startQueue();

    char resp;

    do
    {
        int number;

        printf("Número a ser inserido: ");
        scanf("%d", &number);
        fflush(stdin);

        insertStack(number, stack);

        printf("Inserir outro elemento? (s/n) ");
        scanf("%c", &resp);
        resp = tolower(resp);
    } while (resp != 'n');


    while (stack->top != NULL) {
        insertQueue(unstack(stack), queue);
    }
    
    printf("FILA\n");
    showQueue(queue);
    
    system("pause");
}


Queue *startQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Memória insufucuente");
        exit(1);
    }
    queue->begin = NULL;
    queue->end = NULL;
    return queue;
}

Stack *startStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL)
    {
        printf("Memória insufucuente");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

Nodo *getNewNodo()
{
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));

    if (nodo == NULL)
    {
        printf("\nM?moria insuficiente\n");
        exit(1);
    }
    return nodo;
}

void showQueue(Queue *queue) {
    Nodo *aux = queue->begin;
    while (aux != NULL)
    {
        printf("%d  ", aux->number);
        aux = aux->next;
    }
}

void insertQueue(int number, Queue *queue) {
    Nodo *newNodo = getNewNodo();

    if (queue->begin == NULL)
    {
        queue->begin = newNodo;
    }
    else
    {
        queue->end->next = newNodo;
    }
    queue->end = newNodo;
    newNodo->next = NULL;
    newNodo->number = number; 
}

void insertStack(int number, Stack *stack) {
    Nodo *newNodo = getNewNodo();
    
    newNodo->next = stack->top;
    stack->top = newNodo;
    newNodo->number = number; 
}

int unstack(Stack *stack) {
    if (stack->top == NULL)
    { 
        printf("Pilha Vazia\n");
        return;
    }

    Nodo *top = stack->top;
    int number = top->number;
    stack->top = top->next;
    free(top);
    return number;
}
