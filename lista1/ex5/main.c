/*Fazer um programa que leia 10 valores reais via teclado armazenando em um vetor. Em seguida, verifique se existe algum elemento maior do que 50 escrevendo na tela as posições onde estes se encontram no vetor.*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 10

void add(int [], int);
void verifyBiggerThan50(int []);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int vetor[TAM];

    add(vetor, 0);
    verifyBiggerThan50(vetor);

    system("pause");
    return 0;
}

void add(int vetor[], int position) {
    if (position < TAM) {
        printf("%d número: ", (position + 1));
        scanf("%d", &vetor[position]);
        system("cls");

        add(vetor, ++position);
    }
}

void verifyBiggerThan50(int vetor[]) {
    for (int i = 0; i < TAM; ++i) {
        if (vetor[i] > 50) {
            printf("Número maior que 50 (%d) na posição %d\n", vetor[i], (i + 1));
        }
    }
}