#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// Definição dos elementos no tabuleiro
#define AGUA 0
#define NAVIO 1
#define HABILIDADE 5
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
void aplicarHabilidadeCruz(int tabuleiro[TAM][TAM], int x, int y) {
    tabuleiro[x][y] = HABILIDADE;
    if(x > 0) tabuleiro[x-1][y] = HABILIDADE;
    if(x < TAM-1) tabuleiro[x+1][y] = HABILIDADE;
    if(y > 0) tabuleiro[x][y-1] = HABILIDADE;
    if(y < TAM-1) tabuleiro[x][y+1] = HABILIDADE;
}
void aplicarHabilidadeCone(int tabuleiro[TAM][TAM], int x, int y) {
    for(int i = 0; i <= 2; i++) {
        for(int j = -i; j <= i; j++) {
            int nx = x + i;
            int ny = y + j;
            if(nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
                tabuleiro[nx][ny] = HABILIDADE;
            }
        }
    }
}
void aplicarHabilidadeOctaedro(int tabuleiro[TAM][TAM], int x, int y) {
    for(int dx = -2; dx <= 2; dx++) {
        for(int dy = -2; dy <= 2; dy++) {
            if(abs(dx) + abs(dy) <= 2) {
                int nx = x + dx;
                int ny = y + dy;
                if(nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
                    tabuleiro[nx][ny] = HABILIDADE;
                }
            }
        }
    }
}
int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    int x = 4, y = 4; // ponto de origem da habilidade

    // Testes de aplicação
    aplicarHabilidadeCruz(tabuleiro, x, y);
    // aplicarHabilidadeCone(tabuleiro, x, y);
    // aplicarHabilidadeOctaedro(tabuleiro, x, y);

    imprimirTabuleiro(tabuleiro);
    return 0;
}
