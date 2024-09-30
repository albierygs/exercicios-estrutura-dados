/* Modifique as rotinas de Lista Duplamente Encadeada para que essa atenda as definições de uma lista circular duplamente encadeada. Desenvolva uma aplicação para testar as novas rotinas. */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo
{
    int number;
    struct nodo *next;
    struct nodo *previous;
} Nodo;

typedef struct head 
{
    Nodo *begin;
    Nodo *end;
    int quantity;
} List;

List *startList();
void insert(int, List *);
Nodo *getNewNodo();
void show(List *);

main() 
{
    setlocale(LC_ALL, "Portuguese");

    int option;
    List *list = startList();

    do
    {
        int number;

        printf("Escolha a opção:\n");
        printf("1 - INCLUIR NÚMERO\n2 - LISTAR\n3 - SAIR\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite o número a ser inserido: ");
            scanf("%d", &number);
            insert(number, list);
            break;

        case 2:
            show(list);
            break;

        case 3:
            break;

        default:
            printf("Opção inválida\n");
            break;
        }
    } while (option != 3);
}

List *startList() 
{
    List *aux = (List *) malloc(sizeof(List));

    if (aux == NULL)
    {
        printf("\nMemória insuficiente\n");
        exit(1);
    }
    aux->begin = NULL;
    aux->end = NULL;
    aux->quantity = 0;
    return aux;
}

Nodo *getNewNodo()
{
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));

    if (nodo == NULL)
    {
        printf("\nMemória insuficiente\n");
        exit(1);
    }
    return nodo;
}

void show(List *list)
{
    Nodo *currentNodo = list->end;
    int count = 0;

    while (count < list->quantity)
    {
        printf("%d  ", currentNodo->number);
        currentNodo = currentNodo->previous;
        count++;
    }
    printf("\n");
}

void insert(int number, List *list) 
{
    Nodo *nodo = getNewNodo();

    if (list->begin == NULL)
    {
        list->begin = nodo;
        nodo->previous = nodo;
        nodo->next = nodo;
    }
    else
    {
        list->begin->previous = nodo;
        list->end->next = nodo;
        nodo->previous = list->end;
        nodo->next = list->begin;
    }
    list->end = nodo;
    list->quantity++;
    nodo->number = number;
}