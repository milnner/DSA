/*  Author: Milnner Kauan Torres Andrade
 *  
 */
#ifndef QUICKSORT_H
#define QUICKSORT_H

long long particiona(int vet[], long long ini, long fim);
void quicksort(int vet[], long long ini, long long fim);

void quicksort(int vet[], long long ini, long long fim)
{
    if(fim > ini)
    {
        long long pivo_p = particiona(vet, ini, fim);
        quicksort(vet, ini, pivo_p-1);
        quicksort(vet, pivo_p+1, fim);
    }
}

long long particiona(int vet[], long long ini, long fim)
{
    int pivo = vet[ini];
    long long  esq = ini;
    long long dir = fim;
    while (esq < dir)
    {
        while (vet[esq] <= pivo)
        {
            esq++;
        }
        while (vet[dir] > pivo)
        {
            dir--;
        }
        if (esq < dir)
        {
            int temp = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = temp;
        }
    }
    vet[ini] = vet[dir];
    vet[dir] = pivo;
    return dir;
}
#endif