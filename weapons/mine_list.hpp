#pragma once
#ifndef _MINE_LIST_HPP_
#define _MINE_LIST_HPP_

#include <stdio.h>
#include <stdlib.h>

// mine structure definition

struct mine
{
    int ID;
    int posx, posy;
    bool live;
    int speed;
    int boundx;
    int boundy;
    // int explosionBoundx;
    // int explosionBoundy;
};

// === typoe definition of item in the array ===

// Allias for the original mine structure
typedef struct mine mine_str;

// Allias for th epointer to the mine structure
typedef mine_str *mine_item;

// =============================================

// ============= SETTERS/GETTERS ===============

// Create mine_item
extern mine_item createMineItem();

// Set mine ID
extern void setMineID(mine_item mi, int id);

// Get mine ID:
extern int mineID(mine_item mi);

// set mine position X:
extern void setMinePosX(mine_item mi, int posx);

// get mine position X:
extern int minePosX(mine_item mi);

// set mine position Y:
extern void setMinePosY(mine_item mi, int posy);

// get mine position Y:
extern int minePosY(mine_item mi);

// set mine live flag:
extern void setMineLive(mine_item mi, bool live);

// get mine live flag:
extern bool mineLive(mine_item mi);

// set mine speed:
extern void setMineSpeed(mine_item mi, int speed);

// get mine speed:
extern int mineSpeed(mine_item mi);

// set mine boundary X:
extern void setMineBoundX(mine_item mi, int boundx);

// get mine boundary X:
extern int mineBoundX(mine_item mi);

// set mine boundary Y:
extern void setMineBoundY(mine_item mi, int boundy);

// get mine boundary Y:
extern int mineBoundY(mine_item mi);

// ============================================

// declaration of the whole structure:

struct mine_list_type
{
    mine_item *container;
    int size;
    int count;
};

// ===== type definition of list_type ========

// Allias for the pointer to list_type structure:
typedef struct mine_list_type *mine_list;

// ==============================================

// =========== FUNCTIONS ON mine_list* ==========

extern mine_list createMineList(int size);

extern void destroyMineList(mine_list *l);

// Return current count of the list;
extern int countMines(mine_list *l);

// Return size of the list:
extern int sizeMines(mine_list *l);

// Add an item at the end of the list
extern void push_mine(mine_list *l, mine_item i);

// Get the item at position idx:
extern mine_item mine_at(mine_list *l, int idx);

// Resize a container inside a list
extern void resizeMineList(mine_list *l, int newSize);

// Clear list
extern void clearMineList(mine_list *l);

// ==============================================

#endif //_MINE_LIST_HPP_
