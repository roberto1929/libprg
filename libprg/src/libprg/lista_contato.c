#include <libprg/libprg.h>

typedef struct Pessoa{
    char nome[100];
    char telefone[15];
    char email[50];
}pessoa_t;

typedef struct Contato{
    pessoa_t *vetor;
    int tamanho;
    int total;
}contato_t;



contato_t* criar_contato(int tamanho){
    contato_t* contato = (contato_t*) malloc(sizeof (&contato));
    if (contato == NULL) {
        printf("Erro ao alocar memória para o contato.\n");
        return NULL;
    }
    contato->vetor = (pessoa_t *) malloc(sizeof (pessoa_t) * tamanho);
    if (contato->vetor == NULL) {
        printf("Erro ao alocar memória para o vetor de pessoas.\n");
        free(contato);
        return NULL;
    }
    contato->tamanho = tamanho;
    contato->total = 0;
    return contato;
}


bool adicionar_pessoa(contato_t* contato, char nome[100], char email[50], char telefone[15]){
    if (contato->total < contato->tamanho) {
        pessoa_t nova_pessoa;
        strcpy(nova_pessoa.nome, nome);
        strcpy(nova_pessoa.email, email);
        strcpy(nova_pessoa.telefone, telefone);
        contato->vetor[contato->total++] = nova_pessoa;
        return true;
    } else {
        printf("A lista de contatos está cheia.\n");
        return false;
    }
}

pessoa_t* vizualizar_contato(contato_t* contato){
    if (contato->total == 0) {
        printf("A lista de contatos está vazia.\n");
        return NULL;
    } else {
        return contato->vetor;
    }
}
int busca_contato(contato_t* contato, char nome[100]){
    for (int i = 0; i < contato->total; i++) {
        if (strcmp(contato->vetor[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}
    bool editar_contato(contato_t* contato, char nome[100], char novo_email[50], char novo_telefone[15]) {
        int indice = busca_contato(contato, nome);
        if (indice != -1) {
            strcpy(contato->vetor[indice].email, novo_email);
            strcpy(contato->vetor[indice].telefone, novo_telefone);
            return true;
        } else {
            printf("Contato não encontrado.\n");
            return false;
        }
    }
    bool excluir_contato(contato_t* contato, char nome[100]) {
        int indice = busca_contato(contato, nome);
        if (indice != -1) {
            for (int i = indice; i < contato->total - 1; i++) {
                contato->vetor[i] = contato->vetor[i + 1];
            }
            contato->total--;
            return true;
        } else {
            printf("Contato não encontrado.\n");
            return false;
        }
    }

