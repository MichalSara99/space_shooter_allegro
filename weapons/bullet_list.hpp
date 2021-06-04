#pragma once
#ifndef _BULLET_LIST_H_
#define _BULLET_LIST_H_

#include <stdio.h>
#include <stdlib.h>

// bullet enumeration diraction
enum bullet_direction : unsigned int
{
    BULLET_LEFT,
    BULLET_DOWN,
    BULLET_RIGHT,
    BULLET_UP
};

// bullet structure declaration:

struct bullet
{
    int ID;
    int posx, posy;
    bool live;
    int speed;
    int direction;
};

// === type definitions of item in the array ===

// Allias for the original bullet structure
typedef struct bullet bullet_str;

// Allias for the pointer to the bullet structure
typedef struct bullet *bullet_item;

// =============================================

// ============= SETTERS/GETTERS ===============

// Create bullet_item
extern bullet_item createBulletItem();

// Set bullet ID
extern void setBulletID(bullet_item bi, int id);

// Get bullet ID
extern int bulletID(bullet_item bi);

// Set bullet position X
extern void setBulletPosX(bullet_item bi, int posx);

// Get bullet position X
extern int bulletPosX(bullet_item bi);

// Set bullet position Y
extern void setBulletPosY(bullet_item bi, int posy);

// Get bullet position Y
extern int bulletPosY(bullet_item bi);

// Set bullet live flag
extern void setBulletLive(bullet_item bi, bool live);

// Get bullet live flag
extern bool bulletLive(bullet_item bi);

// Set bullet speed
extern void setBulletSpeed(bullet_item bi, int speed);

// Get bullet speed
extern int bulletSpeed(bullet_item bi);

// Set bullet direction
extern void setBulletDirection(bullet_item bi, enum bullet_direction direction);

// Get bullet diretion
extern int bulletDirection(bullet_item bi);

// ==========================================

// declaration of the whole structure

struct bullet_list_type
{
    bullet_item *container;
    int size;
    int count;
};

// ======= type definitions of list_type  ========

// Allias for the pointer to list_type structure
typedef struct bullet_list_type *bullet_list;

// ================================================

// =========== FUNCTIONS ON bullet_list* ==========

extern bullet_list createBulletList(int size);
extern void destroyBulletList(bullet_list *l);

// Return current count of the list;
extern int countBullets(bullet_list *l);

// Return size of the list:
extern int sizeBullets(bullet_list *l);

// Add an item at the end of the list
extern void push_bullet(bullet_list *l, bullet_item i);

// Get the item at position idx:
extern bullet_item bullet_at(bullet_list *l, int idx);

// Resize a container inside a list
extern void resizeBulletList(bullet_list *l, int newSize);

// Clear list
extern void clearBulletList(bullet_list *l);

// ==============================================

#endif //_BULLET_LIST_H_
