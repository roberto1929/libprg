//
// Created by aluno on 06/11/23.
//
#include <libprg/libprg.h>

void comeca(struct timeval *inicio){
    gettimeofday(inicio, 0);
}

double medir_tempo_cpu(clock_t start){
    clock_t end = clock();
    return  ((double) (end - start)) / CLOCKS_PER_SEC;
}

double medir_tempo_parede(struct timeval *inicio){
    struct timeval fim;
    gettimeofday(&fim, 0);
    long seg = fim.tv_sec - inicio->tv_sec;
    long mseg = fim.tv_usec - inicio->tv_usec;
    return seg + mseg * 1e-6;
}
