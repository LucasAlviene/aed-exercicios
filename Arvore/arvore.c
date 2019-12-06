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
void imprimir(Nodo *arvore,int *n);
void Antecessor(Nodo *arvore,Nodo **arvoreD);
void retirar(Nodo **arvore,Nodo *p);
Nodo * pesquisar(Nodo **arvore, int chave);

int main(){
    Nodo **arvore,*pesquisa;
    int n,list[100],i=0,op,*nespaco;
    nespaco = (int *)malloc(sizeof(int));
    
    arvore = NULL;
    do{
        *nespaco = 10;
        printf("\n1-Adicionar\n2-Imprimir\n3-Remover\n0-Sair\n--> ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Digite a quantidade:");
                scanf("%d",&n);

                for(i=0;i<n;i++){
                    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
                    printf("Digite um número:");
                    scanf("%d",&novo->chave);
                    novo->esquerda = novo->direita = NULL;
                    add(&arvore,novo);
                }
            break;
            case 2:
                imprimir(arvore,nespaco);
            break;
            case 3:
                printf("Digite o numero:");
                scanf("%d",&n);
                pesquisa = pesquisar(&arvore,n);
                retirar(&arvore,pesquisa);
                imprimir(arvore,nespaco);
            break;
        }
    }while(op != 0);
    return 0;
}

void espaco(int n){
    int i;
    for(i=0;i<n;i++){
        printf(" ");
    }
}

void imprimir(Nodo *arvore,int *n){
    /*if(arvore != NULL){
        espaco(*n);
        printf("%d\n",arvore->chave);
        (*n)--;
        imprimir(arvore->esquerda,n);
        imprimir(arvore->direita,n);
    }*/
    mostrarArvore(&arvore,10);
}

void mostrarArvore(Nodo **arvore,int b){
    int i;
    if(*arvore == NULL){
        for(i=0;i<b;i++){
            printf("    ");
        }
        printf("*\n");
        return;
    }
    
    mostrarArvore(&(*arvore)->esquerda,b+1);
    for(i=0;i<b;i++){
        printf("    ");
    }
    printf("%d\n",(*arvore)->chave);
    mostrarArvore(&(*arvore)->direita,b+1);
}

void retirar(Nodo **arvore,Nodo *p){
    Nodo *aux;
    if(*arvore == NULL){
        printf("Registro não encontrado\n");
        return;
    }
    if((*arvore)->chave < p->chave){
        retirar(&(*arvore)->direita,p);
        return;
    }
    if((*arvore)->chave > p->chave){
        retirar(&(*arvore)->esquerda,p);
        return;
    }

    if((*arvore)->direita == NULL){
        aux = *arvore;
        *arvore = (*arvore)->esquerda;
        free(aux);
        return;
    }

    if((*arvore)->esquerda != NULL){
        Antecessor(*arvore,&(*arvore)->esquerda);
    }

    aux = *arvore;
    *arvore = (*arvore)->direita;
    free(aux);
}

void Antecessor(Nodo *arvore,Nodo **arvoreD){
    Nodo *aux;
    if((*arvoreD)->direita != NULL){
        Antecessor(arvore,&(*arvoreD)->direita);
        return;
    }

    arvore->chave = (*arvoreD)->chave;
    aux = *arvoreD;
    *arvoreD = (*arvoreD)->esquerda;
    free(aux);
}
Nodo * pesquisar(Nodo **arvore, int chave){
    if(*arvore == NULL){
        printf("Nao esta na arvore\n");
        return;
    }
    if((*arvore)->chave < chave){
        pesquisar(&(*arvore)->direita,chave);
        return;
    }
    if((*arvore)->chave > chave){
        pesquisar(&(*arvore)->esquerda,chave);
    }else{
        return *arvore;
    }
}
void add(Nodo **arvore, Nodo *novo){
    if(*arvore == NULL){
        *arvore = novo;
        return;
    }

    if((*arvore)->chave < novo->chave){
        add(&(*arvore)->direita,novo);
        return;
    }
    if((*arvore)->chave > novo->chave){
        add(&(*arvore)->esquerda,novo);
    }
}