#ifndef HEAPSORTFORDOUBLYLINKEDLIST_H
#define HEAPSORTFORDOUBLYLINKEDLIST_H
#include "../../TADS/doublyLinkedlist.h"

typedef struct item
{
    int id;
}item;

void criaHeap(linkedlist *list, long long i, long long f);
void heapsort(linkedlist *list, long long n);

void criaHeap(linkedlist *list, long long i, long long f)
{
    item* aux = (item *) return_an_item(i, list);
    long long j = (i * 2) + 1;
    while (j <= f)
    {
        if (j < f) 
        {
            if (((item *)return_an_item(j, list))->id < ((item *)return_an_item(j+1, list))->id)
            {
                j++;
            }
        }
        if (aux->id < ((item *)return_an_item(j, list))->id)
        {
            swap_items(return_an_item(i,list),return_an_item(j, list), list);
            i = j;
            j = (2*i) + 1;
        }
        else {
            j = f+1;
        }
    }
    swap_items(return_an_item(i, list), aux,  list);
}

void heapsort(linkedlist *list, long long n)
{
    for (long long i = (n-1)/2; i > 0; i--)
    {
        criaHeap(list,i,n-1);
    }
    for (long long i = n-1; i >= 1; i--)
    {
        item *aux = (item *) return_an_item(i, list);
        swap_items(return_an_item(0, list), return_an_item(i, list), list);
        swap_items(return_an_item(i, list), aux, list);
        criaHeap(list, 0, i-1);
    }   
}
#endif