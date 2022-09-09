/*  Author: Milnner Kauan Torres Andrade
 *  
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DoublyLinkedlist
{
    void *item;
    struct DoublyLinkedlist *nex;
    struct DoublyLinkedlist *pre;
}DoublyLinkedlist;

typedef struct linkedlist{
    size_t size;
    struct DoublyLinkedlist *begin;
    struct DoublyLinkedlist *end;
}linkedlist;

void make_list(linkedlist *list);
void to_end_list(void *it, linkedlist *list);
void to_begin_list(void *it, linkedlist *list);
void* pop_back(linkedlist *list);
void* pop_front(linkedlist *list);
void* pop_pos(size_t pos, linkedlist *list);
void* return_an_item(size_t pos, linkedlist *list);
void* return_a_node(size_t pos, linkedlist *list);
void free_list(linkedlist *list);
void move_item(size_t pos1, size_t pos2, linkedlist *list); // pos1 and pos2 will swap, the first index is 0 and the last is n-1, for n being the length
void swap_DoublyLinkedlists(DoublyLinkedlist *node1, DoublyLinkedlist *node2, linkedlist *list);
void swap_items(DoublyLinkedlist *node1, DoublyLinkedlist *node2, linkedlist *list);

void make_list(linkedlist *list) {
    list->size = 0;
    list->begin = (DoublyLinkedlist *) malloc (sizeof(DoublyLinkedlist));
    list->begin->nex = NULL;
    list->begin->pre = NULL;
    list->end = list->begin;
}

void to_end_list(void *it, linkedlist *list) {
    if (list->size == 0) {
        list->begin->item = it;
        list->size++;
        return;
    }
    list->end->nex = (DoublyLinkedlist *) malloc (sizeof(DoublyLinkedlist));
    list->end->nex->pre = list->end;
    list->end = list->end->nex;
    list->end->nex = NULL;
    list->end->item = it;
    list->size++;
}

void to_begin_list(void* it, linkedlist *list) {
    if (list->size == 0) {
        list->begin->item = it;
        list->size++;
        return;
    }
    list->begin->pre = (DoublyLinkedlist *) malloc (sizeof(DoublyLinkedlist));
    list->begin->pre->nex = list->begin;
    list->begin = list->begin->pre;
    list->begin->pre = NULL;
    list->begin->item = it;
    list->size++;
}

void* pop_back(linkedlist *list) {
    void* it;
    it = list->end->item;
    DoublyLinkedlist *node = list->end;
    if (list->size == 1) {
        free(node);
        make_list(list);
        return it;
    } else if (list->size == 0) return NULL;

    list->end = list->end->pre;
    list->end->nex = NULL;
    list->size--;
    free(node);
    return it;
}

void* pop_front(linkedlist *list) {
    void* it;
    it = list->begin->item;
    DoublyLinkedlist *node = list->begin;
    if (list->size == 1) {
        free(node);
        make_list(list);
        return it;
    } if (list->size == 0) return NULL;

    list->begin = list->begin->nex;
    list->begin->pre = NULL;
    list->size--;
    free(node);
    return it;
}

void* pop_pos(size_t pos, linkedlist *list) {
    DoublyLinkedlist *node;
    if (pos<=(list->size)/2)
    {
        node = list->begin;
        for (size_t i = 0; i < pos; i++)
        {
            node = node->nex;
        }
    } else if (pos>(list->size)/2) {
        node = list->end;
        for (size_t i = list->size-1; i > pos; i--)
        {
            node = node->pre;
        }
    } else if (list->size == 0) {
        return NULL;
    } else {
        free_list(list);
        printf("POSITON OUT OF RANGE\n");
        exit(EXIT_FAILURE);
    }
    
    void* it = node->item;
    DoublyLinkedlist *pre = node->pre;
    DoublyLinkedlist *nex = node->nex;
    free(node);
    list->size--;

    if (pre == NULL && nex != NULL)
    {
        list->begin = nex;
        nex->pre = NULL;
        return it;
    }
    if (pre != NULL && nex == NULL)
    {
        list->end = pre;
        pre->nex = NULL;
        return it;
    }
    if (pre == NULL && nex == NULL)
    {
        make_list(list);
        return it;
    }
    
    pre->nex = nex;
    nex->pre = pre;
    return it;
}

void* return_an_item(size_t pos, linkedlist *list) {
    DoublyLinkedlist *node;
    if (pos<=(list->size)/2)
    {
        node = list->begin;
        for (size_t i = 0; i < pos; i++)
        {
            node = node->nex;
        }
    } else if (pos>(list->size)/2) {
        node = list->end;
        for (size_t i = list->size-1; i > pos; i--)
        {
            node = node->pre;
        }
    } else if (list->size == 0) {
        return NULL;
    } else {
        free_list(list);
        printf("POSITON OUT OF RANGE\n");
        exit(EXIT_FAILURE);
    }
    return node->item;
}

void* return_a_node(size_t pos, linkedlist *list) {
    DoublyLinkedlist *node;
    if (pos<=(list->size)/2)
    {
        node = list->begin;
        for (size_t i = 0; i < pos; i++)
        {
            node = node->nex;
        }
    } else if (pos>(list->size)/2) {
        node = list->end;
        for (size_t i = list->size-1; i > pos; i--)
        {
            node = node->pre;
        }
    } else if (list->size == 0) {
        return NULL;
    } else {
        free_list(list);
        printf("POSITON OUT OF RANGE\n");
        exit(EXIT_FAILURE);
    }
    return node;
}

void free_list(linkedlist *list) {
    while (list->size > 0)
    {
        void* it = list->end->item;
        DoublyLinkedlist *node = list->end;
        list->end = list->end->pre;
        if (list->end != NULL) {
            list->end->nex = NULL;
        }
        free(node);
        free(it);
        list->size--;
    }
    make_list(list);
}

void move_item(size_t pos1, size_t pos2, linkedlist *list) {
    DoublyLinkedlist *node1, *node2;
    if (pos1 >= list->size || pos2 >= list->size) {
        return;
    }
    if (pos1<=(list->size)/2)
    {
        node1 = list->begin;
        for (size_t i = 0; i < pos1; i++)
        {
            node1 = node1->nex;
        }
    } else if (pos1>(list->size)/2) {
        node1 = list->end;
        for (size_t i = list->size-1; i > pos2; i--)
        {
            node1 = node1->pre;
        }
    } else {
        free_list(list);
        printf("POSITON OUT OF RANGE\n");
        exit(EXIT_FAILURE);
    }
    if (pos2<=(list->size)/2)
    {
        node2 = list->begin;
        for (size_t i = 0; i < pos2; i++)
        {
            node2 = node2->nex;
        }
    } else if (pos2>(list->size)/2) {
        node2 = list->end;
        for (size_t i = list->size-1; i > pos2; i--)
        {
            node2 = node2->pre;
        }
    } else {
        free_list(list);
        printf("POSITON OUT OF RANGE\n");
        exit(EXIT_FAILURE);
    }
    swap_DoublyLinkedlists(node1,node2, list);
}

void swap_DoublyLinkedlists( DoublyLinkedlist *node1, 
                            DoublyLinkedlist *node2,
                            linkedlist *list) {
    if (node1 == node2) {
        return;
    }

    if (    (list->begin == node1 || list->end == node1) && 
            (list->begin == node2 || list->end == node2))
    {
        if (list->begin == node1)
        {
            DoublyLinkedlist *tmp = node1;
            list->begin = node2;
            list->end = tmp;
        } else {
            DoublyLinkedlist *tmp = node2;
            list->begin = node1;
            list->end = tmp;
        }
    }
    else if (   (list->begin == node1 && list->end != node2) || 
                (list->begin == node2 && list->end != node1))
    {
        if ((list->begin == node1 && list->end != node2))
        {
            list->begin = node2;
        } else {
            list->begin = node1;
        }     
    }
    else if (   (list->begin != node1 && list->end == node2) || 
                (list->begin != node2 && list->end == node1))
    {
        if (list->begin != node1 && list->end == node2) 
        {
            list->end = node1;
        } else {
            list->end = node2;
        }
    }
    
    DoublyLinkedlist *pre1 = node1->pre;
    DoublyLinkedlist *pre2 = node2->pre;
    DoublyLinkedlist *nex1 = node1->nex;
    DoublyLinkedlist *nex2 = node2->nex;
    
    if (pre1 != NULL) 
    {
        pre1->nex = node2;
        node2->pre = pre1;
    } else {
        node2->pre = NULL;
    }
    if (nex1 != NULL) 
    {
        nex1->pre = node2;
        node2->nex = nex1;
    } else {
        node2->nex = NULL;
    }
    if (pre2 != NULL) 
    {
        pre2->nex = node1;
        node1->pre = pre2;
    } else {
        node1->pre = NULL;
    }
    if (nex2 != NULL) 
    {
        nex2->pre = node1;
        node1->nex = nex2;
    } else {
        node1->nex = NULL;
    }
}

void swap_items( DoublyLinkedlist *node1, 
                 DoublyLinkedlist *node2, 
                 linkedlist *list) {
    if (node1 == node2) {
        return;
    }
    void *item = node1->item;
    node1->item = node2->item;
    node2->item = item;
}

#endif