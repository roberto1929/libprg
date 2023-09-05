#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <string.h>

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

/**
 * g  jgjh gjh gjh gj
 * @param elemento
 * @param vetor
 * @param tam
 * @param total
 * @return
 */
int inserir(int elemento, int *vetor, int tam, int *total);
// função de remover
int remover(int elemento);
int busca_linear();

#endif
