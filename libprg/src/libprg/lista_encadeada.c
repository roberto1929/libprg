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

int busca_lista(no_t **no, int element){
    int i = 0;
    while (*no != NULL){
        if((*no)->dado == element){
            return i;
        }
        *no = (*no)->proximo;
        i++;
    }
    return -1;
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
    return 1;

}
int busca_pilha(no_t **no, int element){
    int i = 0;
    while (*no != NULL){
        if((*no)->dado == element){
            return i;
        }
    *no = (*no)->proximo;
    i++;
    }
    return -1;
}
void addCircle(no_t **node, bool op, int value) {
    no_t *new = (no_t *) malloc(sizeof(no_t));
    if (new == NULL) {
        return; // Retorna se a alocação de memória falhar
    }

    new->dado = value;

    if (*node == NULL) { // Se a lista estiver vazia
        new->proximo = new; // O próximo do novo nó aponta para ele mesmo
        *node = new; // O ponteiro para o nó recebe o novo nó
    } else if (!op) { // Se op for false, adiciona no final
        no_t *atual = *node;
        while (atual->proximo != *node) {
            atual = atual->proximo;
        }
        atual->proximo = new;
        new->proximo = *node;
    } else { // Se op for true, adiciona ordenado
        no_t *atual = *node;
        no_t *prev = NULL;
        while (atual->dado > value && atual->proximo != *node) {
            prev = atual;
            atual = atual->proximo;
        }
        if (prev == NULL) { // Se o novo nó for o menor da lista
            while (atual->proximo != *node) {
                atual = atual->proximo;
            }
            atual->proximo = new;
            new->proximo = *node;
            *node = new;
        } else { // Caso contrário, insere o novo nó entre prev e atual
            prev->proximo = new;
            new->proximo = atual;
        }
    }
}

int remove_circular(no_t **no, int value){
    
        if (*no == NULL) {
            return 0; // Retorna 0 se a lista estiver vazia
        }

        no_t *prev = NULL;
        no_t *atual = *no;

        // Percorre a lista circular
        do {
            if (atual->dado == value) {
                if (prev == NULL) { // Se o nó a ser removido é o primeiro da lista
                    no_t *last = *no;
                    while (last->proximo != *no) {
                        last = last->proximo;
                    }
                    if (last == atual) { // Se a lista tem apenas um nó
                        free(*no);
                        *no = NULL;
                    } else {
                        last->proximo = atual->proximo;
                        *no = atual->proximo;
                        free(atual);
                    }
                } else {
                    prev->proximo = atual->proximo;
                    free(atual);
                }
                return 1; // Retorna 1 para indicar que a remoção foi bem-sucedida
            }
            prev = atual;
            atual = atual->proximo;
        } while (atual != *no); // O loop continua até voltar ao início da lista

        return 0; // Retorna 0 se o elemento não for encontrado na lista
    

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


int busca_circular(no_t **no,int value){
    int i = 0;
    no_t *atual = *no;
    do {
        if (atual->proximo == value) {
            return i;
        }
        atual = atual->proximo;
        i++;
    } while (atual != *no);
    return -1;
}

void imprime_no(no_t *no){
    while (no != NULL){
        printf("%d ", no->dado);
        no = no->proximo;
    }
}