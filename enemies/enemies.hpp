#pragma once
#ifndef _ENEMIES_HPP_
#define _ENEMIES_HPP_

// ALlegro 5 includes:
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
#include "weapons/bullet_list.hpp"

// enemy lists:
#include "comet_list.hpp"
#include "fighter_list.hpp"
#include "turret_list.hpp"

//==========================================================================
//=============================== DECLARATIONS =============================
//==========================================================================

//================================= COMMETS ===============================

// Initialize comets
extern void initComets(comet_list *cl);

// Draw comets:
extern void drawComets(comet_list *cl);

// Start comets:
extern void startComets(comet_list *cl, struct screen_setting **setting);

// Update comets:
extern void updateComets(comet_list *cl);

//================================= TURRETS ===============================

// Initialize turrets
extern void initTurrets(turret_list *tl);

// Draw turrets:
extern void drawTurrets(turret_list *tl);

// Start turrets:
extern void startTurrets(turret_list *tl, struct screen_setting **setting);

// Update turrets:
extern void updateTurrets(turret_list *tl);

//================================= FIGHTERS ===============================

// Initialize fighters
extern void initFighters(fighter_list *fl, struct screen_setting **setting);

// Draw fighters:
extern void drawFighters(fighter_list *fl);

// Start fighters:
extern void startFighters(fighter_list *fl, struct screen_setting **setting);

// Update fighters:
extern void updateFighters(fighter_list *fl, spaceship *ship);

#endif //_ENEMIES_HPP_
