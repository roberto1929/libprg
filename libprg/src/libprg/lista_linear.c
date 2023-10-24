//#include <libprg/libprg.h>
//
//int criar_lista(int *vetor, int tam){
//    vetor = (int* ) calloc(tam,sizeof (int));
//    return 0;
//}
//
//int povoar_ordenada(int *vetor, int tam, char op) {
//    srand((unsigned)time(NULL));
//
//    if (op == 'a') {
//        for (int i = 0; i < tam; i++) {
//            vetor[i] = i + 1;
//        }
//    } else if (op == 'd') {
//        for (int i = 0; i < tam; i++) {
//            vetor[i] = tam - i;
//        }
//    }
//
//    return 0;
//}
//int povoar_nao_ordenada(int *vetor,int *total, int tamanho)
//{
//    srand((unsigned) time(NULL));
//    for(int i = 0;i < tamanho;i++){
//        vetor[i] = rand() % 1000+1;
//}
//}
//
//int remover(int elemento, int *vetor, int *total, int tam){
//    for(int i = 0;i < total;i++){
//        if(vetor[i] == elemento){
//            vetor[i] = vetor[total - 1];
//        }
//    }
//    return 0;
//}
//
//int remover_ordenada(int elemento, int *vetor, int *total, int tam){
//    for(int i = 0;i < total;i++){
//        if(vetor[i] == elemento){
//            for(;i < total; i++){
//                vetor[i] = vetor[i + 1];
//            }
//            total--;
//            return 1;
//        }
//}
//
//
//int inserir(int elemento, int *vetor, int tam, int *total) {
//    if(tamanho > total){
//        vetor[(int) &total] = elemento;
//        total++;
//    }
//    return 0;
//}
//
//    int inserir_ordenada(int elemento, int *vetor, int tam, int *total){
//        if(total < tamanho){
//            for(int i = 0; i < total; i++){
//                if(vetor[i] > elemento){
//                    for(int j = total;j >= i; j--){
//                        vetor[j + 1] = vetor[j]
//                    }
//                    vetor[i] = elemento;
//                    break;
//                }
//            }
//        }
//        return 0;
//    }
//
//
//int busca_linear(int elemento, int *vetor, int total, int tam){
//    for (int i = 0; i < *total;i++){
//        if(vetor[i] == elemento){;
//        return 1;
//        }
//    }
//}
//
//int busca_binaria_ite(int elemento, int *vetor, int *total){
//    for(int i = 0; i <= total; i++){
//        int meio = i + (*total - i)/2
//        if(vetor[meio] = elemento){
//            return 1;
//        } else if(vetor[meio] < elemento){
//            i = meio+1;
//        } else{
//            *total = meio - 1;
//        }
//    }
//
//}
//
//
//int busca_binaria_rec(int elemento, int *vetor, int fim, int inicio){
//    if(inicio <= fim){
//        int meio = incio + (fim - inicio) / 2;
//        if(vetor[meio] = elemento){
//            return 1;
//        } if(vetor[meio] > elemento){
//            return busca_bin_rec(*vetor,inicio, meio - 1, elemento);
//        }
//        return busca_bin_rec(*vetor, meio + 1, fim, elemento);
//    }
//    return 0;
//}
//}
//int libera_memoria(int *vetor,int tamanho){
//    free(vetor);
//}