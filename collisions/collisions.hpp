#pragma once
#ifndef _COLLISIONS_HPP_
#define _COLLISIONS_HPP_

// Allegro 5 libabries:
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

// My own includes:
#include "player/spaceship.hpp"
// === weapon lists ===
#include "weapons/bullet_list.hpp"
#include "weapons/laser.hpp"
#include "weapons/mine_list.hpp"
#include "weapons/rocket_list.hpp"
// === enemy lists ===
#include "enemies/comet_list.hpp"
#include "enemies/fighter_list.hpp"
#include "enemies/turret_list.hpp"
// === boss objects ===
#include "boss/bosses.hpp"

//==========================================================================
//=============================== DECLARATIONS =============================
//==========================================================================

//------------------------------------------------------------------------
//============================= COMETS COLLISION =========================
//------------------------------------------------------------------------

//============== COMETS vs SPACESHIP BULLETS COLLISION ====================

extern void cometsSpaceshipBulletsCollision(comet_list *cl, bullet_list *bl, spaceship *ship);

//=============== COMETS vs SPACESHIP ROCKETS COLLISION ===================

extern void cometsSpaceshipRocketsCollision(comet_list *cl, rocket_list *bl, spaceship *ship);

//================ COMETS vs SPACESHIP MINES COLLISION ====================

extern void cometsSpaceshipMinesCollision(comet_list *cl, mine_list *ml, spaceship *ship);

//============== COMETS vs SPACESHIP LASER COLLISION ====================

extern void cometsSpaceshipLaserCollision(comet_list *cl, laser_beam *laser, spaceship *ship);

//===================== COMETS vs SPACESHIP COLLISION =====================

extern void cometsSpaceshipCollision(comet_list *cl, spaceship *ship, struct screen_setting **settings);

//===================== COMETS vs AKIRAMBOSS COLLISION =====================

extern void cometsAkiramBossCollision(comet_list *cl, akiramBoss *boss);

//===================== COMETS vs FIGHTERS BULLETS COLLISION ===================

extern void cometsFightersBulletsCollision(comet_list *cl, bullet_list *fighterBullets);

//===================== COMETS vs TURRET BULLETS COLLISION =====================

extern void cometsTurretsBulletsCollision(comet_list *cl, bullet_list *turretsBullets);

//===================== COMETS vs AKIRAMBOSS ROCKETS COLLISION ==================

extern void cometsAkiramBossRockets(comet_list *cl, rocket_list *akiramRockets);

//===================== COMETS vs FIGHTERS COLLISION ==========================

extern void cometsFightersCollision(comet_list *cl, fighter_list *fl);

//===================== COMETS vs TURRETS COLLISION ==========================

extern void cometsTurretsCollision(comet_list *cl, turret_list *tl);

//------------------------------------------------------------------------
//============================ TURRETS COLLISION =========================
//------------------------------------------------------------------------

//===================== TURRETS vs SPACESHIP COLLISION =====================

extern void turretsSpaceshipCollision(turret_list *tl, spaceship *ship, struct screen_setting **settings);

//================ TURRETS vs SPACESHIP BULLETS COLLISION ==================

extern void turretsSpaceshipBulletCollision(turret_list *tl, bullet_list *shipBullets, spaceship *ship);

//================ TURRETS BULLETS vs SPACESHIP COLLISION ==================

extern void turretsBulletSpaceshipCollision(bullet_list *turretBullets, spaceship *ship,
                                            struct screen_setting **setting);

//================= TURRETS vs SPACESHIP ROCKETS COLLISION =================

extern void turretsSpaceshipRocketsCollision(turret_list *tl, rocket_list *rl, spaceship *ship);

//================== TURRETS vs SPACESHIP MINES COLLISION ==================

extern void turretsSpaceshipMinesCollision(turret_list *tl, mine_list *ml, spaceship *ship);

//============== TURRETS vs SPACESHIP LASER COLLISION ====================

extern void turretsSpaceshipLaserCollision(turret_list *tl, laser_beam *laser, spaceship *ship);

//===================== TURRETS vs AKIRAMBOSS COLLISION =====================

extern void turretsAkiramBossCollision(turret_list *tl, akiramBoss *boss);

//===================== TURRETS vs FIGHTERS BULLETS COLLISION ===================

extern void turretsFightersBulletsCollision(turret_list *tl, bullet_list *fighterBullets);

//===================== TURRETS vs AKIRAMBOSS ROCKETS COLLISION ==================

extern void turretsAkiramBossRocketsCollision(turret_list *tl, rocket_list *akiramBossRockets);

//===================== TURRETS vs FIGHTERS COLLISION ==========================

extern void turretsFightersCollision(turret_list *tl, fighter_list *fl);

//------------------------------------------------------------------------
//=========================== FIGHTERS COLLISION =========================
//------------------------------------------------------------------------

//===================== FIGHTERS vs SPACESHIP COLLISION =====================

extern void fightersSpaceshipCollision(fighter_list *fl, spaceship *ship);

//=============== FIGHTERS BULLETS vs SPACESHIP COLLISION ==================

extern void fightersBulletSpaceshipCollision(bullet_list *fighterBullets, spaceship *ship);

//=============== FIGHTERS vs SPACESHIP BULLETS COLLISION ==================

extern void fightersSpaceshipBulletCollision(fighter_list *fl, bullet_list *shipBullets, spaceship *ship);

//=============== FIGHTERS vs SPACESHIP ROCKETS COLLISION ==================

extern void fightersSpaceshipRocketsCollision(fighter_list *fl, rocket_list *rl, spaceship *ship);

//================ FIGHTERS vs SPACESHIP MINES COLLISION ===================

extern void fightersSpaceshipMinesCollision(fighter_list *fl, mine_list *ml, spaceship *ship);

//============== FIGHTERS vs SPACESHIP LASER COLLISION ====================

extern void fightersSpaceshipLaserCollision(fighter_list *fl, laser_beam *laser, spaceship *ship);

//===================== FIGHTERS vs AKIRAMBOSS COLLISION =====================

extern void fightersAkiramBossCollision(fighter_list *fl, akiramBoss *boss);

//===================== FIGHTERS vs TURRETS COLLISION ===================

extern void fightersTurretsCollsion(fighter_list *fl, turret_list *tl);

//===================== FIGHTERS vs TURRETS BULLETS COLLISION ===================

extern void fightersTurretsBulletsCollision(fighter_list *fl, bullet_list *turretsBullets);

//===================== FIGHTERS vs AKIRAMBOSS ROCKETS COLLISION ==================

extern void fightersAkiramBossRocketsCollision(fighter_list *fl, rocket_list *akiramBossRockets);

//--------------------------------------------------------------------------
//=========================== AKIRAMBOSS COLLISION =========================
//--------------------------------------------------------------------------

//============== AKIRAMBOSS vs SPACESHIP BULLETS COLLISION ====================

extern void akiramBossSpaceshipBulletsCollision(akiramBoss *boss, bullet_list *bl, spaceship *ship);

//============== AKIRAMBOSS HEAD vs SPACESHIP BULLETS COLLISION ====================

extern void akiramBossHeadSpaceshipBulletsCollision(akiramBoss *boss, bullet_list *bl, spaceship *ship);

//=============== AKIRAMBOSS vs SPACESHIP ROCKETS COLLISION ===================

extern void akiramBossSpaceshipRocketsCollision(akiramBoss *boss, rocket_list *rl, spaceship *ship);

//=============== AKIRAMBOSS HEAD vs SPACESHIP ROCKETS COLLISION ===================

extern void akiramBossHeadSpaceshipRocketsCollision(akiramBoss *boss, rocket_list *rl, spaceship *ship);

//================ AKIRAMBOSS vs SPACESHIP MINES COLLISION ====================

extern void akiramBossSpaceshipMinesCollision(akiramBoss *boss, mine_list *ml, spaceship *ship);

//=============== AKIRAMBOSS HEAD vs SPACESHIP MINES COLLISION ===================

extern void akiramBossHeadSpaceshipMinesCollision(akiramBoss *boss, mine_list *ml, spaceship *ship);

//================ AKIRAMBOSS vs SPACESHIP LASER COLLISION ====================

extern void akiramBossSpaceshipLaserCollision(akiramBoss *boss, laser_beam *laser, spaceship *ship);

//================ AKIRAMBOSS HEAD vs SPACESHIP LASER COLLISION ====================

extern void akiramBossHeadSpaceshipLaserCollision(akiramBoss *boss, laser_beam *laser, spaceship *ship);

//===================== AKIRAMBOSS vs SPACESHIP COLLISION =====================

extern void akiramBossSpaceshipCollision(akiramBoss *boss, spaceship *ship, struct screen_setting **setting);

//===================== AKIRAMBOSS ROCKETS vs SPACESHIP COLLISION =====================

extern void akiramBossRocketsSpaceshipCollision(akiramBoss *boss, rocket_list *bossRockets, spaceship *ship,
                                                struct screen_setting **setting);

#endif //_COLLISIONS_HPP_
