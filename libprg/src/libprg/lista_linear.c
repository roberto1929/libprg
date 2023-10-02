#include <libprg/libprg.h>


int criar_lista(ListaLinear *lista, int capacidade){
   lista->dados = (int *)malloc(capacidade * sizeof(int));
    if (lista->dados == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

void povoar_ordenada(ListaLinear *lista, int quantidade, int valorMaximo) {
    srand((unsigned)time(NULL));
  for (int i = 0; i < quantidade; i++) {
        int elemento = rand() % valorMaximo;
        inserir_ordenada(lista, elemento);
    }
}

void povoar_nao_ordenada(ListaLinear *lista, int quantidade, int valorMaximo)
{
   for (int i = 0; i < quantidade; i++) {
        int elemento = rand() % valorMaximo;
        inserir(lista, elemento);
    }
}

int remover(ListaLinear *lista, int elemento){
   int i, j;
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == elemento) {
            for (j = i; j < lista->tamanho - 1; j++) {
                lista->dados[j] = lista->dados[j + 1];
            }
            lista->tamanho--;
            return 0;
        }
    }
    fprintf(stderr, "Erro: Elemento não encontrado na lista.\n");
}

int remover_ordenada(ListaLinear *lista, int elemento){
    int i = 0;
    while (i < lista->tamanho && lista->dados[i] < elemento) {
        i++;
    }
    if (i < lista->tamanho && lista->dados[i] == elemento) {
        for (int j = i; j < lista->tamanho - 1; j++) {
            lista->dados[j] = lista->dados[j + 1];
        }
        lista->tamanho--;
    } else {
        fprintf(stderr, "Erro: Elemento não encontrado na lista.\n");
    }
}


int inserir(ListaLinear *lista, int elemento) {
   if (lista->tamanho < lista->capacidade) {
        lista->dados[lista->tamanho] = elemento;
        lista->tamanho++;
    } else {
        fprintf(stderr, "Erro: A lista está cheia. Não é possível inserir mais elementos.\n");
    }
}

    int inserir_ordenada(ListaLinear *lista, int elemento){
         if (lista->tamanho < lista->capacidade) {
        int i = lista->tamanho - 1;
        while (i >= 0 && lista->dados[i] > elemento) {
            lista->dados[i + 1] = lista->dados[i];
            i--;
        }
        lista->dados[i + 1] = elemento;
        lista->tamanho++;
    } else {
        fprintf(stderr, "Erro: A lista está cheia. Não é possível inserir mais elementos.\n");
    }
}


int busca_linear(ListaLinear *lista, int elemento){
     for (int i = 0; i < lista->tamanho; i++) {
         if (lista->dados[i] == elemento) {
             return i;
         }
         return -1;

         int busca_binaria_ite(ListaLinear *lista, int elemento) {
             int esquerda = 0;
             int direita = lista->tamanho - 1;

             while (esquerda <= direita) {
                 int meio = esquerda + (direita - esquerda) / 2;

                 if (lista->dados[meio] == elemento) {
                     return meio;
                 }
                 if (lista->dados[meio] < elemento) {
                     esquerda = meio + 1;
                 } else {
                     direita = meio - 1;
                 }
             }
             return -1;
         }}

         int busca_binaria_rec(ListaLinear *lista, int elemento, int esquerda, int direita) {
             if (esquerda > direita) {
                 return -1;
             }
             int meio = esquerda + (direita - esquerda) / 2;
             if (lista->dados[meio] == elemento) {
                 return meio;
             }
             if (lista->dados[meio] < elemento) {
                 return busca_binaria_rec(lista, elemento, meio + 1, direita);
             } else {
                 return busca_binaria_rec(lista, elemento, esquerda, meio - 1);
             }
         }

         int libera_memoria(ListaLinear *lista){
             free(lista->dados);
             lista->tamanho = 0;
             lista->capacidade = 0;
         }
     }