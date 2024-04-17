#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>
#include <ctype.h>

//LISTA LINEAR

typedef struct {
    int *vetor;
    int tamanho;
    int total;
    int inicio;
    int pos;
} lista_t;

//Irá criar um vetor de tamanho n, alocado de forma dinâmica
int criar(lista_t *lista);

//Irá povoar o vetor criado se for não ordenado
void povoar_nao_ord(lista_t *lista);

//Irá povoar o vetor criado se for ordenado
void povoar_ord(lista_t *lista);

//Irá inserir número em uma lista ordenada
int insere_ord(lista_t *lista, int elemento);

//Irá inserir um número em uma lista não ordenada
int insere_nao_ord(lista_t *lista, int elemento);

//Irá remover um número de uma lista ordenada
int remove_num_ord(lista_t *lista, int elemento);

//Irá remover um número de uma lista não ordenada
int remove_num_nao_ord(lista_t *lista, int elemento);

//Irá fazer uma busca linear pelo vetor
int busca_linear(lista_t *lista, int elemento);

//Irá fazer uma busca binaria de forma interativa pelo vetor e retorna a posição do elemento no vetor
int busca_bin_int(lista_t *lista, int elemento);

//Irá fazer uma busca binaria de forma recursiva pelo vetor e retorna a posição do elemento no vetor
int busca_bin_rec(lista_t *lista, int inicio, int fim, int elemento);

//Irá liberar a memório alocado pelo vetor
int libera_memoria(lista_t *lista);


// LISTA PROJETO

typedef struct Pessoa{
    char nome[100];
    char telefone[15];
    char email[50];
}pessoa_t;

typedef struct Contato{
    pessoa_t *vetor;
    int tamanho;
    int total;
}contato_t;


contato_t* criar_contato(int tamanho);
bool adicionar_pessoa(contato_t* contato, char nome[100], char email[50], char telefone[15]);
int buscar_contato(contato_t* lista_contatos, char nome[100], int* resultados);
int editar_contato(contato_t *contato, int pos_lista, char *nome, char *email, char *telefone);
int excluir_contato(contato_t *contato, int indice);
void imprimir_contatos(contato_t *contato);
void salvar_contatos(contato_t* lista_contatos);
void carregar_contatos(contato_t* lista_contatos);

// FILA

typedef struct Fila{
    int *vetor;
    int total;
    int inicio;
    int fim;
    int tamanho;
} fila_t;

fila_t* criar_fila(int tamanho);

void enqueue(fila_t *fila, int elemento);
// adiciona um elemento na lista
int dequeue(fila_t *fila);
// remove o elemento que está no início da ﬁla
int head(fila_t *fila);
// retorna o elemento que está no início da ﬁla
int tail(fila_t *fila);
//Retorna o elemento que está no ﬁnal da ﬁla
int size(fila_t *fila);
//Retorna o total de elementos na ﬁla
int empty(fila_t *fila);
// Indica se a ﬁla está vazia ou não
int full(fila_t *fila);
// indica se a ﬁla está cheia ou não


// PILHA

typedef struct {
    int* vetor;
    int tamanho;
    int topo;
}pilha_t;



int criar_pilha(pilha_t* pilha, int tamanho);
int push(pilha_t* pilha, int elemento);
int pop(pilha_t* pilha);
int size_p(pilha_t pilha);
int empty_p(pilha_t* pilha);

// ======================LISTA ENCADEADA============================ //

            // SIMPLES

typedef struct {
    int dado;
    struct no* proximo;
}no_t;

typedef struct {
    no_t *inicio;
    int size;
}listaEncadeada_t;

typedef struct {
    no_t *topo;
    int size;
}stacklist_t;

void adiciona_lista(listaEncadeada_t *queue, no_t** no, int valor);

int remove_lista(listaEncadeada_t *queue, no_t **no);
int busca_lista(no_t **no, int element);

void adiciona_pilha(stacklist_t *stack, no_t **no, int element);
int remove_pilha(stacklist_t *stack, no_t **no);
int busca_pilha(no_t **no, int element);

void adiciona_circular(no_t **no, bool op, int value);
int remove_circular(no_t **no, int value);
int busca_circular(no_t **no,int value);

void imprime_no(no_t *no);



            // DUPLAMENTE ENCADEADA

typedef struct {
    int elemento;
    struct nod_t* proximo;
    struct nod_t* anterior;
}nod_t;


#endif
