//
// Created by aluno on 30/10/23.
//
#include "libprg/libprg.h"

void insert_sort(sort_t *sort){
    for (int i = 0; i < sort->n; ++i) {
        int chave = sort->vetor[i];
        int j = i-1;
        while (j >= 0 && sort->vetor[j] > chave){
            sort->vetor[j+1] = sort->vetor[j];
            j = j -1;
        }
        sort->vetor[j+1] = chave;
    }
}

void selection_sort(sort_t *sort){
    int indice;
    for(int i = 0; i < sort->n; i++){
        indice = i;
        for(int j = i + 1; j < sort->n; j++){
            if(sort->vetor[j] < sort->vetor[indice]) {
                indice = j;
            }
        }
        if(i != indice){
            int aux = sort->vetor[i];
            sort->vetor[i] = sort->vetor[indice];
            sort->vetor[indice] = aux;
        }
    }
}

void selection_sort_d(sort_t *sort){
    int indice;
    for(int i = 0; i < sort->n; i++){
        indice = i;
        for(int j = i + 1; j < sort->n; j++){
            if(sort->vetor[j] > sort->vetor[indice]) {
                indice = j;
            }
        }
        if(i != indice){
            int aux = sort->vetor[i];
            sort->vetor[i] = sort->vetor[indice];
            sort->vetor[indice] = aux;
        }
    }
}


void bubble_sort(sort_t *sort){
    int aux;
    for (int i = 0; i < sort->n; ++i) {
        for (int j = 0; j < sort->n - i; ++j) {
            if(sort->vetor[j] > sort->vetor[j+1]){
                aux = sort->vetor[j];
                sort->vetor[j] = sort->vetor[j+1];
                sort->vetor[j+1] = aux;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ", sort->vetor[i]);
    }
    printf("\n");
}

void bubble_sort_d(sort_t *sort){
    int aux;
    for(int i = 0; i < sort->n; i++){
        for(int j = 0; j < sort->n - 1; j++){
            if(sort->vetor[j] < sort->vetor[j + 1]) {
                aux = sort->vetor[j];
                sort->vetor[j] = sort->vetor[j + 1];
                sort->vetor[j + 1] = aux;
            }
        }
    }
}



//
//void merge_sort(sort_t *sort, int esquerda, int direita){
//    if(esquerda < direita){
//        int meio = esquerda + (direita - esquerda)/2;
//        merge_sort(sort->vetor, esquerda , meio);
//        merge_sort(sort->vetor, meio = 1, direita);
//
//        merge(sort->vetor, esquerda, meio, direita);
//    }
//}
//
//void merge(sort_t *sort, int esquerda, int meio, int direita){
//    int *aux= (int *) malloc(sizeof direita - esquerda +1);
//    int i = esquerda;
//    int j = (meio + 1);
//    int k = 0;
//
//    while (i <= meio && j <= direita){
//        if(sort->vetor[i] <= sort->vetor[j]){
//            aux[k] = sort->vetor[i];
//            i++;
//        } else {
//            aux[k] = sort->vetor[j];
//            j++;
//        }
//    }
//    while (i <= meio){
//        aux[k] = sort->vetor[i];
//        i++;
//        k++;
//    }
//    while (j <= (direita)){
//        aux[k] = sort->vetor[j];
//        j++;
//        k++;
//    }
//    for (i = esquerda; esquerda < direita; ++i) {
//        sort->vetor[i] = aux[i - esquerda];
//    }
//}
//
//int *quick_sort(sort_t *sort, int inicio, int fim){
//    int p;
//    if(inicio < fim){
//    p = particiona(sort->vetor, inicio, fim);
//        quick_sort(sort->vetor, inicio, p - 1);
//        quick_sort(sort->vetor, p + 1, fim);
//    }
//    return sort->vetor;
//}
//
//int particiona(int *vetor, int inicio, int fim){
//    int pivo;
//    pivo = vetor[fim];
//    int i = inicio - 1;
//    for (int j = inicio; j < fim; ++j) {
//        if(vetor[j] <= pivo){
//            i++;
//            troca_pos(vetor, i,j);
//        }
//    }
//    i++;
//    troca_pos(vetor, i,fim);
//    return i;
//}
//
//void troca_pos(int *vetor, int i, int j){
//    int aux = vetor[i];
//    vetor[i] = vetor[j];
//    vetor[j] = aux;
//};
