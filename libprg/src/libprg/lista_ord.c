#include <libprg/libprg.h>

int cria_sort(sort_t* sort, int tamanho){
    sort->vetor = (int*) malloc(tamanho * sizeof(int));
    sort->tamanho = tamanho;
    if(sort->vetor == NULL){
        printf("Não foi possível criar o vetor\n");
        exit(EXIT_FAILURE);
    }
    return 1;
}

void preencher_sort(sort_t* sort, int tamanho){
    srand(1);
    for(int i = 0; i < tamanho; i++){
        sort->vetor[i] = rand() % 100 + 1;
    }
}

void imprimir_ord(sort_t *sort)
{
    for(int i = 0; i < sort->tamanho;i++){
        printf("%d ",sort->vetor[i]);
    }
    printf("\n");
}

void bubble_sort(sort_t* sort, bool crescente){
    for (int i = 0; i < sort->tamanho; ++i) {
        for (int j = 0; j < sort->tamanho - i; ++j) {
            if(sort->vetor[j] < sort->vetor[j+1] && crescente == true
            || sort->vetor[j] > sort->vetor[j+1] && crescente == false){
                int aux = sort->vetor[j];
                sort->vetor[j] = sort->vetor[j + 1];
                sort->vetor[j+1] = aux;
            }
        }
    }
}

void insertion_sort(sort_t* sort){
    for (int i = 0; i < sort->tamanho - 1; ++i) {
        int chave = sort->vetor[i];
        int j = i - 1;
        while (j >= 0 && sort->vetor[j] > chave){
            sort->vetor[j+1] = sort->vetor[j];
            j = j -1;
        }
        sort->vetor[j+1] = chave;
    }
}

void selection_sort(sort_t* sort, bool crescente){
    for (int i = 0; i < sort->tamanho - 1; ++i) {
        int min = i;
        for (int j = i; j < sort->tamanho; ++j) {
            if(sort->vetor[j] < sort->vetor[min] && crescente == true
            || sort->vetor[j] > sort->vetor[min] && crescente == false){
                min = j;
            }
        }
        if(i != min){
            int aux = sort->vetor[i];
            sort->vetor[i] = sort->vetor[min];
            sort->vetor[min] =  aux;
        }
    }
}
