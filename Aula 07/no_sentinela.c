/*Implementar um nó sentinela no final da lista*/

#include <stdio.h>
#include<stdlib.h>

typedef struct  no{
    int valor;
    struct no *prox;
}No;


No *CriaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de Alocacao \n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

No *InsereInicio(No *L, int valor){
    No *novo = CriaNo(valor);
    novo->prox = L;
    L = novo;
    return L;

}

No *InsereFinal(No *L, int valor){
    No *novo = CriaNo(valor);
    No *aux = L;
    No *pred = NULL;
    if(aux->valor == -1){
        novo->prox = L;
        L = novo;
        return L;
    }
    else{
        while (aux->valor != -1){
        pred = aux;
        aux = aux->prox;
    }
    novo->prox = aux;
    pred->prox = novo;
    return L;
    }
    

}

void Imprime(No *L){
    No *aux = L;
    while (aux != NULL && aux->valor != -1){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    
}


int main(){
    No *sentinela = CriaNo(-1);
    No *L = sentinela;
    L = InsereInicio(L, 2);
    L = InsereInicio(L, 3);
    L = InsereFinal(L, 8);
    Imprime(L);

}