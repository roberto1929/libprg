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
}

int* getFila(Fila* fila){
    return fila->elementos;
}

int calculaFim(Fila* fila) {
    int fimPrevisto = fila->inicio + fila->tamanho;
    if (fimPrevisto < fila->capacidade) {
        return fimPrevisto - 1;
    } else {
        int fimVetor = fila->capacidade - fila->inicio;
        fimPrevisto = fila->tamanho - fimVetor - 1;
        return fimPrevisto;
    }
};

void enqueue(Fila* fila, int n) {
    if (fila->tamanho > fila->capacidade) {
        fila->elementos[fila->inicio] = n;
        fila->tamanho = fila->tamanho + 1;
        fila->fim = calculaFim(fila);
    } else {
        printf("A lista está cheia;");
    }
}

void dequeue(Fila* fila) {
    fila->inicio = fila->inicio + 1;
    fila->tamanho = fila->tamanho - 1;
    fila->fim = calculaFim(fila);
}

int head(Fila* fila) {
    return fila->inicio;
}

int tail(Fila* fila) {
    fila->fim = calculaFim(fila);
    return fila->inicio + fila->tamanho;
}