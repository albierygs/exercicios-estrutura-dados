// Escreva um programa que receba números inteiros em uma lista duplamente encadeada, não vazia, usando os seguintes critérios:
// a) Para cada entrada N, coloque N no final da lista.
// b) Percorra a lista do final para o início apagando todos os nós que são maiores do que N.

#include <stdio.h>

typedef struct nodo
{
    char number;
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
void removeBiggerThan(int);

main() 
{
    int option;
    head = startHead();

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
            insert(number);
            break;

        case 2:
            show();
            break;

        case 3:
            break;

        default:
            printf("Opção inválida\n");
            break;
        }
    } while (option != 3);
    
}

T_head *startHead() 
{
    T_head *aux = (T_head *) malloc(sizeof(T_head));

    if (aux == NULL)
    {
        printf("\nMémoria insuficiente\n");
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
        printf("\nMémoria insuficiente\n");
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
    
    removeBiggerThan(number);
}

void removeBiggerThan(int number)
{
    T_list *current = head->end;

    if (current == head->begin)
    {
        return;
    }

    while (current != NULL)
    {
        if (current->number > number)
        {
            T_list *temp = current;

            if (current == head->begin)
            {
                head->begin = current->next;
                head->begin->previous = NULL;
            }
            else
            {
                current->next->previous = current->previous;
                current->previous->next = current->next;
            }

            current = temp->previous;
            free(temp);
            head->quantity--;
        }
        else 
        {
            current = current->previous;
        }
    }
}