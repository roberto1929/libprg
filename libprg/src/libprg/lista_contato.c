#include <libprg/libprg.h>

#define TAMANHO_LISTA_CONTATO 10

struct Pessoa {
    char nome[100];
    char telefone[15];
    char email[50];
};

struct Contatos {
    Pessoa* pessoa;
    int capacidade;
    int tamanho;
};

Contatos* criarContatos() {
    Contatos* contatos = (Contatos*) malloc(sizeof (&contatos));
    contatos->pessoa = (Pessoa*) malloc(sizeof (Pessoa) * TAMANHO_LISTA_CONTATO);
    contatos->capacidade = TAMANHO_LISTA_CONTATO;
    contatos->tamanho = 0;
    return contatos;
}

