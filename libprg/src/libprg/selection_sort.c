//
// Created by eliaz on 24/10/2023.
//
#include "libprg/libprg.h"

void selection_sort(int vetor[], int tamanho){
    int min;
    int aux;
    for (int i = 0; i < tamanho; i++) {
        min = i;
        for (int j = i + 1; j < tamanho ; j++) {
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        if(i != min){
            aux= vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}