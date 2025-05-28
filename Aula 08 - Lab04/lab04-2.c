#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
    char nucleotideo[4]; // armazena 3 letras + '\0'
    struct no *prox;
    struct no *pred;
}No;

No *CriaNo(char *nucleotideo){
    if ((strlen(nucleotideo) % 3) != 0){
        printf("Erro: tamanho de string não é multiplo de 3\n");
        return NULL;
    }

    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro de alocacao de memoria \n");
        exit(1);
    }
    
    strncpy(novo->nucleotideo, nucleotideo, 3);
    novo->nucleotideo[3] = '\0';
    
    novo->pred = NULL;
    novo->prox = NULL;
    return novo;
}

No *InsereFinal(No *L, char *nucleotideo){
    No *novo = CriaNo(nucleotideo);
    No *aux = L;    
    novo->prox = L;
    if (aux != NULL){
        aux->pred = novo;
    }
    L = novo;
    return L;
}

No *RNAComplementar(No *DNA){
    No *aux = DNA;
    while (aux != NULL){
        for (int i = 0; i < 3; i++){
            switch (aux->nucleotideo[i]){
            case 'G': aux->nucleotideo[i] = 'C';break;
            case 'C': aux->nucleotideo[i] = 'G';break;
            case 'T': aux->nucleotideo[i] = 'A';break;
            case 'A': aux->nucleotideo[i] = 'U';break;
            default: aux->nucleotideo[i] = '?'; break; //inválido
            }
        }
        aux = aux->prox;
    }
    return DNA;
}


void Imprime(No *L){
    No *aux = L;
    while (aux != NULL){
        for (int i = 0; i < 3; i++){
            printf("%c", aux->nucleotideo[i]);
        }
        aux = aux->prox; 
    }
    printf("\n");
    
}


int main(){
    No *L = NULL;
    char rna[] = "AUGGGAUAA";  
    L = InsereInicio(L, rna);
    Imprime(L);
    L = RNAComplementar(L);
    Imprime(L);


}