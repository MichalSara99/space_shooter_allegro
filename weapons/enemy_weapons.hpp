#pragma once
#ifndef _ENEMY_WEAPONS_HPP_
#define _ENEMY_WEAPONS_HPP_

// ALllegro 5 includes:
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

// C standard library includes:
#include <stdio.h>
#include <stdlib.h>

// own includes:
#include "boss/akiramboss.hpp"
#include "enemies/fighter_list.hpp"
#include "enemies/turret_list.hpp"
#include "game/game_objects.hpp"
#include "screen_settings/screen_settings.hpp"
#include "utilities/tools.hpp"

// bullet_list:
#include "bullet_list.hpp"
// rocket_list:
#include "rocket_list.hpp"

//==========================================================================
//=============================== DECLARATIONS =============================
//==========================================================================

// Draw bullets:
extern void drawEnemyBullets(bullet_list *bl);

// Draw rockets:
extern void drawEnemyRockets(rocket_list *rl);

//-------------------------------------------------------------------------
//================================= TURRETS ===============================
//-------------------------------------------------------------------------

//================================= BULLETS ===============================

// Initialize bullets:
extern void initTurretBullets(bullet_list *bl);

// Update bullets:
extern void updateTurretBullets(bullet_list *bl, turret_list *tl, struct screen_setting **settings);

// Fire bullets:
extern void fireTurretBullets(bullet_list *bl, turret_list *tl);

//-------------------------------------------------------------------------
//================================= FIGHTERS ==============================
//-------------------------------------------------------------------------

//================================= BULLETS ===============================

// Initialize bullets:
extern void initFighterBullets(bullet_list *bl);

// Update bullets:
extern void updateFighterBullets(bullet_list *bl, fighter_list *fl);

// Fire bullets:
extern void fireFighterBullets(bullet_list *bl, fighter_list *fl);

//================================= ROCKETS ===============================

//-------------------------------------------------------------------------
//=============================== AKIRAMBOSS ==============================
//-------------------------------------------------------------------------

//================================= ROCKETS ===============================

// Initialize rockets:
extern void initAkiramBossRockets(rocket_list *rl);

// Update rockets:
extern void updateAkiramBossRockets(rocket_list *rl, akiramBoss *boss);

// Fire rockets:
extern void fireAkiramBossRockets(rocket_list *rl, akiramBoss *boss);

#endif //_ENEMY_WEAPONS_HPP_
