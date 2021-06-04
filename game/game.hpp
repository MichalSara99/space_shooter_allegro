#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

// own includes:
#include "boss/bosses.hpp"
#include "collisions/collisions.hpp"
#include "enemies/enemies.hpp"
#include "game_settings/game_settings.hpp"
#include "player/spaceship.hpp"
#include "screen_settings/screen_settings.hpp"
#include "weapons/enemy_weapons.hpp"
#include "weapons/weapons.hpp"

//========================== EXTERNAL DECLARATIONS =======================

// main game loop
extern void game(ALLEGRO_DISPLAY *display, struct screen_setting **screen_setting, struct game_setting **game_setting);

// all comets collisions:
extern void cometCollisions(spaceship *ship, comet_list *cl, fighter_list *fl, turret_list *tl,
                            bullet_list *shipBullets, rocket_list *shipRockets, mine_list *shipMines,
                            laser_beam *shipLaser, akiramBoss *boss, bullet_list *fighterBullets,
                            bullet_list *turretBullets, rocket_list *akiramBossRockets,
                            struct screen_setting **settings);

// all turrets collisions:
extern void turretCollisions(spaceship *ship, turret_list *tl, fighter_list *fl, /* akiramBoss *boss,
                              rocket_list *akiramBossRockets,*/
                             bullet_list *shipBullets, rocket_list *shipRockets, mine_list *shipMines,
                             laser_beam *shipLaser, bullet_list *turretBullets, bullet_list *fighterBullets,
                             struct screen_setting **setting);

//// all fighters collisions:
extern void fighterCollisions(spaceship *ship, fighter_list *fl, bullet_list *shipBullets, rocket_list *shipRockets,
                              mine_list *shipMines, laser_beam *shipLaser, bullet_list *fighterBullets, turret_list *tl,
                              bullet_list *turretBullets, akiramBoss *boss, rocket_list *akiramBossRockets);
// all akiramBoss collisions:
extern void akiramBossCollisions(spaceship *ship, akiramBoss *boss, bullet_list *shipBullets, rocket_list *shipRockets,
                                 mine_list *shipMines, laser_beam *shipLaser, rocket_list *akiramBossRockets,
                                 struct screen_setting **settings);

// initialize all game objects:
extern void initGameObjects(spaceship *ship, bullet_list *shipBullets, rocket_list *shipRockets, mine_list *shipMines,
                            laser_beam *shipLaser, comet_list *cl, turret_list *tl, bullet_list *turretBullets,
                            fighter_list *fl, bullet_list *fighterBullets, akiramBoss *boss,
                            rocket_list *akiramBossRockets, struct screen_setting **settings);

// start and update all game objects:
extern void startUpdateGameObjects(spaceship *ship, bullet_list *shipBullets, rocket_list *shipRockets,
                                   mine_list *shipMines, laser_beam *shipLaser, comet_list *cl, turret_list *tl,
                                   bullet_list *turretBullets, fighter_list *fl, bullet_list *fighterBullets,
                                   akiramBoss *boss, rocket_list *akiramBossRockets, struct screen_setting **settings);

// draw all game objects:
extern void drawGameObjects(spaceship *ship, bullet_list *shipBullets, rocket_list *shipRockets, mine_list *shipMines,
                            laser_beam *shipLaser, comet_list *cl, turret_list *tl, bullet_list *turretBullets,
                            fighter_list *fl, bullet_list *fighterBullets, akiramBoss *boss,
                            rocket_list *akiramBossBullets);

/**
   Destroy game objects
 */
extern void destroyGameObjects(spaceship *ship, bullet_list *shipBullets, rocket_list *shipRockets,
                               mine_list *shipMines, laser_beam *shipLaser, comet_list *cl, turret_list *tl,
                               bullet_list *turretBullets, fighter_list *fl, bullet_list *fighterBullets,
                               akiramBoss *boss, rocket_list *akiramBossRockets);

#endif //_GHAME_H_
