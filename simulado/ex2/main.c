/* Desenvolva uma rotina que receba duas listas circulares (listaA e listaB) como par�metros. A seguir
desenvolva a l�gica para colocar os elementos da listaA e da listaB em ordem crescente em uma pilha
criada localmente. Escreva no final os elementos da pilha.
Obs: Considere que a listaA e a listaB j� est�o ordenadas e possuem o mesmo tamanho. Para trabalhar
com a estrutura de pilha deve ser usado o crit�rio. Podem ser usadas as fun��es descritas nos slides sem
reescrev�-las. */

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


typedef struct nodo {
  int numero;
  struct nodo *proximo;
} Nodo;

typedef struct lista {
  Nodo *inicio;
  Nodo *fim;
  int quantidade;
} Lista;

typedef struct pilha {
  Nodo *topo;
} Pilha;



Lista *iniciarLista();
Pilha *iniciarPilha();
Nodo *iniciarNodo();
void inserirLista(Lista *, int);
void inserirPilha(Pilha *, int);
int lerNumero();
void mostrarPilha(Pilha *);
void mostrarLista(Lista *);
void ordenarNaPilha(Lista *, Lista *);

main() {
  setlocale(LC_ALL, "Portuguese");

  Lista *lista1 = iniciarLista();
  Lista *lista2 = iniciarLista();
  int opcao;

  do {
    printf("\n1 - INSERIR A\n2 - INSERIR B\n3 - ORDENAR NA PILHA\n4 - MOSTRAR LISTAS\n5 - SAIR\n");
    opcao = lerNumero();

    switch (opcao)
    {
    case 1:
      inserirLista(lista1, lerNumero());
      break;

    case 2:
      inserirLista(lista2, lerNumero());
      break;

    case 3:
      ordenarNaPilha(lista1, lista2);
      break;

    case 4:
      printf("\nLISTA A\n");
      mostrarLista(lista1);
      printf("\nLISTA B\n");
      mostrarLista(lista2);
      break;

    case 5:
      break;
    
    default:
      printf("\nOp��o inv�lida");
      break;
    }
  } while (opcao != 5);
  

  system("pause");
}


Lista *iniciarLista() {
  Lista *lista = (Lista *) malloc(sizeof(Lista));
  if (lista == NULL) {
    printf("M�moria insufucuente para criar a lista");
    exit (1);
  }
  lista->fim = NULL;
  lista->inicio = NULL;
  lista->quantidade = 0;
  return lista;
}

Pilha *iniciarPilha() {
  Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
  if (pilha == NULL) {
    printf("M�moria insufucuente para criar a pilha");
    exit (1);
  }
  pilha->topo = NULL;
  return pilha;
}

Nodo *iniciarNodo() {
  Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
  if (nodo == NULL) {
    printf("M�moria insufucuente para criar a nodo");
    exit (1);
  }
  nodo->proximo = NULL;
  return nodo;
}

void inserirLista(Lista *lista, int n) {
  Nodo *nodo = iniciarNodo();
  nodo->numero = n;
  
  if (lista->inicio == NULL) { // inser��o do primeiro
    lista->inicio = nodo;
    lista->fim = nodo;
    nodo->proximo = nodo;
  } else if (lista->inicio->numero > n) { // inser��o no in�cio
    nodo->proximo = lista->inicio;
    lista->inicio = nodo;
    lista->fim->proximo = nodo;
  } else if (lista->fim->numero < n) { // inser��o no fim
    lista->fim->proximo = nodo;
    nodo->proximo = lista->inicio;
    lista->fim = nodo; 
  } else { // inser��o no meio
    Nodo *atual = lista->inicio;

    while (atual->proximo != lista->inicio && atual->proximo->numero < n) {
      atual = atual->proximo;
    }

    if (atual->numero == n) {
      printf("Elemento j� existente na lista");
      free(nodo);
      return;
    }
    
    nodo->proximo = atual->proximo;
    atual->proximo = nodo;
  }
  lista->quantidade++;
}

void inserirPilha(Pilha *pilha, int n) {
  Nodo *nodo = iniciarNodo();

  nodo->proximo = pilha->topo;
  pilha->topo = nodo;
  nodo->numero = n;
}

int lerNumero() {
  int opcao;
  printf("Informe o n�mero: ");
  scanf("%d", &opcao);
  fflush(stdin);
  return opcao;
}

void mostrarPilha(Pilha *pilha) {
  Nodo *atual = pilha->topo;

  while (atual != NULL) {
    printf("%d  ", atual->numero);
    atual = atual->proximo;
  }
}

void mostrarLista(Lista *lista) {
  Nodo *atual = lista->inicio;
  int count = 0;

  while (count < lista->quantidade) {
    printf("%d  ", atual->numero);
    atual = atual->proximo;
    count++;
  }
}

void ordenarNaPilha(Lista *lista1, Lista *lista2) {
  Pilha *pilha = iniciarPilha();
  Nodo *aux1 = lista1->inicio;
  Nodo *aux2 = lista2->inicio;
  int count1 = 0, count2 = 0;

  while (count1 < lista1->quantidade || count2 < lista2->quantidade) {
    if (count1 < lista1->quantidade && (count2 >= lista2->quantidade || aux1->numero <= aux2->numero)) {
      
      inserirPilha(pilha, aux1->numero);  
      aux1 = aux1->proximo;
      count1++;
    } else if (count2 < lista2->quantidade) {
      inserirPilha(pilha, aux2->numero); 
      aux2 = aux2->proximo;
      count2++;
    }
  }

  mostrarPilha(pilha);
}