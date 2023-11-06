#include <libprg/libprg.h>

int criar_lista(lista_t *lista){
    lista->vetor = (int*) calloc(lista->tamanho,sizeof(int));

    if(lista->vetor == NULL){
        return 0;
    }
    return 1;
}

void povoar_ordenada(lista_t *lista) {
    srand(time(NULL));
    for (int i = 0; i < lista->tamanho; i++) {
        lista->vetor[i] = rand() % 100 + 1;
        lista->total++;
        for (int j = i; j > 0; j--) {
            if (lista->vetor[j] < lista->vetor[j - 1]) {
                int guarda = lista->vetor[j];
                lista->vetor[j] = lista->vetor[j - 1];
                lista->vetor[j - 1] = guarda;
            } else {
                break;
            }
        }
    }
}
void povoar_nao_ordenada(lista_t *lista);{
    srand(time(NULL));
        for(int i = 0;i < lista->tamanho;i++){
            lista->vetor[i] = rand() % 100 + 1;
        }
    lista->total = lista->tamanho;
}

int remover_nao_ord(lista_t *lista, int elemento);{
    for(int i = 0;i < lista->total;i++){
        if(lista->vetor[i] == elemento){
            lista->vetor[i] = lista->vetor[lista->total - 1];
            lista->total--;
            return 1;
            }
        }
    return 0;
}

int remover_ordenada(lista_t *lista, int elemento){
    for (int i = 0; i < lista->total; i++) {
        if (lista->vetor[i] == elemento) {
            for (; i < lista->total - 1; i++) {
                lista->vetor[i] = lista->vetor[i + 1];
            }
            lista->total--;
            return 1;
        }
    }
    return 0;
}


int inserir_nao_ord(lista_t *lista, int elemento){
    if(lista->tamanho > lista->total){
        lista->vetor[lista->total] = elemento;
        lista->total++;
        return 1;
    }
    return 0;
}

int inserir_ordenada(lista_t *lista, int elemento){
    if (lista->total < lista->tamanho) {
        for (int i = 0; i < lista->total; i++) {
            if (lista->vetor[i] > elemento) {
                for (int j = lista->total; j >= i; j--) {
                    lista->vetor[j + 1] = lista->vetor[j];
                }
                lista->vetor[i] = elemento;
                lista->total++;
                return 1;
            }
        }
    }
    return 0;
    }


int busca_linear(lista_t *lista, int elemento){

    for(int i = 0; i < lista->total; i++){
        if(lista->vetor[i] == elemento){
            return i;
        }
    }
    return -1;
}

int busca_binaria_ite(lista_t *lista, int elemento){
    int inicio = 0;
    int fim = lista->total - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (lista->vetor[meio] == elemento) {
            return meio;
        } else if (lista->vetor[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}


int busca_binaria_rec(lista_t *lista, int inicio, int fim, int elemento){
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (lista->vetor[meio] == elemento) {
            return meio; // Retorna a posição em que o elemento está
        } else if (lista->vetor[meio] > elemento) {
            return busca_binaria_rec(lista, inicio, meio - 1, elemento);
        } else {
            return busca_binaria_rec(lista, meio + 1, fim, elemento);
        }
    }
    return -1; // Elemento não encontrado
}

int libera_memoria(lista_t *lista){
    free(lista->vetor);
    return 1;

}