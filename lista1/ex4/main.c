/*
 *Um conjunto cujos elementos são alguns inteiros entre -2 e 3 que podem ser representados por valores lógicos (p. ex. 1, verdadeiro e 0, falso). Assim, {-1, 0, 2} é representado por {0, 1, 1, 0, 1, 0}. Com esta representação, escreva um programa que mostre o elemento máximo, elemento mínimo e número de elementos.
 *
 */

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 6

void initialize(int []);
void add(int []);
int minElement(int []);
int maxElement(int []);
int quantityElements(int []);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int vetor[TAM];
    int option;

    initialize(vetor);

    do {
        printf("Escolha a opção desejada:\n");
        printf("1 - INCLUIR\n");
        printf("2 - VER ELEMENTO MÍNIMO\n");
        printf("3 - VER ELEMENTO MÁXIMO\n");
        printf("4 - VER NÚMERO DE ELEMENTOS\n");
        printf("5 - SAIR\n");
        scanf("%d", &option);

        system("cls");

        switch (option) {
            int returned;

            case 1:
                add(vetor);
                break;
            case 2:
                returned = minElement(vetor);
                returned == -1
                    ? printf("Nenhum número foi adicionado\n")
                    : printf("Menor elemento: %d\n", returned);
                break;
            case 3:
                returned = maxElement(vetor);
                returned == -1
                    ? printf("Nenhum número foi adicionado\n")
                    : printf("Maior elemento: %d\n", returned);
                break;
            case 4:
                returned = quantityElements(vetor);
                returned == 0
                    ? printf("Nenhum número foi adicionado\n")
                    : printf("Quantidade de elementos: %d\n", returned);
                break;
            case 5:
                break;
            default:
                printf("Escolha uma opção válida.\n");
        }
    } while (option != 5);

    return 0;
}

void initialize(int vetor[]) {
    for (int i = 0; i < TAM; ++i) {
        vetor[i] = 0;
    }
}

void add(int vetor[]) {
    int number;

    do {
        printf("Digite um número entre -2 e 3: ");
        scanf("%d", &number);

        if (number > 3 || number < -2) {
            printf("Número fora do intervalo permitido.\n");
        }
    } while (number > 3 || number < -2);

    vetor[number + 2] = 1;
}

int minElement(int vetor[]) {
    for (int i = 0; i < TAM; ++i) {
        if (vetor[i] == 1) {
            return i - 2;
        }
    }
    return -1;
}

int maxElement(int vetor[]) {
    for (int i = TAM - 1; i >= 0; --i) {
        if (vetor[i] == 1) {
            return i - 2;
        }
    }
    return -1;
}

int quantityElements(int vetor[]) {
    int count = 0;

    for (int i = 0; i < TAM; ++i) {
        if (vetor[i] == 1) {
            count++;
        }
    }
    return count;
}