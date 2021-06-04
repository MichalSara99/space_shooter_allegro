#pragma once
#ifndef _SPACESHIP_HPP_
#define _SPACESHIP_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>

// own includes:
#include "game/game_objects.hpp"
#include "screen_settings/screen_settings.hpp"
#include "utilities/tools.hpp"

//========================== DECLARATIONS ===========================

enum ship_weapons_primary : unsigned int
{
    ONE_CANNON = 1,
    DOUBLE_CANNON,
    SHOTGUN
};
enum ship_weapons_secondary : unsigned int
{
    ROCKET = 1,
    ROCKETS,
    MINE,
    LASER
};

struct ship
{
    int ID;
    int posx, posy;
    int lives;
    int speed;
    int boundx, boundy;
    int score;
    int rebornCounter;
    ship_weapons_primary primaryWeaponLevel;
    ship_weapons_primary switchPrimaryWeapon;
    ship_weapons_secondary secondaryWeaponLevel;
    ship_weapons_secondary switchSecondaryWeapon;
};

typedef struct ship *spaceship;

/// Memory management for spaceship structure:

// Allocates memory for spaceship structure
// extern struct spaceship *createSpaceship();
extern spaceship createSpaceship();
// Deallocates memory for spaceship structure
extern void destroySpaceship(spaceship *ship);

/// Other methods:

// Initialize spaceship:
extern void initSpaceship(spaceship *ship, struct screen_setting **setting);
// Draw spaceship:
extern void drawSpaceship(spaceship *ship);
// Move Spaceship Up:
extern void moveSpaceshipUp(spaceship *ship);
// Move Spaceship Right:
extern void moveSpaceshipRight(spaceship *ship, struct screen_setting **setting);
// Move Spaceship Down:
extern void moveSpaceshipDown(spaceship *ship, struct screen_setting **setting);
// Move Spaceship Left:
extern void moveSpaceshipLeft(spaceship *ship);

//================== GETTERS/SETTERS ===================

// Get spaceship position X:
extern int spaceshipPosX(spaceship *ship);
// Set spaceship position X:
extern void setSpaceshipPosX(spaceship *ship, int posX);
// Get spaceship position Y:
extern int spaceshipPosY(spaceship *ship);
// Set spaceship position Y:
extern void setSpaceshipPosY(spaceship *ship, int posY);
// Get Spaceship lives:
extern int spaceshipLives(spaceship *ship);
// Set Spaceship lives:
extern void setSpaceshipLives(spaceship *ship, int lives);
// Get spaceship speed:
extern int spaceshipSpeed(spaceship *ship);
// Set spaceship speed:
extern void setSpaceshipSpeed(spaceship *ship, int speed);
// Get spaceship score:
extern int spaceshipScore(spaceship *ship);
// Set spaceship score:
extern void setSpaceshipScore(spaceship *ship, int score);
// Get spaceship boundy:
extern int spaceshipBoundy(spaceship *ship);
// Set spaceship boundy:
extern void setSpaceshipBoundy(spaceship *ship, int boundy);
// Get spaceship boundx:
extern int spaceshipBoundx(spaceship *ship);
// Set spaceship boundx:
extern void setSpaceshipBoundx(spaceship *ship, int boundx);
// Set spaceship rebornCounter:
extern void setSpaceshipRebornCounter(spaceship *ship, int counter);
// Get spaceship rebornCounter:
extern int spaceshipRebornCounter(spaceship *ship);
// Set the spaceship position:
extern void setSpaceshipInitPosition(spaceship *ship, struct screen_setting **setting);

// Get primaryWeaponLevel:
extern enum ship_weapons_primary primaryWeaponLevel(spaceship *ship);
// Set primaryWeaponLevel:
extern void setPrimaryWeaponLevel(spaceship *ship, enum ship_weapons_primary level);
// Get secondaryWeaponLevel:
extern enum ship_weapons_secondary secondaryWeaponLevel(spaceship *ship);
// Set primaryWeaponLevel:
extern void setSecondaryWeaponLevel(spaceship *ship, enum ship_weapons_secondary level);
// Get switchPrimaryWeapon:
extern enum ship_weapons_primary switchPrimaryWeapon(spaceship *ship);
// Set switchPrimaryWeapon:
extern void setSwitchPrimaryWeapon(spaceship *ship, enum ship_weapons_primary level);
// Get switchSecondaryWeapon:
extern enum ship_weapons_secondary switchSecondaryWeapon(spaceship *ship);
// Set switchSecondaryWeapon:
extern void setSwitchSecondaryWeapon(spaceship *ship, enum ship_weapons_secondary level);

#endif //_SPACESHIP_HPP_
