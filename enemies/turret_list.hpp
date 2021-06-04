#pragma once
#ifndef _TURRET_LIST_HPP_
#define _TURRET_LIST_HPP_

#include <stdio.h>
#include <stdlib.h>

// turret structure declaration:
struct turret
{
    int ID;
    int posx, posy;
    int lives;
    int speed;
    int boundx, boundy;
    int shoot_frequency;
};

// === type definitions of item in the array ===

// Allias for the original turret structure
typedef struct turret turret_str;
// Allias for the pointer to the turret structure
typedef struct turret *turret_item;

// =============================================

// ============= SETTERS/GETTERS ===============

// Create bullet_item
extern turret_item createTurretItem();

// Set turret ID
extern void setTurretID(turret_item ti, int id);

// Get turret ID
extern int turretID(turret_item ti);

// Set turret position X
extern void setTurretPosX(turret_item ti, int posx);

// Get turret position X
extern int turretPosX(turret_item ti);

// Set turret position Y
extern void setTurretPosY(turret_item ti, int posy);

// Get turret position Y
extern int turretPosY(turret_item ti);

// Set turret lives
extern void setTurretLives(turret_item ti, int lives);

// Get turret lives
extern int turretLives(turret_item ti);

// Set turret speed
extern void setTurretSpeed(turret_item ti, int speed);

// Get turret speed
extern int turretSpeed(turret_item ti);

// Set turret boundary X
extern void setTurretBoundX(turret_item ti, int boundx);

// Get turret boundary X
extern int turretBoundX(turret_item ti);

// Set turret boundary Y
extern void setTurretBoundY(turret_item ti, int boundy);

// Get turret boundary Y
extern int turretBoundY(turret_item ti);

// Set turret shoot_frequency
extern void setTurretFrequency(turret_item ti, int frequency);

// Get turret shoot_frequency
extern int turretFrequency(turret_item ti);

// ==========================================

// declaration of the whole structure

struct turret_list_type
{
    turret_item *container;
    int size;
    int count;
};

// ======= type definitions of list_type  ========

// Allias for the pointer to list_type structure
typedef struct turret_list_type *turret_list;

// ================================================

// =========== FUNCTIONS ON turret_list* ==========

extern turret_list createTurretList(int size);
extern void destroyTurretList(turret_list *l);

// Return current count of the list;
extern int countTurrets(turret_list *l);

// Return size of the list:
extern int sizeTurrets(turret_list *l);

// Add an item at the end of the list
extern void push_turret(turret_list *l, turret_item i);

// Get the item at position idx:
extern turret_item turret_at(turret_list *l, int idx);

// Resize a container inside a list
extern void resizeTurretList(turret_list *l, int newSize);

// Clear list
extern void clearTurretList(turret_list *l);

// ==============================================

#endif //_TURRET_LIST_H_
