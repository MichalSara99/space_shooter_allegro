#include "collisions.hpp"

//-----------------------------------------------------------------------------------------------------------
//============================================ COMETS COLLISION =============================================
//-----------------------------------------------------------------------------------------------------------

void cometsSpaceshipBulletsCollision(comet_list *cl, bullet_list *bl, spaceship *ship)
{
    for (int b = 0; b < countBullets(bl); ++b)
    {
        if (bulletLive(bullet_at(bl, b)))
        {
            for (int c = 0; c < countComets(cl); ++c)
            {
                if (cometLives(comet_at(cl, c)) > 0)
                {

                    // if the bullet finds itself inside the bounderies of comet then hit happened
                    if (bulletPosX(bullet_at(bl, b)) > (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) &&
                        bulletPosX(bullet_at(bl, b)) < (cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) &&
                        bulletPosY(bullet_at(bl, b)) < (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))) &&
                        bulletPosY(bullet_at(bl, b)) > (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))))
                    {

                        setBulletLive(bullet_at(bl, b), false);
                        setCometLives(comet_at(cl, c), cometLives(comet_at(cl, c)) - 1);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

void cometsSpaceshipCollision(comet_list *cl, spaceship *ship, struct screen_setting **settings)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) > 0)
        {

            if ((cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) <
                    (spaceshipPosX(ship) + spaceshipBoundx(ship)) &&
                (cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) >
                    (spaceshipPosX(ship) - spaceshipBoundx(ship)) &&
                (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))) <
                    (spaceshipPosY(ship) + spaceshipBoundy(ship)) &&
                (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))) >
                    (spaceshipPosY(ship) - spaceshipBoundy(ship)))
            {

                setCometLives(comet_at(cl, c), 0);
                setSpaceshipLives(ship, spaceshipLives(ship) - 1);

                // additional game logic goes here: losing score,losing armory of ship,losing live of ship,etc...
                setSpaceshipInitPosition(ship, settings);
                setSpaceshipRebornCounter(ship, 10);
            }
            else if (cometPosX(comet_at(cl, c)) < 0)
            {
                setCometLives(comet_at(cl, c), 0);
                // Do u want a spaceship to lose a live when u miss a comet?
                // setSpaceshipLives(ship, spaceshipLives(ship) - 1);
            }
        }
    }
}

void cometsSpaceshipRocketsCollision(comet_list *cl, rocket_list *rl, spaceship *ship)
{
    for (int r = 0; r < countRockets(rl); ++r)
    {
        if (rocketLive(rocket_at(rl, r)))
        {
            for (int c = 0; c < countComets(cl); ++c)
            {
                if (cometLives(comet_at(cl, c)) > 0)
                {

                    // if the bullet finds itself inside the bounderies of comet then hit happened
                    if ((rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r))) >
                            (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) &&
                        (rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r))) <
                            (cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) &&
                        (rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r))) <
                            (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))) &&
                        (rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r))) >
                            (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))))
                    {

                        setRocketLive(rocket_at(rl, r), false);
                        setCometLives(comet_at(cl, c), 0);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

void cometsSpaceshipMinesCollision(comet_list *cl, mine_list *ml, spaceship *ship)
{
    for (int m = 0; m < countMines(ml); ++m)
    {
        if (mineLive(mine_at(ml, m)))
        {
            for (int c = 0; c < countComets(cl); ++c)
            {
                if (cometLives(comet_at(cl, c)) > 0)
                {

                    // if the bullet finds itself inside the bounderies of comet then hit happened
                    if ((minePosX(mine_at(ml, m)) + mineBoundX(mine_at(ml, m))) >
                            (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) &&
                        (minePosX(mine_at(ml, m)) - mineBoundX(mine_at(ml, m))) <
                            (cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) &&
                        (minePosY(mine_at(ml, m)) - mineBoundY(mine_at(ml, m))) <
                            (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))) &&
                        (minePosY(mine_at(ml, m)) + mineBoundY(mine_at(ml, m))) >
                            (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))))
                    {

                        setMineLive(mine_at(ml, m), false);
                        setCometLives(comet_at(cl, c), 0);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

void cometsSpaceshipLaserCollision(comet_list *cl, laser_beam *laser, spaceship *ship)
{
    if (laserBeamLive(laser))
    {
        for (int c = 0; c < countComets(cl); ++c)
        {
            if (cometLives(comet_at(cl, c)) > 0)
            {

                // if the bullet finds itself inside the bounderies of comet then hit happened
                if ((laserBeamPosX(laser) + laserBeamBoundX(laser)) >
                        (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) &&
                    (laserBeamPosX(laser) - laserBeamBoundX(laser)) <
                        (cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) &&
                    (laserBeamPosY(laser) - laserBeamBoundY(laser)) <
                        (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))) &&
                    (laserBeamPosY(laser) + laserBeamBoundY(laser)) >
                        (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))))
                {

                    setCometLives(comet_at(cl, c), 0);
                    setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                }
            }
        }
    }
}

void cometsAkiramBossCollision(comet_list *cl, akiramBoss *boss)
{
    if (akiramBossIsAlive(boss))
    {
        for (int c = 0; c < countComets(cl); ++c)
        {
            if (cometLives(comet_at(cl, c)) > 0)
            {

                if ((cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) >
                        (akiramBossPosX(boss) - akiramBossBoundx(boss)) &&
                    (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) <
                        (akiramBossPosX(boss) + akiramBossBoundx(boss)) &&
                    (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))) >
                        (akiramBossPosY(boss) - akiramBossBoundy(boss)) &&
                    (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))) <
                        (akiramBossPosY(boss) + akiramBossBoundy(boss)))
                {

                    setCometLives(comet_at(cl, c), cometLives(comet_at(cl, c)) - 1);
                }
            }
        }
    }
}

void cometsFightersBulletsCollision(comet_list *cl, bullet_list *fighterBullets)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) > 0)
        {
            for (int b = 0; b < countBullets(fighterBullets); ++b)
            {
                if (bulletLive(bullet_at(fighterBullets, b)))
                {

                    if (bulletPosX(bullet_at(fighterBullets, b)) >
                            (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) &&
                        bulletPosX(bullet_at(fighterBullets, b)) <
                            (cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) &&
                        bulletPosY(bullet_at(fighterBullets, b)) >
                            (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))) &&
                        bulletPosY(bullet_at(fighterBullets, b)) <
                            (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))))
                    {

                        setCometLives(comet_at(cl, c), cometLives(comet_at(cl, c)) - 1);
                        setBulletLive(bullet_at(fighterBullets, b), false);
                    }
                }
            }
        }
    }
}

void cometsTurretsBulletsCollision(comet_list *cl, bullet_list *turretsBullets)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) > 0)
        {
            for (int b = 0; b < countBullets(turretsBullets); ++b)
            {
                if (bulletLive(bullet_at(turretsBullets, b)))
                {

                    if (bulletPosX(bullet_at(turretsBullets, b)) >
                            (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) &&
                        bulletPosX(bullet_at(turretsBullets, b)) <
                            (cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) &&
                        bulletPosY(bullet_at(turretsBullets, b)) >
                            (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))) &&
                        bulletPosY(bullet_at(turretsBullets, b)) <
                            (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))))
                    {

                        setCometLives(comet_at(cl, c), cometLives(comet_at(cl, c)) - 1);
                        setBulletLive(bullet_at(turretsBullets, b), false);
                    }
                }
            }
        }
    }
}

void cometsAkiramBossRockets(comet_list *cl, rocket_list *akiramRockets)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) > 0)
        {
            for (int r = 0; r < countRockets(akiramRockets); ++r)
            {
                if (rocketLive(rocket_at(akiramRockets, r)))
                {

                    if ((rocketPosX(rocket_at(akiramRockets, r)) + rocketBoundX(rocket_at(akiramRockets, r))) >
                            (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) &&
                        (rocketPosX(rocket_at(akiramRockets, r)) - rocketBoundX(rocket_at(akiramRockets, r))) <
                            (cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) &&
                        (rocketPosY(rocket_at(akiramRockets, r)) + rocketBoundY(rocket_at(akiramRockets, r))) >
                            (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))) &&
                        (rocketPosY(rocket_at(akiramRockets, r)) - rocketBoundY(rocket_at(akiramRockets, r))) <
                            (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))))
                    {

                        setCometLives(comet_at(cl, c), cometLives(comet_at(cl, c)) - 1);
                        setRocketLive(rocket_at(akiramRockets, r), false);
                    }
                }
            }
        }
    }
}

void cometsFightersCollision(comet_list *cl, fighter_list *fl)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) > 0)
        {
            for (int f = 0; f < countFighters(fl); ++f)
            {
                if (fighterLives(fighter_at(fl, f)) > 0)
                {

                    if ((cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) >
                            (fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) &&
                        (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) <
                            (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) &&
                        (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))) >
                            (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) &&
                        (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))) <
                            (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))))
                    {

                        setCometLives(comet_at(cl, c), 0);
                        setFighterLives(fighter_at(fl, f), fighterLives(fighter_at(fl, f) - 1));
                    }
                }
            }
        }
    }
}

void cometsTurretsCollision(comet_list *cl, turret_list *tl)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) > 0)
        {
            for (int t = 0; t < countTurrets(tl); ++t)
            {
                if (turretLives(turret_at(tl, t)) > 0)
                {

                    if ((cometPosX(comet_at(cl, c)) + cometBoundX(comet_at(cl, c))) >
                            (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t))) &&
                        (cometPosX(comet_at(cl, c)) - cometBoundX(comet_at(cl, c))) <
                            (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t))) &&
                        (cometPosY(comet_at(cl, c)) + cometBoundY(comet_at(cl, c))) >
                            (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t))) &&
                        (cometPosY(comet_at(cl, c)) - cometBoundY(comet_at(cl, c))) <
                            (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t))))
                    {

                        setCometLives(comet_at(cl, c), cometLives(comet_at(cl, c)) - 1);
                        setTurretLives(turret_at(tl, t), turretLives(turret_at(tl, t) - 1));
                    }
                }
            }
        }
    }
}

//------------------------------------------------------------------------------------------------------------
//============================================ TURRETS COLLISION =============================================
//------------------------------------------------------------------------------------------------------------

void turretsSpaceshipCollision(turret_list *tl, spaceship *ship, struct screen_setting **settings)
{
    for (int t = 0; t < countTurrets(tl); ++t)
    {
        if (turretLives(turret_at(tl, t)) > 0)
        {

            if ((turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t)) <
                 spaceshipPosX(ship) + spaceshipBoundx(ship)) &&
                (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t)) >
                 spaceshipPosX(ship) - spaceshipBoundx(ship)) &&
                (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t)) <
                 spaceshipPosY(ship) + spaceshipBoundy(ship)) &&
                (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t)) >
                 spaceshipPosY(ship) - spaceshipBoundy(ship)))
            {

                setTurretLives(turret_at(tl, t), 0);
                setSpaceshipLives(ship, spaceshipLives(ship) - 1);
                setSpaceshipInitPosition(ship, settings);
                setSpaceshipRebornCounter(ship, 10);
            }
            else if (turretPosX(turret_at(tl, t)) < 0)
            {
                setTurretLives(turret_at(tl, t), 0);
                // Do u want a spaceship to lose a live when u miss a turret?
                // setSpaceshipLives(ship, spaceshipLives(ship) - 1);
            }
        }
    }
}

void turretsSpaceshipBulletCollision(turret_list *tl, bullet_list *shipBullets, spaceship *ship)
{
    for (int b = 0; b < countBullets(shipBullets); ++b)
    {
        if (bulletLive(bullet_at(shipBullets, b)))
        {

            for (int t = 0; t < countTurrets(tl); ++t)
            {
                if (turretLives(turret_at(tl, t)) > 0)
                {

                    if (bulletPosX(bullet_at(shipBullets, b)) >
                            (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t))) &&
                        bulletPosX(bullet_at(shipBullets, b)) <
                            (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t))) &&
                        bulletPosY(bullet_at(shipBullets, b)) >
                            (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t))) &&
                        bulletPosY(bullet_at(shipBullets, b)) <
                            (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t))))
                    {

                        setBulletLive(bullet_at(shipBullets, b), false);
                        setTurretLives(turret_at(tl, t), turretLives(turret_at(tl, t)) - 1);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);
                    }
                }
            }
        }
    }
}

void turretsBulletSpaceshipCollision(bullet_list *turretBullets, spaceship *ship, struct screen_setting **setting)
{
    for (int b = 0; b < countBullets(turretBullets); ++b)
    {
        if (bulletLive(bullet_at(turretBullets, b)))
        {
            if (spaceshipLives(ship) > 0)
            {

                if (bulletPosX(bullet_at(turretBullets, b)) > (spaceshipPosX(ship) - spaceshipBoundx(ship)) &&
                    bulletPosX(bullet_at(turretBullets, b)) < (spaceshipPosX(ship) + spaceshipBoundx(ship)) &&
                    bulletPosY(bullet_at(turretBullets, b)) > (spaceshipPosY(ship) - spaceshipBoundy(ship)) &&
                    bulletPosY(bullet_at(turretBullets, b)) < (spaceshipPosY(ship) + spaceshipBoundy(ship)))
                {

                    setBulletLive(bullet_at(turretBullets, b), false);
                    setSpaceshipLives(ship, spaceshipLives(ship) - 1);
                    setSpaceshipInitPosition(ship, setting);
                    setSpaceshipRebornCounter(ship, 10);
                }
            }
        }
    }
}

void turretsSpaceshipRocketsCollision(turret_list *tl, rocket_list *rl, spaceship *ship)
{
    for (int r = 0; r < countRockets(rl); ++r)
    {
        if (rocketLive(rocket_at(rl, r)))
        {

            for (int t = 0; t < countTurrets(tl); ++t)
            {
                if (turretLives(turret_at(tl, t)) > 0)
                {

                    if ((rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r))) >
                            (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t))) &&
                        (rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r))) <
                            (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t))) &&
                        (rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r))) >
                            (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t))) &&
                        (rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r))) <
                            (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t))))
                    {

                        setRocketLive(rocket_at(rl, r), false);
                        setTurretLives(turret_at(tl, t), 0);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);
                    }
                }
            }
        }
    }
}

void turretsSpaceshipMinesCollision(turret_list *tl, mine_list *ml, spaceship *ship)
{
    for (int m = 0; m < countMines(ml); ++m)
    {
        if (mineLive(mine_at(ml, m)))
        {

            for (int t = 0; t < countTurrets(tl); ++t)
            {
                if (turretLives(turret_at(tl, t)) > 0)
                {

                    if ((minePosX(mine_at(ml, m)) + mineBoundX(mine_at(ml, m))) >
                            (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t))) &&
                        (minePosX(mine_at(ml, m)) - mineBoundX(mine_at(ml, m))) <
                            (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t))) &&
                        (minePosY(mine_at(ml, m)) + mineBoundY(mine_at(ml, m))) >
                            (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t))) &&
                        (minePosY(mine_at(ml, m)) - mineBoundY(mine_at(ml, m))) <
                            (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t))))
                    {

                        setMineLive(mine_at(ml, m), false);
                        setTurretLives(turret_at(tl, t), 0);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);
                    }
                }
            }
        }
    }
}

void turretsSpaceshipLaserCollision(turret_list *tl, laser_beam *laser, spaceship *ship)
{
    if (laserBeamLive(laser))
    {
        for (int t = 0; t < countTurrets(tl); ++t)
        {
            if (turretLives(turret_at(tl, t)) > 0)
            {

                if ((laserBeamPosX(laser) + laserBeamBoundX(laser)) >
                        (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t))) &&
                    (laserBeamPosX(laser) - laserBeamBoundX(laser)) <
                        (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t))) &&
                    (laserBeamPosY(laser) + laserBeamBoundY(laser)) >
                        (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t))) &&
                    (laserBeamPosY(laser) - laserBeamBoundY(laser)) <
                        (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t))))
                {

                    setTurretLives(turret_at(tl, t), 0);
                    setSpaceshipScore(ship, spaceshipScore(ship) + 1);
                }
            }
        }
    }
}

void turretsAkiramBossCollision(turret_list *tl, akiramBoss *boss)
{
    if (akiramBossIsAlive(boss))
    {
        for (int t = 0; t < countTurrets(tl); ++t)
        {
            if (turretLives(turret_at(tl, t)) > 0)
            {
                if ((akiramBossPosX(boss) + akiramBossBoundx(boss)) >
                        (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t))) &&
                    (akiramBossPosX(boss) - akiramBossBoundx(boss)) <
                        (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t))) &&
                    (akiramBossPosY(boss) + akiramBossBoundy(boss)) >
                        (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t))) &&
                    (akiramBossPosY(boss) - akiramBossBoundy(boss)) <
                        (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t))))
                {

                    setTurretLives(turret_at(tl, t), 0);
                    setAkiramBossLives(boss, akiramBossLives(boss) - 1);
                }
            }
        }
    }
}

void turretsFightersBulletsCollision(turret_list *tl, bullet_list *fighterBullets)
{
    for (int b = 0; b < countBullets(fighterBullets); ++b)
    {
        if (bulletLive(bullet_at(fighterBullets, b)))
        {
            for (int t = 0; t < countTurrets(tl); ++t)
            {
                if (turretLives(turret_at(tl, t)) > 0)
                {

                    if ((bulletPosX(bullet_at(fighterBullets, b))) >
                            (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t))) &&
                        (bulletPosX(bullet_at(fighterBullets, b))) <
                            (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t))) &&
                        (bulletPosY(bullet_at(fighterBullets, b))) >
                            (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t))) &&
                        (bulletPosY(bullet_at(fighterBullets, b))) <
                            (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t))))
                    {

                        setBulletLive(bullet_at(fighterBullets, b), false);
                        setTurretLives(turret_at(tl, t), turretLives(turret_at(tl, t)) - 1);
                    }
                }
            }
        }
    }
}

void turretsAkiramBossRocketsCollision(turret_list *tl, rocket_list *akiramBossRockets)
{
    for (int t = 0; t < countTurrets(tl); ++t)
    {
        if (turretLives(turret_at(tl, t)) > 0)
        {
            for (int r = 0; r < countRockets(akiramBossRockets); ++r)
            {
                if (rocketLive(rocket_at(akiramBossRockets, r)))
                {

                    if (((rocketPosX(rocket_at(akiramBossRockets, r)) - rocketBoundX(rocket_at(akiramBossRockets, r))) <
                         (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t)))) &&
                        ((rocketPosX(rocket_at(akiramBossRockets, r)) + rocketBoundX(rocket_at(akiramBossRockets, r))) >
                         (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t)))) &&
                        ((rocketPosY(rocket_at(akiramBossRockets, r)) - rocketBoundY(rocket_at(akiramBossRockets, r))) <
                         (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t)))) &&
                        ((rocketPosY(rocket_at(akiramBossRockets, r)) + rocketBoundY(rocket_at(akiramBossRockets, r))) >
                         (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t)))))
                    {

                        setRocketLive(rocket_at(akiramBossRockets, r), false);
                        setTurretLives(turret_at(tl, t), 0);
                    }
                }
            }
        }
    }
}

void turretsFightersCollision(turret_list *tl, fighter_list *fl)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {
            for (int t = 0; t < countTurrets(tl); ++t)
            {
                if (turretLives(turret_at(tl, t)) > 0)
                {

                    if (((fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) <
                         (turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t)))) &&
                        ((fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) >
                         (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t)))) &&
                        ((fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) <
                         (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t)))) &&
                        ((fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))) >
                         (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t)))))
                    {

                        setFighterLives(fighter_at(fl, f), 0);
                        setTurretLives(turret_at(tl, t), 0);
                    }
                }
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------
//============================================ FIGHTERS COLLISION =============================================
//-------------------------------------------------------------------------------------------------------------

void fightersSpaceshipCollision(fighter_list *fl, spaceship *ship)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {

            if ((fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f)) <
                 spaceshipPosX(ship) + spaceshipBoundx(ship)) &&
                (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f)) >
                 spaceshipPosX(ship) - spaceshipBoundx(ship)) &&
                (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f)) <
                 spaceshipPosY(ship) + spaceshipBoundy(ship)) &&
                (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f)) >
                 spaceshipPosY(ship) - spaceshipBoundy(ship)))
            {

                setFighterLives(fighter_at(fl, f), 0);
                setSpaceshipLives(ship, spaceshipLives(ship) - 1);
            }
            else if (fighterPosX(fighter_at(fl, f)) < 0)
            {
                setFighterLives(fighter_at(fl, f), 0);
                // Do u want a spaceship to lose a live when u miss a fighter?
                // setSpaceshipLives(ship, spaceshipLives(ship) - 1);
            }
        }
    }
}

void fightersBulletSpaceshipCollision(bullet_list *fighterBullets, spaceship *ship)
{
    for (int b = 0; b < countBullets(fighterBullets); ++b)
    {
        if (bulletLive(bullet_at(fighterBullets, b)))
        {
            if (spaceshipLives(ship) > 0)
            {

                if (bulletPosX(bullet_at(fighterBullets, b)) > (spaceshipPosX(ship) - spaceshipBoundx(ship)) &&
                    bulletPosX(bullet_at(fighterBullets, b)) < (spaceshipPosX(ship) + spaceshipBoundx(ship)) &&
                    bulletPosY(bullet_at(fighterBullets, b)) > (spaceshipPosY(ship) - spaceshipBoundy(ship)) &&
                    bulletPosY(bullet_at(fighterBullets, b)) < (spaceshipPosY(ship) + spaceshipBoundy(ship)))
                {

                    setBulletLive(bullet_at(fighterBullets, b), false);
                    setSpaceshipLives(ship, spaceshipLives(ship) - 1);
                }
            }
        }
    }
}

void fightersSpaceshipBulletCollision(fighter_list *fl, bullet_list *shipBullets, spaceship *ship)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {
            for (int b = 0; b < countBullets(shipBullets); ++b)
            {
                if (bulletLive(bullet_at(shipBullets, b)))
                {

                    if (bulletPosX(bullet_at(shipBullets, b)) >
                            (fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) &&
                        bulletPosX(bullet_at(shipBullets, b)) <
                            (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) &&
                        bulletPosY(bullet_at(shipBullets, b)) >
                            (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) &&
                        bulletPosY(bullet_at(shipBullets, b)) <
                            (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))))
                    {

                        setBulletLive(bullet_at(shipBullets, b), false);
                        setFighterLives(fighter_at(fl, f), fighterLives(fighter_at(fl, f)) - 1);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

void fightersSpaceshipRocketsCollision(fighter_list *fl, rocket_list *rl, spaceship *ship)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {
            for (int r = 0; r < countRockets(rl); ++r)
            {
                if (rocketLive(rocket_at(rl, r)))
                {

                    if ((rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r))) >
                            (fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) &&
                        (rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r))) <
                            (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) &&
                        (rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r))) >
                            (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) &&
                        (rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r))) <
                            (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))))
                    {

                        setRocketLive(rocket_at(rl, r), false);
                        setFighterLives(fighter_at(fl, f), 0);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

void fightersSpaceshipMinesCollision(fighter_list *fl, mine_list *ml, spaceship *ship)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {
            for (int m = 0; m < countMines(ml); ++m)
            {
                if (mineLive(mine_at(ml, m)))
                {

                    if ((minePosX(mine_at(ml, m)) + mineBoundX(mine_at(ml, m))) >
                            (fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) &&
                        (minePosX(mine_at(ml, m)) - mineBoundX(mine_at(ml, m))) <
                            (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) &&
                        (minePosY(mine_at(ml, m)) + mineBoundY(mine_at(ml, m))) >
                            (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) &&
                        (minePosY(mine_at(ml, m)) - mineBoundY(mine_at(ml, m))) <
                            (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))))
                    {

                        setMineLive(mine_at(ml, m), false);
                        setFighterLives(fighter_at(fl, f), 0);
                        setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

void fightersSpaceshipLaserCollision(fighter_list *fl, laser_beam *laser, spaceship *ship)
{
    if (laserBeamLive(laser))
    {
        for (int f = 0; f < countFighters(fl); ++f)
        {
            if (fighterLives(fighter_at(fl, f)) > 0)
            {
                if ((laserBeamPosX(laser) + laserBeamBoundX(laser)) >
                        (fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) &&
                    (laserBeamPosX(laser) - laserBeamBoundX(laser)) <
                        (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) &&
                    (laserBeamPosY(laser) + laserBeamBoundY(laser)) >
                        (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) &&
                    (laserBeamPosY(laser) - laserBeamBoundY(laser)) <
                        (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))))
                {

                    setFighterLives(fighter_at(fl, f), 0);
                    setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                }
            }
        }
    }
}

void fightersAkiramBossCollision(fighter_list *fl, akiramBoss *boss)
{
    if (akiramBossLives(boss) > 0)
    {
        for (int f = 0; f < countFighters(fl); ++f)
        {
            if (fighterLives(fighter_at(fl, f)) > 0)
            {

                if (((fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) >
                     (akiramBossPosX(boss) - akiramBossBoundx(boss))) &&
                    ((fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) <
                     (akiramBossPosX(boss) + akiramBossBoundx(boss))) &&
                    ((fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))) >
                     (akiramBossPosY(boss) - akiramBossBoundy(boss))) &&
                    ((fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) <
                     (akiramBossPosY(boss) + akiramBossBoundy(boss))))
                {

                    setFighterLives(fighter_at(fl, f), 0);
                }
            }
        }
    }
}

void fightersTurretsCollsion(fighter_list *fl, turret_list *tl)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {
            for (int t = 0; t < countTurrets(tl); ++t)
            {
                if (turretLives(turret_at(tl, t)) > 0)
                {

                    if ((turretPosX(turret_at(tl, t)) + turretBoundX(turret_at(tl, t))) >
                            (fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) &&
                        (turretPosX(turret_at(tl, t)) - turretBoundX(turret_at(tl, t))) <
                            (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) &&
                        (turretPosY(turret_at(tl, t)) + turretBoundY(turret_at(tl, t))) >
                            (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) &&
                        (turretPosY(turret_at(tl, t)) - turretBoundY(turret_at(tl, t))) <
                            (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))))
                    {

                        setFighterLives(fighter_at(fl, f), 0);
                        setTurretLives(turret_at(tl, t), 0);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

void fightersTurretsBulletsCollision(fighter_list *fl, bullet_list *turretsBullets)
{
    for (int b = 0; b < countBullets(turretsBullets); ++b)
    {
        if (bulletLive(bullet_at(turretsBullets, b)))
        {
            for (int f = 0; f < countFighters(fl); ++f)
            {
                if (fighterLives(fighter_at(fl, f)) > 0)
                {

                    if ((bulletPosX(bullet_at(turretsBullets, b))) >
                            (fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) &&
                        (bulletPosX(bullet_at(turretsBullets, b))) <
                            (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) &&
                        (bulletPosY(bullet_at(turretsBullets, b))) >
                            (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) &&
                        (bulletPosY(bullet_at(turretsBullets, b))) <
                            (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))))
                    {

                        setBulletLive(bullet_at(turretsBullets, b), false);
                        setFighterLives(fighter_at(fl, f), fighterLives(fighter_at(fl, f)) - 1);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

void fightersAkiramBossRocketsCollision(fighter_list *fl, rocket_list *akiramBossRockets)
{
    for (int f = 0; f > countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {
            for (int r = 0; r < countRockets(akiramBossRockets); ++r)
            {
                if (rocketLive(rocket_at(akiramBossRockets, r)))
                {

                    if ((rocketPosX(rocket_at(akiramBossRockets, r)) + rocketBoundX(rocket_at(akiramBossRockets, r))) >
                            (fighterPosX(fighter_at(fl, f)) - fighterBoundX(fighter_at(fl, f))) &&
                        (rocketPosX(rocket_at(akiramBossRockets, r)) - rocketBoundX(rocket_at(akiramBossRockets, r))) <
                            (fighterPosX(fighter_at(fl, f)) + fighterBoundX(fighter_at(fl, f))) &&
                        (rocketPosY(rocket_at(akiramBossRockets, r)) + rocketBoundY(rocket_at(akiramBossRockets, r))) >
                            (fighterPosY(fighter_at(fl, f)) - fighterBoundY(fighter_at(fl, f))) &&
                        (rocketPosY(rocket_at(akiramBossRockets, r)) - rocketBoundY(rocket_at(akiramBossRockets, r))) <
                            (fighterPosY(fighter_at(fl, f)) + fighterBoundY(fighter_at(fl, f))))
                    {

                        setRocketLive(rocket_at(akiramBossRockets, r), false);
                        setFighterLives(fighter_at(fl, f), 0);

                        // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    }
                }
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------------------
//============================================ AKIRAMBOSS COLLISION =============================================
//---------------------------------------------------------------------------------------------------------------

void akiramBossSpaceshipBulletsCollision(akiramBoss *boss, bullet_list *bl, spaceship *ship)
{
    for (int b = 0; b < countBullets(bl); ++b)
    {
        if (bulletLive(bullet_at(bl, b)))
        {
            if (akiramBossIsAlive(boss))
            {

                // if the bullet finds itself inside the bounderies of comet then hit happened
                if (bulletPosX(bullet_at(bl, b)) > (akiramBossPosX(boss) - akiramBossBoundx(boss)) &&
                    bulletPosX(bullet_at(bl, b)) < (akiramBossPosX(boss) + akiramBossBoundx(boss)) &&
                    bulletPosY(bullet_at(bl, b)) < (akiramBossPosY(boss) + akiramBossBoundy(boss)) &&
                    bulletPosY(bullet_at(bl, b)) > (akiramBossPosY(boss) - akiramBossBoundy(boss)))
                {

                    setBulletLive(bullet_at(bl, b), false);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    if (akiramBossLives(boss) <= 0)
                    {
                        setAkiramBossIsAlive(boss, false);
                    }
                }
            }
        }
    }
}

void akiramBossHeadSpaceshipBulletsCollision(akiramBoss *boss, bullet_list *bl, spaceship *ship)
{
    for (int b = 0; b < countBullets(bl); ++b)
    {
        if (bulletLive(bullet_at(bl, b)))
        {
            if (akiramBossIsAlive(boss))
            {

                // if the bullet finds itself inside the bounderies of comet then hit happened
                if (bulletPosX(bullet_at(bl, b)) > (akiramBossPosX(boss) - akiramBossHeadBoundx(boss)) &&
                    bulletPosX(bullet_at(bl, b)) < (akiramBossPosX(boss) + 0) &&
                    bulletPosY(bullet_at(bl, b)) < (akiramBossPosY(boss) + akiramBossHeadBoundy(boss)) &&
                    bulletPosY(bullet_at(bl, b)) > (akiramBossPosY(boss) - akiramBossHeadBoundy(boss)))
                {

                    setBulletLive(bullet_at(bl, b), false);
                    setAkiramBossLives(boss, akiramBossLives(boss) - 1);
                    setSpaceshipScore(ship, spaceshipScore(ship) + 1);
                    setAkiramBossAfterShotCounter(boss, 10);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    if (akiramBossLives(boss) <= 0)
                    {
                        setAkiramBossIsAlive(boss, false);
                    }
                }
            }
        }
    }
}

void akiramBossSpaceshipRocketsCollision(akiramBoss *boss, rocket_list *rl, spaceship *ship)
{
    for (int r = 0; r < countRockets(rl); ++r)
    {
        if (rocketLive(rocket_at(rl, r)))
        {

            if (akiramBossIsAlive(boss))
            {

                if ((rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r))) >
                        (akiramBossPosX(boss) - akiramBossBoundx(boss)) &&
                    (rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r))) <
                        (akiramBossPosX(boss) + akiramBossBoundx(boss)) &&
                    (rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r))) >
                        (akiramBossPosY(boss) - akiramBossBoundy(boss)) &&
                    (rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r))) <
                        (akiramBossPosY(boss) + akiramBossBoundy(boss)))
                {

                    setRocketLive(rocket_at(rl, r), false);
                    setAkiramBossLives(boss, akiramBossLives(boss) - 1);
                    setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    if (akiramBossLives(boss) <= 0)
                    {
                        setAkiramBossIsAlive(boss, false);
                    }
                }
            }
        }
    }
}

void akiramBossHeadSpaceshipRocketsCollision(akiramBoss *boss, rocket_list *rl, spaceship *ship)
{
    for (int r = 0; r < countRockets(rl); ++r)
    {
        if (rocketLive(rocket_at(rl, r)))
        {

            if (akiramBossIsAlive(boss))
            {

                if ((rocketPosX(rocket_at(rl, r)) + rocketBoundX(rocket_at(rl, r))) >
                        (akiramBossPosX(boss) - akiramBossHeadBoundx(boss)) &&
                    (rocketPosX(rocket_at(rl, r)) - rocketBoundX(rocket_at(rl, r))) < (akiramBossPosX(boss) + 0) &&
                    (rocketPosY(rocket_at(rl, r)) + rocketBoundY(rocket_at(rl, r))) >
                        (akiramBossPosY(boss) - akiramBossHeadBoundy(boss)) &&
                    (rocketPosY(rocket_at(rl, r)) - rocketBoundY(rocket_at(rl, r))) <
                        (akiramBossPosY(boss) + akiramBossHeadBoundy(boss)))
                {

                    setRocketLive(rocket_at(rl, r), false);
                    setAkiramBossLives(boss, akiramBossLives(boss) - 2);
                    setSpaceshipScore(ship, spaceshipScore(ship) + 2);
                    setAkiramBossAfterShotCounter(boss, 10);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    if (akiramBossLives(boss) <= 0)
                    {
                        setAkiramBossIsAlive(boss, false);
                    }
                }
            }
        }
    }
}

void akiramBossSpaceshipMinesCollision(akiramBoss *boss, mine_list *ml, spaceship *ship)
{
    for (int m = 0; m < countMines(ml); ++m)
    {
        if (mineLive(mine_at(ml, m)))
        {

            if (akiramBossIsAlive(boss))
            {
                if ((minePosX(mine_at(ml, m)) + mineBoundX(mine_at(ml, m))) >
                        (akiramBossPosX(boss) - akiramBossBoundx(boss)) &&
                    (minePosX(mine_at(ml, m)) - mineBoundX(mine_at(ml, m))) <
                        (akiramBossPosX(boss) + akiramBossBoundx(boss)) &&
                    (minePosY(mine_at(ml, m)) + mineBoundY(mine_at(ml, m))) >
                        (akiramBossPosY(boss) - akiramBossBoundy(boss)) &&
                    (minePosY(mine_at(ml, m)) - mineBoundY(mine_at(ml, m))) <
                        (akiramBossPosY(boss) + akiramBossBoundy(boss)))
                {

                    setMineLive(mine_at(ml, m), false);
                    setAkiramBossLives(boss, akiramBossLives(boss) - 2);
                    setSpaceshipScore(ship, spaceshipScore(ship) + 1);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    if (akiramBossLives(boss) <= 0)
                    {
                        setAkiramBossIsAlive(boss, false);
                    }
                }
            }
        }
    }
}

void akiramBossHeadSpaceshipMinesCollision(akiramBoss *boss, mine_list *ml, spaceship *ship)
{
    for (int m = 0; m < countMines(ml); ++m)
    {
        if (mineLive(mine_at(ml, m)))
        {

            if (akiramBossIsAlive(boss))
            {
                if ((minePosX(mine_at(ml, m)) + mineBoundX(mine_at(ml, m))) >
                        (akiramBossPosX(boss) - akiramBossHeadBoundx(boss)) &&
                    (minePosX(mine_at(ml, m)) - mineBoundX(mine_at(ml, m))) < (akiramBossPosX(boss) + 0) &&
                    (minePosY(mine_at(ml, m)) + mineBoundY(mine_at(ml, m))) >
                        (akiramBossPosY(boss) - akiramBossHeadBoundy(boss)) &&
                    (minePosY(mine_at(ml, m)) - mineBoundY(mine_at(ml, m))) <
                        (akiramBossPosY(boss) + akiramBossHeadBoundy(boss)))
                {

                    setMineLive(mine_at(ml, m), false);
                    setAkiramBossLives(boss, akiramBossLives(boss) - 2);
                    setSpaceshipScore(ship, spaceshipScore(ship) + 1);
                    setAkiramBossAfterShotCounter(boss, 10);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                    if (akiramBossLives(boss) <= 0)
                    {
                        setAkiramBossIsAlive(boss, false);
                    }
                }
            }
        }
    }
}

void akiramBossSpaceshipLaserCollision(akiramBoss *boss, laser_beam *laser, spaceship *ship)
{
    if (laserBeamLive(laser))
    {
        if (akiramBossIsAlive(boss))
        {
            if ((laserBeamPosX(laser) + laserBeamBoundX(laser)) > (akiramBossPosX(boss) - akiramBossBoundx(boss)) &&
                (laserBeamPosX(laser) - laserBeamBoundX(laser)) < (akiramBossPosX(boss) + akiramBossBoundx(boss)) &&
                (laserBeamPosY(laser) + laserBeamBoundY(laser)) > (akiramBossPosY(boss) - akiramBossBoundy(boss)) &&
                (laserBeamPosY(laser) - laserBeamBoundY(laser)) < (akiramBossPosY(boss) + akiramBossBoundy(boss)))
            {

                // setSpaceshipScore(ship, spaceshipScore(ship) + 2);

                // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                if (akiramBossLives(boss) <= 0)
                {
                    setAkiramBossIsAlive(boss, false);
                }
            }
        }
    }
}

void akiramBossHeadSpaceshipLaserCollision(akiramBoss *boss, laser_beam *laser, spaceship *ship)
{
    if (laserBeamLive(laser))
    {
        if (akiramBossIsAlive(boss))
        {
            if ((laserBeamPosX(laser) + laserBeamBoundX(laser)) > (akiramBossPosX(boss) - akiramBossHeadBoundx(boss)) &&
                (laserBeamPosX(laser) - laserBeamBoundX(laser)) < (akiramBossPosX(boss) + 0) &&
                (laserBeamPosY(laser) + laserBeamBoundY(laser)) > (akiramBossPosY(boss) - akiramBossHeadBoundy(boss)) &&
                (laserBeamPosY(laser) - laserBeamBoundY(laser)) < (akiramBossPosY(boss) + akiramBossHeadBoundy(boss)))
            {

                setAkiramBossLives(boss, akiramBossLives(boss) - 2);
                setSpaceshipScore(ship, spaceshipScore(ship) + 2);
                setAkiramBossAfterShotCounter(boss, 10);

                // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                if (akiramBossLives(boss) <= 0)
                {
                    setAkiramBossIsAlive(boss, false);
                }
            }
        }
    }
}

void akiramBossSpaceshipCollision(akiramBoss *boss, spaceship *ship, struct screen_setting **setting)
{
    if (akiramBossIsAlive(boss))
    {

        if (spaceshipLives(ship) > 0)
        {
            if ((akiramBossPosX(boss) + akiramBossBoundx(boss)) > (spaceshipPosX(ship) - spaceshipBoundx(ship)) &&
                (akiramBossPosX(boss) - akiramBossBoundx(boss)) < (spaceshipPosX(ship) + spaceshipBoundx(ship)) &&
                (akiramBossPosY(boss) + akiramBossBoundy(boss)) > (spaceshipPosY(ship) - spaceshipBoundy(ship)) &&
                (akiramBossPosY(boss) - akiramBossBoundy(boss)) < (spaceshipPosY(ship) + spaceshipBoundy(ship)))
            {

                setSpaceshipLives(ship, spaceshipLives(ship) - 1);
                setAkiramBossLives(boss, akiramBossLives(boss) - 1);
                setSpaceshipInitPosition(ship, setting);
                setSpaceshipRebornCounter(ship, 10);

                // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                if (akiramBossLives(boss) <= 0)
                {
                    setAkiramBossIsAlive(boss, false);
                }
            }
        }
    }
}

void akiramBossRocketsSpaceshipCollision(akiramBoss *boss, rocket_list *bossRockets, spaceship *ship,
                                         struct screen_setting **setting)
{
    if (spaceshipLives(ship) > 0)
    {
        for (int r = 0; r < countRockets(bossRockets); ++r)
        {
            if (rocketLive(rocket_at(bossRockets, r)))
            {

                if ((rocketPosX(rocket_at(bossRockets, r)) + rocketBoundX(rocket_at(bossRockets, r))) >
                        (spaceshipPosX(ship) - spaceshipBoundx(ship)) &&
                    (rocketPosX(rocket_at(bossRockets, r)) - rocketBoundX(rocket_at(bossRockets, r))) <
                        (spaceshipPosX(ship) + spaceshipBoundx(ship)) &&
                    (rocketPosY(rocket_at(bossRockets, r)) + rocketBoundY(rocket_at(bossRockets, r))) >
                        (spaceshipPosY(ship) - spaceshipBoundy(ship)) &&
                    (rocketPosY(rocket_at(bossRockets, r)) - rocketBoundY(rocket_at(bossRockets, r))) <
                        (spaceshipPosY(ship) + spaceshipBoundy(ship)))
                {

                    setRocketLive(rocket_at(bossRockets, r), false);
                    setSpaceshipLives(ship, spaceshipLives(ship) - 1);
                    setSpaceshipInitPosition(ship, setting);
                    setSpaceshipRebornCounter(ship, 10);

                    // additional game logic goes here: scoring,improving weapons of spaceship,etc...
                }
            }
        }
    }
}
