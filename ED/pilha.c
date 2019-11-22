#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int idade;
    char nome[100];
    struct nodo *anterior;
} Node;

typedef struct{
    struct nodo *topo;
} Pilha;
void add(Pilha *pilha);
void pop(Pilha *pilha);

int main(){
    int escolha;

    Pilha *pilha;

    pilha = (Pilha *)malloc(sizeof(Pilha));

    do{
        printf("0-Sair\n1-Push\n2-Pop\n>>> ");
        scanf("%d",&escolha);


        switch(escolha){
            case 1:
                add(pilha);
            break;
            case 2:
                pop(pilha);
            break;

        }

    }while(escolha != 0);

    free(pilha);

    return 0;
}

void add(Pilha *pilha){
    Node *novo;

    novo = (Node *)malloc(sizeof(Node));
    printf("Nome: ");
    scanf("%s",novo->nome);
    printf("Idade: ");
    scanf("%d",&novo->idade);
    novo->anterior = NULL;

    if(pilha != NULL){
        novo->anterior = pilha->topo;
    }
    pilha->topo = novo;
}
void pop(Pilha *pilha){
    Node *aux;

    aux = pilha->topo;
    if(aux != NULL){
        printf("Nome: %s\nIdade:%d\n",aux->nome,aux->idade);

        pilha->topo = aux->anterior;
    }

}