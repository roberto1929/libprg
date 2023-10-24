//
// Created by eliaz on 24/10/2023.
//
#include "libprg/libprg.h"

void bubble_sort(int vetor[10]){
    int aux;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10-1; ++j) {
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}
