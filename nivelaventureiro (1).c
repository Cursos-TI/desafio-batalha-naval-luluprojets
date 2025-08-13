#include <stdio.h>

#define SIZE 10

void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = '0';  // '0' representa água
        }
    }
}

int validarCoordenadas(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

int validarDisponibilidade(char tabuleiro[SIZE][SIZE], int x, int y) {
    return (tabuleiro[x][y] == '0');
}

void posicionarNavio(char tabuleiro[SIZE][SIZE], int x, int y, int tamanho, char direcao) {
    // direcao: 'h' = horizontal, 'v' = vertical, 'd' = diagonal
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'h') {
            tabuleiro[x][y + i] = '1';
        } else if (direcao == 'v') {
            tabuleiro[x + i][y] = '1';
        } else if (direcao == 'd') {
            tabuleiro[x + i][y + i] = '1';
        }
    }
}

void exibirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[SIZE][SIZE];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    // Dois navios horizontais/verticais
    posicionarNavio(tabuleiro, 0, 0, 3, 'h'); // exemplo horizontal
    posicionarNavio(tabuleiro, 2, 2, 4, 'v'); // exemplo vertical

    // Dois navios diagonais
    posicionarNavio(tabuleiro, 5, 5, 3, 'd'); // exemplo diagonal
    posicionarNavio(tabuleiro, 7, 0, 2, 'd'); // exemplo diagonal

    exibirTabuleiro(tabuleiro);

    return 0;
}