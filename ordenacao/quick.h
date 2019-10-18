#ifndef _H_QUICK
#define _H_QUICK

#include <stdio.h>

void quick(int *vetor,int left,int right){
    int mid,temp,i,j;

    i = left;
    j = right;

    mid = vetor[(left + right)/2];

    do{
        while(mid > vetor[i]) i++;
        while(mid < vetor[j]) j++;

        if(i <= j){
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }

    }while(i <= j);

    if(left < j) quick(vetor,left,j);
    if(right > i) quick(vetor,i,right);
}

#endif

// 3 5 9 4 6 2 1
