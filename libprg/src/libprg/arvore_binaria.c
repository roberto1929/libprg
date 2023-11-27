//
// Created by aluno on 27/11/23.
//
#include <libprg/libprg.h>

arvore_t *criar_arvore(int valor){
    arvore_t *arvore = (arvore_t *) malloc(sizeof(arvore_t));
    arvore->valor = valor;
    arvore->esquerda = arvore->direita = NULL;
    return arvore;
}

void destruir_arvore(arvore_t *arvore){
    if(arvore != NULL){
        destruir_arvore(arvore->esquerda);
        destruir_arvore(arvore->direita);
        free(arvore);
    }
}

arvore_t *inserir_valor(arvore_t *raiz, int valor){
    if(raiz == NULL){
        return criar_arvore(valor);
    } else if(valor < raiz->valor){
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    } else if(valor > raiz->valor){
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}

bool busca(arvore_t *raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);
}