//  Escreva um programa que leia palavras do teclado, guardando em um vetor e ap�s escreva estas palavras na tela, na ordem inversa em que foram lidas.

#include <stdio.h>
#include <locale.h>
#define MAX 10
#define TAM_PALAVRA 50

void inserir(int [][TAM_PALAVRA], int *);
void listar(int [][TAM_PALAVRA], int);

void main()
{
    setlocale(LC_ALL, "Portuguese");

    char vetor[MAX][TAM_PALAVRA];
    int total = 0, option;

    do
    {
        printf("1 - INCLUIR\n");
        printf("2 - LISTAR INVERSAMENTE\n");
        printf("3 - FIM\n");
        scanf("%d", &option);

        system("cls");

        switch (option)
        {
            case 1:
                inserir(vetor, &total);
                break;
            
            case 2: 
                listar(vetor, total);
                break;

            case 3: 
                break;
                
            default:
                printf("Op��o inv�lida\n");
                break;
        }
    } while (option != 3);
}

void inserir(int vetor[][TAM_PALAVRA], int *total) {
    if (*total < 10)
    {
        printf("Digite uma palavara: ");
        scanf("%s", &vetor[*total]);
        fflush(stdin);
        *total = *total + 1;
        return;
    }
    printf("N�o � poss�vel adicionar mais palavras\n");
}

void listar(int vetor[][TAM_PALAVRA], int total) {
    printf("Palavras em ordem inversa de inser��o: ");
    for (int i = total - 1; i >= 0; i--)
    {
        printf("%s  ", vetor[i]);
    }
    printf("\n");
}


