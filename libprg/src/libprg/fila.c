#include "libprg/libprg.h"

int enqueue(fila_t *fila, int elemento){
    if(full(fila)){
        return -1; // retorna erro fila cheia
    }
    fila->fila->vetor[fila->fim] = elemento;
    fila->fila->total++;
    fila->fim = (fila->fim + 1) % fila->fila->tamanho;
    return 0;
}

int dequeue(fila_t *fila){
    if(empty(fila)){
        return -1; //retorna fila vazia
    }
    fila->fila->total--;
    fila->inicio = (fila->inicio - 1) % fila->fila->tamanho;
    return fila->fila->vetor[fila->fim];
}

int head(fila_t *fila){
    return fila->fila->vetor[fila->inicio];
}

int tail(fila_t *fila){
    return fila->fila->vetor[fila->fim];
}
int size(fila_t *fila){
    return (fila->fila->total);
    }
int empty(fila_t *fila){
    return (fila->inicio == fila->fim);
}

int full(fila_t *fila){
    return (fila->fila->total == fila->fila->tamanho);
}
