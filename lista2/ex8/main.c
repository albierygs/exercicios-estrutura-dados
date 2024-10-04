/* 
A expressão em C, m % n, resulta o resto de m ao dividir por n. Defina o máximo divisor comum (MDC) de dois inteiros, x e y, por:
mdc( x, y) = y se ((y <= x) && ((x % y) == 0))
mdc( x, y) = mdc( y, x) se (x < y)
mdc( x, y) = mdc( y, x % y) caso contrário 
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calculateMDC(int, int);

main() {
    setlocale(LC_ALL, "Portuguese");

    printf("%d\n", calculateMDC(20, 24));

    system("pause");
}


int calculateMDC(int x, int y) {
    if (x < y)
    {
        return calculateMDC(y, x); 
    }
    else if (y<= x && x % y == 0)
    {
        return y;
    }
    else
    {
        return calculateMDC(y, x % y);
    }
    
}