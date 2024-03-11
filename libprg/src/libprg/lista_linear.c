#include "libprg/libprg.h"
#include <stdlib.h>

#define TAMANHO_LISTA 10

typedef struct lista {
    int* elementos;
    int capacidade;
    int tamanho;
    bool ordenado;
} lista_t;

void criaLista () {
    lista_t* lista = (lista_t*) malloc(sizeof (lista_t));
    lista->capacidade = TAMANHO_LISTA;
    lista->elementos = (int*) malloc(sizeof (int) * TAMANHO_LISTA);
    lista->tamanho = 0;
    lista->ordenado = false;
}

void inserir (lista_t* lista, int elemento) {
    int tamanho = lista->tamanho;
    lista->elementos[tamanho] = elemento;
    lista->tamanho++;
}