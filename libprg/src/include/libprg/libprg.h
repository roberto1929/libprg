#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int a;
} vetor_t;

/**
 * para criar uma lista linear de alocação sequencial ordenada
 * @param vetor lista a ser criada
 * @param tam tamamho da lista
 * @return 0 se criou e -1 se não conseguiu
 */

int criar_lista(int *vetor, int tam);
int lista_nao_ord(int *vetor, int tam);
int povoar_ordenada(int *vetor, int tam, char op);
int povoar_nao_ordenada(int *vetor,int *total, int tamanho);
/**
 * para inserir um elemento na lista não ordenada e não ordenada
 * @param elemento elemento a ser inserido
 * @param vetor lista
 * @param tam tamanho da lista
 * @param total total de elementos da lista
 * @return
 */
int inserir(int elemento, int *vetor, int tam, int *total);
int inserir_ordenada(int elemento, int *vetor, int tam, int *total);

/**
 * para remover um elemento na lista ordenada e não ordenada
 * @param elemento elemento inserido pelo user
 * @param vetor lista
 * @param total total de elementos
 * @return
 */
int remover(int elemento, int *vetor, int *total, int tam);
int remover_ordenada(int elemento, int *vetor, int *total, int tam);
int libera_memoria(int *vetor,int tam);
/**
 * para buscar o elemento na lista
 * @param elemento elemento inserido
 * @param vetor lista criada
 * @return
 */
int busca_linear(int elemento, int *vetor, int *total, int tam);
int busca_binaria_ite(int elemento, int *vetor, int *total);
int busca_binaria_rec(int *vetor, int inicio, int fim, int elemento);

/**
 *
 * @param vetor lista criada
 * @param tam tamanho da lista
 * @return
 */
int destruir(int *vetor, int tam);

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
typedef struct {
    int topo;
    int tam;
    int *pilha;
}pilha_t;


int push(pilha_t *pilha, int elemento);
int pop(pilha_t *pilha);
int size_p(pilha_t pilha);
int empty_p(pilha_t pilha);


#endif
