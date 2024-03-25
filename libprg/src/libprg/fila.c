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

void enqueue(Fila* fila, int n) {
    if (fila->tamanho > fila->capacidade) {
        fila->elementos[fila->inicio] = n;
        fila->fim = fila->fim + 1;
        fila->tamanho = fila->tamanho + 1;
    } else {
        printf("A lista está cheia;");
    }

}

void dequeue(Fila* fila) {
    fila->inicio = fila->inicio + 1;
    fila->tamanho = fila->tamanho - 1;
}

int head(Fila* fila) {
    return fila->inicio;
}

int tail(Fila* fila) {
    return fila->inicio + fila->tamanho;
}