#pragma once
#ifndef _AKIRAM_BOSS_HPP_
#define _AKIRAM_BOSS_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------------
//================================ AKIRAM BOSS =====================================
//---------------------------------------------------------------------------------

enum AkiramDir : unsigned int
{
    AKIRAM_UP,
    AKIRAM_RIGHT,
    AKIRAM_DOWN,
    AKIRAM_LEFT
};

struct firstBoss
{
    int ID;
    int posx, posy;
    int speed;
    int lives;
    int boundx, boundy;
    int headBoundx, headBoundy;
    AkiramDir dir;
    int barrier;
    bool isAlive;
    int afterShotCounter;
};

// Allias for the original comet structure
typedef struct firstBoss akiramBoss_str;

typedef struct firstBoss *akiramBoss;

// Create AkiramBoss:
extern akiramBoss createAkiramBoss();
// Destroy AkiramBoss
extern void destroyAkiramBoss(akiramBoss *boss);

// ============== GETTERS/SETTERS ==============

// Get akiramBoss ID:
extern int akiramBossID(akiramBoss *boss);
// Set akiramBoss ID:
extern void setAkiramBossID(akiramBoss *boss, int id);
// Get akiramBoss position X:
extern int akiramBossPosX(akiramBoss *boss);
// Set akiramBoss position X:
extern void setAkiramBossPosX(akiramBoss *boss, int posX);
// Get akiramBoss position Y:
extern int akiramBossPosY(akiramBoss *boss);
// Set akiramBoss position Y:
extern void setAkiramBossPosY(akiramBoss *boss, int posY);
// Get akiramBoss isAlive flag:
extern bool akiramBossIsAlive(akiramBoss *boss);
// Set akiramBoss flag isAlive:
extern void setAkiramBossIsAlive(akiramBoss *boss, bool alive);
// Get akiramBoss lives:
extern int akiramBossLives(akiramBoss *boss);
// Set akiramBoss lives:
extern void setAkiramBossLives(akiramBoss *boss, int lives);
// Get akiramBoss speed:
extern int akiramBossSpeed(akiramBoss *boss);
// Set akiramBoss speed:
extern void setAkiramBossSpeed(akiramBoss *boss, int speed);
// Get akiramBoss boundy:
extern int akiramBossBoundy(akiramBoss *boss);
// Set akiramBoss boundy:
extern void setAkiramBossBoundy(akiramBoss *boss, int boundy);
// Get akiramBoss boundx:
extern int akiramBossBoundx(akiramBoss *boss);
// Set akiramBoss boundx:
extern void setAkiramBossBoundx(akiramBoss *boss, int boundx);
// Set akiramBoss direction:
extern void setAkiramBossDir(akiramBoss *boss, enum AkiramDir dir);
// Get akiramBoss direction:
extern enum AkiramDir akiramBossDir(akiramBoss *boss);
// Set akiramBoss barrier:
extern void setAkiramBossBarrier(akiramBoss *boss, int barrier);
// Get akiramBoss barrier:
extern int akiramBossBarrier(akiramBoss *boss);
// Get akiramBoss head boundary X:
extern int akiramBossHeadBoundx(akiramBoss *boss);
// Set akiramBoss head boundary X:
extern void setAkiramBossHeadBoundx(akiramBoss *boss, int boundx);
// Get akiramBoss head boundary Y:
extern int akiramBossHeadBoundy(akiramBoss *boss);
// Set akiramBoss head boundary X:
extern void setAkiramBossHeadBoundy(akiramBoss *boss, int boundy);
// Get akiramBoss afterShotCounter:
extern int akiramBossAfterShotCounter(akiramBoss *boss);
// Set akiramBoss afterShotCounter:
extern void setAkiramBossAfterShotCounter(akiramBoss *boss, int counter);

#endif //_AKIRAM_BOSS_HPP_
