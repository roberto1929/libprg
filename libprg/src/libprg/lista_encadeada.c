#include <libprg/libprg.h>


void adiciona_lista(listaEncadeada_t *queue, no_t** no, int valor){
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    novo->dado = valor;
    novo->proximo = NULL;

    if(*no == NULL){
        *no = novo;
        queue->inicio = *no;
        queue->size++;
    } else {
        no_t * atual = *no;
        while (atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
        queue->size++;
    }

}

bool remove_lista(no_t** inicio, int dado, listaEncadeada_t * queue){
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while (atual != NULL){
        if(atual->dado == dado){
            if(anterior == NULL){
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            queue->size--;
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

no_t* busca_lista(no_t* inicio, int dado){
    while (inicio != NULL){
        if(inicio->dado == dado){
            return inicio;
        }
        inicio = inicio->proximo;
    }
    return NULL;
}

void adiciona_pilha(stacklist_t *stack, no_t **no, int elemento){
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if(novo == NULL){
        return;
    }

    novo->dado = elemento;
    novo->proximo = *no;
    *no = novo;
    stack->topo = novo;
    stack->size++;
}
int remove_pilha(stacklist_t *stack, no_t **no){
    if(*no == NULL){
        return 0;
    }
    no_t  *atual = stack->topo;
    *no = stack->topo->proximo;
    free(atual);
    stack->topo = *no;
    stack->size--;
    return 1;

}

no_t *busca_pilha(no_t* inicio, int dado){
    while (inicio != NULL){
        if(inicio->dado == dado){
            return inicio;
        }
        inicio = inicio->proximo;
    }
    return NULL;
}




void addCircle(no_t **node, bool op, int value) {
    no_t *new = (no_t *) malloc(sizeof(no_t));
    new->dado = value;
    new->proximo = *node;

    if (*node == NULL) {
        *node = new;
        return;
    }
    if(!op){
        no_t *atual = *node;
        while (atual->proximo != *node){
            atual = atual->proximo;
        }
        atual->proximo = new;
    } else {
        no_t* atual = *node;
        while (atual->proximo != *node && atual->dado > value){
            atual = atual->proximo;
        }
        new->proximo = atual->proximo;
        atual->proximo = new;
    }
}

int remove_circular(no_t **node, int value){

    if(*node == NULL){
        return -1;
    }
    no_t *current = *node;
    while(current != NULL){
        if(current->proximo->dado == value){
            current->proximo = current->proximo->proximo;
            return 1;
        }
        current = current->proximo;
    }
    return 0;

}

void destruir(no_t** no){
    no_t* atual = *no;
    no_t* prox;
    while (atual != NULL){
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *no = NULL;
}


void imprime_no(no_t *no){
    while (no != NULL){
        printf("%d ", no->dado);
        no = no->proximo;
    }
}

// Duplamente encadeada

bool criar_d(int dado){
    nod_t *inicio = malloc(sizeof (nod_t));
    if(inicio == NULL){
        return false;
    }
    inicio->elemento = dado;
    inicio->proximo = NULL;
    inicio->anterior = NULL;
    return true;
}

nod_t add_d(nod_t *nod, int dado){
    nod_t *novo = malloc(sizeof (novo));
    novo->elemento = dado;
    nod->anterior = novo->proximo;
    novo->proximo = nod->proximo;
    nod->proximo = novo;
}

nod_t * add_do(nod_t *nod, int dado){
    nod_t *novo = malloc(sizeof (nod_t));
    novo->elemento = dado;
    while (nod->proximo != NULL){
        if(dado < nod->elemento){
            novo->proximo = nod;
            novo->anterior = nod->anterior;
            nod->anterior = novo;
        }else{
            novo->proximo = nod;
        }
    }
    return nod;
}