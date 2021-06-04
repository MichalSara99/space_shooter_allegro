#include "mine_list.hpp"

mine_item createMineItem()
{
    mine_item mi = (mine_item)malloc(sizeof(mine_str));
    if (!mi)
    {
        printf("Error in createMineItem: an error occured while allocating memory block for mine_item.\n");
        exit(EXIT_FAILURE);
    }
    return mi;
}

void setMineID(mine_item mi, int id)
{
    mi->ID = id;
}

int mineID(mine_item mi)
{
    return (mi->ID);
}

void setMinePosX(mine_item mi, int posx)
{
    mi->posx = posx;
}

int minePosX(mine_item mi)
{
    return (mi->posx);
}

void setMinePosY(mine_item mi, int posy)
{
    mi->posy = posy;
}

int minePosY(mine_item mi)
{
    return (mi->posy);
}

void setMineLive(mine_item mi, bool live)
{
    mi->live = live;
}

bool mineLive(mine_item mi)
{
    return (mi->live);
}

void setMineSpeed(mine_item mi, int speed)
{
    mi->speed = speed;
}

int mineSpeed(mine_item mi)
{
    return (mi->speed);
}

void setMineBoundX(mine_item mi, int boundx)
{
    mi->boundx = boundx;
}

int mineBoundX(mine_item mi)
{
    return mi->boundx;
}

void setMineBoundY(mine_item mi, int boundy)
{
    mi->boundy = boundy;
}

int mineBoundY(mine_item mi)
{
    return mi->boundy;
}

mine_list createMineList(int size)
{
    mine_list ls = (mine_list)malloc(sizeof(struct mine_list_type));
    if (!ls)
    {
        printf("Error createMineList: An error occured while allocating memory block for list_type sstructure.\n");
        exit(EXIT_FAILURE);
    }
    ls->container = (mine_item *)malloc(size * sizeof(mine_item));
    if (!(ls->container))
    {
        free(ls);
        printf("Error createMineList: An error occured while allocating memory block for container in list_type.\n");
        exit(EXIT_FAILURE);
    }
    ls->count = 0;
    ls->size = size;
    return ls;
}

int sizeMines(mine_list *l)
{
    return ((*l)->size);
}

void destroyMineList(mine_list *l)
{
    // first free the memory blocks in the container member:
    for (int b = 0; b < sizeMines(l); ++b)
    {
        free(((*l)->container)[b]);
    }
    // free the memory block allocated for the container member:
    free((*l)->container);
    // free the memory block for the entire bullet_list:
    free(*l);
}

int countMines(mine_list *l)
{
    return ((*l)->count);
}

void resizeMineList(mine_list *l, int newSize)
{
    (*l)->container = (mine_item *)realloc((*l)->container, newSize * sizeof(mine_item));
    if (!((*l)->container))
    {
        printf(
            "Error resizeBulletList: An error occured while allocating new memory block for container in list_type.\n");
        destroyMineList(l);
        exit(EXIT_FAILURE);
    }
    (*l)->size = newSize;
}

void push_mine(mine_list *l, mine_item i)
{
    if ((*l)->count >= (*l)->size)
    {
        resizeMineList(l, ((*l)->count) * 2);
    }
    (*l)->container[(*l)->count++] = i;
}

mine_item mine_at(mine_list *l, int idx)
{
    if (idx < ((*l)->count))
    {
        return (*l)->container[idx];
    }
    printf("Error mine_at: Given index idx is out of boundaries.\n");
    exit(EXIT_FAILURE);
}

void clearMineList(mine_list *l)
{
    (*l)->count = 0;
}
