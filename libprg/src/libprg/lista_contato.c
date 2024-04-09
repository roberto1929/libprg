#include <libprg/libprg.h>
#include <string.h>


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
        return false;
    }
}

contato_t *buscar_contatos(contato_t *contato, const char *sequencia) {

    for (int i = 0; i < contato->total; i++) {
        if (strcasestr(contato->vetor[i].nome, sequencia) != NULL) {
            printf("Nome: %s\n", contato->vetor[i].nome);
            printf("Telefone: %s\n", contato->vetor[i].telefone);
            printf("Email: %s\n\n", contato->vetor[i].email);
            return 1;
        } else{
            return 0;
        }
    }
}


void imprimir_contatos(contato_t *contato){
    printf("Contatos:\n");
        for (int i = 0; i < contato->tamanho; ++i) {
            printf("[%d] Nome: %s\n", i, contato->vetor[i].nome);
            printf("    Telefone: %s\n", contato->vetor[i].telefone);
            printf("    Email: %s\n\n", contato->vetor[i].email);
    }
}


int buscar_contato(contato_t* lista_contatos, const char* nome_busca) {
        // Percorre a lista de contatos
    for (int i = 0; i < lista_contatos->total; i++) {
        if (strstr(lista_contatos->vetor[i].nome, nome_busca) == 0) {
            printf("O contato encontrado:\n");
            printf("Nome: %s\n", lista_contatos->vetor[i].nome);
            printf("Telefone: %s\n", lista_contatos->vetor[i].telefone);
            printf("Email: %s\n", lista_contatos->vetor[i].email);
            return i;
        }
    }

    printf("O contato não foi encontrado.\n");
    return -1;
}
int editar_contato(contato_t *contato, int pos_lista, char *nome, char *email, char *telefone) {
    if (pos_lista >= 0 && pos_lista < contato->total) {
        strcpy(contato->vetor[pos_lista].nome, nome);
        strcpy(contato->vetor[pos_lista].telefone, telefone);
        strcpy(contato->vetor[pos_lista].email, email);
        return 1;
    } else {
        return 0;
    }
}


int excluir_contato(contato_t *contato, int indice) {
    if (indice < 0 || indice >= contato->total) {
        return 0;
    }

    for (int i = indice; i < contato->total - 1; i++) {
        strcpy(contato->vetor[i].nome, contato->vetor[i + 1].nome);
        strcpy(contato->vetor[i].telefone, contato->vetor[i + 1].telefone);
        strcpy(contato->vetor[i].email, contato->vetor[i + 1].email);
    }
    contato->total --;
    return 1;
}