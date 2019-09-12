#include <stdio.h>
#include <stdlib.h>

void ler(int *lista);

int main(){

    int n, *lista,*i,*output;

    scanf("%d",&n);

    lista = (int *)malloc(sizeof(int) * (n+1));
    i = (lista + sizeof(int));
    *i = n;
    ler(lista);

    output = (lista + sizeof(int) * 2);
    printf("Resultado\n");
    for(n=0;n<*i;n++){
        printf("%d\n",*output);
        output += sizeof(int);
    }

    free(lista);
    return 0;
}


void ler(int *lista){
    int *i,n,*input;
    i = (lista + sizeof(int));
    input = (lista + sizeof(int) * 2);
    for(n=0;n<*i;n++){
        scanf("%d",input);
        input += sizeof(int);
    }
}