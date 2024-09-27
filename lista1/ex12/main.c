//Escreva um programa que leia duas seqüências de caracteres, equivalentes a duas palavras, armazenando-as em duas listas encadeadas distintas (cada letra deve ser um nodo da lista). Após, remova as vogais existentes nas duas listas e, em seguida, determine se elas têm as mesmas consoantes.


#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct nodo
{
    char letter;
    struct nodo *next;
} T_list;

typedef struct head 
{
    T_list *begin;
    T_list *end;
    int quantity;
} T_head;

T_head *h1, *h2;

T_head *startHead();
void insert(char[], T_head *);
T_list *getNewNodo();
void removeVowels(T_head *);
void show(T_head *);
bool isVowel(char);

main() 
{
    h1 = startHead();
    h2 = startHead();

    char word1[20] = {0}, word2[20] = {0};

    printf("Digite uma palavra: ");
    scanf("%s", &word1);
    printf("Digite outra palavra: ");
    scanf("%s", &word2);

    insert(word1, h1);
    insert(word2, h2);
    printf("Antes de retirar as vogais:\n");
    show(h1);
    show(h2);
    removeVowels(h1);
    removeVowels(h2);
    printf("Depois de retirar as vogais:\n");
    show(h1);
    show(h2);
}


T_head *startHead() 
{
    T_head *head = (T_head *) malloc(sizeof(T_head));

    if (head == NULL)
    {
        printf("\nMémoria insuficiente\n");
        exit(1);
    }
    head->begin = NULL;
    head->end = NULL;
    head->quantity = 0;
    return head;
}

void insert(char word[], T_head *head) 
{
    int i = 0;

    while (word[i] != '\0')
    {
        char currentLetter = word[i];
        T_list *newNodo = getNewNodo();

        if (head->begin == NULL)
        {
            head->begin = newNodo;
        }
        else
        {
            head->end->next = newNodo;
        }
        
        head->end = newNodo;
        head->quantity++;
        newNodo->letter = currentLetter;
        newNodo->next = NULL;

        i++;
    }  
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

void show(T_head *head)
{
    T_list *currentNodo = head->begin;

    while (currentNodo != NULL)
    {
        printf("%c", currentNodo->letter);
        currentNodo = currentNodo->next;
    }
    printf("\n");
}

void removeVowels(T_head *head)
{
    T_list *currentNodo = head->begin;
    T_list *previousNodo = NULL;

    while (currentNodo != NULL)
    {
        if (isVowel(currentNodo->letter))
        {
            T_list *aux = currentNodo;

            if (currentNodo == head->begin)
            {
                head->begin = currentNodo->next;
            }
            else if (currentNodo == head->end)
            {
                head->end = previousNodo;
                head->end->next = NULL;
            }
            else
            {
                previousNodo->next = currentNodo->next;
            }
            
            currentNodo = currentNodo->next;
            free(aux);
            head->quantity--;
        }
        else
        {
            previousNodo = currentNodo;
            currentNodo = currentNodo->next;
        }
    }
}

bool isVowel(char letter) 
{
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}