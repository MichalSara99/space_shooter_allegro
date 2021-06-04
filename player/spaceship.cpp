#include "spaceship.hpp"

// struct spaceship *createSpaceship() {
spaceship createSpaceship()
{
    spaceship ship = (spaceship)malloc(sizeof(struct ship));
    if (!ship)
    {
        printf("Spaceship struct error: An error occured while allocating memory block for spaceship structure.\n");
        exit(EXIT_FAILURE);
    }
    return ship;
}

void destroySpaceship(spaceship *ship)
{
    if ((*ship))
    {
        free(*ship);
    }
    return;
}

void initSpaceship(spaceship *ship, struct screen_setting **setting)
{
    if ((*ship))
    {
        (*ship)->posx = 40;
        (*ship)->posy = screenHeight(setting) / 2;
        (*ship)->ID = SPACESHIP_ID;
        (*ship)->lives = 20;
        (*ship)->speed = 7;
        (*ship)->boundx = 6;
        (*ship)->boundy = 7;
        (*ship)->score = 25;
        (*ship)->rebornCounter = 10;
        (*ship)->primaryWeaponLevel = ship_weapons_primary::SHOTGUN;
        (*ship)->switchPrimaryWeapon = ship_weapons_primary::ONE_CANNON;
        (*ship)->secondaryWeaponLevel = ship_weapons_secondary::LASER;
        (*ship)->switchSecondaryWeapon = ship_weapons_secondary::ROCKET;
    }
}

void drawSpaceship(spaceship *ship)
{
    if (spaceshipRebornCounter(ship) > 0)
    {
        if (random() % 7 == 0)
        {
            // turrets
            al_draw_filled_rectangle((*ship)->posx, (*ship)->posy - 9, (*ship)->posx + 10, (*ship)->posy - 7,
                                     al_map_rgb(255, 0, 0));
            al_draw_filled_rectangle((*ship)->posx, (*ship)->posy + 9, (*ship)->posx + 10, (*ship)->posy + 7,
                                     al_map_rgb(255, 0, 0));
            // body:
            al_draw_filled_triangle((*ship)->posx - 12, (*ship)->posy - 17, (*ship)->posx + 12, (*ship)->posy,
                                    (*ship)->posx - 12, (*ship)->posy + 17, al_map_rgb(0, 255, 0));
            al_draw_filled_rectangle((*ship)->posx - 12, (*ship)->posy - 2, (*ship)->posx + 15, (*ship)->posy + 2,
                                     al_map_rgb(0, 0, 255));
            setSpaceshipRebornCounter(ship, spaceshipRebornCounter(ship) - 1);
        }
    }
    else
    {
        // turrets
        al_draw_filled_rectangle((*ship)->posx, (*ship)->posy - 9, (*ship)->posx + 10, (*ship)->posy - 7,
                                 al_map_rgb(255, 0, 0));
        al_draw_filled_rectangle((*ship)->posx, (*ship)->posy + 9, (*ship)->posx + 10, (*ship)->posy + 7,
                                 al_map_rgb(255, 0, 0));
        // body:
        al_draw_filled_triangle((*ship)->posx - 12, (*ship)->posy - 17, (*ship)->posx + 12, (*ship)->posy,
                                (*ship)->posx - 12, (*ship)->posy + 17, al_map_rgb(0, 255, 0));
        al_draw_filled_rectangle((*ship)->posx - 12, (*ship)->posy - 2, (*ship)->posx + 15, (*ship)->posy + 2,
                                 al_map_rgb(0, 0, 255));
    }
}

void moveSpaceshipUp(spaceship *ship)
{
    (*ship)->posy -= (*ship)->speed;
    if ((*ship)->posy < 0)
    {
        (*ship)->posy = 0;
    }
}

void moveSpaceshipRight(spaceship *ship, struct screen_setting **setting)
{
    (*ship)->posx += (*ship)->speed;
    if ((*ship)->posx > (screenWidth(setting) * 0.75))
    {
        (*ship)->posx = screenWidth(setting) * 0.75;
    }
}

void moveSpaceshipDown(spaceship *ship, struct screen_setting **setting)
{
    (*ship)->posy += (*ship)->speed;
    if ((*ship)->posy > screenHeight(setting))
    {
        (*ship)->posy = screenHeight(setting);
    }
}

void moveSpaceshipLeft(spaceship *ship)
{
    (*ship)->posx -= (*ship)->speed;
    if ((*ship)->posx < 0)
    {
        (*ship)->posx = 0;
    }
}

int spaceshipPosX(spaceship *ship)
{
    return ((*ship)->posx);
}

void setSpaceshipPosX(spaceship *ship, int posX)
{
    (*ship)->posx = posX;
}

int spaceshipPosY(spaceship *ship)
{
    return ((*ship)->posy);
}

void setSpaceshipPosY(spaceship *ship, int posY)
{
    (*ship)->posy = posY;
}

void setSpaceshipLives(spaceship *ship, int lives)
{
    (*ship)->lives = lives;
}

int spaceshipLives(spaceship *ship)
{
    return (*ship)->lives;
}

int spaceshipSpeed(spaceship *ship)
{
    return ((*ship)->speed);
}

void setSpaceshipSpeed(spaceship *ship, int speed)
{
    (*ship)->speed = speed;
}

int spaceshipScore(spaceship *ship)
{
    return ((*ship)->score);
}

void setSpaceshipScore(spaceship *ship, int score)
{
    (*ship)->score = score;
}

int spaceshipBoundy(spaceship *ship)
{
    return (*ship)->boundy;
}

void setSpaceshipBoundy(spaceship *ship, int boundy)
{
    (*ship)->boundy = boundy;
}

int spaceshipBoundx(spaceship *ship)
{
    return (*ship)->boundx;
}

void setSpaceshipBoundx(spaceship *ship, int boundx)
{
    (*ship)->boundx = boundx;
}

enum ship_weapons_primary primaryWeaponLevel(spaceship *ship)
{
    return (*ship)->primaryWeaponLevel;
}

void setPrimaryWeaponLevel(spaceship *ship, enum ship_weapons_primary level)
{
    (*ship)->primaryWeaponLevel = level;
}

enum ship_weapons_primary switchPrimaryWeapon(spaceship *ship)
{
    return (*ship)->switchPrimaryWeapon;
}

void setSwitchPrimaryWeapon(spaceship *ship, enum ship_weapons_primary level)
{
    (*ship)->switchPrimaryWeapon = level;
}

enum ship_weapons_secondary secondaryWeaponLevel(spaceship *ship)
{
    return (*ship)->secondaryWeaponLevel;
}

void setSecondaryWeaponLevel(spaceship *ship, enum ship_weapons_secondary level)
{
    (*ship)->secondaryWeaponLevel = level;
}

enum ship_weapons_secondary switchSecondaryWeapon(spaceship *ship)
{
    return (*ship)->switchSecondaryWeapon;
}

void setSwitchSecondaryWeapon(spaceship *ship, enum ship_weapons_secondary level)
{
    (*ship)->switchSecondaryWeapon = level;
}

extern void setSpaceshipRebornCounter(spaceship *ship, int counter)
{
    (*ship)->rebornCounter = counter;
}

extern int spaceshipRebornCounter(spaceship *ship)
{
    return ((*ship)->rebornCounter);
}

void setSpaceshipInitPosition(spaceship *ship, struct screen_setting **setting)
{
    (*ship)->posx = 40;
    (*ship)->posy = screenHeight(setting) / 2;
}
