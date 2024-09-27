//Uma maneira usual de representar um conjunto � pela lista de seus elementos. Supondo esta representa��o, escreva um programa com os procedimentos para as opera��es de uni�o e interse��o de conjuntos.
// Dica: Desenvolva um menu com as op��es de Inclus�o no conjunto A, Inclus�o no conjunto B, Listagem A, Listagem B, Uni�o, Interse��o, Listagem da Uni�o, Listagem da Interse��o e fim.
// Obs: Use listas simplesmente encadeadas para resolver o problema.

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

typedef struct nodo
{
    int number;
    struct nodo *next;
} T_list;

typedef struct head 
{
    T_list *begin;
    T_list *end;
    int quantity;
} T_head;

T_head *a, *b, *unity, *intersection;

T_head *startHead();
void insert(int, T_head *);
T_list *getNewNodo();
void show(T_head *);
void intersect();
void unite();
bool checkAlreadyIncluded(int, T_head *);

int readNumber();

main()
{
    setlocale(LC_ALL, "Portuguese");

    a = startHead();
    b = startHead();
    unity = startHead();
    intersection = startHead();

    int option;

    do
    {
        int number;

        printf("\nEscolha a op��o desejada: ");
        printf("\n1 - INSERIR A\n2 - INSERIR B\n3 - LISTAR A\n4 - LISTAR B\n5 - UNI�O\n6 - INTERSE��O\n7 - SAIR\n");
        scanf("%d", &option);
        fflush(stdin);

        switch (option)
        {
            case 1:
                number = readNumber();
                insert(number, a);
                break;
            
            case 2:
                number = readNumber();
                insert(number, b);
                break;

            case 3:
                printf("CONJUNTO A\n");
                show(a);
                break;

            case 4: 
                printf("CONJUNTO B\n");
                show(b);
                break;

            case 5:
                unite();
                printf("UNI�O\n");
                show(unity);
                break;

            case 6:
                intersect();
                printf("INTERSE��O\n");
                show(intersection);
                break;

            case 7:
                break;

            default:
                printf("\nOp��o inv�lida");
                break;
        }
    } while (option != 7);
}


T_head *startHead() 
{
    T_head *head = (T_head *) malloc(sizeof(T_head));

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

T_list *getNewNodo()
{
    T_list *nodo = (T_list *) malloc(sizeof(T_list));

    if (nodo == NULL)
    {
        printf("\nM�moria insuficiente\n");
        exit(1);
    }
    return nodo;
}

void show(T_head *head)
{
    T_list *currentNodo = head->begin;

    while (currentNodo != NULL)
    {
        printf("%d  ", currentNodo->number);
        currentNodo = currentNodo->next;
    }
    printf("\n");
}

void insert(int number, T_head *head) 
{
    T_list *newNodo = getNewNodo();

    if (head->begin == NULL)
    {
        head->begin = newNodo;
        head->end = newNodo;
    } else
    {
        head->end->next = newNodo;
        head->end = newNodo;
    }

    newNodo->next = NULL;
    head->quantity++;
    newNodo->number = number;
}

int readNumber()
{
    int number;
    printf("N�mero para inserir: ");
    scanf("%d", &number);
    fflush(stdin);
    return number;
}

void intersect()
{
    T_list *currentA = a->begin;

    while (currentA != NULL)
    {
        int currentNumber = currentA->number;

        if (!checkAlreadyIncluded(currentNumber, intersection))
        {
            T_list *currentB = b->begin;

            while (currentB != NULL)
            {
                if (currentNumber == currentB->number)
                {
                    insert(currentNumber, intersection);
                    break;
                }
                currentB = currentB->next;
            }
        }
        currentA = currentA->next;
    }
}

void unite()
{
    T_list *currentA = a->begin;
    T_list *currentB = b->begin;

    while (currentA != NULL || currentB != NULL)
    {
        if (currentA != NULL)
        {
            if (!checkAlreadyIncluded(currentA->number, unity))
            {
                insert(currentA->number, unity);
            }
            currentA = currentA->next;
        }

        if (currentB != NULL)
        {
            if (!checkAlreadyIncluded(currentB->number, unity))
            {
                insert(currentB->number, unity);
            }
            currentB = currentB->next;
        }
    }
}

bool checkAlreadyIncluded(int number, T_head *head)
{
    T_list *current = head->begin;

    while (current != NULL)
    {
        if (current->number == number)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}