// editor de texto cada linha com 30 caracteres

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct nodo
{
  char texto[30];
  int posicao;
  struct nodo *proximo;
  struct nodo *anterior;
} Nodo;

typedef struct lista
{
  Nodo *comeco;
  Nodo *fim;
} Lista;

Lista *iniciarLista();
void inserir(char [], int, Lista *);
Nodo *iniciarNodo(char [], int);
void mostrar(Lista *);
void atualizarPosicoes(Lista *);


main() {
  setlocale(LC_ALL, "Portuguese");

  Lista *lista = iniciarLista();

  char a[30], b[30], c[30];
  fgets(a, sizeof(a), stdin);
  fgets(b, sizeof(b), stdin);
  fgets(c, sizeof(c), stdin);

  inserir(a, 0, lista);
  inserir(b, 0, lista);
  inserir(c, 1, lista);

  mostrar(lista);

  system("pause");
}



Lista *iniciarLista() {
  Lista *lista = (Lista *) malloc(sizeof(Lista));
  if (lista == NULL) {
    printf("\nMémoria insuficiente para criar a lista\n");
    exit(1);
  }
  lista->comeco = NULL;
  lista->fim = NULL;
  return lista;
}

Nodo *iniciarNodo(char texto[], int posicao) {
  Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
  if (nodo == NULL) {
    printf("\nMémoria insuficiente para criar o nodo\n");
    exit(1);
  }
  strcpy(nodo->texto, texto);
  nodo->posicao = posicao;
  return nodo;
}

void mostrar(Lista *lista) {
  Nodo *aux = lista->comeco;

  while (aux != NULL) {
    printf("%s", aux->texto);
    aux = aux->proximo;
  }
}

void inserir(char texto[], int posicao, Lista *lista) {
  printf("\nInserindo %s", texto);
  Nodo *nodo = iniciarNodo(texto, posicao);

  if (lista->comeco == NULL) { // inserção do primeiro
    lista->comeco = nodo;
    lista->fim = nodo;
    nodo->anterior = NULL;
    nodo->proximo = NULL;
  } else if (posicao == 0) { // inserção na primeira posição
    nodo->proximo = lista->comeco;
    lista->comeco->anterior = nodo;
    lista->comeco = nodo;
    nodo->anterior = NULL;

    atualizarPosicoes(lista);
  } else if (posicao > lista->fim->posicao) { // inserção no fim
    lista->fim->proximo = nodo;
    nodo->anterior = lista->fim;
    nodo->proximo = NULL;
    lista->fim = nodo;
  } else { // inserção no meio
    Nodo *aux = lista->comeco->proximo;

    while (aux != NULL && aux->posicao < posicao)
    {
      aux = aux->proximo;
    }

    nodo->proximo = aux;
    nodo->anterior = aux->anterior;
    aux->anterior->proximo = nodo;
    aux->anterior = nodo;   

    atualizarPosicoes(lista);
  }
}

void atualizarPosicoes(Lista *lista) {
  Nodo *aux = lista->comeco;

  while (aux != NULL && aux->posicao + 1 == aux->proximo->posicao)
  {
    aux = aux->proximo;
  }
  aux = aux->proximo;

  while (aux != NULL)
  {
    aux->posicao = aux->anterior->posicao + 1;
    aux = aux->proximo;
  }
}