/* Escreva um programa para calcular o fatorial de um número que utiliza uma pilha dinâmica para resolver o problema. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

typedef struct nodo
{
    int number;
    struct nodo *next;
} Nodo;

typedef struct stack
{
    Nodo *top;
} Stack;

int readNumber(Stack *);
int calculateFactorial(Stack *);
Stack *startStack();
Nodo *getNewNodo();
void insertStack(int, Stack *);
int unstack(Stack *);


main() {
    setlocale(LC_ALL, "Portuguese");

    Stack *stack = startStack();    
    char resp;

    do
    {
        int number = readNumber(stack);

        printf("O fatorial de %d é %d\n",number, calculateFactorial(stack));

        printf("Continuar ? (s/n) ");
        scanf(" %c", &resp);
        resp = tolower(resp);
    } while (resp != 'n');
    
    system("pause");
}



int readNumber(Stack *stack) {
    int number;

    printf("CÁLCULO FATORIAL\n");
    do
    {
        printf("Digite um número positivo: ");
        scanf("%d", &number);
        fflush(stdin);
    } while (number < 0);
    
    for (int i = 1; i <= number; i++)
    {
        insertStack(i, stack);
    }
    return number;
}

int calculateFactorial(Stack *stack) {    
    if (stack->top == NULL)
    {
        return 0;
    }
    
    int result = 1;

    while (stack->top != NULL)
    {
        result *= unstack(stack);
    }
    return result;
}

Stack *startStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL)
    {
        printf("Mem?ria insufucuente");
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
        return -1;
    }

    Nodo *top = stack->top;
    int number = top->number;
    stack->top = top->next;
    free(top);
    return number;
}