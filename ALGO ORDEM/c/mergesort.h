/*  Author: Milnner Kauan Torres Andrade
 *  
 */
#ifndef MERGESORT_H
#define  MERGESORT_H
#include <stdlib.h>
void mergesort(int vet[], long long ini, long long fim);
void merge(int vet[], long long ini, long long meio, long long fim);


void merge(int vet[], long long ini, long long meio, long long fim)
{
       long long tam = fim - ini + 1;
       int* temp = (int *) malloc(sizeof(int)*tam);
       long long p1 = ini;
       long long p2 = meio+1;
       long long fim1 = 0, fim2 = 0;
;       for (size_t i = 0; i <  tam; i++)
       {
            if (!fim1 && !fim2){
                if (vet[p1] < vet[p2])
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];

                if (p1 > meio) fim1 = 1;

                if (p2 > fim) fim2 = 1;                
            } else {
                if (!fim1)
                    temp[i] = vet[p1++];
                else 
                    temp[i] = vet[p2++];
            }
       }
       for (size_t i = 0, j = ini; i < tam; i++, j++)
       {
            vet[j] = temp[i];
       }
       free(temp);
}

void mergesort(int vet[], long long ini, long long fim)
{
    if (ini < fim)
    {
        size_t meio = (ini+fim)/2;
        mergesort(vet, ini, meio);
        mergesort(vet, meio+1, fim);
        merge(vet, ini, meio, fim);
    }
}
#endif