#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

// Lista Linear
typedef struct Lista Lista;
Lista* criarLista();
int* getElementos(Lista* lista);
int getTamanho(Lista* lista);
int inserirElemento(Lista* lista, int n);
void removerElemento(Lista* lista, int n);
int buscaLinear(Lista* lista, int n);
int buscaBinariaInterativa(Lista* lista, int n);
int buscaBinariaRecursiva(Lista* lista, int n, int inicio, int fim);

// Lista Contato
typedef struct Pessoa {
    char nome[100];
    char telefone[20];
    char email[50];
} Pessoa;

typedef struct Contato {
    struct Pessoa* pessoa;
    int capacidade;
    int tamanho;
} Contatos;

Contatos* criarContatos();
Pessoa* getPessoas(Contatos* contatos);
int getTamanhoContatos(Contatos* contatos);
bool adicionarPessoa(Contatos* contatos, char nome[100], char telefone[14], char email[50]);
void removerPessoa(Contatos* contatos, int id);
int* buscarPessoas(Contatos* contatos, char nome[100]);
void verPessoa(Contatos* contatos, int id);
void editarPessoa(Contatos* contatos, int id, char nome[100], char telefone[14], char email[50]);
void salvarArquivo(Contatos* contatos);
void lerArquivo(Contatos* contatos);
void salvarArquivoBin(Contatos* contatos);
void lerArquivoBin(Contatos* contatos);

// Soma
typedef enum { SUM, SUB } operation_t;
result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

// Fila
typedef struct Fila Fila;
Fila* criaFila(int capacidade); // OK
int* getFila(Fila* fila); // OK
int getSize(Fila* fila); // OK
bool isEmpty(Fila* fila); // OK
bool isFull(Fila* fila); // OK
void enqueue(Fila* fila, int n); // OK
int dequeue(Fila* fila); // OK
int head(Fila* fila); // OK
int tail(Fila* fila); // OK

// pilha
typedef struct Pilha Pilha;
Pilha* criarPilha();
void push();

#endif