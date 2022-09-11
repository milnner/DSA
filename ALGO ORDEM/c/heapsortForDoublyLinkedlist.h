#ifndef HEAPSORTFORDOUBLYLINKEDLIST_H
#define HEAPSORTFORDOUBLYLINKEDLIST_H
#include "../../TADS/doublyLinkedlist.h"

typedef struct item
{
    int id;
}item;

void makeheapForDoublyLinkedlist(doublyLinkedlist *list, long long i, long long f);
void heapsortForDoublyLinkedlist(doublyLinkedlist *list, long long n);

void makeHeapForDoublyLinkedlist(doublyLinkedlist *list, long long i, long long f)
{
    item *aux = return_an_item_from_doublyLinkedlist(i,list);
    long long j = (i * 2) + 1;
    while (j <= f)
    {
        if (j < f) 
        {
            
            if (
                ((item *)return_an_item_from_doublyLinkedlist(j  ,list))->id    < 
                ((item *)return_an_item_from_doublyLinkedlist(j+1,list))->id)
            {
                j = j+1;
            }
        }
        if (aux->id < ((item *)return_an_item_from_doublyLinkedlist(j  ,list))->id)
        {
            ((doublyLinkedlist_node *)return_a_node_from_doublyLinkedlist(i,list))->item = return_an_item_from_doublyLinkedlist(j  ,list);
            i = j;
            j = i*2 + 1;
        }
        else {
            j = f+1;
        }
    }
    ((doublyLinkedlist_node *)return_a_node_from_doublyLinkedlist(i,list))->item = aux;
}

void heapsortForDoublyLinkedlist(doublyLinkedlist *list, long long n)
{
    for (long long i = (n-1)/2; i >= 0; i--)
    {
        makeHeapForDoublyLinkedlist( list, i, n-1);
    }
    for (long long i = n-1; i >= 1 ;i--)
    {
        swap_doublyLinkedlist_items(
            return_a_node_from_doublyLinkedlist(i,list),
            return_a_node_from_doublyLinkedlist(0,list),
            list
        );
        makeHeapForDoublyLinkedlist(list, 0,i-1);
    }   
}
#endif