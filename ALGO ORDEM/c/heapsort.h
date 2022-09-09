/*  Author: Milnner Kauan Torres Andrade
 *  
 */
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <stdio.h>
long long criaHeap(int vet[], long long i, long long f);
void heapsort(int vet[], long long n);

long long criaHeap(int vet[], long long i, long long f)
{
    int aux = vet[i];
    long long j = (i * 2) + 1;
    while (j <= f)
    {
        if (j < f) 
        {
            if (vet[j] < vet[j+1])
            {
                j++;
            }
        }
        if (aux < vet[j])
        {
            vet[i] = vet[j];
            i = j;
            j = (2*i) + 1;
        }
        else {
            j = f+1;
        }
    }
    vet[i] = aux;
}

void heapsort(int vet[], long long n)
{
    for (long long i = (n-1)/2; i > 0; i--)
    {
        criaHeap(vet,i,n-1);
    }
    for (long long i = n-1; i >= 1; i--)
    {
        int aux = vet[i];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i-1);
    }   
}
#endif