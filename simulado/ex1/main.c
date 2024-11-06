/* Escreva uma função que receba como parâmetro uma fila dinâmica e possa identificar quais números
contidos na fila satisfazem a propriedade descrita abaixo e possa colocar esses números em uma pilha
estática. No final mostre a pilha estática usando o critério de pilha.
Propriedade: 3025 tem uma propriedade interessante: 30 + 25 = 55 e (55)2
= 3025.
Obs: Considere que todos os números contidos na fila possuem 4 dígitos. */

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define TAM 10


typedef struct nodo
{
  int numero;
  struct nodo *proximo;
} Nodo;

typedef struct fila
{
  Nodo *inicio;
  Nodo *fim;
} Fila;

typedef struct pilha
{
  int topo;
  int numeros[TAM];
} Pilha;



Fila *iniciarFila();
Pilha *iniciarPilha();
Nodo *iniciarNodo();
int lerNumero();
void inserirFila(Fila *);
void selecionarNumeros(Fila *);
void inserirPilha(Pilha *, int);
void mostrarPilha(Pilha *);


main() {
  setlocale(LC_ALL, "Portuguese");

  Fila *fila = iniciarFila();
  int opcao;

  do
  {
    printf("1 - INCLUIR\n2 - IDENTIFICAR NÚMEROS\n3 - SAIR\n");
    opcao = lerNumero();

    switch (opcao)
    {
    case 1:
      inserirFila(fila);
      break;

    case 2:
      selecionarNumeros(fila);
      break;

    case 3:
      break;
    
    default:
      printf("Opção inválida");
      break;
    }
  } while (opcao != 3);

  system("pause");
}


Fila *iniciarFila() {
  Fila *fila = (Fila *) malloc(sizeof(Fila));
  if (fila == NULL) {
    printf("Mémoria insufucuente para criar a fila");
    exit (1);
  }
  fila->fim = NULL;
  fila->inicio = NULL;
  return fila;
}

Pilha *iniciarPilha() {
  Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
  if (pilha == NULL) {
    printf("Mémoria insufucuente para criar a pilha");
    exit (1);
  }
  pilha->topo = 0;
  return pilha;
}

Nodo *iniciarNodo() {
  Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
  if (nodo == NULL) {
    printf("Mémoria insufucuente para criar a nodo");
    exit (1);
  }
  return nodo;
}

int lerNumero() {
  int numero;
  printf("Informe o número: ");
  scanf("%d", &numero);
  fflush(stdin);
  return numero;
}

void inserirFila(Fila *fila) {
  int numero = lerNumero();
  Nodo *nodo = iniciarNodo();

  if (fila->inicio == NULL)
  {
    fila->inicio = nodo;
  } else {
    fila->fim->proximo = nodo;
  }
  fila->fim = nodo;
  nodo->proximo = NULL;
  nodo->numero = numero;
}

void selecionarNumeros(Fila *fila) {
  Nodo *aux = fila->inicio;
  Pilha *pilha = iniciarPilha();

  while (aux != NULL)
  {
    int parte1 = aux->numero / 100;
    int parte2 = aux->numero % 100;
    int soma = parte1 + parte2;
    int result = soma * soma;

    if (result == aux->numero)
    {
      inserirPilha(pilha, aux->numero);
    }
    aux = aux->proximo;
  }

  mostrarPilha(pilha);
}

void inserirPilha(Pilha *pilha, int numero) {
  if (pilha->topo == TAM)
  {
    printf("Pilha cheia");
    return;
  }
  pilha->numeros[pilha->topo] = numero;
  pilha->topo++;
}

void mostrarPilha(Pilha *pilha) {
  int aux = pilha->topo - 1;
  printf("Resultado: ");
  while (aux != -1)
  {
    printf("%d  ", pilha->numeros[aux]);
    aux--;
  } 
  printf("\n");
}