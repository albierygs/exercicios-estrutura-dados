/* Modifique as rotinas de Lista Encadeada para que essa atenda as defini��es de uma lista circular simplesmente encadeada. Desenvolva uma aplica��o para testar as novas rotinas. */


#include <stdio.h>
#include <locale.h>

typedef struct nodo
{
    int number;
    struct nodo *next;
} Nodo;

typedef struct head 
{
    Nodo *begin;
    Nodo *end;
    int quantity;
} List;

List *list;


List *startList();
void insert(int, List *);
Nodo *getNewNodo();
void show(List *);
int menu();

main() {
    setlocale(LC_ALL, "Portuguese");

    list = startList();
    int option;

    do
    {
        option = menu();

        switch (option)
        {
            case 1:
                insert(readNumber(), list);
                break;
            case 2:
                show(list);
                break;
            case 3:
                break;
            default:
                printf("Op��o inv�lida\n");
                break;
        }
    } while (option != 3);
}


int menu() {
    printf("Escolha a op��o:\n");
    printf("1 - INSERIR\n2 - LISTAR\n3 - SAIR\n");
    int number; 
    scanf("%d", &number);
    fflush(stdin);
    return number;
}

List *startList() 
{
    List *head = (List *) malloc(sizeof(List));

    if (head == NULL)
    {
        printf("\nM�moria insuficiente\n");
        exit(1);
    }
    head->begin = NULL;
    head->end = NULL;
    head->quantity = 0;
    return head;
}

Nodo *getNewNodo()
{
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));

    if (nodo == NULL)
    {
        printf("\nM�moria insuficiente\n");
        exit(1);
    }
    return nodo;
}

void show(List *list)
{
    Nodo *currentNodo = list->begin;
    int total = 0;

    while (total < list->quantity)
    {
        printf("%d  ", currentNodo->number);
        currentNodo = currentNodo->next;
        total++;
    }
    printf("\n");
}

void insert(int number, List *list) 
{
    Nodo *newNodo = getNewNodo();

    if (list->begin == NULL)
    {
        list->begin = newNodo;
        list->end = newNodo;
        newNodo->next = newNodo;
    } else
    {
        list->end->next = newNodo;
        list->end = newNodo;
        newNodo->next = list->begin;
    }

    list->quantity++;
    newNodo->number = number;
}

int readNumber()
{
    int number;
    printf("Informe o número: ");
    scanf("%d", &number);
    fflush(stdin);
    return number;
}