#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void trocar(int *a, int *b){
    int temp = *a;

    *a = *b;
    *b = temp;
}

void ordenarLinha_rec(int *linha, int tamanho){
    if (tamanho <= 1)
        return;

    int indice_menor = 0;

    for (int i = 1; i < tamanho; i++){
        if (linha[i] < linha[indice_menor])
            indice_menor = i;
    }

    trocar(&linha[indice_menor], &linha[tamanho - 1]);

    ordenarLinha_rec(linha, tamanho - 1);
}

int **ordenar_matriz(int **matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++)
        ordenarLinha_rec(matriz[i], colunas);

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
