// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Dimensão do tabuleiro

void exibirMatriz(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para criar um padrão de cone
// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1

void habilidadeCone(int matriz[SIZE][SIZE], int centroX, int centroY) {
    // Zera a matriz
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] = 0;
        }
    }

    // Define a área afetada em formato de cone
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i >= centroX && abs(j - centroY) <= i - centroX) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Função para criar um padrão de cruz
// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0

void habilidadeCruz(int matriz[SIZE][SIZE], int centroX, int centroY) {
    // Zera a matriz
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] = 0;
        }
    }

    // Define a área afetada em formato de cruz
    for (int i = 0; i < SIZE; i++) {
        matriz[i][centroY] = 1; // Linha vertical
    }
    for (int j = 0; j < SIZE; j++) {
        matriz[centroX][j] = 1; // Linha horizontal
    }
}

// Função para criar um padrão de octaedro
// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

void habilidadeOctaedro(int matriz[SIZE][SIZE], int centroX, int centroY, int alcance) {
    // Zera a matriz
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] = 0;
        }
    }

    // Define a área afetada em formato de octaedro
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (abs(i - centroX) + abs(j - centroY) <= alcance) {
                matriz[i][j] = 1;
            }
        }
    }
}

int main() {
    int matriz[SIZE][SIZE];

    printf("\nHabilidade em Cone:\n\n");
    habilidadeCone(matriz, 2, 4); // Centro do cone
    exibirMatriz(matriz);

    printf("\nHabilidade em Cruz:\n\n");
    habilidadeCruz(matriz, 4, 4); // Centro da cruz
    exibirMatriz(matriz);

    printf("\nHabilidade em Octaedro:\n\n");
    habilidadeOctaedro(matriz, 4, 4, 2); // Centro e alcance do octaedro
    exibirMatriz(matriz);

    return 0;
}
