#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5

typedef struct {
    char nome;
    int id;
} Peca;

Peca fila[TAMANHO_FILA];
int frente = 0;
int tras = -1;
int quantidade = 0;
int contador_id = 0;

// Gera uma peça aleatória
Peca geraPeca() {
    Peca nova_peca;
    char tipos[] = {'I', 'O', 'T', 'L'};
    nova_peca.nome = tipos[rand() % 4];
    nova_peca.id = contador_id++;
    return nova_peca;
}

// Insere peça no final da fila (enqueue)
int inserirPeca() {
    if (quantidade == TAMANHO_FILA) {
        printf("Fila cheia! Não é possível adicionar mais peças.\n");
        return 0;
    }
    
    tras = (tras + 1) % TAMANHO_FILA;
    fila[tras] = geraPeca();
    quantidade++;
    return 1;
}

// Remove peça da frente da fila (dequeue)
int jogarPeca() {
    if (quantidade == 0) {
        printf("Fila vazia! Não há peças para jogar.\n");
        return 0;
    }
    
    printf("Peça jogada: [%c %d]\n", fila[frente].nome, fila[frente].id);
    frente = (frente + 1) % TAMANHO_FILA;
    quantidade--;
    return 1;
}

// Exibe o estado atual da fila
void exibirFila() {
    printf("\nFila de peças\n");
    if (quantidade == 0) {
        printf("Fila vazia\n");
        return;
    }
    
    int i = frente;
    for (int count = 0; count < quantidade; count++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % TAMANHO_FILA;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int opcao;
    
    // Inicializa a fila com 5 peças
    for (int i = 0; i < TAMANHO_FILA; i++) {
        inserirPeca();
    }
    
    printf("=== Simulador Fila de Peças Tetris ===\n");
    
    do {
        exibirFila();
        printf("\nOpções:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                jogarPeca();
                break;
            case 2:
                inserirPeca();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 3);
    
    return 0;
}