#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int idade;
	char nome[100];
	struct N *anterior;
} Node;

typedef struct {
	Node *primeiro;
	Node *ultimo;
} Fila;


void add(Fila *fila);
void pop(Fila *fila);

int main(){

	int escolha;

	Fila *fila;

	fila = (Fila *)malloc(sizeof(Fila));
	do{

		printf("0-sair\n");
		printf("1-Add\n2-Printar\n:");
		scanf("%d",&escolha);
		switch(escolha){
			case 1:
				add(fila);
			break;
			case 2:
				pop(fila);
			break;
		}
	}while(escolha != 0);

}
void pop(Fila *fila){
	Node *aux;
	aux = fila->primeiro;
	if(aux != NULL){

		printf("Nome: %s\nIdade:%d\n",aux->nome,aux->idade);
	
		fila->primeiro = aux->anterior;
	}
	free(aux);

}

void add(Fila *fila){
	Node *novo,*aux;
	
	novo = (Node *)malloc(sizeof(Node));
	printf("Nome: ");
	scanf("%s",novo->nome);
	printf("Idade: ");
	scanf("%d",&novo->idade);
	novo->anterior = NULL;
	aux = fila->ultimo;

	fila->ultimo = novo;

	if(fila->primeiro == NULL){
		fila->primeiro = novo;
	}else{
		aux->anterior = novo;
	}
}