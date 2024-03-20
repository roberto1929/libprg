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
    Lista* lista = (Lista*) malloc(sizeof (lista));
    lista->capacidade = TAMANHO_LISTA;
    lista->elementos = (int*) malloc(sizeof (int) * TAMANHO_LISTA);
    lista->tamanho = 0;
    lista->ordenada = false;
}

int inserir(Lista* lista, int elemento) {
    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
    return lista->tamanho - 1;
}

