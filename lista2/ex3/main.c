// Escreva um programa que possa gerar números aleatórios e distribui-los em duas filas. As filas dos pares e a fila dos ímpares. A geração de números aleatórios deve acabar quando for gerado um número primo. Posteriormente retire de forma intercalada os elementos das filas e mostre na tela.
// Obs: Use fila em estrutura estática.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define SIZE 10

typedef struct queue
{
    int number[SIZE];
    int begin;
    int end;
    int count;
} Queue;


Queue *startQueue();
void showQueue(Queue *);
int generateRandomNumber();
void insert(int, Queue *);
int removeFromQueue(Queue *);
bool checkNumberPrime(int);


main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Queue *even = startQueue();
    Queue *odd = startQueue();
    int randomNumber;

    do
    {
        randomNumber = generateRandomNumber();

        if (!checkNumberPrime(randomNumber))
        {
            if (randomNumber % 2 == 0)
            {
                insert(randomNumber, even); 
            }
            else
            {
                insert(randomNumber, odd);
            }
        }
        else 
        {
            printf("\nNúmero primo: %d\n", randomNumber);
        }
    } while (!checkNumberPrime(randomNumber));
    
    while (even->count != 0 || odd->count != 0)
    {
        if (even->count != 0)
        {
            printf("Número par: %d\n", removeFromQueue(even));
        }

        if (odd->count != 0)
        {
            printf("Número ímpar: %d\n", removeFromQueue(odd));
        }
    }

    system("pause");
}


Queue *startQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Memória insufucuente");
        exit(1);
    }
    queue->begin = 0;
    queue->end = 0;
    queue->count = 0;
    return queue;
}

void showQueue(Queue *queue) {
    int aux = queue->begin;
    while (aux != queue->end)
    {
        printf("%d  ", queue->number[aux]);
        aux = (aux + 1) % SIZE;
    }
}

int generateRandomNumber() {
    return rand() % 101;
}

void insert(int number, Queue *queue) {
    if (queue->count == SIZE)
    {
        printf("Fila cheia\n");
        return;
    }
    queue->number[queue->end] = number;
    queue->end = (queue->end + 1) % SIZE;
    queue->count++;
}

int removeFromQueue(Queue *queue) {
    if (queue->count == 0)
    {
        printf("Fila vazia\n");
        return -1;
    }
    
    int value = queue->number[queue->begin];
    queue->begin = (queue->begin + 1) % SIZE;
    queue->count--;
    return value;
} 

bool checkNumberPrime(int number) {
    int count = 0;

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            count++;
        }
    }
    
    if (count == 2)
    {
        return true;
    }
    return false;
}