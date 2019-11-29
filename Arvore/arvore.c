#include <stdio.h>
#include <stdlib.h>

typedef struct {
   char nome[100];
   int idade;
} Dados;

typedef struct N{
    int chave;
    struct N *esquerda,*direita;
} Nodo;

void add(Nodo **arvore, Nodo *novo);
void imprimir(Nodo *arvore);

int main(){
    Nodo **arvore;
    int n,list[100],i=0;


    do{
        scanf("%d",&n);
        list[i++] = n;
    }while(n != 0);

    n = i;
    arvore = NULL;
    for(i=0;i<n;i++){
        Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
        novo->chave = list[i];
        novo->esquerda = novo->direita = NULL;
        add(&arvore,novo);
    }

    imprimir(arvore);
    return 0;
}

void imprimir(Nodo *arvore){
    if(arvore != NULL){
        printf("%d\n",arvore->chave);
        printf(" ");
        imprimir(arvore->esquerda);
        printf(" ");
        imprimir(arvore->direita);
    }
}

void add(Nodo **arvore, Nodo *novo){
    if(*arvore == NULL){
        *arvore = novo;
        return;
    }

    if((*arvore)->chave < novo->chave){
        add(&(*arvore)->direita,novo);
    }
    if((*arvore)->chave > novo->chave){
        add(&(*arvore)->esquerda,novo);
    }
}
