//#include <libprg/libprg.h>
//
//void addList(lista_encadeada_t *listaEncadeada, no_t **no, int value)
//{
//    no_t *novo = (no_t*) malloc(sizeof(no_t));
//    novo->elemento = value;
//    novo->proximo = NULL;
//
//    if (*no == NULL) {
//        *no = novo;
//        listaEncadeada->start = *no;
//        listaEncadeada->size++;
//    } else {
//        no_t *atual = *no;
//        while (atual->proximo != NULL) {
//            atual = atual->proximo;
//        }
//        atual->proximo = novo;
//        listaEncadeada->size++;
//    }
//}
//
//int removeList(lista_encadeada_t *listaEncadeada, no_t **no)
//{
//    if(*no == NULL){
//        return 0;
//    }
//
//    no_t *atual = *no;
//    *no = (*no)->proximo;
//    free(atual);
//    listaEncadeada->size--;
//    return 1;
//}
//
//int searchList(no_t **no, int elemento)
//{
//    int i = 0;
//    while(*no != NULL){
//        if((*no)->elemento == elemento){
//            return i;
//        }
//        *no = (*no)->proximo;
//        i++;
//    }
//    return -1;
//}
//
//void addStack(Stackist_t *stack, no_t **no, int elemento) {
//    no_t *novo = (no_t*) malloc(sizeof(no_t));
//    if (novo == NULL) {
//        return;
//    }
//
//    novo->elemento = elemento;
//    novo->proximo = *no;
//    *no = novo;
//    stack->high = novo;
//    stack->size++;
//}
//
//int removeStack(Stackist_t *stack, no_t **no)
//{
//    if (*no == NULL) {
//        return 0;
//    }
//
//    no_t *current = stack->high;
//    *no = stack->high->proximo;
//    free(current);
//    stack->high = *no;
//
//    return 1;
//}
//
//int searchStack(no_t **no, int element)
//{
//    int i = 0;
//    while(*no != NULL){
//        if((*no)->elemento == element){
//            return i;
//        }
//        *no = (*no)->proximo;
//        i++;
//    }
//    return -1;
//}
//
//void printNo(no_t *no)
//{
//    while(no != NULL){
//        printf("%d ",no->elemento);
//        no = no->proximo;
//    }
//}