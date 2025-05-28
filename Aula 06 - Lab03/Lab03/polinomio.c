#include <stdio.h>
#include <stdlib.h>

typedef struct poli{
    float coeficiente;
    int expoente;
    struct poli *prox;
}Poli;

Poli *CriaNo(float coeficiente, int expoente){
    Poli *novo = (Poli*)malloc(sizeof(Poli));
    if (novo == NULL){
        printf("Erro de Alocacao");
        exit(1);
    }

    novo->coeficiente = coeficiente;
    novo->expoente = expoente;
    novo->prox = NULL;
    return novo;
}

Poli *InsereOrd(Poli *Lista, float coeficiente, int expoente){
    Poli *novo = CriaNo(coeficiente, expoente);
    Poli *aux = Lista, *pred = NULL;
    if (Lista == NULL){
        Lista = novo;
    }
    else{
        while (aux != NULL && expoente < aux->expoente){
            pred = aux;
            aux = aux->prox;
        }
        if (aux != NULL && aux->expoente == expoente) {
            aux->coeficiente += coeficiente;
            if (aux->coeficiente == 0){
                if(pred == NULL){
                    Lista = aux->prox;
                    free(aux);
                }
                else{
                    pred->prox = aux->prox;
                    free(aux);
                }
            }
            free(novo);
            return Lista;
        }
        else if(pred == NULL){
            novo->prox = aux;
            Lista = novo;
        }
        else{
            novo->prox = aux;
            pred->prox = novo;
        }
        
    }
    return Lista;
    
}

Poli *Soma(Poli *Lista, Poli *Lista2){
    Poli *aux = Lista;
    Poli *aux2 = Lista2;
    Poli *Lista3 = NULL;
    while (aux != NULL){
        Lista3 = InsereOrd(Lista3, aux->coeficiente, aux->expoente);
        aux = aux->prox;
    }
    while (aux2 != NULL){
        Lista3 = InsereOrd(Lista3, aux2->coeficiente, aux2->expoente);
        aux2 = aux2->prox;
    }
    return Lista3;
}


Poli *Subtracao(Poli *Lista, Poli *Lista2){
    Poli *aux = Lista;
    Poli *aux2 = Lista2;
    Poli *Lista3 = NULL;
    while (aux != NULL){
        Lista3 = InsereOrd(Lista3, aux->coeficiente, aux->expoente);
        aux = aux->prox;
    }
    while (aux2 != NULL){
        Lista3 = InsereOrd(Lista3, (-(aux2->coeficiente)), aux2->expoente);
        aux2 = aux2->prox;
    }
    return Lista3;
}

Poli *Multiplicacao(Poli *Lista, Poli *Lista2){
    Poli *Lista3 = NULL;
    Poli *aux = Lista;
    Poli *aux2 = Lista2;
    while (aux != NULL){
        aux2 = Lista2;
        while (aux2 != NULL){
            Lista3 = InsereOrd(Lista3, ((aux->coeficiente) * (aux2->coeficiente)), ((aux->expoente) + (aux2->expoente)));
            aux2 = aux2->prox;
    }
        aux = aux->prox;
    }
    
    return Lista3;
    

}

void Imprime(Poli *Lista){
    Poli *aux = Lista;
    while (aux !=  NULL){
        printf("%.2f", aux->coeficiente);
        printf("x^%d + ", aux->expoente);
        aux = aux->prox;
    }
    printf("\n");
    
}

int main(){
    Poli *Lista = NULL;
    Lista = InsereOrd(Lista, 5, 1);
    Lista = InsereOrd(Lista, 3, 2);
    Lista = InsereOrd(Lista, 2, 3);
    
    Poli *Lista2 = NULL;
    Lista2 = InsereOrd(Lista2, 3, 3);
    Lista2 = InsereOrd(Lista2, 4, 2);
    Lista2 = InsereOrd(Lista2, 6, 1);

    Poli *Lista3 = NULL;
    Lista3 = Multiplicacao(Lista, Lista2);
    //Lista3 = Subtracao(Lista2, Lista);

    //Imprime(Lista);
    //Imprime(Lista2);
    Imprime(Lista3);


}
