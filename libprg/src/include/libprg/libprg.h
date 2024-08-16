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

typedef struct no {
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
bool remove_lista(no_t** inicio, int dado, listaEncadeada_t * queue);
no_t* busca_lista(no_t* inicio, int dado);
void destruir(no_t** no);

void adiciona_pilha(stacklist_t *stack, no_t **no, int elemento);
int remove_pilha(stacklist_t *stack, no_t **no);
no_t* busca_pilha(no_t* inicio, int dado);

void adiciona_circular(no_t **no, bool op, int value);
int remove_circular(no_t **no, int value);
int busca_circular(no_t **no,int value);

void imprime_no(no_t *no);



//============// DUPLAMENTE ENCADEADA

typedef struct nod{
    int elemento;
    struct nod_t* proximo;
    struct nod_t* anterior;
}nod_t;

bool criar_d(int dado);
nod_t add_d(nod_t *nod, int dado);
nod_t * add_do(nod_t *nod, int dado);

// TOMADA DE TEMPO


void inicio(struct timeval *inicio_t);
double finaliza(struct timeval *inicio_t);

double finaliza_cpu(clock_t start);


// ALGORITMOS DE ORDENAÇÃO

typedef struct{
    int *vetor;
    int tamanho;
} sort_t;

int cria_sort(sort_t* sort, int tamanho);
void preencher_sort(sort_t* sort, int tamanho);
void imprimir_ord(sort_t* sort);

//============ TROCA E SELEÇÃO=================//
void bubble_sort(sort_t* sort, bool crescente);
void insertion_sort(sort_t* sort);
void selection_sort(sort_t* sort, bool crescente);

//============ DIVISÃO E CONQUISTA=============//
void merge_sort(sort_t* sort, int esquerda, int direita);
void quick_sort(sort_t* sort, int inicio, int fim);

// ÁRVORE BINÁRIA

typedef struct arvore{
    int valor;
    struct arvore* esquerda;
    struct arvore* direita;
}arvore_t;

arvore_t *criar_arvore(int valor);
void destruir_arvore(arvore_t *arvore);
arvore_t *inserir_valor(arvore_t *raiz, int valor);
bool busca_arvore(arvore_t *raiz, int valor);
arvore_t *remover_numero(arvore_t *raiz, int valor);
void imprime_filho_nivel(arvore_t *raiz, int valor, int nivel);
void imprime_arvore_in_order(arvore_t *raiz);
void imprime_arvore_pre_order(arvore_t *raiz);
void imprime_arvore_post_order(arvore_t *raiz);
void imprime_arvore_grafo(arvore_t *raiz);







//------------// ARVORE DE BUSCA BINARIA BALANCEADA
typedef struct no_avl{
    int valor;
    int altura;
    struct no_avl *esquerda;
    struct no_avl *direita;
} no_avl_t;

no_avl_t *criar_arvore_avl(int valor);
int altura(no_avl_t *v);
int fator_balanceamento(no_avl_t *v);
no_avl_t *rotacao_esquerda(no_avl_t *v);
no_avl_t *rotacao_direita(no_avl_t *v);
no_avl_t *rotacao_dupla_direita(no_avl_t *v);
no_avl_t *rotacao_dupla_esquerda(no_avl_t *v);
no_avl_t *balancear(no_avl_t  *v);
no_avl_t *inserir(no_avl_t *v, int valor);
no_avl_t *remover(no_avl_t *v, int valor);
void imprime_arvore_avl_grafo(no_avl_t *raiz);
void imprimir_texto_grafo(no_avl_t *raiz);



#endif
