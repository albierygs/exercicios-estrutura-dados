/* Escreva um programa com uma rotina recursiva que possa multiplicar um número por outro através de somas consecutivas. Exemplo: 5 * 4 = 5 + 5 + 5 +5 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int multiply(int, int);

main() {
    setlocale(LC_ALL, "Portuguese");

    int multiplying, multiplier;

    printf("Multiplicando: ");
    scanf("%d", &multiplying);
    fflush(stdin);
    printf("Multiplicador: ");
    scanf("%d", &multiplier);
    fflush(stdin);

    printf("Resultado: %d\n", multiply(multiplying, multiplier));

    system("pause");
}


int multiply(int multiplying, int multiplier) {
    if (multiplier > 0)
    {
        return multiplying + multiply(multiplying, --multiplier);
    }
    return 0;
}