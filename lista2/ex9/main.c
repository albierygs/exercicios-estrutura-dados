/* Escreva um programa com uma função recursiva que possa converter um número decimal em um número binário. Use o método das divisões sucessivas. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define BASE 2

void toBinary(int);

main() {
    setlocale(LC_ALL, "Portuguese");

    int number;
    printf("Informe o número: ");
    scanf("%d", &number);
    fflush(stdin);

    printf("%d em binário: ", number);
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