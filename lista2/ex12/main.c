/* Escreva um programa que seja capaz de criar duas listas simplesmente encadeadas e que tenha um método recursivo para concatenar as duas listas em uma terceira lista.
Exemplo: Lista 1 = (1, 5, 9, 18, 24) Lista2 = (7, 8, 20, 24, 30) Lista R = (1, 7, 5, 8, 9, 20, 18, 24, 24, 30).
Obs: Escreva um menu com os seguintes itens: Inclui A, Inclui B, Concatena, Lista A, Lista B, Lista Concatenação e Fim. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct nodo
{
    int number;
    struct nodo *next;
} Nodo;

typedef struct list
{
    Nodo *begin;
    Nodo *end;
    int count;
} List;


List *startList();
int menu();
int readNumber();
void concat(Nodo *, Nodo *, List *);
void insert(int, List *);
Nodo *getNewNodo();
void show(List *);



main() {
    setlocale(LC_ALL, "Portuguese");

    List *A = startList(), *B = startList(), *C;
    int option;

    do
    {
        option = menu();
        int number;

        switch (option)
        {
            case 1:
                number = readNumber();
                insert(number, A);
                break;

            case 2:
                number = readNumber();
                insert(number, B);
                break;

            case 3:
                C = startList();
                concat(A->begin, B->begin, C);
                break;

            case 4: 
                show(A);
                break;

            case 5: 
                show(B);
                break;

            case 6: 
                show(C);
                break;

            case 7: 
                break;
            
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (option != 7);

    system("pause");
}


int menu() 
{
    int option;
    printf("1 - INCLUIR EM A\n2 - INCLUIR EM B\n3 - CONCATENAR\n4 - LISTAR A\n5 - LISTAR B\n6 - LISTAR CONCATENADA\n7 - FIM\n");
    printf("Escolha a opção: ");
    scanf("%d", &option);
    fflush(stdin);
    return option;    
}

int readNumber() {
    int number;
    printf("Número a ser incluído: ");
    scanf("%d", &number);
    fflush(stdin);
    return number;
}

List *startList() 
{
    List *list = (List *) malloc(sizeof(List));

    if (list == NULL)
    {
        printf("\nMemória insuficiente\n");
        exit(1);
    }
    list->begin = NULL;
    list->end = NULL;
    list->count = 0;
    return list;
}

void insert(int n, List *list) {
    Nodo *new = getNewNodo();

    if (list->begin == NULL)
    {
        list->begin = new;
        list->end = new;
    } else
    {
        list->end->next = new;
        list->end = new;
    }

    new->next = NULL;
    list->count++;
    new->number = n;
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

void concat(Nodo *currentList1, Nodo *currentList2, List *list) {
    if (currentList1 == NULL && currentList2 == NULL)
    {
        return;
    }

    if (currentList1 != NULL)
    {
        insert(currentList1->number, list);
    }
    concat(currentList2, currentList1->next, list);
}

void show(List *list)
{
    Nodo *currentNodo = list->begin;

    while (currentNodo != NULL)
    {
        printf("%d  ", currentNodo->number);
        currentNodo = currentNodo->next;
    }
    printf("\n");
}