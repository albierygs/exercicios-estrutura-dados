/* Escreva um programa para ler dados e colocar em um vetor, após crie uma rotina recursiva para ordenar o vetor e no final mostre o vetor ordenado. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define SIZE 10


void readVector(int [], int size);
void orderVector(int [], int, int);
void showVector(int [], int);

main() {
    setlocale(LC_ALL, "Portuguese");

    int vector[SIZE];

    readVector(vector, 0);

    printf("\nVetor original\n");
    showVector(vector, 0);

    orderVector(vector, 0, 1);

    printf("\nVetor ordenado\n");
    showVector(vector, 0);

    system("pause");
}


void readVector(int vector[], int index) {
    if (index < SIZE)
    {
        printf("Valor %d: ", index + 1);
        scanf("%d", &vector[index]);
        fflush(stdin);
        readVector(vector, ++index); 
    }
}

void orderVector(int vector[], int aux1, int aux2) {
    if (aux1 < SIZE - 1)
    {
        if (aux2 < SIZE)
        {
            if (vector[aux1] > vector[aux2])
            {
                int aux = vector[aux1];
                vector[aux1] = vector[aux2];
                vector[aux2] = aux;
            }
            orderVector(vector, aux1, ++aux2);            
        } else {
            orderVector(vector, ++aux1, aux1 + 1);
        }        
    }    
}

void showVector(int vector[], int index) {
    if (index < SIZE)
    {
        printf("%d  ", vector[index]);
        showVector(vector, ++index);
    }
    
}