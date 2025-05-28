#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *prox;
}No;


No *CriaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de Alocacao");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

No *InsereInicio(No *Lista, int valor){
    No *novo = CriaNo(valor);
    novo->prox = Lista;
    Lista = novo;
    return Lista;
}

No *InsereFinal(No *Lista, int valor){
    No *aux = Lista;
    No *novo = CriaNo(valor);
    if (Lista != NULL){
        while(aux->prox != NULL){
        aux = aux->prox;
    }
        aux->prox = novo;
    }
    else{
        Lista = novo;
    }
    return Lista;
}

void ImprimeLista(No *Lista){
    No *aux = Lista;
    while (aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void ImprimeRecursivo(No *Lista){
    if (Lista != NULL){
        printf("%d ", Lista->valor);
        ImprimeLista(Lista->prox);
    } 
}


int ocorrencia(No *Lista, int valor){
    No *aux = Lista;
    int conta = 0;
    while (aux != NULL && aux->valor != valor){
        conta++;
        aux = aux->prox;
    }
    return conta;
}

No *InverteNos(No *Lista){
    No *aux = Lista;
    No *pred = NULL;
    No *front;
    while(aux != NULL){
        front = aux->prox;
        aux->prox = pred;
        pred = aux;
        aux = front;
    }
    return pred;
}

   
   

int main(){
    No *Lista = NULL;
    No *Lista2 = NULL;
    int conta = 0;
    Lista = InsereInicio(Lista, 3);
    //ImprimeLista(Lista);
    Lista2 = InsereFinal(Lista2, 3);
    Lista2 = InsereFinal(Lista2, 4);
    Lista2 = InsereFinal(Lista2, 5);
    Lista2 = InsereFinal(Lista2, 6);
    Lista2 = InsereFinal(Lista2, 7);
    Lista2 = InsereFinal(Lista2, 8);
    ImprimeLista(Lista2);
    //ImprimeRecursivo(Lista);
    Lista2 = InverteNos(Lista2);
    ImprimeLista(Lista2);
    //conta = ocorrencia(Lista2, 4);
    //printf("%d \n", conta);
}