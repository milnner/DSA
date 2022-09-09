/*  Author: Milnner Kauan Torres Andrade
 *  
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>
#include <string.h>

// ainda precisa implementar um pop_pos

typedef struct item {
    int id;
}item;

typedef struct linkedlist_node
{
    struct item it;
    struct linkedlist_node *nex;
    struct linkedlist_node *pre;
}linkedlist_node;

typedef struct linkedlist{
    size_t size;
    struct linkedlist_node *begin;
    struct linkedlist_node *end;
}linkedlist;

void copy_item(item in, item *out);
void make_list(linkedlist *list);
void to_end_list(item it, linkedlist *list);
void to_begin_list(item it, linkedlist *list);
item pop_back(linkedlist *list);
item pop_front(linkedlist *list);
void free_list(linkedlist *list);
void move_item(size_t pos1, size_t pos2, linkedlist *list); // pos1 and pos2 will swap, the first index is 0 and the last is n-1, for n being the length
void swap_linkedlist_nodes(linkedlist_node *node1, linkedlist_node *node2, linkedlist *list);

void copy_item(item in, item *out) {
    out->id = in.id;
}   

void make_list(linkedlist *list) {
    list->size = 0;
    list->begin = (linkedlist_node *) malloc (sizeof(linkedlist_node));
    list->begin->nex = NULL;
    list->begin->pre = NULL;
    list->end = list->begin;
}

void to_end_list(item it, linkedlist *list) {
    if (list->size == 0) {
        copy_item(it, &(list->begin->it));
        list->size++;
        return;
    }
    list->end->nex = (linkedlist_node *) malloc (sizeof(linkedlist_node));
    list->end->nex->pre = list->end;
    list->end = list->end->nex;
    list->end->nex = NULL;
    copy_item(it, &(list->end->it));
    list->size++;
}

void to_begin_list(item it, linkedlist *list) {
    if (list->size == 0) {
        copy_item(it, &(list->begin->it));
        list->size++;
        return;
    }
    list->begin->pre = (linkedlist_node *) malloc (sizeof(linkedlist_node));
    list->begin->pre->nex = list->begin;
    list->begin = list->begin->pre;
    list->begin->pre = NULL;
    copy_item(it, &(list->begin->it));
    list->size++;
}

item pop_back(linkedlist *list) {
    item it;
    linkedlist_node* node;
    it = list->end->it;
    node = list->end;
    if (list->size == 1)
    {
        free(list->begin);

        list->begin = NULL;
        list->end = NULL;
        list->size--;
        return it;
    }
    list->end = list->end->pre;
    list->end->nex = NULL;
    free(node);
    list->size--;
    return it;
}

item pop_front(linkedlist *list) {
    item it;
    linkedlist_node* node;
    it = list->begin->it;
    node = list->begin;
    if (list->size == 1) {
        free(list->begin);
        list->begin = NULL;
        list->end = NULL;
        list->size--;
        return it;
    }
    list->begin = list->begin->nex;
    list->begin->pre = NULL;
    free(node);
    list->size--;
    return it;
}

void free_list(linkedlist *list) {
    while (list->end != NULL)
    {
        pop_back(list);
    }
}

void move_item(size_t pos1, size_t pos2, linkedlist *list) {
    linkedlist_node *node1, *node2;
    if (pos1 >= list->size || pos2 >= list->size) {
        return;
    }
    if (pos1<=(list->size)/2 )
    {
        node1 = list->begin;
        for (size_t i = 0; i < pos1; i++)
        {
            node1 = node1->nex;
        }
    } else {
        node1 = list->end;
        for (size_t i = list->size-1; i > pos2; i--)
        {
            node1 = node1->pre;
        }
    }
    if (pos2<=(list->size)/2)
    {
        node2 = list->begin;
        for (size_t i = 0; i < pos2; i++)
        {
            node2 = node2->nex;
        }
    } else {
        node2 = list->end;
        for (size_t i = list->size-1; i > pos2; i--)
        {
            node2 = node2->pre;
        }
    }
    
    swap_linkedlist_nodes(node1,node2, list);
}

void swap_linkedlist_nodes(linkedlist_node *node1, linkedlist_node *node2, linkedlist *list) {
    if (node1 == node2) {
        return;
    }
    if ((list->begin == node1 || list->end == node1) && (list->begin == node2 || list->end == node2))
    {
        if (list->begin == node1)
        {
            linkedlist_node *tmp = node1;
            list->begin = node2;
            list->end = tmp;
        } else {
            linkedlist_node *tmp = node2;
            list->begin = node1;
            list->end = tmp;
        }
    }
    else if ((list->begin == node1 && list->end != node2) || (list->begin == node2 && list->end != node1))
    {
        if ((list->begin == node1 && list->end != node2))
        {
            list->begin = node2;
        } else {
            list->begin = node1;
        }     
    }
    else if ((list->begin != node1 && list->end == node2) || (list->begin != node2 && list->end == node1))
    {
        if (list->begin != node1 && list->end == node2) {
            list->end = node1;
        } else {
            list->end = node2;
        }
    }
    
    linkedlist_node *pre1 = node1->pre;
    linkedlist_node *pre2 = node2->pre;
    linkedlist_node *nex1 = node1->nex;
    linkedlist_node *nex2 = node2->nex;
    
    if (pre1 != NULL) {
        pre1->nex = node2;
        node2->pre = pre1;
    } else {
        node2->pre = NULL;
    }
    if (nex1 != NULL) {
        nex1->pre = node2;
        node2->nex = nex1;
    } else {
        node2->nex = NULL;
    }
    if (pre2 != NULL) {
        pre2->nex = node1;
        node1->pre = pre2;
    } else {
        node1->pre = NULL;
    }
    if (nex2 != NULL) {
        nex2->pre = node1;
        node1->nex = nex2;
    } else {
        node1->nex = NULL;
    }
}
#endif