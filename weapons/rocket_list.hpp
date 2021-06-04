#pragma once
#ifndef _ROCKET_LIST_HPP_
#define _ROCKET_LIST_HPP_

#include <stdio.h>
#include <stdlib.h>

// rocket enumeration diraction
enum rocket_direction
{
    ROCKET_LEFT,
    ROCKET_DOWN,
    ROCKET_RIGHT,
    ROCKET_UP
};

// rocket structure definition

struct rocket
{
    int ID;
    int posx, posy;
    bool live;
    int speed;
    int boundx;
    int boundy;
    int direction;
};

// === typoe definition of item in the array ===

// Allias for the original rocket structure
typedef struct rocket rocket_str;

// Allias for th epointer to the rocket structure
typedef rocket_str *rocket_item;

// =============================================

// ============= SETTERS/GETTERS ===============

// Create rocket_item
extern rocket_item createRocketItem();

// Set rocket ID
extern void setRocketID(rocket_item ri, int id);

// Get rocket ID:
extern int rocketID(rocket_item ri);

// set rocket position X:
extern void setRocketPosX(rocket_item ri, int posx);

// get rocket position X:
extern int rocketPosX(rocket_item ri);

// set rocket position Y:
extern void setRocketPosY(rocket_item ri, int posy);

// get rocket position Y:
extern int rocketPosY(rocket_item ri);

// set rocket live flag:
extern void setRocketLive(rocket_item ri, bool live);

// get rocket live flag:
extern bool rocketLive(rocket_item ri);

// set rocket speed:
extern void setRocketSpeed(rocket_item ri, int speed);

// get rocket speed:
extern int rocketSpeed(rocket_item ri);

// set rocket boundary X:
extern void setRocketBoundX(rocket_item ri, int boundx);

// get rocket boundary X:
extern int rocketBoundX(rocket_item ri);

// set rocket boundary Y:
extern void setRocketBoundY(rocket_item ri, int boundy);

// get rocket boundary Y:
extern int rocketBoundY(rocket_item ri);

// Set rocket direction
extern void setRocketDirection(rocket_item ri, enum rocket_direction direction);

// Get rocket diretion
extern int rocketDirection(rocket_item ri);

// ============================================

// declaration of the whole structure:

struct rocket_list_type
{
    rocket_item *container;
    int size;
    int count;
};

// ===== type definition of list_type ========

// Allias for the pointer to list_type structure:
typedef struct rocket_list_type *rocket_list;

// ==============================================

// =========== FUNCTIONS ON rocket_list* ==========

extern rocket_list createRocketList(int size);

extern void destroyRocketList(rocket_list *l);

// Return current count of the list;
extern int countRockets(rocket_list *l);

// Return size of the list:
extern int sizeRockets(rocket_list *l);

// Add an item at the end of the list
extern void push_rocket(rocket_list *l, rocket_item i);

// Get the item at position idx:
extern rocket_item rocket_at(rocket_list *l, int idx);

// Resize a container inside a list
extern void resizeRocketList(rocket_list *l, int newSize);

// Clear list
extern void clearRocketList(rocket_list *l);

// ==============================================

#endif //_ROCKET_LIST_HPP_
