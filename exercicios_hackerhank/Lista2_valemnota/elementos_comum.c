#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell{
    int item;

    Cell *next;
};

struct ListaE{
    Cell *head;
};

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

int procurar(int key, ListaE *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}

void inserir_primeiro(int key, ListaE *l){
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}

void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *novo;

    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}

int remover(int key, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
        }else{
            auxP = auxA;

            while((auxA != NULL) && (auxA->item != key)){
                    auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL){
            if (auxP != NULL)
                auxP->next = auxA->next;

            free(auxA);

            return 1;
        }

    }

    return 0;
}

void imprimir(ListaE *l){
    Cell *aux;

    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}

int liberar_LE(ListaE *l){
    Cell *aux = NULL;

    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}

void bubblesort_LE(ListaE *l){
    int tam = tamanho_LE(l);
    Cell *auxA, *auxB;
    int vaux, i;

    while (tam > 0){
        i = 0;
        auxA = l->head;
        auxB = auxA->next;

        while ((i < tam) && (auxB != NULL)){
            if (auxA->item > auxB->item){
                vaux = auxA->item;
                auxA->item = auxB->item;
                auxB->item = vaux;
            }

            auxA = auxB;
            auxB = auxB->next;

            i--;
        }

        tam--;
    }
}

ListaE* comum(ListaE *x, ListaE *y){
    ListaE *z = criar_listaE();

    if (x != NULL && y != NULL){
        Cell *aux1 = x->head;
        Cell *aux2 = y->head;

        while (aux1 != NULL){
            while (aux2 != NULL){
                if (aux1->item == aux2->item)
                    inserir_ultimo(aux2->item, z);

                aux2 = aux2->next;
            }
            aux2 = y->head;
            aux1 = aux1->next;
        }
    }
    bubblesort_LE(z);

    return z;
}

int main(void){
    ListaE *l1, *l2, *l3;
    int aux = 0;

    l1 = criar_listaE();
    l2 = criar_listaE();

    while (aux != -1){
        scanf("%d", &aux);

        if (aux != -1)
            inserir_ultimo(aux, l1);
    }

    aux = 0;

    while (aux != -1){
        scanf("%d", &aux);

        if (aux != -1)
            inserir_ultimo(aux, l2);
    }

    l3 = comum(l1, l2);

    if(!listaE_vazia(l3))
        imprimir(l3);

    liberar_LE(l1);
    liberar_LE(l2);
    liberar_LE(l3);

    return 0;
}
