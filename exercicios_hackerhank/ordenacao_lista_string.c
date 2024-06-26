#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell{
    char *item;
    struct Cell *next;
} Cell;

typedef struct ListaE{
    Cell *head;
} ListaE;

Cell* criar_celula(char *key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = (char*) malloc(strlen(key)*sizeof(char)); 
    
    strcpy(c->item, key); 
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

void inserir_primeiro(char *key, ListaE *l){
    Cell *aux;
    
    if (l == NULL)
        l = criar_listaE();
    
    aux = criar_celula(key);
    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(char *key, ListaE *l){
    Cell *aux, *novo;
    
    if (l == NULL)
        l = criar_listaE();
    
    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    
    else{
        aux = l->head;
        
        while (aux->next != NULL)
            aux = aux->next;
        
        novo = criar_celula(key);
        aux->next = novo;
    }
}

int remover(char *key, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        if (strcmp(auxA->item, key) == 0){
            l->head = l->head->next;
            free(auxA->item);
            free(auxA);
            return 1;
        } 
        else{
            auxP = auxA;

            while ((auxA != NULL) && (strcmp(auxA->item, key) != 0)){
                auxP = auxA;
                auxA = auxA->next;
            }

            if (auxA != NULL){
                auxP->next = auxA->next;
                free(auxA->item);
                free(auxA);
                return 1;
            }
        }
    }

    return 0;
}

void imprimir(ListaE *l){
    Cell *aux;
    if (!listaE_vazia(l)){
        aux = l->head;
        while (aux != NULL){
            printf("%s ", aux->item);
            aux = aux->next;
            printf("\n");
        }
    }
}

int liberar_LE(ListaE *l){
    Cell *aux = NULL;
    if (l != NULL) {
        while (l->head != NULL){
            aux = l->head;
            l->head = aux->next;
            free(aux->item); 
            free(aux);
        }
        free(l);
        return 1;
    }
    return 0;
}

void ordenar_lista(ListaE *l){
    if (!listaE_vazia(l)){
        Cell *atual, *indice;
        char *temp;

        for (atual = l->head; atual != NULL; atual = atual->next)
            for (indice = atual->next; indice != NULL; indice = indice->next)
                if (strcmp(atual->item, indice->item) > 0){
                    temp = atual->item;
                    atual->item = indice->item;
                    indice->item = temp;
                }
    }
}

int main(){
    ListaE *l = criar_listaE();
    
    inserir_ultimo("Jessica", l);
    inserir_ultimo("Julia", l);
    
    ordenar_lista(l);
    
    imprimir(l);
    
    liberar_LE(l);
    
    return 0;
}