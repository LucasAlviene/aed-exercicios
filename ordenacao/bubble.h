#ifndef _H_BUBBLE
#define _H_BUBBLE

void bubble(int *vetor,int n){
    int aux,i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

#endif