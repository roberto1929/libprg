#include <libprg/libprg.h>



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

void buscar_contato(contato_t* lista_contatos, const char* nome_busca) {
    bool encontrado = false;

    // Percorre a lista de contatos
    for (int i = 0; i < lista_contatos->total; i++) {
        // Verifica se o nome do contato atual contém a string de busca
        if (strstr(lista_contatos->vetor[i].nome, nome_busca) != NULL) {
            // Se encontrado, exibe as informações do contato e marca como encontrado
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", lista_contatos->vetor[i].nome);
            printf("Telefone: %s\n", lista_contatos->vetor[i].telefone);
            printf("Email: %s\n", lista_contatos->vetor[i].email);
            encontrado = true;
        }
    }

    // Se o contato não for encontrado, exibe uma mensagem
    if (!encontrado) {
        printf("Nenhum contato encontrado para '%s'.\n", nome_busca);
    }
}
void editar_contato(contato_t* lista_contatos) {
    char nome_busca[100];
    printf("Digite o nome do contato que deseja editar: ");
    scanf("%99s", nome_busca);

    // Busca o contato pelo nome
    pessoa_t* contato = buscar_contato(lista_contatos, nome_busca);

    if (contato != NULL) {
        // Se o contato for encontrado, solicita as novas informações
        char novo_telefone[15], novo_email[50];
        printf("Digite o novo email do contato: ");
        scanf("%49s", novo_email);
        printf("Digite o novo telefone do contato: ");
        scanf("%14s", novo_telefone);

        // Atualiza as informações do contato
        strcpy(contato->telefone, novo_telefone);
        strcpy(contato->email, novo_email);

        printf("Informacoes do contato atualizadas com sucesso.\n");
    }
}

// Função para excluir um contato
void excluir_contato(contato_t* lista_contatos) {
    char nome_busca[100];
    printf("Digite o nome do contato que deseja excluir: ");
    scanf("%99s", nome_busca);

    // Busca o contato pelo nome
    pessoa_t* contato = buscar_contato(lista_contatos, nome_busca);

    if (contato != NULL) {
        // Se o contato for encontrado, remove-o da lista
        // Encontra o índice do contato na lista
        int indice_contato = -1;
        for (int i = 0; i < lista_contatos->total; i++) {
            if (&lista_contatos->vetor[i] == contato) {
                indice_contato = i;
                break;
            }
        }

        if (indice_contato != -1) {
            // Desloca os contatos restantes para preencher o espaço
            for (int i = indice_contato; i < lista_contatos->total - 1; i++) {
                lista_contatos->vetor[i] = lista_contatos->vetor[i + 1];
            }
            lista_contatos->total--;
            printf("Contato excluido com sucesso.\n");
        } else {
            printf("Erro ao excluir contato.\n");
        }
    }
}
