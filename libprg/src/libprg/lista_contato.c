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

int comparar_contatos(const void* a, const void* b){
    pessoa_t* pessoa_a = (pessoa_t*)a;
    pessoa_t* pessoa_b = (pessoa_t*)b;
    return strcmp(pessoa_a->nome, pessoa_b->nome);

}


int visualizar_contatos(contato_t* lista_contatos) {
    if (lista_contatos->total == 0) {
        printf("Lista de contatos vazia.\n");
        return 0; // Retorna 0 para indicar que a visualização falhou
    }

    // Ordena os contatos por nome
    qsort(lista_contatos->vetor, lista_contatos->total, sizeof(pessoa_t), comparar_contatos);

    // Exibe os contatos ordenados
    printf("Contatos em ordem alfabética:\n");
    for (int i = 0; i < lista_contatos->total; i++) {
        printf("Nome: %s\n", lista_contatos->vetor[i].nome);
        printf("Telefone: %s\n", lista_contatos->vetor[i].telefone);
        printf("Email: %s\n", lista_contatos->vetor[i].email);
        printf("\n");
    }

    return 1; // Retorna 1 para indicar que a visualização foi bem-sucedida
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

