/* Escreva um programa com uma fun��o recursiva que possa converter um n�mero decimal em um n�mero bin�rio. Use o m�todo das divis�es sucessivas. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define BASE 2

void toBinary(int);

main() {
    setlocale(LC_ALL, "Portuguese");

    int number;
    printf("Informe o n�mero: ");
    scanf("%d", &number);
    fflush(stdin);

    printf("%d em bin�rio: ", number);
    toBinary(number);
    printf("\n");

    system("pause");
}


void toBinary(int number) {
    if (number > 0) {
        toBinary(number / 2);
        printf("%d", number % 2);
    }
}