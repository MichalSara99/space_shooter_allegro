#include "bosses.hpp"

void initAkiramBoss(akiramBoss *boss, struct screen_setting **settings)
{
    if ((*boss))
    {
        setAkiramBossID(boss, BOSS_ID);
        setAkiramBossIsAlive(boss, false);
        setAkiramBossSpeed(boss, 5);
        setAkiramBossBoundx(boss, 10);
        setAkiramBossBoundy(boss, 40);
        setAkiramBossHeadBoundx(boss, 21);
        setAkiramBossHeadBoundy(boss, 11);
        setAkiramBossAfterShotCounter(boss, 10);
        setAkiramBossBarrier(boss, screenWidth(settings) / 3.0);
    }
}

void drawAkiramBoss(akiramBoss *boss)
{
    if (akiramBossIsAlive(boss))
    {
        if (akiramBossAfterShotCounter(boss) > 0)
        {
            if (random() % 3 == 0)
            {
                // head:
                al_draw_filled_circle(akiramBossPosX(boss) - 10, akiramBossPosY(boss), 10, al_map_rgb(255, 51, 0));
                // main body:
                al_draw_filled_rectangle(akiramBossPosX(boss) - 10, akiramBossPosY(boss) - 40,
                                         akiramBossPosX(boss) + 10, akiramBossPosY(boss) + 40, al_map_rgb(153, 102, 0));
                // turrets:
                al_draw_filled_rectangle(akiramBossPosX(boss) - 15, akiramBossPosY(boss) - 30,
                                         akiramBossPosX(boss) - 10, akiramBossPosY(boss) - 20, al_map_rgb(255, 153, 0));
                al_draw_filled_rectangle(akiramBossPosX(boss) - 15, akiramBossPosY(boss) + 30,
                                         akiramBossPosX(boss) - 10, akiramBossPosY(boss) + 20, al_map_rgb(255, 153, 0));
                setAkiramBossAfterShotCounter(boss, akiramBossAfterShotCounter(boss) - 1);
            }
        }
        else
        {
            // head:
            al_draw_filled_circle(akiramBossPosX(boss) - 10, akiramBossPosY(boss), 10, al_map_rgb(255, 51, 0));
            // main body:
            al_draw_filled_rectangle(akiramBossPosX(boss) - 10, akiramBossPosY(boss) - 40, akiramBossPosX(boss) + 10,
                                     akiramBossPosY(boss) + 40, al_map_rgb(153, 102, 0));
            // turrets:
            al_draw_filled_rectangle(akiramBossPosX(boss) - 15, akiramBossPosY(boss) - 30, akiramBossPosX(boss) - 10,
                                     akiramBossPosY(boss) - 20, al_map_rgb(255, 153, 0));
            al_draw_filled_rectangle(akiramBossPosX(boss) - 15, akiramBossPosY(boss) + 30, akiramBossPosX(boss) - 10,
                                     akiramBossPosY(boss) + 20, al_map_rgb(255, 153, 0));
        }
    }
}

void startAkiramBoss(akiramBoss *boss, spaceship *ship, struct screen_setting **settings)
{
    if ((spaceshipScore(ship) > 0) && (spaceshipScore(ship) % 30 == 0) && (!akiramBossIsAlive(boss)))
    {
        setAkiramBossIsAlive(boss, true);
        setAkiramBossLives(boss, 10);
        setAkiramBossPosX(boss, screenWidth(settings));
        setAkiramBossPosY(boss, 30 + rand() % (screenHeight(settings) - 60));
        setAkiramBossDir(boss, AKIRAM_LEFT);
    }
}

void updateAkiramBoss(akiramBoss *boss, struct screen_setting **settings)
{
    if (akiramBossIsAlive(boss))
    {
        switch (akiramBossDir(boss))
        {
        case AKIRAM_DOWN:
            if (akiramBossPosY(boss) + 40 >= screenHeight(settings))
            {
                setAkiramBossDir(boss, static_cast<AkiramDir>(randomInt(0, 3)));
            }
            else
            {
                setAkiramBossPosY(boss, akiramBossPosY(boss) + akiramBossSpeed(boss));
            }
            break;
        case AKIRAM_LEFT:
            if (akiramBossPosX(boss) - 15 <= akiramBossBarrier(boss))
            {
                setAkiramBossDir(boss, static_cast<AkiramDir>(randomInt(0, 3)));
            }
            else
            {
                setAkiramBossPosX(boss, akiramBossPosX(boss) - akiramBossSpeed(boss));
            }
            break;
        case AKIRAM_UP:
            if (akiramBossPosY(boss) - 40 <= 0)
            {
                setAkiramBossDir(boss, static_cast<AkiramDir>(randomInt(0, 3)));
            }
            else
            {
                setAkiramBossPosY(boss, akiramBossPosY(boss) - akiramBossSpeed(boss));
            }
            break;
        case AKIRAM_RIGHT:
            if (akiramBossPosX(boss) + 10 >= screenWidth(settings))
            {
                setAkiramBossDir(boss, static_cast<AkiramDir>(randomInt(0, 3)));
            }
            else
            {
                setAkiramBossPosX(boss, akiramBossPosX(boss) + akiramBossSpeed(boss));
            }
            break;
        }
    }
}
