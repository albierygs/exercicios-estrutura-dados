// Escreva um programa capaz de cadastrar produtos. A estrutura do produto deve ser composta por c�digo, descri��o e pre�o. Armazene os itens cadastrados em uma tabela, e mostre as informa��es na tela quando solicitado Dica: Desenvolva um menu com as op��es inclus�o, listagem e fim.

#include <stdio.h>
#include <locale.h>
#define TAM 10

typedef struct produto
{
    int codigo;
    char descricao[50];
    double preco;
} t_produto;

void inserir(t_produto [], int *);
void listar(t_produto [], int);


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    t_produto tabela[TAM];
    int opcao, total = 0;

    do
    {
        printf("1 - INCLUIR\n");
        printf("2 - LISTAR\n");
        printf("3 - FIM\n");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao)
        {
        case 1:
            inserir(tabela, &total);
            break;

        case 2: 
            listar(tabela, total);
            break;

        case 3: 
            break;
        
        default:
            printf("Op��o inv�lida\n");
            break;
        }
    } while (opcao != 3);
    

    return 0;
}

void inserir(t_produto tabela[], int *total) {
    if (*total < TAM)
    {
        printf("NOVO PRODUTO:\n");
        printf("C�digo: ");
        scanf("%d", &tabela[*total].codigo);
        fflush(stdin);
        printf("Descri��o: ");
        scanf("%s", &tabela[*total].descricao);
        fflush(stdin);
        printf("Pre�o: ");
        scanf("%lf", &tabela[*total].preco);
        fflush(stdin);
        *total = *total + 1;
        return;
    }
    printf("N�o � poss�vel adicionar mais produtos\n");
}


void listar(t_produto tabela[], int total) {
    for (int i = 0; i < total; i++)
    {
        printf("PRODUTO -> %d %s R$ %.2lf\n", tabela[i].codigo, tabela[i].descricao, tabela[i].preco);
    }
    
}
