#include <libprg/libprg.h>

int enqueue(int elemento, fila_t *fila){
    if(fila->tamanho == fila->total){
        return 1;
    }
    fila->vetor[fila->fim] = elemento;
    fila->total++;
    fila->fim = (fila->fim + 1)% fila ->tamanho;
    return 0;
}

int dequeue( fila_t *fila){
    if(empty(fila)){
        return 1;
    };
    fila->inicio = (fila->inicio + 1) % fila->tamanho;
    fila->total--;
    return fila->vetor[fila->fim];
}

int head(fila_t *fila){
    return vetor->vetor[vetor->inicio];
}

int tail(fila_t *fila){
    return fila->vetor[vetor->fim];
}

int size(fila_t *vetor){
    return fila->total;
}

int empty(fila_t *fila){
    if(fila->total == 0){
        return 0;
    }
    return 1;
}

int full(fila_t *fila){
    if(fila->total == fila->tamanho){
        return 0;
    }
    return 1;
}
