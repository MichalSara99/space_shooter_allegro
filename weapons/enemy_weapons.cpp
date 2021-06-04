#include "enemy_weapons.hpp"

void initTurretBullets(bullet_list *bl)
{
    for (int i = 0; i < sizeBullets(bl); ++i)
    {
        bullet_item blt = createBulletItem();
        // setting initial properties:
        setBulletID(blt, BULLET_ID);
        setBulletPosX(blt, 0);
        setBulletPosY(blt, 0);
        setBulletLive(blt, false);
        setBulletSpeed(blt, 9);
        setBulletDirection(blt, static_cast<bullet_direction>(randomInt(0, 3)));

        push_bullet(bl, blt);
    }
}

void drawEnemyBullets(bullet_list *bl)
{
    for (int i = 0; i < countBullets(bl); ++i)
    {
        if (bulletLive(bullet_at(bl, i)))
        {
            al_draw_filled_circle(bulletPosX(bullet_at(bl, i)), bulletPosY(bullet_at(bl, i)), 2,
                                  al_map_rgb(255, 255, 255));
        }
    }
}

void updateTurretBullets(bullet_list *bl, turret_list *tl, struct screen_setting **settings)
{
    fireTurretBullets(bl, tl);
    for (int b = 0; b < countBullets(bl); ++b)
    {
        if (bulletLive(bullet_at(bl, b)))
        {
            switch (bulletDirection(bullet_at(bl, b)))
            {
            case BULLET_LEFT:
                setBulletPosX(bullet_at(bl, b), (bulletPosX(bullet_at(bl, b)) - bulletSpeed(bullet_at(bl, b))));
                break;
            case BULLET_UP:
                setBulletPosY(bullet_at(bl, b), (bulletPosY(bullet_at(bl, b)) - bulletSpeed(bullet_at(bl, b))));
                break;
            case BULLET_DOWN:
                setBulletPosY(bullet_at(bl, b), (bulletPosY(bullet_at(bl, b)) + bulletSpeed(bullet_at(bl, b))));
                break;
            case BULLET_RIGHT:
                setBulletPosX(bullet_at(bl, b), (bulletPosX(bullet_at(bl, b)) + bulletSpeed(bullet_at(bl, b))));
                break;
            }

            if ((bulletPosX(bullet_at(bl, b)) > screenWidth(settings)) || (bulletPosX(bullet_at(bl, b)) < 0) ||
                (bulletPosY(bullet_at(bl, b)) < 0) || (bulletPosY(bullet_at(bl, b)) > screenHeight(settings)))
            {
                setBulletLive(bullet_at(bl, b), false);
            }
        }
    }
}

void fireTurretBullets(bullet_list *bl, turret_list *tl)
{
    for (int t = 0; t < countTurrets(tl); ++t)
    {
        if (turretLives(turret_at(tl, t)) > 0)
        {
            if (random() % 2)
            {
                for (int b = 0; b < countBullets(bl) / countTurrets(tl); ++b)
                {
                    // shoot only those bullets  that are not alive
                    if (!bulletLive(bullet_at(bl, b)))
                    {
                        setBulletLive(bullet_at(bl, b), true);
                        setBulletDirection(bullet_at(bl, b), static_cast<bullet_direction>(randomInt(0, 3)));

                        switch (bulletDirection(bullet_at(bl, b)))
                        {
                        case BULLET_LEFT:
                            setBulletPosX(bullet_at(bl, b), turretPosX(turret_at(tl, t)) - 10);
                            setBulletPosY(bullet_at(bl, b), turretPosY(turret_at(tl, t)));
                            break;
                        case BULLET_RIGHT:
                            setBulletPosX(bullet_at(bl, b), turretPosX(turret_at(tl, t)) + 10);
                            setBulletPosY(bullet_at(bl, b), turretPosY(turret_at(tl, t)));
                            break;
                        case BULLET_UP:
                            setBulletPosX(bullet_at(bl, b), turretPosX(turret_at(tl, t)));
                            setBulletPosY(bullet_at(bl, b), turretPosY(turret_at(tl, t)) - 10);
                            break;
                        case BULLET_DOWN:
                            setBulletPosX(bullet_at(bl, b), turretPosX(turret_at(tl, t)));
                            setBulletPosY(bullet_at(bl, b), turretPosY(turret_at(tl, t)) + 10);
                            break;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void initFighterBullets(bullet_list *bl)
{
    for (int b = 0; b < sizeBullets(bl); ++b)
    {
        bullet_item blt = createBulletItem();
        // setting initial properties:
        setBulletID(blt, BULLET_ID);
        setBulletPosX(blt, 0);
        setBulletPosY(blt, 0);
        setBulletLive(blt, false);
        setBulletSpeed(blt, 12);
        setBulletDirection(blt, BULLET_LEFT);

        push_bullet(bl, blt);
    }
}

void updateFighterBullets(bullet_list *bl, fighter_list *fl)
{
    fireFighterBullets(bl, fl);
    for (int b = 0; b < countBullets(bl); ++b)
    {
        if (bulletLive(bullet_at(bl, b)))
        {
            setBulletPosX(bullet_at(bl, b), bulletPosX(bullet_at(bl, b)) - bulletSpeed(bullet_at(bl, b)));
            if (bulletPosX(bullet_at(bl, b)) < 0)
            {
                setBulletLive(bullet_at(bl, b), false);
            }
        }
    }
}

void fireFighterBullets(bullet_list *bl, fighter_list *fl)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {

            if (random() % 6)
            {
                for (int b = 0; b < countBullets(bl); ++b)
                {
                    if (!bulletLive(bullet_at(bl, b)))
                    {

                        setBulletLive(bullet_at(bl, b), true);
                        setBulletPosX(bullet_at(bl, b), fighterPosX(fighter_at(fl, f)) - 23);
                        setBulletPosY(bullet_at(bl, b), fighterPosY(fighter_at(fl, f)));

                        break;
                    }
                }
            }
        }
    }
}

void drawEnemyRockets(rocket_list *rl)
{
    for (int r = 0; r < countRockets(rl); ++r)
    {
        if (rocketLive(rocket_at(rl, r)))
        {
            al_draw_filled_rectangle(rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r)) + 2,
                                     rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r)) - 1,
                                     rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r)) + 2,
                                     rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r)) + 1,
                                     al_map_rgb(255, 153, 51));
            al_draw_filled_rectangle(rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r)),
                                     rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r)),
                                     rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r)),
                                     rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r)),
                                     al_map_rgb(209, 224, 224));
            al_draw_filled_circle(rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r)),
                                  rocketPosY(rocket_at(rl, r)), rocketBoundY(rocket_at(rl, r)), al_map_rgb(255, 0, 0));
        }
    }
}

void initAkiramBossRockets(rocket_list *rl)
{
    for (int r = 0; r < sizeRockets(rl); ++r)
    {
        rocket_item rkt = createRocketItem();
        // setting initial properties:
        setRocketID(rkt, ROCKET_ID);
        setRocketPosX(rkt, 0);
        setRocketPosY(rkt, 0);
        setRocketLive(rkt, false);
        setRocketSpeed(rkt, 8);
        setRocketBoundX(rkt, 6);
        setRocketBoundY(rkt, 3);

        push_rocket(rl, rkt);
    }
}

void updateAkiramBossRockets(rocket_list *rl, akiramBoss *boss)
{
    fireAkiramBossRockets(rl, boss);
    for (int r = 0; r < countRockets(rl); ++r)
    {
        if (rocketLive(rocket_at(rl, r)))
        {
            setRocketPosX(rocket_at(rl, r), rocketPosX(rocket_at(rl, r)) - rocketSpeed(rocket_at(rl, r)));
            if (rocketPosX(rocket_at(rl, r)) < 0)
            {
                setRocketLive(rocket_at(rl, r), false);
            }
        }
    }
}

void fireAkiramBossRockets(rocket_list *rl, akiramBoss *boss)
{
    if (akiramBossIsAlive(boss))
    {
        if (random() % 13 == 0)
        {
            for (int r = 0; r < countRockets(rl); ++r)
            {
                if (!rocketLive(rocket_at(rl, r)))
                {
                    setRocketLive(rocket_at(rl, r), true);
                    setRocketPosX(rocket_at(rl, r), akiramBossPosX(boss) - 18);
                    setRocketPosY(rocket_at(rl, r), akiramBossPosY(boss) + ((random() % 2 == 0) ? -1 : 1) * 25);
                    break;
                }
            }
        }
    }
}
