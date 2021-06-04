#include "game.hpp"

void cometCollisions(spaceship *ship, comet_list *cl, fighter_list *fl, turret_list *tl, bullet_list *shipBullets,
                     rocket_list *shipRockets, mine_list *shipMines, laser_beam *shipLaser, akiramBoss *boss,
                     bullet_list *fighterBullets, bullet_list *turretBullets, rocket_list *akiramBossRockets,
                     struct screen_setting **settings)
{
    cometsSpaceshipBulletsCollision(cl, shipBullets, ship);
    cometsSpaceshipRocketsCollision(cl, shipRockets, ship);
    cometsSpaceshipMinesCollision(cl, shipMines, ship);
    cometsSpaceshipCollision(cl, ship, settings);
    cometsSpaceshipLaserCollision(cl, shipLaser, ship);
    cometsAkiramBossCollision(cl, boss);
    cometsFightersBulletsCollision(cl, fighterBullets);
    cometsTurretsBulletsCollision(cl, turretBullets);
    cometsAkiramBossRockets(cl, akiramBossRockets);
    cometsFightersCollision(cl, fl);
    cometsTurretsCollision(cl, tl);
}

void turretCollisions(spaceship *ship, turret_list *tl, fighter_list *fl, akiramBoss *boss,
                      rocket_list *akiramBossRockets, bullet_list *shipBullets, rocket_list *shipRockets,
                      mine_list *shipMines, laser_beam *shipLaser, bullet_list *turretBullets,
                      bullet_list *fighterBullets, struct screen_setting **settings)
{
    turretsSpaceshipCollision(tl, ship, settings);
    turretsSpaceshipBulletCollision(tl, shipBullets, ship);
    turretsBulletSpaceshipCollision(turretBullets, ship, settings);
    turretsSpaceshipRocketsCollision(tl, shipRockets, ship);
    turretsSpaceshipMinesCollision(tl, shipMines, ship);
    turretsSpaceshipLaserCollision(tl, shipLaser, ship);
    turretsAkiramBossCollision(tl, boss);
    turretsFightersBulletsCollision(tl, fighterBullets);
    turretsAkiramBossRocketsCollision(tl, akiramBossRockets);
    turretsFightersCollision(tl, fl);
}

void fighterCollisions(spaceship *ship, fighter_list *fl, bullet_list *shipBullets, rocket_list *shipRockets,
                       mine_list *shipMines, laser_beam *shipLaser, bullet_list *fighterBullets, turret_list *tl,
                       bullet_list *turretBullets, akiramBoss *boss, rocket_list *akiramBossRockets)
{
    fightersSpaceshipCollision(fl, ship);
    fightersBulletSpaceshipCollision(fighterBullets, ship);
    fightersSpaceshipBulletCollision(fl, shipBullets, ship);
    fightersSpaceshipRocketsCollision(fl, shipRockets, ship);
    fightersSpaceshipMinesCollision(fl, shipMines, ship);
    fightersSpaceshipLaserCollision(fl, shipLaser, ship);
    fightersAkiramBossCollision(fl, boss);
    fightersTurretsCollsion(fl, tl);
    fightersTurretsBulletsCollision(fl, turretBullets);
    fightersAkiramBossRocketsCollision(fl, akiramBossRockets);
}

void akiramBossCollisions(spaceship *ship, akiramBoss *boss, bullet_list *shipBullets, rocket_list *shipRockets,
                          mine_list *shipMines, laser_beam *shipLaser, rocket_list *akiramBossRockets,
                          struct screen_setting **settings)
{
    akiramBossSpaceshipBulletsCollision(boss, shipBullets, ship);
    akiramBossSpaceshipCollision(boss, ship, settings);
    akiramBossSpaceshipMinesCollision(boss, shipMines, ship);
    akiramBossSpaceshipRocketsCollision(boss, shipRockets, ship);
    akiramBossSpaceshipLaserCollision(boss, shipLaser, ship);
    akiramBossHeadSpaceshipBulletsCollision(boss, shipBullets, ship);
    akiramBossHeadSpaceshipRocketsCollision(boss, shipRockets, ship);
    akiramBossHeadSpaceshipMinesCollision(boss, shipMines, ship);
    akiramBossHeadSpaceshipLaserCollision(boss, shipLaser, ship);
    akiramBossRocketsSpaceshipCollision(boss, akiramBossRockets, ship, settings);
}

void drawGameObjects(spaceship *ship, bullet_list *shipBullets, rocket_list *shipRockets, mine_list *shipMines,
                     laser_beam *shipLaser, comet_list *cl, turret_list *tl, bullet_list *turretBullets,
                     fighter_list *fl, bullet_list *fighterBullets, akiramBoss *boss, rocket_list *akiramBossBullets)
{
    // ship:
    drawSpaceship(ship);
    drawBullets(shipBullets);
    drawRockets(shipRockets);
    drawMines(shipMines);
    drawLaser(shipLaser);
    //// comets:
    drawComets(cl);
    //// turrets:
    drawTurrets(tl);
    drawEnemyBullets(turretBullets);
    //// fighters:
    drawFighters(fl);
    drawEnemyBullets(fighterBullets);
    //// bosses:
    //// akiramBoss:
    drawAkiramBoss(boss);
    drawEnemyRockets(akiramBossBullets);
}

void initGameObjects(spaceship *ship, bullet_list *shipBullets, rocket_list *shipRockets, mine_list *shipMines,
                     laser_beam *shipLaser, comet_list *cl, turret_list *tl, bullet_list *turretBullets,
                     fighter_list *fl, bullet_list *fighterBullets, akiramBoss *boss, rocket_list *akiramBossRockets,
                     struct screen_setting **settings)
{
    // ship:
    initSpaceship(ship, settings);
    initBullets(shipBullets);
    initRockets(shipRockets);
    initMines(shipMines);
    initLaser(shipLaser);
    //// comets:
    initComets(cl);
    //// turrets:
    initTurrets(tl);
    initTurretBullets(turretBullets);
    //// fighters:
    initFighterBullets(fighterBullets);
    initFighters(fl, settings);
    //// bosses:
    //// akiramBoss:
    initAkiramBoss(boss, settings);
    initAkiramBossRockets(akiramBossRockets);
}

void destroyGameObjects(spaceship *ship, bullet_list *shipBullets, rocket_list *shipRockets, mine_list *shipMines,
                        laser_beam *shipLaser, comet_list *cl, turret_list *tl, bullet_list *turretBullets,
                        fighter_list *fl, bullet_list *fighterBullets, akiramBoss *boss, rocket_list *akiramBossRockets)
{
    // ship:
    destroySpaceship(ship);
    destroyBulletList(shipBullets);
    destroyRocketList(shipRockets);
    destroyMineList(shipMines);
    destroyLaserBeam(shipLaser);
    //// comets:
    destroyCometList(cl);
    //// turrets:
    destroyBulletList(turretBullets);
    destroyTurretList(tl);
    //// fighters:
    destroyBulletList(fighterBullets);
    destroyFighterList(fl);
    //// bosses:
    //// akiramBoss:
    destroyAkiramBoss(boss);
    destroyRocketList(akiramBossRockets);
}

void startUpdateGameObjects(spaceship *ship, bullet_list *shipBullets, rocket_list *shipRockets, mine_list *shipMines,
                            laser_beam *shipLaser, comet_list *cl, turret_list *tl, bullet_list *turretBullets,
                            fighter_list *fl, bullet_list *fighterBullets, akiramBoss *boss,
                            rocket_list *akiramBossRockets, struct screen_setting **settings)
{
    // ship:
    updatePrimaryWeapons(shipBullets, ship, settings);
    updateSecondaryWeapons(shipRockets, shipMines, shipLaser, ship, settings);
    //// commets:
    startComets(cl, settings);
    updateComets(cl);
    //// turrets:
    startTurrets(tl, settings);
    updateTurrets(tl);
    updateTurretBullets(turretBullets, tl, settings);
    //// fighters:
    startFighters(fl, settings);
    updateFighters(fl, ship);
    updateFighterBullets(fighterBullets, fl);
    //// bosses:
    //// akiramBoss:
    startAkiramBoss(boss, ship, settings);
    updateAkiramBoss(boss, settings);
    updateAkiramBossRockets(akiramBossRockets, boss);
}

void game(ALLEGRO_DISPLAY *display, struct screen_setting **screen_setting, struct game_setting **game_setting)
{
    // Allegro 5 installs/inits:
    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();

    // Allegro 5 structures declarations:
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

    // primitive variables:
    bool done = false, draw = false;

    // Game objects memory allocation:
    // ship:
    spaceship ship = createSpaceship();
    bullet_list bullets = createBulletList(100);
    rocket_list rockets = createRocketList(10);
    mine_list mines = createMineList(3);
    laser_beam laser = createLaserBeam();

    //// comets:
    comet_list comets = createCometList(10);
    //// turrets:
    turret_list turrets = createTurretList(5);
    bullet_list turret_bullets = createBulletList(15);
    //// fighters:
    bullet_list fighter_bullets = createBulletList(3);
    fighter_list fighters = createFighterList(7);
    //// bosses:
    //// akiramBoss:
    akiramBoss akiram = createAkiramBoss();
    rocket_list akiram_rockets = createRocketList(5);

    // Game objects initialization:
    initGameObjects(&ship, &bullets, &rockets, &mines, &laser, &comets, &turrets, &turret_bullets, &fighters,
                    &fighter_bullets, &akiram, &akiram_rockets, screen_setting);

    // Allegro 5 structures definitions:
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / framesPerSecond(game_setting));

    // Registering event sources:
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_start_timer(timer);
    while (!done)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER)
        {
            draw = true;
            if ((*game_setting)->keys[UP])
            {
                moveSpaceshipUp(&ship);
            }
            if ((*game_setting)->keys[RIGHT])
            {
                moveSpaceshipRight(&ship, screen_setting);
            }
            if ((*game_setting)->keys[DOWN])
            {
                moveSpaceshipDown(&ship, screen_setting);
            }
            if ((*game_setting)->keys[LEFT])
            {
                moveSpaceshipLeft(&ship);
            }

            // ============ START & UPDATE ============

            startUpdateGameObjects(&ship, &bullets, &rockets, &mines, &laser, &comets, &turrets, &turret_bullets,
                                   &fighters, &fighter_bullets, &akiram, &akiram_rockets, screen_setting);

            //=========== COLLISIONS =============
            // after update test collision:
            // comets:
            cometCollisions(&ship, &comets, &fighters, &turrets, &bullets, &rockets, &mines, &laser, &akiram,
                            &fighter_bullets, &turret_bullets, &akiram_rockets, screen_setting);
            //// turrets:
            turretCollisions(&ship, &turrets, &fighters, &akiram, &akiram_rockets, &bullets, &rockets, &mines, &laser,
                             &turret_bullets, &fighter_bullets, screen_setting);

            //// fighters:
            fighterCollisions(&ship, &fighters, &bullets, &rockets, &mines, &laser, &fighter_bullets, &turrets,
                              &turret_bullets, &akiram, &akiram_rockets);

            //// bosses:
            //// akiramBoss:
            akiramBossCollisions(&ship, &akiram, &bullets, &rockets, &mines, &laser, &akiram_rockets, screen_setting);
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (event.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            case ALLEGRO_KEY_UP:
                (*game_setting)->keys[UP] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                (*game_setting)->keys[RIGHT] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                (*game_setting)->keys[DOWN] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                (*game_setting)->keys[LEFT] = true;
                break;
            case ALLEGRO_KEY_SPACE:
                (*game_setting)->keys[SPACE] = true;
                firePrimaryWeapon(&bullets, &ship);
                break;
            case ALLEGRO_KEY_ALT:
                (*game_setting)->keys[ALT] = true;
                fireSecondaryWeapon(&rockets, &mines, &laser, &ship);
                break;
            case ALLEGRO_KEY_TAB:
                (*game_setting)->keys[TAB] = true;
                switchPrimaryWeapons(&ship);
                break;
            case ALLEGRO_KEY_LCTRL:
                (*game_setting)->keys[LCTRL] = true;
                switchSecondaryWeapons(&ship);
                break;
            }
        }
        if (event.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch (event.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                (*game_setting)->keys[UP] = false;
                break;
            case ALLEGRO_KEY_RIGHT:
                (*game_setting)->keys[RIGHT] = false;
                break;
            case ALLEGRO_KEY_DOWN:
                (*game_setting)->keys[DOWN] = false;
                break;
            case ALLEGRO_KEY_LEFT:
                (*game_setting)->keys[LEFT] = false;
                break;
            case ALLEGRO_KEY_SPACE:
                (*game_setting)->keys[SPACE] = false;
                break;
            case ALLEGRO_KEY_ALT:
                (*game_setting)->keys[ALT] = false;
                ceaseFireSecondaryWeapon(&laser);
                break;
            case ALLEGRO_KEY_TAB:
                (*game_setting)->keys[TAB] = false;
                break;
            case ALLEGRO_KEY_LCTRL:
                (*game_setting)->keys[LCTRL] = false;
                break;
            }
        }

        if (draw && al_is_event_queue_empty(event_queue))
        {
            draw = false;

            // =============== DRAW OBJECTS ================

            drawGameObjects(&ship, &bullets, &rockets, &mines, &laser, &comets, &turrets, &turret_bullets, &fighters,
                            &fighter_bullets, &akiram, &akiram_rockets);

            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
    }

    // Allegro 5 freeing memory:
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    // freeing memory
    destroyGameObjects(&ship, &bullets, &rockets, &mines, &laser, &comets, &turrets, &turret_bullets, &fighters,
                       &fighter_bullets, &akiram, &akiram_rockets);
}
