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



contato_t* criar_contato(int tamanho){

    contato_t* contato = (contato_t*) malloc(sizeof (&contato));
    contato->vetor = (pessoa_t *) malloc(sizeof (pessoa_t) * tamanho);
    contato->tamanho = tamanho;
    contato->total = 0;
    return contato;
}

