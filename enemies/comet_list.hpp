#pragma once
#ifndef _COMMET_LIST_HPP_
#define _COMMET_LIST_HPP_

#include <stdio.h>
#include <stdlib.h>

// comet structure declaration:

struct comet
{
    int ID;
    int posx, posy;
    int lives;
    int speed;
    int boundx;
    int boundy;
};

// === type definitions of item in the array ===

// Allias for the original comet structure
typedef struct comet comet_str;

// Allias for the pointer to the comet structure
typedef struct comet *comet_item;

// =============================================

// ============= SETTERS/GETTERS ===============

extern comet_item createCometItem();

// Set comet ID
extern void setCometID(comet_item ci, int id);

// Get comet ID
extern int cometID(comet_item ci);

// Set comet position X
extern void setCometPosX(comet_item ci, int posx);

// Get comet position X
extern int cometPosX(comet_item ci);

// Set comet position Y
extern void setCometPosY(comet_item ci, int posy);

// Get comet position Y
extern int cometPosY(comet_item ci);

// Set comet live flag
extern void setCometLives(comet_item ci, int lives);

// Get comet live flag
extern int cometLives(comet_item ci);

// Set comet speed
extern void setCometSpeed(comet_item ci, int speed);

// Get comet speed
extern int cometSpeed(comet_item ci);

// Set comet boundary X
extern void setCometBoundX(comet_item ci, int boundx);

// Get comet boundary X
extern int cometBoundX(comet_item ci);

// Set comet boundary Y
extern void setCometBoundY(comet_item ci, int boundy);

// Get comet boundary Y
extern int cometBoundY(comet_item ci);

// ==========================================

// declaration of the whole structure

struct comet_list_type
{
    comet_item *container;
    int size;
    int count;
};

// ======= type definitions of list_type  ========

// Allias for the pointer to list_type structure
typedef struct comet_list_type *comet_list;

// ================================================

// =========== FUNCTIONS ON comet_list* ==========

extern comet_list createCometList(int size);
extern void destroyCometList(comet_list *l);

// Return current count of the list;
extern int countComets(comet_list *l);

// Return size of the list:
extern int sizeComets(comet_list *l);

// Add an item at the end of the list
extern void push_comet(comet_list *l, comet_item i);

// Get the item at position idx:
extern comet_item comet_at(comet_list *l, int idx);

// Resize a container inside a list
extern void resizeCometList(comet_list *l, int newSize);

// Clear list
extern void clearCometList(comet_list *l);

// ==============================================

#endif //_COMMET_LIST_HPP_
