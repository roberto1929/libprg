#include "libprg/libprg.h"
#include <stdlib.h>

#define TAMANHO_LISTA 10

 struct Lista {
    int* elementos;
    int capacidade;
    int tamanho;
    bool ordenada;
};

Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof (&lista));
    lista->capacidade = TAMANHO_LISTA;
    lista->elementos = (int*) malloc(sizeof (int) * TAMANHO_LISTA);
    lista->tamanho = 0;
    lista->ordenada = false;
    return lista;
}

int* getElementos(Lista* lista) {
    return lista->elementos;
}

int getTamanho (Lista* lista) {
    return lista->tamanho;
}

int inserirElemento(Lista* lista, int n) {
    lista->elementos[lista->tamanho] = n;
    lista->tamanho++;
    return lista->tamanho - 1;
}

int buscaLinear(Lista* lista, int n) {
    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == n) {
            return i;
        }
    }
    return -1;
}

void removerElemento(Lista* lista, int n) {
    int pos = buscaLinear(lista, n);
    lista->tamanho = lista->tamanho - 1;
    lista->elementos[pos] = lista->elementos[lista->tamanho];
//    Aqui é para lista ordenada
//    for (int i = pos; i < lista->tamanho; ++i) {
//        lista->elementos[i] = lista->elementos[pos + 1];
//    }
}