#ifndef _H_MERGE
#define _H_MERGE

#include <stdio.h>
#include <stdlib.h>

int total = 0;
int *mergeSort(int * esquerda,int *direita,int meioA,int meio);

int * merge(int *vetor,int n){
    int meio,meioA,*esquerda,*direita,i,a;
    if(n <= 1) return vetor;
    
    meioA = meio = n/2;
    esquerda = (int *)malloc(sizeof(int) * meio);
    direita = (int *)malloc(sizeof(int) * meio);
        
    if(n%2 == 1) meioA++;

    for(a=0,i=0;i<meioA;i++,a++){
        esquerda[i] = vetor[a];
    }
    for(a=0,i=meioA;i<n;i++,a++){
        direita[a] = vetor[i];
    }
    esquerda =  merge(esquerda,meioA);
    direita = merge(direita,meio);
    return mergeSort(esquerda,direita,meioA,meio);
}

int *mergeSort(int * esquerda,int *direita,int meioA,int meio){

    int i=0,j=0,*aux,a=0;

    aux = (int *)malloc(sizeof(int) * (meioA + meio));
    while(meioA > 0 || meio > 0){
        if(meioA > 0 && meio > 0){
            if(esquerda[i] < direita[j]){
                aux[a] = esquerda[i];
                i++;
                meioA--;
            }else{
                aux[a] = direita[j];
                j++;
                meio--;
            }
        }else if(meioA > 0){
            aux[a] = esquerda[i];
            i++;
            meioA--;
        }else if(meio > 0){
            aux[a] = direita[j];
            j++;
            meio--;
        }
        a++;
    }
    free(esquerda);
    free(direita);
    return aux;
}

#endif