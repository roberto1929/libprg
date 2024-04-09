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
            printf("     Telefone: %s\n", contato->vetor[i].telefone);
            printf("     Email: %s\n\n", contato->vetor[i].email);
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
int editar_contato(contato_t* lista_contatos, char nome[100], char novo_telefone[15], char novo_email[50]) {


    /* Percorre a lista de contatos*/
    for (int i = 0; i < lista_contatos->total; i++) {
        if (strcmp(lista_contatos->vetor[i].nome, nome) == 0) {
            // Atualiza as informações do contato
            strcpy(lista_contatos->vetor[i].telefone, novo_telefone);
            strcpy(lista_contatos->vetor[i].email, novo_email);

            return 1;
        } else{
            return 0;
        }
    }
}


int excluir_contato(contato_t* lista_contatos, char nome[100]){
    // Percorre a lista de contatos
    for (int i = 0; i < lista_contatos->total; i++) {
        // Verifica se o nome do contato é igual ao fornecido pelo usuário
        if (strcmp(lista_contatos->vetor[i].nome, nome) == 0) {
            // Remove o contato da lista (deslocando os contatos restantes para preencher o espaço)
            for (int j = i; j < lista_contatos->total - 1; j++) {
                lista_contatos->vetor[j] = lista_contatos->vetor[j + 1];
            }
            lista_contatos->total--;
            return 1;
        } else{
            return 0;
        }

    }
}