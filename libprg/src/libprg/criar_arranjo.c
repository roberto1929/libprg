//
// Created by eliaz on 24/10/2023.
//

#include "libprg/libprg.h"

int * criar_arranjo(int tamanho){
    int * vetor = (int*) malloc(tamanho * sizeof(int));
    srand(1);
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = rand() % 10 +  1;
    }
    return vetor;
}
