/* Um laborat�rio est� fazendo um controle sobre a doen�a toxoplasmose. O exame que detecta a doen�a � baseado em dois reagentes IGG e IGM que podem apresentar os seguintes �ndices:
a.
Quando o teste do IGG e IGM retornam o resultado 0 o paciente n�o possui toxoplasmose.
b.
Quando o IGM est� entre 1 e 100 o paciente j� teve a doen�a ativa no organismo.
c.
Quando o IGG est� acima de 100 o paciente est� com a doen�a ativa.
O laborat�rio quer fazer um levantamento dos pr�ximos pacientes que solicitarem o exame para saber as seguintes informa��es:
a.
Quantos pacientes nunca tiveram a doen�a.
b.
Quantos pacientes est�o com a doen�a ativa.
c.
Quantos pacientes j� tiveram a doen�a e est�o com ela ativa no momento.
Desenvolva uma rotina que receba duas Filas com os resultados do IGM e IGG dos �ltimos pacientes e informe o solicitado pelo laborat�rio.
Obs: Trabalhe com o crit�rio de fila para resolver o problema. Podem ser usadas fun��es descritas nas transpar�ncias sem reescrev�-las. */


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
} Lista;


Lista *iniciarLista();
void inserirLista(Lista *, int);
int lerNumero();
Nodo *iniciarNodo();
void cadastrar(Lista *, Lista *);
void resultado(Lista *, Lista *);


main() {
  setlocale(LC_ALL, "Portuguese");

  Lista *igm = iniciarLista();
  Lista *igg = iniciarLista();
  int opcao;

  do {
    printf("\n1 - CADASTRAR\n2 - RESULTADOS\n3 - SAIR\n");
    opcao = lerNumero();

    switch (opcao) {
      case 1:
        cadastrar(igm, igg);
        break;

      case 2:
        resultado(igm, igg);
        break;

      case 3:
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
  return lista;
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

int lerNumero() {
  int opcao;
  scanf("%d", &opcao);
  fflush(stdin);
  return opcao;
}

void inserirLista(Lista *lista, int n) {
  Nodo *nodo = iniciarNodo();

  if (lista->inicio == NULL) {
      lista->inicio = nodo;
  } else {
      lista->fim->proximo = nodo;
  }
  lista->fim = nodo;
  nodo->proximo = NULL;
  nodo->numero = n;
}

void cadastrar(Lista *igmLista, Lista *iggLista) {
  int igm, igg;

  printf("IGM: ");
  scanf("%d", &igm);
  fflush(stdin);
  printf("IGG: ");
  scanf("%d", &igg);
  fflush(stdin);

  inserirLista(igmLista, igm);
  inserirLista(iggLista, igg);
}

void resultado(Lista *igmLista, Lista *iggLista) {
  Nodo *iggAux = iggLista->inicio;
  Nodo *igmAux = igmLista->inicio;

  int negativo = 0; // n�o possuem a doen�a -> igg e igm = 0
  int naoAtivo = 0; // j� tiveram a doen�a -> igm entre 1 e 100
  int ativo = 0; // possuem a doen�a ativa -> igg > 100

  while (iggAux != NULL || igmAux != NULL) {
    if (iggAux->numero == 0 && igmAux->numero == 0) {
      negativo++;
    } else if (igmAux->numero >= 1 && igmAux->numero <= 100) {
      naoAtivo++;
    } else if (iggAux->numero > 100) {
      ativo++;
    }
    iggAux = iggAux->proximo;
    igmAux = igmAux->proximo;
  }
  
  printf("\nPacientes que n�o possuem a doen�a: %d", negativo);
  printf("\nPacientes que j� tiveram a doen�a: %d", naoAtivo);
  printf("\nPacientes que est�o com a doen�a: %d", ativo);
}