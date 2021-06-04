#include "akiramboss.hpp"

akiramBoss createAkiramBoss()
{
    akiramBoss boss = (akiramBoss)malloc(sizeof(akiramBoss_str));
    if (!boss)
    {
        printf("AkiramBoss structure error: An error occured while allocating memory block for firstBoss structure.\n");
        exit(EXIT_FAILURE);
    }
    return boss;
}

void destroyAkiramBoss(akiramBoss *boss)
{
    if (*boss)
    {
        free(*boss);
    }
    return;
}

int akiramBossID(akiramBoss *boss)
{
    return ((*boss)->ID);
}

void setAkiramBossID(akiramBoss *boss, int id)
{
    ((*boss)->ID) = id;
}

int akiramBossPosX(akiramBoss *boss)
{
    return ((*boss)->posx);
}

void setAkiramBossPosX(akiramBoss *boss, int posX)
{
    (*boss)->posx = posX;
}

int akiramBossPosY(akiramBoss *boss)
{
    return ((*boss)->posy);
}

void setAkiramBossPosY(akiramBoss *boss, int posY)
{
    ((*boss)->posy) = posY;
}

int akiramBossLives(akiramBoss *boss)
{
    return ((*boss)->lives);
}

void setAkiramBossLives(akiramBoss *boss, int lives)
{
    ((*boss)->lives) = lives;
}

bool akiramBossIsAlive(akiramBoss *boss)
{
    return ((*boss)->isAlive);
}

void setAkiramBossIsAlive(akiramBoss *boss, bool alive)
{
    ((*boss)->isAlive) = alive;
}

int akiramBossSpeed(akiramBoss *boss)
{
    return ((*boss)->speed);
}

void setAkiramBossSpeed(akiramBoss *boss, int speed)
{
    ((*boss)->speed) = speed;
}

int akiramBossBoundy(akiramBoss *boss)
{
    return ((*boss)->boundy);
}

void setAkiramBossBoundy(akiramBoss *boss, int boundy)
{
    ((*boss)->boundy) = boundy;
}

int akiramBossBoundx(akiramBoss *boss)
{
    return ((*boss)->boundx);
}

void setAkiramBossBoundx(akiramBoss *boss, int boundx)
{
    ((*boss)->boundx) = boundx;
}

void setAkiramBossDir(akiramBoss *boss, enum AkiramDir dir)
{
    ((*boss)->dir) = dir;
}

enum AkiramDir akiramBossDir(akiramBoss *boss)
{
    return ((*boss)->dir);
}

void setAkiramBossBarrier(akiramBoss *boss, int barrier)
{
    ((*boss)->barrier) = barrier;
}

int akiramBossBarrier(akiramBoss *boss)
{
    return ((*boss)->barrier);
}

int akiramBossHeadBoundx(akiramBoss *boss)
{
    return (*boss)->headBoundx;
}

void setAkiramBossHeadBoundx(akiramBoss *boss, int boundx)
{
    (*boss)->headBoundx = boundx;
}

int akiramBossHeadBoundy(akiramBoss *boss)
{
    return (*boss)->headBoundy;
}

void setAkiramBossHeadBoundy(akiramBoss *boss, int boundy)
{
    (*boss)->headBoundy = boundy;
}

int akiramBossAfterShotCounter(akiramBoss *boss)
{
    return (*boss)->afterShotCounter;
}

void setAkiramBossAfterShotCounter(akiramBoss *boss, int counter)
{
    (*boss)->afterShotCounter = counter;
}
