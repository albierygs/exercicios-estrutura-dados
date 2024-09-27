// Escreva um programa capaz de cadastrar produtos. A estrutura do produto deve ser composta por código, descrição e preço. Armazene os itens cadastrados em uma tabela, e mostre as informações na tela quando solicitado Dica: Desenvolva um menu com as opções inclusão, listagem e fim.

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
            printf("Opção inválida\n");
            break;
        }
    } while (opcao != 3);
    

    return 0;
}

void inserir(t_produto tabela[], int *total) {
    if (*total < TAM)
    {
        printf("NOVO PRODUTO:\n");
        printf("Código: ");
        scanf("%d", &tabela[*total].codigo);
        fflush(stdin);
        printf("Descrição: ");
        scanf("%s", &tabela[*total].descricao);
        fflush(stdin);
        printf("Preço: ");
        scanf("%lf", &tabela[*total].preco);
        fflush(stdin);
        *total = *total + 1;
        return;
    }
    printf("Não é possível adicionar mais produtos\n");
}


void listar(t_produto tabela[], int total) {
    for (int i = 0; i < total; i++)
    {
        printf("PRODUTO -> %d %s R$ %.2lf\n", tabela[i].codigo, tabela[i].descricao, tabela[i].preco);
    }
    
}
