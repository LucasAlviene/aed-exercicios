#ifndef _H_SELECT
#define _H_SELECT

void select(int *vetor,int n){
    int aux,min,i,j,pos;
    for(i=0;i<n-1;i++){
        pos = i;
        min = vetor[i];
        for(j=i+1;j<n;j++){
            if(min > vetor[j]){
                min = vetor[j];
                pos = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[pos];
        vetor[pos] = aux;
    }
}

#endif