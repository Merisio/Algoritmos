#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_bseq(int valor, int *v, int n, int m){
    int esquerdo = 0;
    int direito = n - 1;

    while (direito - esquerdo + 1 > m){
        int meio = (esquerdo + direito) / 2;

        if (v[meio] == valor)
            return meio;

        else if (v[meio] < valor)
            esquerdo = meio + 1;

        else
            direito = meio - 1;
    }

    for (int i = esquerdo; i <= direito; i++){
        printf ("%d ", v[i]);
    }

    printf ("\n");

    for (int i = esquerdo; i <= direito; i++){
        if (v[i] == valor)
        return i;
    }

    return -1;
}

int main(void){
    int valor;
    int tam, min;

    scanf ("%d", &valor);
    scanf ("%d", &tam);

    int v[tam];

    for (int i = 0; i < tam; i++)
        scanf ("%d", &v[i]);

    scanf ("%d", &min);

    int posicao = busca_bseq(valor, v, tam, min);

    printf ("%d\n", posicao);

    return 0;
}
