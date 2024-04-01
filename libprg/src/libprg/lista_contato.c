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

void ler_contato(pessoa_t* pesssoa){
    printf("Entre com o nome: ");
    fgets(pesssoa->nome,100,stdin);
    printf("Entre com o email: ");
    fgets(pesssoa->email,50,stdin);
    printf("Entre com o numero: ");
    fgets(pesssoa->telefone,15,stdin);
}

bool adicionar_pessoa(contato_t* contato, char nome[100], char email[50], char telefone[15]){
    return 0;
}

pessoa_t* vizualizar_contato(contato_t* contato){
    return 0;
}
int busca_contato(contato_t* contato){
    return 0;
}
int editar_contato(contato_t* contato){
    return 0;
}
int excluir_contato(contato_t* contato){
    return 0;
}


