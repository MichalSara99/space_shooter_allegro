#include "turret_list.hpp"

turret_item createTurretItem()
{
    turret_item turret = (turret_item)malloc(sizeof(turret_str));
    if (!turret)
    {
        printf("Error createTurretItem: an error occured while allocating memory block for turret structure.\n");
        exit(EXIT_FAILURE);
    }
    return turret;
}

void setTurretID(turret_item ti, int id)
{
    ti->ID = id;
}

int turretID(turret_item ti)
{
    return ti->ID;
}

void setTurretPosX(turret_item ti, int posx)
{
    ti->posx = posx;
}

int turretPosX(turret_item ti)
{
    return ti->posx;
}

void setTurretPosY(turret_item ti, int posy)
{
    ti->posy = posy;
}

int turretPosY(turret_item ti)
{
    return ti->posy;
}

void setTurretLives(turret_item ti, int lives)
{
    ti->lives = lives;
}

int turretLives(turret_item ti)
{
    return ti->lives;
}

void setTurretSpeed(turret_item ti, int speed)
{
    ti->speed = speed;
}

int turretSpeed(turret_item ti)
{
    return ti->speed;
}

void setTurretBoundX(turret_item ti, int boundx)
{
    ti->boundx = boundx;
}

int turretBoundX(turret_item ti)
{
    return ti->boundx;
}

void setTurretBoundY(turret_item ti, int boundy)
{
    ti->boundy = boundy;
}

int turretBoundY(turret_item ti)
{
    return ti->boundy;
}

void setTurretFrequency(turret_item ti, int frequency)
{
    ti->shoot_frequency = frequency;
}

int turretFrequency(turret_item it)
{
    return it->shoot_frequency;
}

turret_list createTurretList(int size)
{
    turret_list ls = (turret_list)malloc(sizeof(struct turret_list_type));
    if (!ls)
    {
        printf("Error createTurretList: An error occured while allocating memory block for list_type structure.\n");
        exit(EXIT_FAILURE);
    }
    ls->container = (turret_item *)malloc(size * sizeof(turret_item));
    if (!(ls->container))
    {
        free(ls);
        printf("Error createTurretList: An error occured while allocating memory block for container in list_type.\n");
        exit(EXIT_FAILURE);
    }
    ls->count = 0;
    ls->size = size;
    return ls;
}

void destroyTurretList(turret_list *l)
{
    for (size_t t = 0; t < sizeTurrets(l); ++t)
    {
        free(((*l)->container)[t]);
    }
    free((*l)->container);
    free((*l));
}

int sizeTurrets(turret_list *l)
{
    return (*l)->size;
}

int countTurrets(turret_list *l)
{
    return (*l)->count;
}

void resizeTurretList(turret_list *l, int newSize)
{
    (*l)->container = (turret_item *)realloc((*l)->container, newSize * sizeof(turret_item));
    if (!((*l)->container))
    {
        printf(
            "Error resizeTurretList: An error occured while allocating new memory block for container in list_type.\n");
        destroyTurretList(l);
        exit(EXIT_FAILURE);
    }
    (*l)->size = newSize;
}

void push_turret(turret_list *l, turret_item i)
{
    if (countTurrets(l) >= sizeTurrets(l))
    {
        resizeTurretList(l, countTurrets(l) * 2);
    }
    (*l)->container[(*l)->count++] = i;
}

turret_item turret_at(turret_list *l, int idx)
{
    if (idx >= countTurrets(l))
    {
        printf("Error comet_at: Given index idx is out of boundaries.\n");
        exit(EXIT_FAILURE);
    }
    return ((*l)->container)[idx];
}

void clearTurretList(turret_list *l)
{
    (*l)->count = 0;
}
