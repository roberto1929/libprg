#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

// Lista
typedef struct Lista Lista;
Lista* criarLista();
int* getElementos(Lista* lista);
int getTamanho (Lista* lista);
int inserirElemento(Lista* lista, int n);
void removerElemento(Lista* lista, int n);
int buscaLinear(Lista* lista, int n);
int buscaBinariaInterativa(Lista* lista, int n);
int buscaBinariaRecursiva(Lista* lista, int n, int inicio, int fim);

// Soma
typedef enum { SUM, SUB } operation_t;
result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

// Fila
typedef struct Fila Fila;
Fila* criaFila(int capacidade);
int* getFila(Fila* fila);
void enqueue(Fila* fila, int n);
void dequeue(Fila* fila);
int head(Fila* fila);
int tail(Fila* fila);
int size(Fila* fila);
bool empty(Fila* fila);
bool full(Fila* fila);

#endif
