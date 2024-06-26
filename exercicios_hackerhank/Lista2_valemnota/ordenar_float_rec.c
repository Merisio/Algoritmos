#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell{
    float item;

    Cell *next;
};

struct ListaE{
    Cell *head;
};

Cell* criar_celula(float key){
    Cell *c = (Cell*)malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*)malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(float key, ListaE *l){
    Cell* nova = criar_celula(key);

    nova->next = l->head;
    l->head = nova;
}

void imprimir(ListaE *l){
    Cell* aux = l->head;

    while (aux != NULL){
        printf("%.1f ", aux->item);
        aux = aux->next;
    }
    printf("\n");
}

void trocar(Cell *a, Cell *b){
    float aux = a->item;

    a->item = b->item;
    b->item = aux;
}

void bubble_sort_rec(Cell *primeiro, Cell *ultimo){
    if (primeiro == ultimo)
        return;


    Cell *aux = primeiro;

    while (aux->next != ultimo){
        if (aux->item > aux->next->item)
            trocar(aux, aux->next);

        aux = aux->next;
    }

    bubble_sort_rec(primeiro, aux);
}

void bubble_sort(ListaE *l){
    if (listaE_vazia(l)){
        return;
    }

    Cell *ultimo = NULL;

    bubble_sort_rec(l->head, ultimo);
}

int main(void){
    ListaE *l1 = criar_listaE();
    float valor;

    while (valor != -1){
        scanf ("%f", &valor);

        if (valor != -1)
            inserir_primeiro(valor, l1);
    }

    bubble_sort(l1);

    imprimir(l1);

    Cell* atual = l1->head;

    while (atual != NULL){
        Cell* next = atual->next;

        free(atual);
        atual = next;
    }
    free(l1);

    return 0;
}
