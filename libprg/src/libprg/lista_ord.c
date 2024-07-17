#include <libprg/libprg.h>

int cria_sort(sort_t* sort, int tamanho){
    if (tamanho <= 0) {
        printf("Tamanho inválido\n");
        exit(EXIT_FAILURE);
    }
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
        for (int j = 0; j < sort->tamanho - 1; ++j) {
            if(sort->vetor[j] > sort->vetor[j+1] && crescente == true
            || sort->vetor[j] < sort->vetor[j+1] && crescente == false){
                int aux = sort->vetor[j];
                sort->vetor[j] = sort->vetor[j + 1];
                sort->vetor[j+1] = aux;
            }
        }
    }
}

void insertion_sort(sort_t* sort){
    for (int i = 0; i < sort->tamanho; ++i) {
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

void merge_sort(sort_t* sort, int esquerda, int direita){
    int meio;
    if(esquerda < direita) {
        meio = esquerda + (direita - esquerda)/2;
        merge_sort(sort, esquerda,meio);
        merge_sort(sort, meio + 1, direita);
        merge(sort, esquerda, meio, direita);
    }
}

void merge(sort_t* sort, int meio, int esquerda, int direita){
    int tamanho_esquerda = meio - esquerda + 1;
    int tamanho_direita = direita - meio;

    int *vetor_esquerda = (int *) malloc(tamanho_esquerda * sizeof(int));
    int *vetor_direita = (int *) malloc(tamanho_direita * sizeof(int));

    for (int i = 0; i < tamanho_esquerda; i++)
        vetor_esquerda[i] = sort->vetor[esquerda + i];
    for (int i = 0; i < tamanho_direita; i++)
        vetor_direita[i] = sort->vetor[meio + 1 + i];

    int i = 0, j = 0, k = esquerda;

    while (i < tamanho_esquerda && j < tamanho_direita) {
        if (vetor_esquerda[i] <= vetor_direita[j]) {
            sort->vetor[k] = vetor_esquerda[i];
            i++;
        } else {
            sort->vetor[k] = vetor_direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanho_esquerda) {
        sort->vetor[k] = vetor_esquerda[i];
        i++;
        k++;
    }

    while (j < tamanho_direita) {
        sort->vetor[k] = vetor_direita[j];
        j++;
        k++;
    }

    free(vetor_esquerda);
    free(vetor_direita);
}

void quick_sort(sort_t* sort, int inicio, int fim){
    int p;
    if(inicio < fim){
        p = particiona(sort, inicio, fim);
        quick_sort(sort, inicio, p - 1);
        quick_sort(sort, p + 1, fim);
    }
}

int particiona(sort_t* sort, int inicio, int fim){
    int pivo = sort->vetor[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; ++j) {
        if(sort->vetor[j] <= pivo){
            i++;
            troca_posicao(sort, i, j);
        }
    }
    i++;
    troca_posicao(sort, i, fim);
    return i;
}

void troca_posicao(sort_t* sort, int i, int j){
    int aux = sort->vetor[i];
    sort->vetor[i] = sort->vetor[j];
    sort->vetor[j] = aux;
}

