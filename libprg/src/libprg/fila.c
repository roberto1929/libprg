//#include <libprg/libprg.h>
//
//int criar_fila(fila_t *vetor){
//    vetor->vetor = (int* ) calloc(vetor->tam, sizeof(int));
//    vetor->inicio = -1;
//    vetor->fim = -1;
//}
//
//int enqueue(int elemento, fila_t *vetor){
//    if(full(vetor)){
//        return 0;
//    }
//    if(empty(vetor)){
//        vetor->inicio = 0;
//    }
//    vetor->fim = (vetor->fim+1)%100;
//    vetor->vetor[vetor->fim] = elemento;
//    return 1;
//}
//
//int dequeue( fila_t *vetor){
//    if(empty(vetor)){
//        return -1;
//    }
//    int elemento_removido = vetor->vetor[vetor->inicio];
//    if(vetor->inicio == vetor->fim){
//        criar_fila(vetor);
//    } else {
//        vetor->inicio = (vetor->inicio +1)%100;
//    }
//    return  elemento_removido;
//}
//
//int head(fila_t *vetor){
//    if(empty(vetor)){
//        return -1;
//    }
//    return vetor->vetor[vetor->inicio];
//}
//
//int tail(fila_t *vetor){
//    if(empty(vetor)){
//        return -1;
//    }
//    return vetor->vetor[vetor->fim];
//}
//
//int size(fila_t *vetor){
//    if(empty(vetor)){
//        return 0;
//    }
//    if(vetor->inicio <= vetor->fim){
//        return vetor->fim - vetor->inicio +1;
//    } else{
//        return 100 - vetor->inicio + vetor->fim +1;
//    }
//}
//
//int empty(fila_t *vetor){
//    return (vetor->inicio == -1 && vetor->fim == -1);
//}
//
//int full(fila_t *vetor){
//    return ((vetor->fim +1) % 100 == vetor->inicio);
//}
