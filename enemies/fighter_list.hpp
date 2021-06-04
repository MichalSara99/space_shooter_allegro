#pragma once
#ifndef _FIGHETR_LIST_HPP_
#define _FIGHTER_LIST_HPP_

#include <stdio.h>
#include <stdlib.h>

// fighter state enumeration:
enum fighter_state
{
    IDLE,
    CHASING
};

// fighter structure declaration:
struct fighter
{
    int ID;
    int posx, posy;
    int lives;
    int speed;
    int boundx, boundy;
    int shoot_frequency;
    fighter_state state;
    int treshold;
};

// === type definitions of item in the array ===

// Allias for the original fighter structure
typedef struct fighter fighter_str;
// Allias for the pointer to the fighter structure
typedef struct fighter *fighter_item;

// =============================================

// ============= SETTERS/GETTERS ===============

// Create fighter_item
extern fighter_item createFighterItem();

// Set fighter ID
extern void setFighterID(fighter_item fi, int id);

// Get fighter ID
extern int fighterID(fighter_item fi);

// Set fighter position X
extern void setFighterPosX(fighter_item fi, int posx);

// Get fighter position X
extern int fighterPosX(fighter_item fi);

// Set fighter position Y
extern void setFighterPosY(fighter_item fi, int posy);

// Get fighter position Y
extern int fighterPosY(fighter_item fi);

// Set fighter lives
extern void setFighterLives(fighter_item fi, int lives);

// Get fighter lives
extern int fighterLives(fighter_item fi);

// Set fighter speed
extern void setFighterSpeed(fighter_item fi, int speed);

// Get fighter speed
extern int fighterSpeed(fighter_item fi);

// Set fighter boundary X
extern void setFighterBoundX(fighter_item fi, int boundx);

// Get fighter boundary X
extern int fighterBoundX(fighter_item fi);

// Set fighter boundary Y
extern void setFighterBoundY(fighter_item fi, int boundy);

// Get fighter boundary Y
extern int fighterBoundY(fighter_item fi);

// Set fighter shoot_frequency
extern void setFighterFrequency(fighter_item fi, int frequency);

// Get fighter shoot_frequency
extern int fighterFrequency(fighter_item fi);

// Set fighter state:
extern void setFighterState(fighter_item fi, enum fighter_state state);

// Get fighter state:
extern enum fighter_state fighterState(fighter_item fi);

// Set fighter treshold
extern void setFighterTreshold(fighter_item fi, int treshold);

// Get fighter treshold
extern int fighterTreshold(fighter_item fi);

// ==========================================

// declaration of the whole structure

struct fighter_list_type
{
    fighter_item *container;
    int size;
    int count;
};

// ======= type definitions of list_type  ========

// Allias for the pointer to list_type structure
typedef struct fighter_list_type *fighter_list;

// ================================================

// =========== FUNCTIONS ON fighter_list* ==========

extern fighter_list createFighterList(int size);
extern void destroyFighterList(fighter_list *l);

// Return current count of the list;
extern int countFighters(fighter_list *l);

// Return size of the list:
extern int sizeFighters(fighter_list *l);

// Add an item at the end of the list
extern void push_fighter(fighter_list *l, fighter_item i);

// Get the item at position idx:
extern fighter_item fighter_at(fighter_list *l, int idx);

// Resize a container inside a list
extern void resizeFighterList(fighter_list *l, int newSize);

// Clear list
extern void clearFighterList(fighter_list *l);

// ==============================================

#endif //_FIGHTER_LIST_HPP_
