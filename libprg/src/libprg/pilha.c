
#include <libprg/libprg.h>

int push(pilha_t *pilha, int elemento){
if(pilha-> topo == pilha->tam){
    return 0;
} else {
    pilha->pilha[pilha->topo++] = elemento;
    return 1;
    }
}

int pop(pilha_t *pilha){
    if(pilha->topo == -1){
        return -1;
    } else{
        return pilha->pilha[(pilha->topo)--];
    }
}

int size_p(pilha_t pilha){
    return (pilha.topo == +1);
}

int empty_p(pilha_t pilha){
    return (pilha.topo == -1);
}
