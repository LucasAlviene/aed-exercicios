#include <stdio.h>
#include <stdlib.h>
 
void *add(int n);
void imprimir(int *vetor,int n);
void ler(int *vetor,int n);
void liberar(int *vetor);
int main(){

    int *vetor,n;
    scanf("%d",&n);
    vetor = add(n);

    ler(vetor,n);

    imprimir(vetor,n);

    liberar(vetor);
    return 0;
}
void liberar(int *vetor){
    free(vetor);
}

void ler(int *vetor, int n){
    int i,*input;
    for(i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
}
void *add(int n){
    int *vetor;
    vetor = (int *)malloc(sizeof(int) * n);
    return vetor;
}
void imprimir(int *vetor,int n){
    int *output,i;

    printf("Resultado\n");
    for(i=0;i<n;i++){
        printf("%d\n",vetor[i]);
    }

}