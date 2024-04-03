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



contato_t* criar_contato(int tamanho) {
    contato_t* contato = (contato_t*) malloc(sizeof(contato_t));
    if (contato == NULL) {
        printf("Erro ao alocar memória para o contato.\n");
        return NULL;
    }
    contato->vetor = (pessoa_t *) malloc(sizeof(pessoa_t) * tamanho);
    if (contato->vetor == NULL) {
        printf("Erro ao alocar memória para o vetor de pessoas.\n");
        free(contato);
        return NULL;
    }
    contato->tamanho = tamanho;
    contato->total = 0;
    return contato;
}



void adicionar_contato(contato_t* lista_contatos, char nome[100], char telefone[15], char email[50]) {
    if (lista_contatos->total < lista_contatos->tamanho) {
        pessoa_t* nova_pessoa = (pessoa_t*) malloc(sizeof(pessoa_t));
        if (nova_pessoa == NULL) {
            printf("Erro ao alocar memória para o novo contato.\n");
            return;
        }
        strcpy(nova_pessoa->nome, nome);
        strcpy(nova_pessoa->telefone, telefone);
        strcpy(nova_pessoa->email, email);

        lista_contatos->vetor[lista_contatos->total] = *nova_pessoa;
        lista_contatos->total++; // Incrementa o total de contatos na lista

        printf("Contato adicionado com sucesso!\n");

        free(nova_pessoa);
    } else {
        printf("A lista de contatos está cheia. Não é possível adicionar mais contatos.\n");
    }
}

void visualizar_contatos(contato_t* lista_contatos) {
    // Verifica se há contatos na lista
    if (lista_contatos->total == 0) {
        printf("A lista de contatos está vazia.\n");
    } else {
        printf("Lista de contatos:\n");
        // Percorre a lista de contatos e exibe as informações de cada contato
        for (int i = 0; i < lista_contatos->total; i++) {
            printf("Nome: %s\n", lista_contatos->vetor[i].nome);
            printf("Telefone: %s\n", lista_contatos->vetor[i].telefone);
            printf("Email: %s\n", lista_contatos->vetor[i].email);
            printf("\n");
        }
    }
}
void buscar_contato(contato_t* lista_contatos, char nome[100]) {
    // Variável para controlar se pelo menos uma correspondência foi encontrada
    int correspondencias = 0;

    // Percorre a lista de contatos
    for (int i = 0; i < lista_contatos->total; i++) {
        // Verifica se o nome do contato contém a string fornecida pelo usuário
        if (strstr(lista_contatos->vetor[i].nome, nome) != NULL) {
            // Exibe as informações do contato correspondente
            printf("Nome: %s\n", lista_contatos->vetor[i].nome);
            printf("Telefone: %s\n", lista_contatos->vetor[i].telefone);
            printf("Email: %s\n", lista_contatos->vetor[i].email);
            printf("\n");

            // Atualiza o contador de correspondências
            correspondencias++;
        }
    }

    // Verifica se nenhuma correspondência foi encontrada
    if (correspondencias == 0) {
        printf("Nenhuma correspondencia encontrada para \"%s\".\n", nome);
    }
}

void editar_contato(contato_t* lista_contatos, char nome[100], char novo_telefone[15], char novo_email[50]) {
    // Variável para controlar se o contato foi encontrado e editado
    int editado = 0;

    // Percorre a lista de contatos
    for (int i = 0; i < lista_contatos->total; i++) {
        // Verifica se o nome do contato é igual ao fornecido pelo usuário
        if (strcmp(lista_contatos->vetor[i].nome, nome) == 0) {
            // Atualiza as informações do contato
            strcpy(lista_contatos->vetor[i].telefone, novo_telefone);
            strcpy(lista_contatos->vetor[i].email, novo_email);

            // Define que o contato foi editado
            editado = 1;
            printf("Contato editado com sucesso!\n");
            break; // Interrompe o loop assim que o contato é encontrado e editado
        }
    }

    // Verifica se o contato não foi encontrado
    if (!editado) {
        printf("Contato não encontrado.\n");
    }
}

void excluir_contato(contato_t* lista_contatos, char nome[100]) {
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


int getTamanho(contato_t* contato){
    return contato->tamanho;
}
void getPessoas(contato_t* contato){
    for (int i = 0; i < contato->total; ++i) {
        printf("%s - %s - %s", contato->vetor->nome, contato->vetor->email, contato->vetor->telefone);
    }
}

