//Escreva um programa com um procedimento para inverter uma lista duplamente encadeada, de modo que o último elemento se torne o primeiro, o penúltimo o segundo e assim por diante.

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

typedef struct nodo
{
    int number;
    struct nodo *next;
    struct nodo *previous;
} T_list;

typedef struct head
{
    T_list *begin;
    T_list *end;
    int quantity;
} T_head;
T_head *head;

T_head *startHead();
void insert(int);
T_list *getNewNodo();
void show();
void reverse();

main()
{
    setlocale(LC_ALL, "Portuguese");
    
    head = startHead();

    char resp;

    do
    {
        int number;

        printf("Número a ser inserido: ");
        scanf("%d", &number);
        fflush(stdin);

        insert(number);

        printf("Deseja inserir outro número? (s/n) ");
        scanf("%c", &resp);
        resp = tolower(resp);
    } while (resp != 'n');
    
    printf("LISTA ORIGINAL\n");
    show();
    reverse();
    printf("LISTA INVERTIDA\n");
    show();
}


T_head *startHead() 
{
    T_head *aux = (T_head *) malloc(sizeof(T_head));

    if (aux == NULL)
    {
        printf("\nM?moria insuficiente\n");
        exit(1);
    }
    aux->begin = NULL;
    aux->end = NULL;
    aux->quantity = 0;
    return aux;
}

T_list *getNewNodo()
{
    T_list *nodo = (T_list *) malloc(sizeof(T_list));

    if (nodo == NULL)
    {
        printf("\nM?moria insuficiente\n");
        exit(1);
    }
    return nodo;
}

void show()
{
    T_list *currentNodo = head->begin;

    while (currentNodo != NULL)
    {
        printf("%d  ", currentNodo->number);
        currentNodo = currentNodo->next;
    }
    printf("\n");
}

void insert(int number) 
{
    T_list *nodo = getNewNodo();

    if (head->end == NULL)
    {
        head->begin = nodo;
        nodo->previous = NULL;
    }
    else
    {
        head->end->next = nodo;
        nodo->previous = head->end;
    }
    head->end = nodo;
    nodo->next = NULL;
    head->quantity++;
    nodo->number = number;
}

void reverse()
{
    T_list *begin = head->begin;
    T_list *end = head->end;

    int middle = head->quantity / 2;

    for (int i = 0; i < middle; i++)
    {
        int aux = begin->number;
        begin->number = end->number;
        end->number = aux;

        begin = begin->next;
        end = end->previous;
    }
}