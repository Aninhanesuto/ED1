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

No *Intercala(No *Lista, No *Lista2){
    No *inicio = NULL;
    No *aux = NULL;
    if(Lista == NULL && Lista2 == NULL)return NULL;
    else if(Lista == NULL && Lista2 != NULL)return Lista2;
    else if(Lista != NULL && Lista2 == NULL)return Lista;
    if (Lista->valor <= Lista2->valor){
        inicio = Lista;
        aux = Lista;
        Lista = Lista->prox;
        
    }
    else{
        inicio = Lista2;
        aux = Lista2;
        Lista2 = Lista2->prox;
        
    }
    while(aux -> prox != NULL){
        if(Lista->valor <= Lista2->valor){
            aux->prox = Lista;
            Lista = Lista->prox;
        }
        else {
            aux->prox = Lista2;
            Lista2 = Lista2->prox;
        }
        aux = aux->prox;
    }
    if (Lista == NULL){
        aux->prox = Lista2;
    }
    else{
        aux->prox = Lista;
    }
    return inicio;
    
    
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
    L = InsereInicio(L, 5);
    L = InsereInicio(L, 3);
    L = InsereInicio(L, 2);
    L2 = InsereInicio(L2, 5);
    L2 = InsereInicio(L2, 2);
    L2 = InsereInicio(L2, 1);
    Imprime(L);
    Imprime(L2);
    L = Intercala(L, L2);
    Imprime(L);
}