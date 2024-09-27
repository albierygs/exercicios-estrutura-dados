// Escreva um programa que receba n?meros inteiros e armazene em um vetor A. Ap?s use o m?todo chamado de ordena??o por inser??o para gerar um segundo vetor B ordenado. O m?todo de ordena??o por inser??o funciona da seguinte forma: Come?amos com o vetor A com os dados que queremos ordenar e um vetor B vazio. Para cada elemento no vetor A, verificamos em que ordem ele deve aparecer no vetor B (atrav?s da compara??o com os elementos j? existentes no novo vetor) e inserimos o elemento naquela posi??o. O algoritmo termina quando todos os elementos do vetor A est?o no vetor B.

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#define TAM 14

void ordenar(int [], int []);
void mostrar(int []);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int vetor[] = {4, 2, 8, 9, 1, 7, 10, 0, 3, 4, 1, 12, 6, -1};
    
    int novoVetor[TAM];

    printf("Vetor original\n");
    mostrar(vetor);

    ordenar(vetor, novoVetor);

    printf("\nVetor ordenado\n");
    mostrar(novoVetor);

    return 0;
}

void ordenar(int vetor[], int novoVetor[]) {
    for (int i = 0; i < TAM; i++)
    {
        int atual = vetor[i];

        if (i == 0)
        {
            novoVetor[i] = atual;
        }
        else if (atual >= novoVetor[i - 1])
        {
            novoVetor[i] = atual;
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (atual <= novoVetor[j])
                {
                    for (int x = i; x > j; x--)
                    {
                        novoVetor[x] = novoVetor[x - 1];
                    }
                    novoVetor[j] = atual;
                    break;
                }  
            }
        }
    }
}

void mostrar(int vetor[]) {
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }
}

