#include <libprg/libprg.h>
#include <string.h>;


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


pessoa_t *visualizar_contatos(contato_t *lista_contatos, pessoa_t *contatos_ordenados) {
    if (lista_contatos->total == 0) {
        printf("Lista de contatos vazia.\n");
        return NULL;
    }

    for (int i = 0; i < lista_contatos->total; i++) {
        contatos_ordenados[i] = lista_contatos->vetor[i];
    }

    qsort(contatos_ordenados, lista_contatos->total, sizeof(pessoa_t), comparar_contatos);

    printf("Contatos em ordem alfabética:\n");
    for (int i = 0; i < lista_contatos->total; i++) {
        printf("Nome: %s\n", contatos_ordenados[i].nome);
        printf("Telefone: %s\n", contatos_ordenados[i].telefone);
        printf("Email: %s\n", contatos_ordenados[i].email);
        printf("\n");
    }

return contatos_ordenados;
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
void editar_contato(contato_t* lista_contatos, char nome[100], char novo_telefone[15], char novo_email[50]) {
    int editado = 0;

    /* Percorre a lista de contatos*/
    for (int i = 0; i < lista_contatos->total; i++) {
        if (strcmp(lista_contatos->vetor[i].nome, nome) == 0) {
            // Atualiza as informações do contato
            strcpy(lista_contatos->vetor[i].telefone, novo_telefone);
            strcpy(lista_contatos->vetor[i].email, novo_email);

            editado = 1;
            printf("Contato editado com sucesso!\n");
            break;
        }
    }
    if (!editado) {
        printf("Contato não encontrado.\n");
    }
}


void excluir_contato(contato_t* lista_contatos, char nome[100]){
    // Variável para controlar se o contato foi encontrado e excluído
    int excluido = 0;

    // Percorre a lista de contatos
    for (int i = 0; i < lista_contatos->total; i++) {
        // Verifica se o nome do contato é igual ao fornecido pelo usuário
        if (strcmp(lista_contatos->vetor[i].nome, nome) == 0) {
            // Remove o contato da lista (deslocando os contatos restantes para preencher o espaço)
            for (int j = i; j < lista_contatos->total - 1; j++) {
                lista_contatos->vetor[j] = lista_contatos->vetor[j + 1];
            }
            lista_contatos->total--; // Decrementa o total de contatos na lista

            // Define que o contato foi excluído
            excluido = 1;
            printf("Contato excluído com sucesso!\n");
            break; // Interrompe o loop assim que o contato é encontrado e excluído
        }
    }

    // Verifica se o contato não foi encontrado
    if (!excluido) {
        printf("Contato não encontrado.\n");
    }
}