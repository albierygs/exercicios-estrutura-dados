#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_LINHA 30

// Definição do nó para lista duplamente encadeada
typedef struct No {
    char conteudo[TAMANHO_LINHA];    // Conteúdo da linha
    struct No* anterior;              // Ponteiro para nó anterior
    struct No* proximo;               // Ponteiro para próximo nó
} No;

// Estrutura para representar o editor
typedef struct {
    No* cabeca;      // Primeiro nó do documento
    No* atual;       // Linha atual
} EditorTexto;

// Protótipos das funções
EditorTexto* criarEditor();
void inserirLinha(EditorTexto* editor, const char* texto);
void deletarLinha(EditorTexto* editor);
void editarLinha(EditorTexto* editor, const char* novoTexto);
void imprimirDocumento(EditorTexto* editor);
void liberarEditor(EditorTexto* editor);
void moverCima(EditorTexto* editor);
void moverBaixo(EditorTexto* editor);

// Criar um novo editor
EditorTexto* criarEditor() {
    EditorTexto* editor = (EditorTexto*)malloc(sizeof(EditorTexto));
    editor->cabeca = NULL;
    editor->atual = NULL;
    return editor;
}

// Inserir linha no final do documento
void inserirLinha(EditorTexto* editor, const char* texto) {
    No* novoNo = (No*)malloc(sizeof(No));
    strncpy(novoNo->conteudo, texto, TAMANHO_LINHA - 1);
    novoNo->conteudo[TAMANHO_LINHA - 1] = '\0';  // Garantir terminação
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if (editor->cabeca == NULL) {
        // Primeiro nó do documento
        editor->cabeca = novoNo;
        editor->atual = novoNo;
    } else {
        // Encontrar último nó
        No* ultimo = editor->cabeca;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }

        // Inserir no final
        ultimo->proximo = novoNo;
        novoNo->anterior = ultimo;
    }
}

// Deletar linha atual
void deletarLinha(EditorTexto* editor) {
    if (editor->atual == NULL) return;

    No* paraRemover = editor->atual;

    // Atualizar ponteiros
    if (paraRemover->anterior != NULL) {
        paraRemover->anterior->proximo = paraRemover->proximo;
    } else {
        // Deletando primeiro nó
        editor->cabeca = paraRemover->proximo;
    }

    if (paraRemover->proximo != NULL) {
        paraRemover->proximo->anterior = paraRemover->anterior;
    }

    // Atualizar linha atual
    editor->atual = paraRemover->proximo ? paraRemover->proximo : paraRemover->anterior;

    // Liberar memória
    free(paraRemover);
}

// Editar linha atual
void editarLinha(EditorTexto* editor, const char* novoTexto) {
    if (editor->atual == NULL) return;

    strncpy(editor->atual->conteudo, novoTexto, TAMANHO_LINHA - 1);
    editor->atual->conteudo[TAMANHO_LINHA - 1] = '\0';  // Garantir terminação
}

// Mover para linha acima
void moverCima(EditorTexto* editor) {
    if (editor->atual && editor->atual->anterior) {
        editor->atual = editor->atual->anterior;
    }
}

// Mover para linha abaixo
void moverBaixo(EditorTexto* editor) {
    if (editor->atual && editor->atual->proximo) {
        editor->atual = editor->atual->proximo;
    }
}

// Imprimir documento
void imprimirDocumento(EditorTexto* editor) {
    No* atual = editor->cabeca;
    int numeroLinha = 1;
    
    printf("--- Documento ---\n");
    while (atual != NULL) {
        printf("%d: %s\n", numeroLinha++, atual->conteudo);
        atual = atual->proximo;
    }
    printf("----------------\n");
}

// Liberar memória do editor
void liberarEditor(EditorTexto* editor) {
    No* atual = editor->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(editor);
}

// Função principal para demonstração
int main() {
    EditorTexto* editor = criarEditor();
    int escolha;
    char texto[TAMANHO_LINHA];

    while (1) {
        printf("\nEditor de Texto\n");
        printf("1. Inserir linha\n");
        printf("2. Deletar linha atual\n");
        printf("3. Editar linha atual\n");
        printf("4. Mover para cima\n");
        printf("5. Mover para baixo\n");
        printf("6. Imprimir documento\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        getchar();  // Consumir newline

        switch (escolha) {
            case 1:
                printf("Digite o texto (máx 30 caracteres): ");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = 0;  // Remover newline
                inserirLinha(editor, texto);
                break;
            case 2:
                deletarLinha(editor);
                break;
            case 3:
                printf("Digite o novo texto (máx 30 caracteres): ");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = 0;  // Remover newline
                editarLinha(editor, texto);
                break;
            case 4:
                moverCima(editor);
                break;
            case 5:
                moverBaixo(editor);
                break;
            case 6:
                imprimirDocumento(editor);
                break;
            case 7:
                liberarEditor(editor);
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}