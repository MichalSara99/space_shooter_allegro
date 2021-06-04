#include "enemies.hpp"

//================================= COMMETS ===============================

void initComets(comet_list *cl)
{
    for (int c = 0; c < sizeComets(cl); ++c)
    {
        comet_item comet = createCometItem();
        setCometID(comet, ENEMY_ID);
        setCometLives(comet, 1);
        setCometPosX(comet, 0);
        setCometPosY(comet, 0);
        setCometSpeed(comet, 5);
        setCometBoundX(comet, 18);
        setCometBoundY(comet, 18);

        push_comet(cl, comet);
    }
}

void drawComets(comet_list *cl)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) > 0)
        {
            al_draw_filled_circle(cometPosX(comet_at(cl, c)), cometPosY(comet_at(cl, c)), 20, al_map_rgb(255, 0, 0));
        }
    }
}

void startComets(comet_list *cl, struct screen_setting **setting)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) <= 0)
        {
            if ((random() % 300) == 0)
            {
                setCometLives(comet_at(cl, c), 1);
                setCometPosX(comet_at(cl, c), screenWidth(setting));
                setCometPosY(comet_at(cl, c), 30 + rand() % (screenHeight(setting) - 60));
                break;
            }
        }
    }
}

void updateComets(comet_list *cl)
{
    for (int c = 0; c < countComets(cl); ++c)
    {
        if (cometLives(comet_at(cl, c)) > 0)
        {
            setCometPosX(comet_at(cl, c), (cometPosX(comet_at(cl, c)) - cometSpeed(comet_at(cl, c))));
            if (cometPosX(comet_at(cl, c)) < 0)
            {
                setCometLives(comet_at(cl, c), 0);
            }
        }
    }
}

//================================= TURRETS ===============================

void initTurrets(turret_list *tl)
{
    for (size_t i = 0; i < sizeTurrets(tl); ++i)
    {
        turret_item turret = createTurretItem();
        setTurretID(turret, ENEMY_ID);
        setTurretLives(turret, 2);
        setTurretPosX(turret, 0);
        setTurretPosY(turret, 0);
        setTurretSpeed(turret, 3);
        setTurretFrequency(turret, 10);
        setTurretBoundX(turret, 10);
        setTurretBoundY(turret, 10);

        push_turret(tl, turret);
    }
}

void drawTurrets(turret_list *tl)
{
    for (int t = 0; t < countTurrets(tl); ++t)
    {
        if (turretLives(turret_at(tl, t)) > 0)
        {
            al_draw_filled_rectangle(turretPosX(turret_at(tl, t)) - 9, turretPosY(turret_at(tl, t)) - 9,
                                     turretPosX(turret_at(tl, t)) + 9, turretPosY(turret_at(tl, t)) + 9,
                                     al_map_rgb(0, 255, 0));
            al_draw_filled_circle(turretPosX(turret_at(tl, t)), turretPosY(turret_at(tl, t)), 6, al_map_rgb(255, 0, 0));
        }
    }
}

void startTurrets(turret_list *tl, struct screen_setting **setting)
{
    for (int t = 0; t < countTurrets(tl); ++t)
    {
        if (turretLives(turret_at(tl, t)) <= 0)
        {
            if ((random() % 700) == 0)
            {
                setTurretLives(turret_at(tl, t), 2);
                setTurretPosX(turret_at(tl, t), screenWidth(setting));
                setTurretPosY(turret_at(tl, t), 30 + random() % (screenHeight(setting) - 60));
                break;
            }
        }
    }
}

void updateTurrets(turret_list *tl)
{
    for (int t = 0; t < countTurrets(tl); ++t)
    {
        if (turretLives(turret_at(tl, t)) > 0)
        {
            setTurretPosX(turret_at(tl, t), (turretPosX(turret_at(tl, t)) - turretSpeed(turret_at(tl, t))));
            if (turretPosX(turret_at(tl, t)) < 0)
            {
                setTurretLives(turret_at(tl, t), 0);
            }
        }
    }
}

//================================= FIGHTERS ===============================

void initFighters(fighter_list *fl, struct screen_setting **setting)
{
    for (int f = 0; f < sizeFighters(fl); ++f)
    {
        fighter_item fighter = createFighterItem();

        setFighterID(fighter, ENEMY_ID);
        setFighterLives(fighter, 2);
        setFighterPosX(fighter, 0);
        setFighterPosY(fighter, 0);
        setFighterSpeed(fighter, 7);
        setFighterFrequency(fighter, 10);
        setFighterBoundX(fighter, 15);
        setFighterBoundY(fighter, 14);
        setFighterTreshold(fighter, 0.8 * screenWidth(setting));
        setFighterState(fighter, IDLE);

        push_fighter(fl, fighter);
    }
}

void drawFighters(fighter_list *fl)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {
            // cannons:
            al_draw_filled_rectangle(fighterPosX(fighter_at(fl, f)) - 5, fighterPosY(fighter_at(fl, f)) - 9,
                                     fighterPosX(fighter_at(fl, f)) + 10, fighterPosY(fighter_at(fl, f)) - 7,
                                     al_map_rgb(255, 255, 255));
            al_draw_filled_rectangle(fighterPosX(fighter_at(fl, f)) - 5, fighterPosY(fighter_at(fl, f)) + 9,
                                     fighterPosX(fighter_at(fl, f)) + 10, fighterPosY(fighter_at(fl, f)) + 7,
                                     al_map_rgb(255, 255, 255));
            // body:
            al_draw_filled_triangle(fighterPosX(fighter_at(fl, f)) - 20, fighterPosY(fighter_at(fl, f)),
                                    fighterPosX(fighter_at(fl, f)) + 12, fighterPosY(fighter_at(fl, f)) - 11,
                                    fighterPosX(fighter_at(fl, f)) + 12, fighterPosY(fighter_at(fl, f)) + 11,
                                    al_map_rgb(255, 255, 255));
            al_draw_filled_triangle(fighterPosX(fighter_at(fl, f)) - 7, fighterPosY(fighter_at(fl, f)),
                                    fighterPosX(fighter_at(fl, f)) + 7, fighterPosY(fighter_at(fl, f)) - 9,
                                    fighterPosX(fighter_at(fl, f)) + 7, fighterPosY(fighter_at(fl, f)) + 9,
                                    al_map_rgb(0, 0, 250));
        }
    }
}

void startFighters(fighter_list *fl, struct screen_setting **setting)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) <= 0)
        {
            if ((random() % 750) == 0)
            {
                setFighterLives(fighter_at(fl, f), 3);
                setFighterPosX(fighter_at(fl, f), screenWidth(setting));
                setFighterPosY(fighter_at(fl, f), 30 + random() % (screenHeight(setting) - 60));

                break;
            }
        }
    }
}

void updateFighters(fighter_list *fl, spaceship *ship)
{
    for (int f = 0; f < countFighters(fl); ++f)
    {
        if (fighterLives(fighter_at(fl, f)) > 0)
        {

            setFighterPosX(fighter_at(fl, f), fighterPosX(fighter_at(fl, f)) - fighterSpeed(fighter_at(fl, f)));

            if (fighterState(fighter_at(fl, f)) == CHASING)
            {
                int dist = 0, dx = 0, dy = 0;
                dx = spaceshipPosX(ship) - fighterPosX(fighter_at(fl, f));
                dy = spaceshipPosY(ship) - fighterPosY(fighter_at(fl, f));
                dist = euclidDistance(fighterPosX(fighter_at(fl, f)), fighterPosY(fighter_at(fl, f)),
                                      spaceshipPosX(ship), spaceshipPosY(ship));

                if ((dist < fighterTreshold(fighter_at(fl, f))) && (dx <= -100))
                {
                    setFighterPosX(fighter_at(fl, f), fighterPosX(fighter_at(fl, f)) + 4 * sgn(dx));
                    setFighterPosY(fighter_at(fl, f),
                                   fighterPosY(fighter_at(fl, f)) + 4 * sgn(dy) /**(1 - randomInt(0, 1))*/);
                }
                else
                {
                    setFighterState(fighter_at(fl, f), IDLE);
                }
            }
            else if (fighterState(fighter_at(fl, f)) == IDLE)
            {

                int dist = 0, dx = 0, dy = 0;
                dist = euclidDistance(fighterPosX(fighter_at(fl, f)), fighterPosY(fighter_at(fl, f)),
                                      spaceshipPosX(ship), spaceshipPosY(ship));

                if (dist < fighterTreshold(fighter_at(fl, f)))
                {
                    setFighterState(fighter_at(fl, f), CHASING);
                }
            }

            if (fighterPosX(fighter_at(fl, f)) < 0)
            {
                setFighterLives(fighter_at(fl, f), 0);
            }
        }
    }
}
