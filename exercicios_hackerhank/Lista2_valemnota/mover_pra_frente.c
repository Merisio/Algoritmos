#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void MPF(int v[], int t, int chave){
    if (t <= 1){
        return;
    }

    if (v[t - 1] == chave){
        int aux = v[t - 1];

        for (int i = t - 1; i > 0; i--){
            v[i] = v[i - 1];
        }
        v[0] = aux;
    }
    MPF(v, t - 1, chave);
}

int main (void){
    int tamanho, quantidade, chave;

    scanf("%d", &tamanho);

    int v[tamanho];

    for(int i = 0; i < tamanho; i++)
        scanf("%d", &v[i]);

    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++){
        scanf("%d", &chave);

        MPF(v, tamanho, chave);
    }

    for (int j = 0; j < tamanho; j++)
            printf("%d ", v[j]);

    return 0;
}
