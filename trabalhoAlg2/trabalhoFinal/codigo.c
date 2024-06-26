#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int EhPalindromo(char *str, int in, int fin) {
    while (in < fin) {
        if (str[in] != str[fin]) {
            return 0;
        }
        in++;
        fin--;
    }
    return 1;
}

void ordenar_posicoes(int pos[][30], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int len_i = pos[1][i] - pos[0][i];
            int len_j = pos[1][j] - pos[0][j];
            if (len_j > len_i) {
                int temp_start = pos[0][i];
                int temp_end = pos[1][i];
                pos[0][i] = pos[0][j];
                pos[1][i] = pos[1][j];
                pos[0][j] = temp_start;
                pos[1][j] = temp_end;
            }
        }
    }
}

void achar_todos_palindromos(char *str, int tamanho) {
    int Tamanho = strlen(str);
    int pos[2][30];
    int i = 0;
    //identificar palintromos
    for (int start = 0; start < Tamanho; start++) {
        for (int end = start; end < Tamanho; end++) {
            if (EhPalindromo(str, start, end) && (end - start + 1 > 1)) {
                char pala[101];
                strncpy(pala, str + start, end - start + 1);
                pos[0][i] = start;
                pos[1][i] = end;
                i++;
                pala[end - start + 1] = '\0';

            }
        }
    }

    ordenar_posicoes(pos, i); // ordenar do maior para o menor palindromo
    // Remover subpalíndromos
        for (int j = 0; j < i; j++) { // removendo os que fazem parte de um amior e adicionando -1 no lugar
            for (int k = j + 1; k < i; k++) {
                if ((pos[0][k] <= pos[1][j]) && (pos[0][j] <= pos[1][k]) ) {
                    pos[0][k] = -1;  // Marcar como removido
                    pos[1][k] = -1;
                }
            }
        }

        int new_i = 0; // remover os -1 da matriz
        for (int j = 0; j < i; j++) {
            if (pos[0][j] != -1) {
                pos[0][new_i] = pos[0][j];
                pos[1][new_i] = pos[1][j];
                new_i++;
            }
        }
        pos[0][new_i +1] = -1; // adicionado mais uma linha para não imprimir o ultimo | no final da string
        pos[1][new_i +1] = -1; // adicionado mais uma linha para não imprimir o ultimo | no final da string
        i = new_i;
        //printf("o numero de cortes minimos necessarios: %d\n", i);
        for (int l = 0; l < i - 1; l++) { // ordenando a matriz
            for (int j = l + 1; j < i; j++) {
                if (pos[0][l] > pos[0][j]) {
                    int temp_start = pos[0][l];
                    pos[0][l] = pos[0][j];
                    pos[0][j] = temp_start;
                    int temp_end = pos[1][l];
                    pos[1][l] = pos[1][j];
                    pos[1][j] = temp_end;
                }
            }
        }
        //IMPRIMIR
        int n=0;
        int posiin=0;
        int posifin=0;
        int cont=0;
        while(n < tamanho){ //imprimindo com | nas posições indicadas que está cada palindromo no codigo. presente na matriz.
            if(pos[0][posiin]==n && pos[0][posiin]!=0){
                printf(" | %c", str[n]);
                cont++;
                posiin++;
            }else if(pos[0][posiin]==0){
                printf("%c", str[n]);
                posiin++;
            }else if(pos[1][posifin] == n && pos[1][posifin +1] != -1 && ((pos[1][posifin] - pos[0][posiin]) != -1)){
                printf("%c | ", str[n]);
                cont++;
                posifin++;
            }else if ((pos[1][posifin] - pos[0][posiin]) == -1){
                    printf("%c", str[n]);
                    posifin++;
                }else{
                printf("%c", str[n]);
            }
            n++;
        }
        printf("\n");
        printf("o numero de cortes minimos necessarios: %d\n", cont);
}

int main() {
    char str[100];
    char escolha[3]; // Aumentado para 3 para evitar problemas com '\0'
    while(1) {
        printf("Digite uma string: ");
        scanf("%s", str);
        int tamanho = strlen(str);
        achar_todos_palindromos(str, tamanho);
        printf("\n");
        printf("\nVoce quer continuar o programa (s/n): ");
        scanf("%2s", escolha); // Lê uma string com até 2 caracteres
        if (escolha[0] == 'n' || escolha[0] == 'N') {
            printf("Encerrando o programa...\n");
            break;
        }
        printf("\n");
    }
    return 0;
}