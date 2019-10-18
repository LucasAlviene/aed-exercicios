#include <stdio.h>
#include <stdlib.h>

#include "bubble.h"
#include "select.h"
#include "quick.h"
#include "merge.h"

void ler(int *vetor,int n);
void imprimir(int *vetor,int n);

int main(){
    int escolha,n,*vetor;

    do{
        printf("\n\n == MENU ==\n\n");
        printf("1- Bubble\n");
        printf("2- Select\n");
        printf("3- Quick\n");
        printf("4- Merge\n");
        printf("0- Sair\n\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if(escolha != 0){
            printf("Quantidade de Numeros: ");
            scanf("%d",&n);
            vetor = (int *)malloc(sizeof(int) * n);
            
            ler(vetor,n);
            switch(escolha){
                case 1:
                    bubble(vetor,n);
                break;
                case 2:
                    select(vetor,n);
                break;
                case 3:
                    quick(vetor,0,n);
                break;
                case 4:
                    vetor = merge(vetor,n);
                break;
            }
            imprimir(vetor,n);
        }
    }while(escolha != 0);
    free(vetor);
    return 0;
}


void ler(int *vetor,int n){
    int i;

    for(i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
}

void imprimir(int *vetor,int n){
    int i;
    printf("\n\n == Resultado == \n\n");
    for(i=0;i<n;i++){
        printf("%d - ",vetor[i]);
    }
    free(vetor);
}
