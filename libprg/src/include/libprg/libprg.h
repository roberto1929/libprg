#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int *dados;    
    int tamanho;   
    int capacidade; 
} ListaLinear;


int criar_lista(ListaLinear *lista, int capacidade);

void povoar_ordenada(ListaLinear *lista, int quantidade, int valorMaximo);
void povoar_nao_ordenada(ListaLinear *lista, int quantidade, int valorMaximo);

int inserir(ListaLinear *lista, int elemento);
int inserir_ordenada(ListaLinear *lista, int elemento);


int remover(ListaLinear *lista, int elemento);
int remover_ordenada(ListaLinear *lista, int elemento);
int libera_memoria(ListaLinear *lista);

int busca_linear(ListaLinear *lista, int elemento);
int busca_binaria_ite(ListaLinear *lista, int elemento);
int busca_binaria_rec(ListaLinear *lista, int elemento, int esquerda, int direita);


// FILA //
typedef struct{
    int *vetor;
    int total;
    int inicio;
    int fim;
    int tamamho;
}fila_t;

int criar_fila(fila_t *vetor);

int enqueue(int elemento, fila_t *vetor);
int dequeue( fila_t *fila);
int head(fila_t *fila);
int tail(fila_t *vetor);
int size(fila_t *vetor);
int empty(fila_t *vetor);
int full(fila_t *vetor);

//PILHA//
typedef struct Pilha{
    int topo;
    int tam;
    int *pilha;
}pilha_t;


int push(pilha_t *pilha, int elemento);
int pop(pilha_t *pilha);
int size_p(pilha_t pilha);
int empty_p(pilha_t pilha);


#endif
