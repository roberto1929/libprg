#include <libprg/libprg.h>
#include <string.h>
#include <math.h>

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

Contatos* criarContatos() {
    Contatos* contatos = (Contatos*) malloc(sizeof (&contatos));
    if (contatos != NULL) {
        contatos->capacidade = TAMANHO_LISTA_CONTATO;
        contatos->pessoa = (Pessoa*) malloc(sizeof (Pessoa) * contatos->capacidade);
        contatos->tamanho = 0;
        if (contatos->pessoa != NULL) {
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
    for (int i = 0; i < tamanho; ++i) {
        printf("%d | %s | %s | %s", i, contatos->pessoa[i].nome, contatos->pessoa[i].telefone, contatos->pessoa[i].email);
    }
    printf("\n");
}

bool adicionarPessoa(Contatos* contatos, char nome[100], char telefone[15], char email[50]) {
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
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int buscarPessoa(Contatos* contatos, char nome[100]) {
    double vRef = 10000, vAtual;
    int indice;

    for (int i = 0; i < contatos->tamanho; ++i) {
        vAtual = (double) strcasecmp(contatos->pessoa[i].nome, nome);
        vAtual = sqrt(pow(vAtual, 2));
        if (vAtual < vRef) {
            vRef = vAtual;
            indice = i;
        }
    }
    return indice;
}