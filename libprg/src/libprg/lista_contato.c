#include <libprg/libprg.h>
#include <string.h>

#define TAMANHO_P 10

contato_t* criar_contato(){
    contato_t* contato = (contato_t*) malloc(sizeof (&contato));
    if (contato == NULL) {
        printf("Erro ao alocar memória para o contato.\n");
        return NULL;
    }
    if(contato != NULL){
        contato->total = TAMANHO_P;
        contato->vetor = malloc(sizeof(pessoa_t) * contato->total);
        contato->tamanho = 0;
    }
    FILE *arq = fopen("contato.bin", "rb");

    if(arq){
        fseek(arq, 0, SEEK_END);
        long tam_arq = ftell(arq);
        rewind(arq);

        contato->tamanho = tam_arq / sizeof(pessoa_t);

        while (contato->tamanho >= contato->total) {
            contato->total = contato->total * 2;
            contato->vetor = (pessoa_t *) realloc(&contato->vetor, sizeof (pessoa_t) * contato->total);
        }
        if (contato->vetor != NULL) {
            fread(contato->vetor, sizeof(pessoa_t), contato->tamanho, arq);
            fclose(arq);
        }
    }
    if (contato->vetor != NULL) {
        return contato;
    }else {
        free(contato);
    }
    return NULL;

}

bool adicionar_pessoa(contato_t* contato, char nome[100], char email[50], char telefone[15]){
    if (contato->total > contato->tamanho) {
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
        for (int i = 0; i < contato->tamanho; ++i) {
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
