#include "fighter_list.hpp"

fighter_item createFighterItem()
{
    fighter_item fighter = (fighter_item)malloc(sizeof(fighter_str));
    if (!fighter)
    {
        printf("Error createFighterItem: an error occured while allocating memory block for fighter structure.\n");
        exit(EXIT_FAILURE);
    }
    return fighter;
}

void setFighterID(fighter_item fi, int id)
{
    fi->ID = id;
}

int fighterID(fighter_item fi)
{
    return fi->ID;
}

void setFighterPosX(fighter_item fi, int posx)
{
    fi->posx = posx;
}

int fighterPosX(fighter_item fi)
{
    return fi->posx;
}

void setFighterPosY(fighter_item fi, int posy)
{
    fi->posy = posy;
}

int fighterPosY(fighter_item fi)
{
    return fi->posy;
}

void setFighterLives(fighter_item fi, int lives)
{
    fi->lives = lives;
}

int fighterLives(fighter_item fi)
{
    return fi->lives;
}

void setFighterSpeed(fighter_item fi, int speed)
{
    fi->speed = speed;
}

int fighterSpeed(fighter_item fi)
{
    return fi->speed;
}

void setFighterBoundX(fighter_item fi, int boundx)
{
    fi->boundx = boundx;
}

int fighterBoundX(fighter_item fi)
{
    return fi->boundx;
}

void setFighterBoundY(fighter_item fi, int boundy)
{
    fi->boundy = boundy;
}

int fighterBoundY(fighter_item fi)
{
    return fi->boundy;
}

void setFighterFrequency(fighter_item fi, int frequency)
{
    fi->shoot_frequency = frequency;
}

int fighterFrequency(fighter_item fi)
{
    return fi->shoot_frequency;
}

void setFighterState(fighter_item fi, enum fighter_state state)
{
    fi->state = state;
}

enum fighter_state fighterState(fighter_item fi)
{
    return (fi->state);
}

void setFighterTreshold(fighter_item fi, int treshold)
{
    fi->treshold = treshold;
}

int fighterTreshold(fighter_item fi)
{
    return (fi->treshold);
}

fighter_list createFighterList(int size)
{
    fighter_list ls = (fighter_list)malloc(sizeof(struct fighter_list_type));
    if (!ls)
    {
        printf("Error createFighterList: An error occured while allocating memory block for list_type structure.\n");
        exit(EXIT_FAILURE);
    }
    ls->container = (fighter_item *)malloc(size * sizeof(fighter_item));
    if (!(ls->container))
    {
        free(ls);
        printf("Error createFighterList: An error occured while allocating memory block for container in list_type.\n");
        exit(EXIT_FAILURE);
    }
    ls->count = 0;
    ls->size = size;
    return ls;
}

void destroyFighterList(fighter_list *l)
{
    for (size_t t = 0; t < sizeFighters(l); ++t)
    {
        free(((*l)->container)[t]);
    }
    free((*l)->container);
    free((*l));
}

int sizeFighters(fighter_list *l)
{
    return (*l)->size;
}

int countFighters(fighter_list *l)
{
    return (*l)->count;
}

void resizeFighterList(fighter_list *l, int newSize)
{
    (*l)->container = (fighter_item *)realloc((*l)->container, newSize * sizeof(fighter_item));
    if (!((*l)->container))
    {
        printf("Error resizeFighterList: An error occured while allocating new memory block for container in "
               "list_type.\n");
        destroyFighterList(l);
        exit(EXIT_FAILURE);
    }
    (*l)->size = newSize;
}

void push_fighter(fighter_list *l, fighter_item i)
{
    if (countFighters(l) >= sizeFighters(l))
    {
        resizeFighterList(l, countFighters(l) * 2);
    }
    (*l)->container[(*l)->count++] = i;
}

fighter_item fighter_at(fighter_list *l, int idx)
{
    if (idx >= countFighters(l))
    {
        printf("Error comet_at: Given index idx is out of boundaries.\n");
        exit(EXIT_FAILURE);
    }
    return ((*l)->container)[idx];
}

void clearFighterList(fighter_list *l)
{
    (*l)->count = 0;
}
