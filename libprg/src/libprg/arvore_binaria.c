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

bool busca_arvore(arvore_t *raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca_arvore(raiz->esquerda, valor);
    return busca_arvore(raiz->direita, valor);
}


arvore_t *remover_numero(arvore_t *raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->esquerda = remover_numero(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover_numero(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL) {
            arvore_t *temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            arvore_t *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        arvore_t *temp = raiz->direita;
        while (temp->esquerda != NULL)
            temp = temp->esquerda;

        raiz->valor = temp->valor;

        raiz->direita = remover_numero(raiz->direita, temp->valor);
    }
    return raiz;
}


void imprime_filho_nivel(arvore_t *raiz, int valor, int nivel){
    if(raiz == NULL){
        printf("Número não encontrado na árvore\n");
        return;
    }
    if (valor == raiz->valor) {
        printf("Número encontrado na árvore.\n");
        if (raiz->esquerda != NULL)
            printf("Filho a esquerda: %d\n", raiz->esquerda->valor);
        else
            printf("Não tem filho à esquerda.\n");

        if (raiz->direita != NULL)
            printf("Filho a direita: %d\n", raiz->direita->valor);
        else
            printf("Não tem filho à direita.\n");

        printf("O nível do número encontrado na árvore é: %d\n", nivel);
        return;
    }
    if (valor < raiz->valor) {
        imprime_filho_nivel(raiz->esquerda, valor, nivel + 1);
    } else {
        imprime_filho_nivel(raiz->direita, valor, nivel + 1);
    }
}

void imprime_arvore_in_order(arvore_t *raiz){
    if(raiz != NULL){
        imprime_arvore_in_order(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprime_arvore_in_order(raiz->direita);
    }
}
void imprime_arvore_pre_order(arvore_t *raiz){
    if (raiz != NULL){
        printf("%d ", raiz->valor);
        imprime_arvore_pre_order(raiz->esquerda);
        imprime_arvore_pre_order(raiz->direita);
    }
}
void imprime_arvore_post_order(arvore_t *raiz){
    if(raiz != NULL){
    imprime_arvore_post_order(raiz->esquerda);
    imprime_arvore_post_order(raiz->direita);
    printf("%d ", raiz->valor);
    }
}

void imprimir_texto_grafo(arvore_t *raiz){
    printf("strict graph{\n");
    printf("label=\"Árvore de busca binária\";\n");
    printf("node [shape=\"circle\", color=\"#339966\", style=\"filled\",\n");
    printf("\tfixedsize=true];\n");
    imprime_arvore_grafo(raiz);
    printf("}\n");
}

void imprime_arvore_grafo(arvore_t *raiz){
    if(raiz != NULL){

        if (raiz->esquerda != NULL) {
            printf("%d -- %d\n", raiz->valor, raiz->esquerda->valor);
        }
        if (raiz->direita != NULL) {
            printf("%d -- %d\n", raiz->valor, raiz->direita->valor);
        }
        imprime_arvore_grafo(raiz->esquerda);
        imprime_arvore_grafo(raiz->direita);
    }
}

int exibir_altura(arvore_t *raiz, int valor){

}