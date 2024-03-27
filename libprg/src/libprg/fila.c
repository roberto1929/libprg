//
// Created by Mirella Barros on 25/03/24.
//

#include "libprg/libprg.h"

struct Fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
};

Fila* criaFila(int capacidade) {
    Fila* fila = (Fila*) malloc(sizeof(&fila));
    if (fila != NULL) {
        fila->elementos = (int*) malloc(sizeof(int) * capacidade);
        if (fila->elementos != NULL) {
            fila->capacidade = capacidade;
            fila->tamanho = 0;
            fila->inicio = 0;
            fila->fim = 0;
            return fila;
        } else {
            printf("Não foi posssível criar a fila.");
        }
    } else {
        printf("Não foi posssível criar a fila.");
    }
}

int* getFila(Fila* fila) {
    return fila->elementos;
}

int getSize(Fila* fila) {
    return fila->tamanho;
}

int head(Fila* fila) {
    return fila->inicio;
}

int tail(Fila* fila) {
    return fila->fim;
}

bool isFull(Fila* fila) {
    if(fila->tamanho == fila->capacidade) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty(Fila* fila) {
    if(fila->tamanho == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Fila* fila, int n) {
    if (isFull(fila)) {
        printf("A fila está cheia.\n");
    } else {
        fila->elementos[fila->fim] = n;
        fila->fim = (fila->fim + 1) % fila->capacidade;
        fila->tamanho = fila->tamanho + 1;
    }
}

int dequeue(Fila* fila) {
    int n = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho = fila->tamanho - 1;
    return n;
}

