#pragma once
#ifndef _LIST_ADT_HPP_
#define _LIST_ADT_HPP_

#include <stdio.h>
#include <stdlib.h>

// type definition of item in the array

typedef int item;

// declaration of the whole structure

struct list_type
{
    item *container;
    int size;
    int count;
};

// typedef of the list_type struct:

typedef struct list_type *list;

// Function on list_type *list structure:

extern list createList(int size);
extern void destroyList(list l);

// Return current count of the list;
extern int count(list l);

// Return size of the list:
extern int size(list l);

// Add an item at the end of the list
extern void push_back(list l, item i);

// Get the item at position idx:
extern item at(list l, int idx);

// Resize a container inside a list
void resizeList(list l, int newSize);

// Clear list

void clear(list l);

#endif //_LIST_ADT_HPP_
