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



void merge(sort_t *sort, int mid, int left, int right){
    int *aux = (int *) malloc(sizeof(right - left + 1));
    int i = left;
    int j = mid + 1;
    int k = 0;
    while((i <= mid) && (j <= right)){
        if(sort->vetor[i] <= sort->vetor[j]){
            aux[k] = sort->vetor[i];
            i++;
        }else{
            aux[k] = sort->vetor[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        aux[k] = sort->vetor[i];
        i++; k++;
    }
    while(j <= right){
        aux[k] = sort->vetor[j];
        j++; k++;
    }
    for(i = left; i < right; i++){
        sort->vetor[i] = aux[i - left];
    }
}


void merge_sort(sort_t *sort, int left, int right){
    int mid;
    if(left < right){
        mid = left + (right - left) / 2;
        merge_sort(sort, left, mid);
        merge_sort(sort, mid + 1, right);
        merge(sort, mid, left, right);
    }
}

void quick_sort(sort_t *sort, int start, int end){
    int p;
    if(start < end){
        p = particiona(sort, start, end);
        quick_sort(sort, start, p - 1);
        quick_sort(sort, p + 1, end);
    }
}

int particiona(sort_t *sort, int start, int end){
    int pivot = sort->vetor[end];
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(sort->vetor[j] <= pivot){
            i++;
            troca_posicao(sort, i, j);
        }
    }
    i++;
    troca_posicao(sort, i, end);
    return i;
}
bool troca_posicao(sort_t *sort, int i, int j){
    int aux = sort->vetor[i];
    sort->vetor[i] = sort->vetor[j];
    sort->vetor[j] = aux;
}