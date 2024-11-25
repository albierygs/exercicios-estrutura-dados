// editor de texto cada linha com 30 caracteres

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

#define TAM 31


typedef struct nodo
{
  char texto[TAM];
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
void editar(Lista *);
Nodo *iniciarNodo(char [], int);
void mostrar(Lista *, Nodo *, int);
void atualizarPosicoes(Lista *);
int acharUltimoCaracter(Nodo *);
void moverCursor(Nodo **, int *, char);


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

  editar(lista);

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

void mostrar(Lista *lista, Nodo *nodoEditor, int posicaoEditor) {
  Nodo *aux = lista->comeco;

  while (aux != NULL) {
    if (nodoEditor == NULL || aux != nodoEditor) {
      printf("%s", aux->texto);
    } else {
      for (int i = 0; i < acharUltimoCaracter(aux) + 1; i++) {
        if (i == posicaoEditor)
        {
          printf("%c|", aux->texto[i]);
        } else {
          printf("%c", aux->texto[i]);
        }
      }
    }
    aux = aux->proximo;
  }
}

void inserir(char texto[], int posicao, Lista *lista) {
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

int acharUltimoCaracter(Nodo *nodo) {  
  for (int i = 0; i < TAM; i++) {
    if (nodo->texto[i] == '\n') {
      return i - 1;
    }
  }
  return -1;
}

void moverCursor(Nodo **nodo, int *posicao, char tipo) {
  if (tipo == 'e') {
    if (!(*posicao == 0 && (*nodo)->anterior == NULL)) {
      if (*posicao == 0) {
        *nodo = (*nodo)->anterior;
        *posicao = acharUltimoCaracter(*nodo);
      } else {
        (*posicao)--;
      }
    }
  } else if (tipo == 'd') {
    int ultimoCaracter = acharUltimoCaracter(*nodo);

    if (!(*posicao == ultimoCaracter && (*nodo)->proximo == NULL)) {
      if (*posicao == ultimoCaracter) {
        *nodo = (*nodo)->proximo;
        *posicao = 0;
      } else {
        (*posicao)++;
      }
    }
  } else if (tipo == 'c') {
    if (!((*nodo)->anterior == NULL)) {
      *nodo = (*nodo)->anterior;
      *posicao = acharUltimoCaracter(*nodo);
    } else {
      *posicao = 0;
    }
  } else if (tipo == 'b') {
    if (!((*nodo)->proximo == NULL)) {
      *nodo = (*nodo)->proximo;
    }
    *posicao = acharUltimoCaracter(*nodo);
  }
}

void editar(Lista *lista) {
  Nodo *aux = lista->fim;
  int posicao = acharUltimoCaracter(aux);

  while (1) {
    system("cls");
    mostrar(lista, aux, posicao);

    int tecla = getch();
        
    if (tecla == 0 || tecla == 224) {
      tecla = getch();

      if (tecla == 72) { // tecla pra cima
        moverCursor(&aux, &posicao, 'c');
      } else if (tecla == 80) { // tecla pra baixo
        moverCursor(&aux, &posicao, 'b');
      } else if (tecla == 75) { // tecla pra esquerda
        moverCursor(&aux, &posicao, 'e');
      } else if (tecla == 77) { // tecla pra direita
        moverCursor(&aux, &posicao, 'd');
      }

    } else if (tecla == 8) { //tecla backspace
      printf("Backspace");
    } else if (tecla == 13) { // tecla enter
      printf("Enter");
    } else if (tecla == 27) {
      return;
    } else {
      printf("%c - %d", tecla, tecla);
    }
  }
  system("cls");
}