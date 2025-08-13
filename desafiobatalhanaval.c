#include <stdio.h>

#define TAM 10       // tamanho do tabuleiro (10x10)
#define NAVIO 3      // valor que representa o navio
#define TAM_NAVIO 3  // tamanho fixo do navio

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se um navio cabe no tabuleiro sem sair dos limites ou sobrepor outro
int podeColocarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') { // Horizontal
        if (coluna + TAM_NAVIO > TAM) return 0; // sai do limite
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // sobreposição
        }
    } 
    else if (orientacao == 'V') { // Vertical
        if (linha + TAM_NAVIO > TAM) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }
    return 1; // pode colocar
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char orientacao) {
    if (podeColocarNavio(tabuleiro, linha, coluna, orientacao)) {
        if (orientacao == 'H') {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha][coluna + i] = NAVIO;
            }
        } else {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha + i][coluna] = NAVIO;
            }
        }
    } else {
        printf("Erro: não é possível posicionar o navio nas coordenadas (%d,%d)!\n", linha, coluna);
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas fixas para o desafio (pode trocar)
    int linhaH = 2, colunaH = 4; // navio horizontal
    int linhaV = 5, colunaV = 1; // navio vertical

    // Posiciona os navios
    posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    posicionarNavio(tabuleiro, linhaV, colunaV, 'V');

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}