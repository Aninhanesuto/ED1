#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

No *CriaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
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
    return novo;
}


No *concatena(No *L, No *L2){
    
    if(L == NULL && L2 == NULL)return NULL;
    else if(L == NULL && L2 != NULL)return L2;
    else if(L != NULL && L2 == NULL)return L;
    No *aux = L;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = L2;
    return L;
}

void Imprime(No *L){
    No *aux = L;
    while (aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    
}

int main(){
    No *L = NULL;
    No *L2 = NULL;
    L = InsereInicio(L, 3);
    L = InsereInicio(L, 2);
    L = InsereInicio(L, 1);
    L2 = InsereInicio(L2, 6);
    L2 = InsereInicio(L2, 5);
    L2 = InsereInicio(L2, 4);
    Imprime(L);
    Imprime(L2);
    L = concatena(L2, L);
    Imprime(L);
}