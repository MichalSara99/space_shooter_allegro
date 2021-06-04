#pragma once
#ifndef _WEAPONS_HPP_
#define _WEAPONS_HPP_

// ALllegro 5 includes:
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

// C standard library includes:
#include <stdio.h>
#include <stdlib.h>

// own includes:
#include "game/game_objects.hpp"
#include "player/spaceship.hpp"
#include "screen_settings/screen_settings.hpp"
#include "utilities/tools.hpp"

// bullet_list:
#include "bullet_list.hpp"

// rocket_list:
#include "rocket_list.hpp"

// mine_list:
#include "mine_list.hpp"

// laser_beam:
#include "laser.hpp"

//==========================================================================
//=============================== DECLARATIONS =============================
//==========================================================================

// switch primary weapons:
extern void switchPrimaryWeapons(spaceship *ship);

// Fire primary weapon:
extern void firePrimaryWeapon(bullet_list *bl, spaceship *ship);

// Update primary weapons:
extern void updatePrimaryWeapons(bullet_list *bl, spaceship *ship, struct screen_setting **settings);

// switch secondary weapons:
extern void switchSecondaryWeapons(spaceship *ship);

// Fire secondary weapon:
extern void fireSecondaryWeapon(rocket_list *rl, mine_list *ml, laser_beam *laser, spaceship *ship);

// Cease fire secondary weapon:
extern void ceaseFireSecondaryWeapon(laser_beam *laser);

// Update secondary weapons:
extern void updateSecondaryWeapons(rocket_list *rl, mine_list *ml, laser_beam *laser, spaceship *ship,
                                   struct screen_setting **settings);

//================================= BULLETS ===============================

// Initialize bullets:
extern void initBullets(bullet_list *bl);

// Draw bullets:
extern void drawBullets(bullet_list *bl);

//================================= ROCKETS ===============================

// Initialize rockets:
extern void initRockets(rocket_list *rl);

// Draw rockets:
extern void drawRockets(rocket_list *rl);

//================================== MINES ================================

// Initialize mines:
extern void initMines(mine_list *ml);

// Draw mines:
extern void drawMines(mine_list *ml);

//================================== LASER ================================

// Initialize laser:
extern void initLaser(laser_beam *laser);

// Draw laser:
extern void drawLaser(laser_beam *laser);

#endif //_WEAPONS_HPP_
