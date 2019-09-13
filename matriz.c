#include <stdio.h>
#include <stdlib.h>
int **alocar(int m,int n);
void liberar(int **matriz);
void ler(int **matriz, int m,int n);
void imprimir(int **matriz, int m,int n);

int main(){

    int **matriz,m,n;

    scanf("%d%d",&m,&n);

    matriz = alocar(m,n); 
    ler(matriz,m,n);
    imprimir(matriz,m,n);
    liberar(matriz);
    return 0;
}

void ler(int **matriz, int m,int n){
    int i,c,l;
    for(l=0;l<n;l++){
        for(c=0;c<n;c++){
            scanf("%d",&matriz[l][c]);
        }
    }
}
void imprimir(int **matriz, int m,int n){
    int i,c,l;
    printf("Resultado\n");
    for(l=0;l<n;l++){
        for(c=0;c<n;c++){
            printf("%d ",matriz[l][c]);
        }
        printf("\n");
    }
}

void liberar(int **matriz){
    free(matriz);
}

int **alocar(int m,int n){
    int **matriz,l,c;

    matriz = (int **)malloc(sizeof(int *) * m);

    for(l=0;l<m;l++){
        matriz[l] = (int *)malloc(sizeof(int) * n);
        for(c=0;c<n;c++){
            matriz[l][c] = 0;
        }
    }
    return matriz;
}