#include <libprg/libprg.h>
#include <string.h>

#define TAMANHO_LISTA_CONTATO 10

struct Pessoa {
    char nome[100];
    char telefone[20];
    char email[50];
};

struct Contatos {
    Pessoa* pessoa;
    int capacidade;
    int tamanho;
};

void cabecalhoTabela() {
    printf("--------------------------------------------------------------------------------\n");
    printf("%-2s | %-24s | %-15s | %s\n", "ID", "Nome", "Telefone", "E-mail");
    printf("--------------------------------------------------------------------------------\n");
}

Contatos* criarContatos() {
    Contatos* contatos = (Contatos*) malloc(sizeof (&contatos));
    if (contatos != NULL) {
        contatos->capacidade = TAMANHO_LISTA_CONTATO;
        contatos->pessoa = (Pessoa*) malloc(sizeof (Pessoa) * contatos->capacidade);
        contatos->tamanho = 0;
        if (contatos->pessoa != NULL) {
            printf("Lista de contatos criada com sucesso.\n");
            return contatos;
        } else {
            printf("Erro ao criar lista de contatos.\n");
            return contatos;
        }
    } else {
        printf("Erro ao criar lista de contatos.\n");
        return contatos;
    }
}

int getTamanhoContatos(Contatos* contatos) {
    return contatos->tamanho;
}

void getPessoas(Contatos* contatos) {
    int tamanho = getTamanhoContatos(contatos);

    if (tamanho > 0) {
        cabecalhoTabela();
        for (int i = 0; i < tamanho; ++i) {
            printf("%-2d | %-24s | %-15s | %s\n",
                   i,
                   contatos->pessoa[i].nome,
                   contatos->pessoa[i].telefone,
                   contatos->pessoa[i].email
            );
        }
    } else {
        printf("Não há contatos cadastrados.\n");
    }
}

void adicionarPessoa(Contatos* contatos, char nome[100], char telefone[15], char email[50]) {
    if (contatos->tamanho >= contatos->capacidade) {
        contatos->capacidade = contatos->capacidade * 2;
        contatos->pessoa = (Pessoa*) realloc(&contatos->pessoa, sizeof (Pessoa) * contatos->capacidade);
    }
    if (contatos->pessoa != NULL) {
        // Copia os valores para a struct pessoa
        strcpy(contatos->pessoa[contatos->tamanho].nome, nome);
        strcpy(contatos->pessoa[contatos->tamanho].telefone, telefone);
        strcpy(contatos->pessoa[contatos->tamanho].email, email);
        // Compara o conteúdo das strings
        int cmp1 = strcmp(contatos->pessoa[contatos->tamanho].nome, nome);
        int cmp2 = strcmp(contatos->pessoa[contatos->tamanho].telefone, telefone);
        int cmp3 = strcmp(contatos->pessoa[contatos->tamanho].email, email);
        // Verifica se os valores são iguais
        if (cmp1 == 0 && cmp2 == 0 & cmp3 == 0) {
            contatos->tamanho = contatos->tamanho + 1;
            printf("Pessoa adicionada com sucesso!\n");
        } else {
            printf("Erro ao adicionar pessoa\n");
        }
    } else {
        printf("Erro ao adicionar pessoa\n");
    }
}

void removerPessoa(Contatos* contatos, int id) {
    char nome[100];
    strcpy(nome, contatos->pessoa[id].nome);
    contatos->tamanho = contatos->tamanho - 1;
    contatos->pessoa[id] = contatos->pessoa[contatos->tamanho];
    printf("%s foi removido(a) da lista de contatos.", nome);
}

void buscarPessoas(Contatos* contatos, char nome[100]) {
    int resultados[5];
    int contagem = 0;

    for (int i = 0; i < contatos->tamanho; ++i) {
        if (strcasestr(contatos->pessoa[i].nome, nome) != NULL) {
            resultados[contagem] = i;
            contagem++;
        }
    }

    if (contagem > 0) {
        cabecalhoTabela();
        for (int i = 0; i < contagem; ++i) {
            printf("%-2d | %-24s | %-15s | %s\n",
                   resultados[i],
                   contatos->pessoa[resultados[i]].nome,
                   contatos->pessoa[resultados[i]].telefone,
                   contatos->pessoa[resultados[i]].email);
        }
    } else {
        printf("Não foi encontrada nenhuma pessoa com '%s'", nome);
    }
}

void verPessoa(Contatos* contatos, int id) {
    cabecalhoTabela();
    printf("%-2d | %-24s | %-15s | %s\n",
           id,
           contatos->pessoa[id].nome,
           contatos->pessoa[id].telefone,
           contatos->pessoa[id].email);
}

void editarPessoa(Contatos* contatos, int id, char nome[100], char telefone[14], char email[50]) {
    if (strcmp(nome, "") != 0) {
        strcpy(contatos->pessoa[id].nome, nome);
    }
    if (strcmp(telefone, "") != 0) {
        strcpy(contatos->pessoa[id].telefone, telefone);
    }
    if (strcmp(email, "") != 0) {
        strcpy(contatos->pessoa[id].email, email);
    }
    printf("Pessoa editada com sucesso!\n");
}

void salvarArquivo(Contatos* contatos) {
    FILE *arq = fopen("contatos.txt", "w");
    if (arq) {
        int tamanho = getTamanhoContatos(contatos);
        if (tamanho > 0) {
            for (int i = 0; i < tamanho; ++i) {
                fprintf(arq, "%-2d | %-24s | %-15s | %s\n",
                       i,
                       contatos->pessoa[i].nome,
                       contatos->pessoa[i].telefone,
                       contatos->pessoa[i].email
                );
            }
        }
        fclose(arq);
    } else {
        printf("Não foi possível abrir o arquivo\n");
    }
}