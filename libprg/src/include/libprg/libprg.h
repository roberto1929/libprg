#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef struct Lista Lista;
Lista* criarLista();
int inserirElemento(Lista* lista, int n);
int removerElemento(Lista* lista, int n);
int buscaLinear(Lista* lista, int n);
int buscaBinariaInterativa(Lista* lista, int n);
int buscaBinariaRecursiva(Lista* lista, int n, int inicio, int fim);


typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

#endif
