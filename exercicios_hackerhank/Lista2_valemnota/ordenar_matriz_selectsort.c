#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void selectsort2(int v[], int n){
    int i, j, p, aux;

    for (i = 0; i < n - 1;  i++){
        p = i;

        for (j = i + 1; j < n; j++)
            if (v[j] > v[p])
                p = j;

        if (p != i){
            aux = v[i];
            v[i] = v[p];
            v[p] = aux;
        }
    }
}

int **ordenar_matriz(int **matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++)
        selectsort2(matriz[i], colunas);

    return matriz;
}

void imprimir_matriz(int **matriz, int linhas, int colunas){
    int i, j;

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);

        printf ("\n");
    }
}

int main(void){
    int linhas, colunas, i, j;

    scanf("%d %d", &linhas, &colunas);

    int **matriz = (int **)malloc(linhas * sizeof(int *));

    for (i = 0; i < linhas; i++)
        matriz[i] = (int *)malloc(colunas * sizeof(int));


    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    int **matriz_ordenada = ordenar_matriz(matriz, linhas, colunas);

    imprimir_matriz(matriz_ordenada, linhas, colunas);

    for (i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
