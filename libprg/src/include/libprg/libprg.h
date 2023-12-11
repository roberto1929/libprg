#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#define max(a,b) (((a) > (b)) ? (a) : (b))

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>


                   //LISTA LINEAR
typedef struct {
    int *vetor;
    int tamanho;
    int total;
    int inicio;
    int pos;
} lista_t;


int criar_lista(lista_t *lista);

void povoar_ordenada(lista_t *lista);
void povoar_nao_ordenada(lista_t *lista);

int inserir_nao_ord(lista_t *lista, int elemento);
int inserir_ordenada(lista_t *lista, int elemento);


int remover_nao_ord(lista_t *lista, int elemento);
int remover_ordenada(lista_t *lista, int elemento);
int libera_memoria(lista_t *lista);

int busca_linear(lista_t *lista, int elemento);
int busca_binaria_ite(lista_t *lista, int elemento);
int busca_binaria_rec(lista_t *lista, int inicio, int fim, int elemento);


                   // FILA //
typedef struct{
    int *vetor;
    int total;
    int inicio;
    int fim;
    int tamanho;
}fila_t;

int enqueue(fila_t *fila, int elemento);
int dequeue( fila_t *fila);
int head(fila_t *fila);
int tail(fila_t *fila);
int size(fila_t *fila);
int empty(fila_t *fila);
int full(fila_t *fila);

                    //PILHA//
typedef struct{
    int topo;
    int tamanho;
    int *vetor;
}pilha_t;

int criar_pilha(pilha_t *pilha);
int push(pilha_t *pilha, int elemento);
int pop(pilha_t *pilha);
int size_p(pilha_t pilha);
int empty_p(pilha_t pilha);



//-------------//LISTA SEQUENCIAL ENCADEADA//

 typedef struct no_t{
    int elemento;
    struct no_t* proximo;
}no_t;

// a) //

no_t* criar_lista_e(int dado);

no_t* inserir_e(no_t* inicio, int dado);
no_t* inserir_o(no_t* inicio, int dado);

no_t* buscar_e(no_t* inicio, int dado);
no_t* buscar_o(no_t* inicio, int dado);

void excluir_e(no_t* inicio, int dado);
//}

//b)//

typedef struct node_t {
   int elemento;
   struct node_t* anterior;
   struct node_t* proximo;
}node_t;

node_t* criar_lista_de(node_t* inicio, int dado);

node_t* inserir_de(node_t* inicio, int dado);
node_t* inserir_de_o(node_t* inicio, int dado);

node_t* buscar_de(node_t* inicio, int dado);
node_t* buscar_de_o(node_t* inicio, int dado);

void excluir_de(node_t* inicio, int dado);
//}


no_t* criar_fila_e(int dado);

void enqueue_e(no_t** inicio, no_t** fim, int dado);
void desenqueue_e(no_t** inicio);
//}


no_t* criar_pilha_e(int dado);

void empilhar_e(no_t** topo, int dados);
void desempilhar_e(no_t** topo);


            // TOMADA DE TEMPO

void comeca(struct timeval *inicio);
double medir_tempo_cpu(clock_t start);
double medir_tempo_parede(struct timeval *inicio);



             //ALGORITMOS DE ORDENAÇÃO

typedef struct{
    int *vetor;
    int n;
}sort_t;

int *cria_arranjo(int tamanho);

        // Troca e seleção
void bubble_sort(sort_t *sort);
void bubble_sort_d(sort_t *sort);
void insert_sort(sort_t *sort);
void selection_sort(sort_t *sort);
void selection_sort_d(sort_t *sort);
bool troca_posicao(sort_t *sort, int i, int j);

        // Divisão e conquista

int particiona(sort_t *sort, int start, int end);
void merge(sort_t *sort, int mid, int left, int right);
void merge_sort(sort_t *sort, int left, int right);
void quick_sort(sort_t *sort, int start, int end);
#endif


//ÁRVORE BINÁRIA

typedef struct arvore{
    int valor;
    struct arvore *esquerda;
    struct arvore *direita;
} arvore_t;

arvore_t *criar_arvore(int valor);
void destruir_arvore(arvore_t *arvore);
arvore_t *inserir_valor(arvore_t *raiz, int valor);
bool busca_arvore(arvore_t *raiz, int valor);
void imprime_filho_nivel(arvore_t *raiz, int valor, int nivel);
arvore_t *remover_numero(arvore_t *raiz, int valor);

//------------// ARVORE DE BUSCA BINARIA
void imprime_arvore_in_order(arvore_t *raiz);
void imprime_arvore_pre_order(arvore_t *raiz);
void imprime_arvore_post_order(arvore_t *raiz);

void imprime_arvore_grafo(arvore_t *raiz);
void imprimir_texto_grafo(arvore_t *raiz);
int exibir_altura(arvore_t *raiz, int valor);

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