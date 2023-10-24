//
// Created by eliaz on 24/10/2023.
//
#include "libprg/libprg.h"

void insert_sort(int vetor[], int tamanho){
    int chave;
    int j;
    for (int i = 0; i < tamanho; ++i) {
        chave = vetor[i];
        j = i-1;
        while (j >= 0 && vetor[j] > chave){
            vetor[j+1] = vetor[j];
            j = j -1;
        }
        vetor[j+1] = chave;
    }
}