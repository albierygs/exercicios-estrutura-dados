//Escreva um programa que leia o nome e a nota de n alunos, armazene em uma lista duplamente encadeada, mostre o nome e a nota do melhor aluno (varrendo a lista da direita para a esquerda), mostre o nome e a nota do pior aluno (varrendo a lista da esquerda para a direita) e a média geral.
//Obs: Pegue sempre o primeiro nome encontrado no caso de duas ou mais notas serem iguais.

#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

typedef struct nodo
{
    char name[40];
    double grade;
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
void insert(char[], double);
T_list *getNewNodo();
void show();
void betterStudent();
void worstStudent();
void average();


main()
{
    setlocale(LC_ALL, "Portuguese");

    head = startHead();

    char resp;

    do
    {
        char name[40];
        double grade;

        printf("ALUNO\n");
        printf("Nome: ");
        scanf("%s", &name);
        printf("Nota: ");
        scanf("%lf", &grade);
        fflush(stdin);

        insert(name, grade);

        printf("Deseja inserir outro aluno? (s/n) ");
        scanf("%c", &resp);
        resp = tolower(resp);
    } while (resp != 'n');
    
    betterStudent();
    worstStudent();
    average(); 
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
        printf("ALUNO: %s  NOTA: %.1lf\n", currentNodo->name, currentNodo->grade);
        currentNodo = currentNodo->next;
    }
    printf("\n");
}

void insert(char name[], double grade) 
{
    T_list *nodo = getNewNodo();

    if (head->begin == NULL)
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
    nodo->grade = grade;
    strcpy(nodo->name, name);
    head->quantity++;
}

void betterStudent()
{
    T_list *current = head->end;
    T_list *better = current;

    while (current != NULL)
    {
        if (current->grade > better->grade)
        {
            better = current;
        }
        
        current = current->previous;
    }

    printf("Melhor aluno: %s - %.1lf\n", better->name, better->grade);
}

void worstStudent()
{
    T_list *current = head->begin;
    T_list *worst = current;

    while (current != NULL)
    {
        if (current->grade < worst->grade)
        {
            worst = current;
        }
        
        current = current->next;
    }

    printf("Pior aluno: %s - %.1lf\n", worst->name, worst->grade);
}

void average()
{
    T_list *current = head->end;
    double sum = 0;

    while (current != NULL)
    {
        sum += current->grade;       
        current = current->previous;
    }

    printf("Média geral: %.1lf\n", (sum / head->quantity));
}