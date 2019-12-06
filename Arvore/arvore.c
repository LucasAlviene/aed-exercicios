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

int add(Nodo **arvore, Nodo *novo);
void imprimir(Nodo **arvore,int b);
void Antecessor(Nodo *arvore,Nodo **arvoreD);
void retirar(Nodo **arvore,Nodo *p);
int Altura(Nodo *arvore);
int FB(Nodo *arvore);
Nodo * pesquisar(Nodo **arvore, int chave);

int main(){
    Nodo **arvore,*pesquisa;
    int n,list[100],i=0,op;
    
    arvore = NULL;
    do{
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
                imprimir(&arvore,5);
            break;
            case 3:
                printf("Digite o numero:");
                scanf("%d",&n);
                pesquisa = pesquisar(&arvore,n);
                retirar(&arvore,pesquisa);
                imprimir(&arvore,5);
            break;
            case 4:
                printf("Altura: %d",FB(arvore));
            break;
        }
    }while(op != 0);
    return 0;
}

void RSE(Nodo **arvore){
    Nodo *aux;

    aux = (*arvore)->direita;
    (*arvore)->direita = (*arvore)->esquerda;
    (*arvore)->esquerda = *arvore
    *arvore = aux;
}

void RSD(Nodo **arvore){
    Nodo *aux;

    aux = (*arvore)->esquerda;
    (*arvore)->esquerda = (*arvore)->direita;
    (*arvore)->direita = *arvore
    *arvore = aux;
}

int BE(Nodo **arvore){
    int fb = FB((*arvore)->direita);

    if(fb > 0){
        RSE(arvore);
        return 1;
    }
    if(fb < 0){
        RSD((*arvore)->direita);
        RSE(arvore);
        return 1;
    }
    return 0;
}

int BD(Nodo **arvore){
    int fb = FB((*arvore)->esquerda);

    if(fb < 0){
        RSD(arvore);
        return 1;
    }
    if(fb > 0){
        RSE((*arvore)->esquerda);
        RSD(arvore);
        return 1;
    }
    return 0;
}

int Balanceamento(Nodo *arvore){
    int fb = FB(arvore);

    if(fb > 1){
        return BE(arvore);
    }
    if(fb < -1){
        return BD(arvore);
    }
}

int FB(Nodo *arvore){
    if(arvore == NULL) return 0;

    return Altura(arvore->esquerda)-Altura(arvore->direita);
}

int Altura(Nodo *arvore){
    int iEsq=0,iDir=0;
    if(arvore == NULL) return 0;    

    iEsq = Altura(arvore->esquerda);
    iDir = Altura(arvore->direita);

    if(iEsq > iDir){
        return iEsq+1;
    }
    return iDir+1;
}

void espaco(int n){
    int i;
    for(i=0;i<n;i++){
        printf(" ");
    }
}

void imprimir(Nodo **arvore,int b){
    int i;
    if(*arvore == NULL){
        for(i=0;i<b;i++){
            printf("    ");
        }
        printf("*\n");
        return;
    }
    
    imprimir(&(*arvore)->esquerda,b+1);
    for(i=0;i<b;i++){
        printf("    ");
    }
    printf("%d\n",(*arvore)->chave);
    imprimir(&(*arvore)->direita,b+1);
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
int add(Nodo **arvore, Nodo *novo){
    if(*arvore == NULL){
        *arvore = novo;
        return 1;
    }

    if((*arvore)->chave < novo->chave){
        if(add(&(*arvore)->direita,novo)){
            if(Balanceamento(arvore)) return 1;
        }
        return 0;
    }
    if((*arvore)->chave > novo->chave){
        if(add(&(*arvore)->esquerda,novo)){
            if(Balanceamento(arvore)) return 1;
        }
    }
    return 0;
}