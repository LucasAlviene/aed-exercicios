#include <stdio.h>
#include <stdlib.h>
 
void *add(int n);
void imprimir(int *vetor,int n);
void ler(int *lista,int n);
void liberar(int *vetor);
int main(){

    int *vetor,n;
    scanf("%d",&n);
    vetor = add(n);

    imprimir(vetor,n);

    liberar(vetor);
    return 0;
}
void liberar(int *vetor){
    free(vetor);
}

void ler(int *lista, int n){
    int i,*input;
    input = (lista + sizeof(int));

    for(i=0;i<n;i++){
        scanf("%d",input);
        input += sizeof(int);
    }
}
void *add(int n){
    int *vetor;
    vetor = (int *)malloc(sizeof(int) * n);
    ler(vetor,n);
    return vetor;
}
void imprimir(int *vetor,int n){
    int *output,i;

    output = (int *)(vetor + sizeof(int));
    printf("Resultado\n");
    for(i=0;i<n;i++){
        printf("%d\n",*output);
        output += sizeof(int);
    }

}