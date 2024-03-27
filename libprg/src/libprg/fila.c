//
// Created by Mirella Barros on 25/03/24.
//

#include "libprg/libprg.h"
#include <stdlib.h>

struct Fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
};

Fila* criaFila(int capacidade) {
    Fila* fila = (Fila*) malloc(sizeof(&fila));
    fila->elementos = (int*) malloc(sizeof(int) * capacidade);
    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

int* getFila(Fila* fila){
    return fila->elementos;
}

int head(Fila* fila) {
    return fila->inicio;
}

int tail(Fila* fila) {
    if (fila->tamanho == 0) {
        fila->fim = 0;
    } else {
        fila->fim = (fila->fim + 1) % fila->tamanho;
    }
    return fila->fim;
}

bool full(Fila* fila) {
    if(fila->tamanho == fila->capacidade) {
        return true;
    } else {
        return false;
    }
}

bool empty(Fila* fila) {
    if(fila->tamanho == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Fila* fila, int n) {
    if (full(fila)) {
        printf("A lista está cheia.");
    } else {
        fila->tamanho = fila->tamanho + 1;
        fila->elementos[tail(fila)] = n;
    }
}

void dequeue(Fila* fila) {
    fila->inicio = fila->inicio + 1;
    fila->tamanho = fila->tamanho - 1;
    fila->fim = tail(fila);
}

