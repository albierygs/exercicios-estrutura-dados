// Seja X = (x1, x2, ..., xn) e Y = (y1, y2, ..., ym) duas listas simplesmente encadeadas. Escreva um programa que leia as duas listas e as intercale, formando uma lista encadeada Z = (x1, y1, x2, y2,..., xn,,ym). Mostre o resultado na tela.

#include <stdio.h>

typedef struct nodo
{
    int info;
    struct nodo *next;
} T_list;

typedef struct cab_lista
{
    T_list *begin;
    T_list *end;
    int quantity;
} T_head;
T_head *x, *y, *z;

void insert(int, T_head *);
void interleave();
T_list *get_address();
void show();
T_head *start_head();

main()
{
    int option;
    x = start_head();
    y = start_head();
    z = start_head();

    do
    {
        int number;

        printf("\nEscolha a opção desejada: ");
        printf("\n1- INSERIR X\n2 - INSERIR Y\n3 - INTERCALAR E MOSTRAR RESULTADO\n4 - SAIR\n");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("Número para inserir: ");
                scanf("%d", &number);
                insert(number, x);
                break;
            
            case 2:
                printf("Número para inserir: ");
                scanf("%d", &number);
                insert(number, y);
                break;

            case 3:
                interleave();
                show();
                break;

            case 4: 
                break;

            default:
                printf("\nOpção inválida");
                break;
        }
    } while (option != 4);
}

void insert(int n, T_head *head) {
    T_list *new = get_address();

    if (head->begin == NULL)
    {
        head->begin = new;
        head->end = new;
    } else
    {
        head->end->next = new;
        head->end = new;
    }

    new->next = NULL;
    head->quantity++;
    new->info = n;
}


T_list *get_address() {
    T_list *new = (T_list *) malloc(sizeof(T_list));

    if (new == NULL)
    {
        printf("\nMemória insuficiente");
        exit(1);
    }

    return new;
}

T_head *start_head() {
    T_head *head = (T_head *) malloc(sizeof(T_head));

    if (head == NULL)
    {
        printf("\nMemória insuficiente");
        exit(1);
    }

    head->begin = NULL;
    head->end = NULL;
    head->quantity = 0;
    return head;
}

void show() {
    T_list *aux = z->begin;

    while (aux != NULL)
    {
        printf("%d  ", aux->info);
        aux = aux->next;
    }
    getchar();
}

void interleave() {
    T_list *aux_x = x->begin;
    T_list *aux_y = y->begin;

    while (aux_x != NULL || aux_y != NULL)
    {
        if (aux_x != NULL)
        {
            insert(aux_x->info, z);
            aux_x = aux_x->next;
        } 
        if (aux_y != NULL)
        {
            insert(aux_y->info, z);
            aux_y = aux_y->next;
        }   
    }
}