#include <libprg/libprg.h>


fila_t* criar_fila(int tamanho)
{
    fila_t *fila = (fila_t*) malloc(sizeof(&fila));
    fila->vetor = (int*) malloc(sizeof(int) * tamanho);
//    if(fila->vetor == NULL){
//        return 0;
//    }
    fila->total = 0; // Inicializa o total de elementos como 0
    fila->inicio = 0; // Inicializa o índice de início como 0
    fila->fim = 0; // Inicializa o índice de fim como 0
    fila->tamanho = tamanho; // Define o tamanho da fila
    return fila;
}

void enqueue(fila_t *fila , int elemento)
{
    if(full(fila)){
        printf("A fila está cheia\n");
    } else {
        fila->vetor[fila->fim] = elemento;
        fila->fim = (fila->fim + 1) % fila->tamanho;
        fila->total = fila->total + 1;
    }
}


int dequeue(fila_t *fila)
{
    if (empty(fila)) {
        printf("Fila vazia\n");
    } else {
    int elemento = fila->vetor[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->tamanho;
    fila->total--;
    return elemento;
    }
}

int head(fila_t *fila)
{
    return fila->vetor[fila->inicio];
}

int tail(fila_t *fila)
{
    return fila->vetor[fila->fim];
}

int size(fila_t *fila)
{
    return fila->total;
}

int empty(fila_t *fila)
{
    if(fila->total == 0){
        return 1;
    }
    return 0;
}

int full(fila_t *fila)
{
    if(fila->total == fila->tamanho){
        return 1;
    }
    return 0;
}


