#include "weapons.hpp"

void initBullets(bullet_list *bl)
{
    for (int i = 0; i < sizeBullets(bl); ++i)
    {
        bullet_item blt = createBulletItem();
        // setting initial properties:
        setBulletID(blt, BULLET_ID);
        setBulletPosX(blt, 0);
        setBulletPosY(blt, 0);
        setBulletLive(blt, false);
        setBulletSpeed(blt, 10);
        setBulletDirection(blt, BULLET_LEFT);

        push_bullet(bl, blt);
    }
}

void initRockets(rocket_list *rl)
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

void initMines(mine_list *ml)
{
    for (int m = 0; m < sizeMines(ml); ++m)
    {
        mine_item mi = createMineItem();
        // setting initial properties:
        setMineID(mi, MINE_ID);
        setMinePosX(mi, 0);
        setMinePosY(mi, 0);
        setMineLive(mi, false);
        setMineSpeed(mi, 2);
        setMineBoundX(mi, 6);
        setMineBoundY(mi, 6);

        push_mine(ml, mi);
    }
}

void initLaser(laser_beam *laser)
{
    setLaserBeamID(laser, LASER_ID);
    setLaserBeamLive(laser, false);
    setLaserBeamPosX(laser, 0);
    setLaserBeamPosY(laser, 0);
    setLaserBeamBoundX(laser, 350);
    setLaserBeamBoundY(laser, 1);
}

void drawBullets(bullet_list *bl)
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

void drawRockets(rocket_list *rl)
{
    for (int r = 0; r < countRockets(rl); ++r)
    {
        if (rocketLive(rocket_at(rl, r)))
        {
            al_draw_filled_rectangle(rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r)) - 2,
                                     rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r)) + 1,
                                     rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r)) - 2,
                                     rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r)) - 1,
                                     al_map_rgb(255, 153, 51));
            al_draw_filled_rectangle(rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r)),
                                     rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r)),
                                     rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r)),
                                     rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r)),
                                     al_map_rgb(209, 224, 224));
            al_draw_filled_circle(rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r)),
                                  rocketPosY(rocket_at(rl, r)), rocketBoundY(rocket_at(rl, r)), al_map_rgb(255, 0, 0));
        }
    }
}

void drawMines(mine_list *ml)
{
    for (int m = 0; m < countMines(ml); ++m)
    {
        if (mineLive(mine_at(ml, m)))
        {
            al_draw_filled_circle(minePosX(mine_at(ml, m)), minePosY(mine_at(ml, m)), mineBoundY(mine_at(ml, m)),
                                  al_map_rgb(194, 194, 163));
            if (random() % 2)
            {
                al_draw_filled_circle(minePosX(mine_at(ml, m)), minePosY(mine_at(ml, m)),
                                      mineBoundY(mine_at(ml, m)) - 3, al_map_rgb(204, 0, 0));
            }
            else
            {
                al_draw_filled_circle(minePosX(mine_at(ml, m)), minePosY(mine_at(ml, m)),
                                      mineBoundY(mine_at(ml, m)) - 3, al_map_rgb(255, 255, 0));
            }
        }
    }
}

void drawLaser(laser_beam *laser)
{
    if (laserBeamLive(laser))
    {
        al_draw_filled_circle(laserBeamPosX(laser), laserBeamPosY(laser), 2.5, al_map_rgb(244, 107, 66));
        al_draw_line(laserBeamPosX(laser), laserBeamPosY(laser), laserBeamPosX(laser) + laserBeamBoundX(laser),
                     laserBeamPosY(laser), al_map_rgb(244, 107, 66), 2.0);
    }
}

void updatePrimaryWeapons(bullet_list *bl, spaceship *ship, struct screen_setting **settings)
{
    enum ship_weapons_primary weapon = switchPrimaryWeapon(ship);
    int projectilePerCannon = 0;

    switch (weapon)
    {
    case ONE_CANNON:
    case DOUBLE_CANNON:
        for (int b = 0; b < countBullets(bl); ++b)
        {
            if (bulletLive(bullet_at(bl, b)))
            {
                setBulletPosX(bullet_at(bl, b), (bulletPosX(bullet_at(bl, b)) + bulletSpeed(bullet_at(bl, b))));
                if (bulletPosX(bullet_at(bl, b)) > screenWidth(settings))
                {
                    setBulletLive(bullet_at(bl, b), false);
                }
            }
        }
        break;
    case SHOTGUN:
        projectilePerCannon = 10;
        for (int b = 0; b < projectilePerCannon; ++b)
        {
            if (bulletLive(bullet_at(bl, b)))
            {
                setBulletPosX(bullet_at(bl, b), (bulletPosX(bullet_at(bl, b)) + bulletSpeed(bullet_at(bl, b))));
                setBulletPosY(bullet_at(bl, b), (bulletPosY(bullet_at(bl, b)) - bulletSpeed(bullet_at(bl, b)) / 2));

                if (bulletPosX(bullet_at(bl, b)) > screenWidth(settings))
                {
                    setBulletLive(bullet_at(bl, b), false);
                }
                if (bulletPosY(bullet_at(bl, b)) > screenHeight(settings))
                {
                    setBulletLive(bullet_at(bl, b), false);
                }
            }
        }

        for (int b = 0; b < projectilePerCannon; ++b)
        {
            if (bulletLive(bullet_at(bl, projectilePerCannon + b)))
            {
                setBulletPosX(bullet_at(bl, projectilePerCannon + b),
                              (bulletPosX(bullet_at(bl, projectilePerCannon + b)) +
                               bulletSpeed(bullet_at(bl, projectilePerCannon + b))));

                if (bulletPosX(bullet_at(bl, projectilePerCannon + b)) > screenWidth(settings))
                {
                    setBulletLive(bullet_at(bl, projectilePerCannon + b), false);
                }
            }
        }

        for (int b = 0; b < projectilePerCannon; ++b)
        {
            if (bulletLive(bullet_at(bl, 2 * projectilePerCannon + b)))
            {

                setBulletPosX(bullet_at(bl, 2 * projectilePerCannon + b),
                              (bulletPosX(bullet_at(bl, 2 * projectilePerCannon + b)) +
                               bulletSpeed(bullet_at(bl, 2 * projectilePerCannon + b))));
                setBulletPosY(bullet_at(bl, 2 * projectilePerCannon + b),
                              (bulletPosY(bullet_at(bl, 2 * projectilePerCannon + b)) +
                               bulletSpeed(bullet_at(bl, 2 * projectilePerCannon + b)) / 2));

                if (bulletPosX(bullet_at(bl, 2 * projectilePerCannon + b)) > screenWidth(settings))
                {
                    setBulletLive(bullet_at(bl, 2 * projectilePerCannon + b), false);
                }
                if (bulletPosY(bullet_at(bl, 2 * projectilePerCannon + b)) < 0)
                {
                    setBulletLive(bullet_at(bl, 2 * projectilePerCannon + b), false);
                }
            }
        }
        break;
    }
}

void updateSecondaryWeapons(rocket_list *rl, mine_list *ml, laser_beam *laser, spaceship *ship,
                            struct screen_setting **settings)
{
    // For updating rockets:
    for (int b = 0; b < countRockets(rl); ++b)
    {
        if (rocketLive(rocket_at(rl, b)))
        {
            setRocketPosX(rocket_at(rl, b), (rocketPosX(rocket_at(rl, b)) + rocketSpeed(rocket_at(rl, b))));
            if (rocketPosX(rocket_at(rl, b)) > screenWidth(settings))
            {
                setRocketLive(rocket_at(rl, b), false);
            }
        }
    }
    // For updating mines:
    for (int m = 0; m < countMines(ml); ++m)
    {
        if (mineLive(mine_at(ml, m)))
        {
            setMinePosX(mine_at(ml, m), (minePosX(mine_at(ml, m)) - mineSpeed(mine_at(ml, m))));
            if (minePosX(mine_at(ml, m)) < 0)
            {
                setMineLive(mine_at(ml, m), false);
            }
        }
    }

    if (laserBeamLive(laser))
    {
        setLaserBeamPosX(laser, spaceshipPosX(ship) + 17);
        setLaserBeamPosY(laser, spaceshipPosY(ship) + 1);
    }
}

void switchPrimaryWeapons(spaceship *ship)
{

    unsigned int level = static_cast<unsigned int>((*ship)->switchPrimaryWeapon);
    level++;
    (*ship)->switchPrimaryWeapon = static_cast<ship_weapons_primary>(level);
    if ((*ship)->switchPrimaryWeapon > (*ship)->primaryWeaponLevel)
    {
        (*ship)->switchPrimaryWeapon = ship_weapons_primary::ONE_CANNON;
    }
}

void switchSecondaryWeapons(spaceship *ship)
{
    unsigned int level = static_cast<unsigned int>((*ship)->switchSecondaryWeapon);
    level++;
    (*ship)->switchSecondaryWeapon = static_cast<ship_weapons_secondary>(level);
    if ((*ship)->switchSecondaryWeapon > (*ship)->secondaryWeaponLevel)
    {
        (*ship)->switchSecondaryWeapon = ship_weapons_secondary::ROCKET;
    }
}

void firePrimaryWeapon(bullet_list *bl, spaceship *ship)
{
    enum ship_weapons_primary weapon = switchPrimaryWeapon(ship);
    int projectilePerCannon = 0;

    switch (weapon)
    {
    case ONE_CANNON:
        projectilePerCannon = 10;
        for (int i = 0; i < projectilePerCannon; ++i)
        {
            if (!bulletLive(bullet_at(bl, i)))
            {
                setBulletPosX(bullet_at(bl, i), ((*ship)->posx + 17));
                setBulletPosY(bullet_at(bl, i), ((*ship)->posy));
                setBulletLive(bullet_at(bl, i), true);
                break;
            }
        }
        break;
    case DOUBLE_CANNON:
        projectilePerCannon = 10;
        for (int i = 0; i < projectilePerCannon; ++i)
        {
            if (!bulletLive(bullet_at(bl, i)))
            {
                setBulletPosX(bullet_at(bl, i), ((*ship)->posx + 17));
                setBulletPosY(bullet_at(bl, i), ((*ship)->posy + 15));
                setBulletLive(bullet_at(bl, i), true);

                setBulletPosX(bullet_at(bl, projectilePerCannon + i), ((*ship)->posx + 17));
                setBulletPosY(bullet_at(bl, projectilePerCannon + i), ((*ship)->posy - 15));
                setBulletLive(bullet_at(bl, projectilePerCannon + i), true);
                break;
            }
        }
        break;
    case SHOTGUN:
        projectilePerCannon = 10;
        for (int i = 0; i < projectilePerCannon; ++i)
        {
            if (!bulletLive(bullet_at(bl, i)))
            {
                setBulletPosX(bullet_at(bl, i), ((*ship)->posx + 17));
                setBulletPosY(bullet_at(bl, i), ((*ship)->posy - 15));
                setBulletLive(bullet_at(bl, i), true);

                setBulletPosX(bullet_at(bl, projectilePerCannon + i), ((*ship)->posx + 17));
                setBulletPosY(bullet_at(bl, projectilePerCannon + i), ((*ship)->posy));
                setBulletLive(bullet_at(bl, projectilePerCannon + i), true);

                setBulletPosX(bullet_at(bl, 2 * projectilePerCannon + i), ((*ship)->posx + 17));
                setBulletPosY(bullet_at(bl, 2 * projectilePerCannon + i), ((*ship)->posy + 15));
                setBulletLive(bullet_at(bl, 2 * projectilePerCannon + i), true);
                break;
            }
        }
        break;
    }
}

void fireSecondaryWeapon(rocket_list *rl, mine_list *ml, laser_beam *laser, spaceship *ship)
{
    enum ship_weapons_secondary weapon = switchSecondaryWeapon(ship);
    int projectilePerCannon = 0;

    switch (weapon)
    {
    case ROCKET:
        projectilePerCannon = 2;
        for (int i = 0; i < projectilePerCannon; ++i)
        {
            if (!rocketLive(rocket_at(rl, i)))
            {
                setRocketPosX(rocket_at(rl, i), spaceshipPosX(ship) + 17);
                setRocketPosY(rocket_at(rl, i), ((*ship)->posy));
                setRocketLive(rocket_at(rl, i), true);
                break;
            }
        }
        break;
    case ROCKETS:
        projectilePerCannon = 4;
        for (int i = 0; i < projectilePerCannon; ++i)
        {
            if (!rocketLive(rocket_at(rl, i)))
            {
                setRocketPosX(rocket_at(rl, i), ((*ship)->posx + 17));
                setRocketPosY(rocket_at(rl, i), ((*ship)->posy));
                setRocketLive(rocket_at(rl, i), true);
                break;
            }
        }
        break;
    case MINE:
        projectilePerCannon = 3;
        for (int i = 0; i < projectilePerCannon; ++i)
        {
            if (!mineLive(mine_at(ml, i)))
            {
                setMinePosX(mine_at(ml, i), spaceshipPosX(ship) + 7);
                setMinePosY(mine_at(ml, i), spaceshipPosY(ship));
                setMineLive(mine_at(ml, i), true);

                break;
            }
        }
        break;
    case LASER:
        if (!laserBeamLive(laser))
        {
            setLaserBeamPosX(laser, spaceshipPosX(ship) + 17);
            setLaserBeamPosY(laser, spaceshipPosY(ship) + 1);
            setLaserBeamLive(laser, true);
        }
        break;
    }
}

void ceaseFireSecondaryWeapon(laser_beam *laser)
{
    setLaserBeamLive(laser, false);
}
