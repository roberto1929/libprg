#include <libprg/libprg.h>

void bubble_sort(sort_t *sort, bool crescente){
    int aux;
    for(int i = 0; i < sort->n; i++){
        for(int j = 0; j < sort->n - i; j++){
            if((sort->vetor[j] > sort->vetor[j + 1] && crescente == true) ||
               (sort->vetor[j] < sort->vetor[j + 1] && crescente == false)){
                aux = sort->vetor[j];
                sort->vetor[j] = sort->vetor[j + 1];
                sort->vetor[j + 1] = aux;
            }
        }
    }
}

void insertion_sort(sort_t *sort){
    for(int i = 0; i < sort->n; i++){
        int chave = sort->vetor[i];
        int j = i - 1;
        while(j >= 0 && sort->vetor[j] > chave){
            sort->vetor[j + 1] = sort->vetor[j];
            j = j - 1;
        }
        sort->vetor[j + 1] = chave;
    }
}

void selection_sort(sort_t *sort, bool crescente){
    int indice;
    for(int i = 0; i < sort->n; i++){
        indice = i;
        for(int j = i + 1; j < sort->n; j++){
            if((sort->vetor[j] < sort->vetor[indice] && crescente == true) ||
               (sort->vetor[j] < sort->vetor[indice] && crescente == false)){
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

bool create_S(sort_t *sort, int n){
    sort->vetor = (int *) malloc(n * sizeof(int));
    sort->n = n;
    if(sort->vetor == NULL){
        return false;
    }
    return true;
}

void povoar_S(sort_t *sort, int n){
    srand(1);
    for(int i = 0; i < n; i++){
        sort->vetor[i] = rand() % 100 + 1;
    }
}

bool troca_posicao(sort_t *sort, int i, int j){
    int aux = sort->vetor[i];
    sort->vetor[i] = sort->vetor[j];
    sort->vetor[j] = aux;
}

//------------ MERGE/QUIKE _ SORT ---------------//
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
void merge(sort_t *sort, int mid, int left, int right){
    int *aux = (int *) malloc((right - left + 1) * sizeof(int));
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
    free(aux);
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

