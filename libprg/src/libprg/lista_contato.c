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


void imprimir_contatos(contato_t *contato){
    printf("Contatos:\n");
        for (int i = 0; i < contato->total; ++i) {
            printf("[%d] Nome: %s\n", i, contato->vetor[i].nome);
            printf("    Telefone: %s\n", contato->vetor[i].telefone);
            printf("    Email: %s\n\n", contato->vetor[i].email);
    }
}


int buscar_contato(contato_t* lista_contatos, char nome[100], int* resultados) {

    int contagem = 0;

    for (int i = 0; i < lista_contatos->total; ++i) {
        if (strcasestr(lista_contatos->vetor[i].nome, nome) != NULL) {
            resultados[contagem] = i;
            contagem++;
        }
    }
    return contagem;
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
        contato->vetor[i] = contato->vetor[i+1];
    }
    contato->total --;
    return 1;
}