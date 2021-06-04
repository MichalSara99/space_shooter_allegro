#pragma once
#ifndef _BOSSES_HPP_
#define _BOSSES_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>

// Own includes:
#include "game/game_objects.hpp"
#include "player/spaceship.hpp"
#include "screen_settings/screen_settings.hpp"
#include "utilities/tools.hpp"

// bosses:
#include "boss/akiramboss.hpp"

//---------------------------------------------------------------------------------
//================================ AKIRAM BOSS =====================================
//---------------------------------------------------------------------------------

// Initialize AkiramBoss:
extern void initAkiramBoss(akiramBoss *boss, struct screen_setting **settings);
// Draw AkiramBoss:
extern void drawAkiramBoss(akiramBoss *boss);
// Start AkiramBoss:
extern void startAkiramBoss(akiramBoss *boss, spaceship *ship, struct screen_setting **settings);
// Update AkiramBoss:
extern void updateAkiramBoss(akiramBoss *boss, struct screen_setting **settings);

//----------------------------------------------------------------------------------
//================================ SECOND BOSS =====================================
//----------------------------------------------------------------------------------

#endif //_BOSSES_H_
