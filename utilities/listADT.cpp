#include "listADT.hpp"

list createList(int size)
{
    list ls = (list)malloc(sizeof(struct list_type));
    if (!ls)
    {
        printf("Error list_type: An error occured while allocating memory block for list_type sstructure.\n");
        exit(EXIT_FAILURE);
    }
    ls->container = (item *)malloc(size * sizeof(item));
    if (!(ls->container))
    {
        free(ls);
        printf("Error list_type: An error occured while allocating memory block for container in list_type.\n");
        exit(EXIT_FAILURE);
    }
    ls->count = 0;
    ls->size = size;
    return ls;
}

void destroyList(list l)
{
    free(l->container);
    free(l);
}

int count(list l)
{
    return l->count;
}

int size(list l)
{
    return l->size;
}

void resizeList(list l, int newSize)
{
    l->container = (item *)realloc(l->container, newSize * sizeof(item));
    if (!(l->container))
    {
        printf("Error item: An error occured while allocating new memory block for container in list_type.\n");
        free(l);
        exit(EXIT_FAILURE);
    }
    l->size = newSize;
}

void push_back(list l, item i)
{
    if (l->count >= l->size)
    {
        resizeList(l, (l->count) * 2);
    }
    l->container[l->count++] = i;
}

item at(list l, int idx)
{
    if (idx < (l->count))
    {
        return l->container[idx];
    }
    printf("Error index: Given index idx is out of boundaries.\n");
    exit(EXIT_FAILURE);
}

void clear(list l)
{
    l->count = 0;
}
