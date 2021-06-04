#include "rocket_list.hpp"

rocket_item createRocketItem()
{
    rocket_item ri = (rocket_item)malloc(sizeof(rocket_str));
    if (!ri)
    {
        printf("Error in createRocketItem: an error occured while allocating memory block for rocket_item.\n");
        exit(EXIT_FAILURE);
    }
    return ri;
}

void setRocketID(rocket_item ri, int id)
{
    ri->ID = id;
}

int rocketID(rocket_item ri)
{
    return (ri->ID);
}

void setRocketPosX(rocket_item ri, int posx)
{
    ri->posx = posx;
}

int rocketPosX(rocket_item ri)
{
    return (ri->posx);
}

void setRocketPosY(rocket_item ri, int posy)
{
    ri->posy = posy;
}

int rocketPosY(rocket_item ri)
{
    return (ri->posy);
}

void setRocketLive(rocket_item ri, bool live)
{
    ri->live = live;
}

bool rocketLive(rocket_item ri)
{
    return (ri->live);
}

void setRocketSpeed(rocket_item ri, int speed)
{
    ri->speed = speed;
}

int rocketSpeed(rocket_item ri)
{
    return (ri->speed);
}

void setRocketBoundX(rocket_item ri, int boundx)
{
    ri->boundx = boundx;
}

int rocketBoundX(rocket_item ri)
{
    return ri->boundx;
}

void setRocketBoundY(rocket_item ri, int boundy)
{
    ri->boundy = boundy;
}

int rocketBoundY(rocket_item ri)
{
    return ri->boundy;
}

void setRocketDirection(rocket_item ri, enum rocket_direction direction)
{
    ri->direction = direction;
}

int rocketDirection(rocket_item ri)
{
    return ri->direction;
}

rocket_list createRocketList(int size)
{
    rocket_list ls = (rocket_list)malloc(sizeof(struct rocket_list_type));
    if (!ls)
    {
        printf("Error createRocketList: An error occured while allocating memory block for list_type sstructure.\n");
        exit(EXIT_FAILURE);
    }
    ls->container = (rocket_item *)malloc(size * sizeof(rocket_item));
    if (!(ls->container))
    {
        free(ls);
        printf("Error createRocketList: An error occured while allocating memory block for container in list_type.\n");
        exit(EXIT_FAILURE);
    }
    ls->count = 0;
    ls->size = size;
    return ls;
}

int sizeRockets(rocket_list *l)
{
    return ((*l)->size);
}

void destroyRocketList(rocket_list *l)
{
    // first free the memory blocks in the container member:
    for (int b = 0; b < sizeRockets(l); ++b)
    {
        free(((*l)->container)[b]);
    }
    // free the memory block allocated for the container member:
    free((*l)->container);
    // free the memory block for the entire bullet_list:
    free(*l);
}

int countRockets(rocket_list *l)
{
    return ((*l)->count);
}

void resizeRocketList(rocket_list *l, int newSize)
{
    (*l)->container = (rocket_item *)realloc((*l)->container, newSize * sizeof(rocket_item));
    if (!((*l)->container))
    {
        printf(
            "Error resizeBulletList: An error occured while allocating new memory block for container in list_type.\n");
        destroyRocketList(l);
        exit(EXIT_FAILURE);
    }
    (*l)->size = newSize;
}

void push_rocket(rocket_list *l, rocket_item i)
{
    if ((*l)->count >= (*l)->size)
    {
        resizeRocketList(l, ((*l)->count) * 2);
    }
    (*l)->container[(*l)->count++] = i;
}

rocket_item rocket_at(rocket_list *l, int idx)
{
    if (idx < ((*l)->count))
    {
        return (*l)->container[idx];
    }
    printf("Error rocket_at: Given index idx is out of boundaries.\n");
    exit(EXIT_FAILURE);
}

void clearRocketList(rocket_list *l)
{
    (*l)->count = 0;
}
