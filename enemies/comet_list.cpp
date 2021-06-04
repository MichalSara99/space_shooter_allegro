#include "comet_list.hpp"

comet_item createCometItem()
{
    comet_item comet = (comet_item)malloc(sizeof(comet_str));
    if (!comet)
    {
        printf("Error initComet: an error occured while allocating memory block for comet structure.\n");
        exit(EXIT_FAILURE);
    }
    return comet;
}

void setCometID(comet_item ci, int id)
{
    ci->ID = id;
}

int cometID(comet_item ci)
{
    return (ci->ID);
}

void setCometPosX(comet_item ci, int posx)
{
    ci->posx = posx;
}

int cometPosX(comet_item ci)
{
    return (ci->posx);
}

void setCometPosY(comet_item ci, int posy)
{
    ci->posy = posy;
}

int cometPosY(comet_item ci)
{
    return (ci->posy);
}

void setCometLives(comet_item ci, int lives)
{
    ci->lives = lives;
}

int cometLives(comet_item ci)
{
    return (ci->lives);
}

void setCometSpeed(comet_item ci, int speed)
{
    ci->speed = speed;
}

int cometSpeed(comet_item ci)
{
    return (ci->speed);
}

int cometBoundX(comet_item ci)
{
    return ci->boundx;
}

void setCometBoundX(comet_item ci, int boundx)
{
    ci->boundx = boundx;
}

void setCometBoundY(comet_item ci, int boundy)
{
    ci->boundy = boundy;
}

int cometBoundY(comet_item ci)
{
    return ci->boundy;
}

comet_list createCometList(int size)
{
    comet_list ls = (comet_list)malloc(sizeof(struct comet_list_type));
    if (!ls)
    {
        printf("Error createCometList: An error occured while allocating memory block for list_type structure.\n");
        exit(EXIT_FAILURE);
    }
    ls->container = (comet_item *)malloc(size * sizeof(comet_item));
    if (!(ls->container))
    {
        free(ls);
        printf("Error createCometList: An error occured while allocating memory block for container in list_type.\n");
        exit(EXIT_FAILURE);
    }
    ls->count = 0;
    ls->size = size;
    return ls;
}

void destroyCometList(comet_list *l)
{
    // first free the memory blocks in the container member:
    for (int b = 0; b < sizeComets(l); ++b)
    {
        free(((*l)->container)[b]);
    }
    // free the memory block allocated for the container member:
    free((*l)->container);
    // free the memory block for the entire comet_list:
    free(*l);
}

int countComets(comet_list *l)
{
    return ((*l)->count);
}

int sizeComets(comet_list *l)
{
    return ((*l)->size);
}

void resizeCometList(comet_list *l, int newSize)
{
    (*l)->container = (comet_item *)realloc((*l)->container, newSize * sizeof(comet_item));
    if (!((*l)->container))
    {
        printf(
            "Error resizeCometList: An error occured while allocating new memory block for container in list_type.\n");
        destroyCometList(l);
        exit(EXIT_FAILURE);
    }
    (*l)->size = newSize;
}

void push_comet(comet_list *l, comet_item i)
{
    if ((*l)->count >= (*l)->size)
    {
        resizeCometList(l, ((*l)->count) * 2);
    }
    (*l)->container[(*l)->count++] = i;
}

comet_item comet_at(comet_list *l, int idx)
{
    if (idx < ((*l)->count))
    {
        return (*l)->container[idx];
    }
    printf("Error comet_at: Given index idx is out of boundaries.\n");
    exit(EXIT_FAILURE);
}

void clearCometList(comet_list *l)
{
    (*l)->count = 0;
}
