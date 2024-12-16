#include <stdio.h>

int main() {
    int x, y, z, w;

    printf("Digite o número de linhas e colunas da primeira matriz, separados por espaço:\t ");
    scanf("%d %d", &x, &y);

    printf("Digite o número de linhas e colunas da segunda matriz, separados por espaço:\t ");
    scanf("%d %d", &z, &w);

    
    if (y != z) {
        printf("Multiplicação impossível.\n");
        return 1;
    }

    int matriz1[x][y], matriz2[z][w];

    printf("Digite os valores da primeira matriz, linha por linha:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

  
    printf("Digite os valores da segunda matriz, linha por linha:\n");
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    int matriz3[x][w];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < w; j++) {
            matriz3[i][j] = 0;
        }
    }

    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < y; k++) {
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

   
    printf("A matriz resultante é:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", matriz3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
