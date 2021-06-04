#include "bullet_list.hpp"

bullet_item createBulletItem()
{
    bullet_item bi = (bullet_item)malloc(sizeof(bullet_str));
    if (!bi)
    {
        printf("Error in createBulletItem: an error occured while allocating memory block for bullet_item.\n");
        exit(EXIT_FAILURE);
    }
    return bi;
}

void setBulletID(bullet_item bi, int id)
{
    bi->ID = id;
}

int bulletID(bullet_item bi)
{
    return (bi->ID);
}

void setBulletPosX(bullet_item bi, int posx)
{
    bi->posx = posx;
}

int bulletPosX(bullet_item bi)
{
    return (bi->posx);
}

void setBulletPosY(bullet_item bi, int posy)
{
    bi->posy = posy;
}

int bulletPosY(bullet_item bi)
{
    return (bi->posy);
}

void setBulletLive(bullet_item bi, bool live)
{
    bi->live = live;
}

bool bulletLive(bullet_item bi)
{
    return (bi->live);
}

void setBulletSpeed(bullet_item bi, int speed)
{
    bi->speed = speed;
}

int bulletSpeed(bullet_item bi)
{
    return (bi->speed);
}

void setBulletDirection(bullet_item bi, enum bullet_direction direction)
{
    bi->direction = direction;
}

int bulletDirection(bullet_item bi)
{
    return bi->direction;
}

bullet_list createBulletList(int size)
{
    bullet_list ls = (bullet_list)malloc(sizeof(struct bullet_list_type));
    if (!ls)
    {
        printf("Error createBulletList: An error occured while allocating memory block for list_type sstructure.\n");
        exit(EXIT_FAILURE);
    }
    ls->container = (bullet_item *)malloc(size * sizeof(bullet_item));
    if (!(ls->container))
    {
        free(ls);
        printf("Error createBulletList: An error occured while allocating memory block for container in list_type.\n");
        exit(EXIT_FAILURE);
    }
    ls->count = 0;
    ls->size = size;
    return ls;
}

void destroyBulletList(bullet_list *l)
{
    // first free the memory blocks in the container member:
    for (int b = 0; b < sizeBullets(l); ++b)
    {
        free(((*l)->container)[b]);
    }
    // free the memory block allocated for the container member:
    free((*l)->container);
    // free the memory block for the entire bullet_list:
    free(*l);
}

int countBullets(bullet_list *l)
{
    return ((*l)->count);
}

int sizeBullets(bullet_list *l)
{
    return ((*l)->size);
}

void resizeBulletList(bullet_list *l, int newSize)
{
    (*l)->container = (bullet_item *)realloc((*l)->container, newSize * sizeof(bullet_item));
    if (!((*l)->container))
    {
        printf(
            "Error resizeBulletList: An error occured while allocating new memory block for container in list_type.\n");
        destroyBulletList(l);
        exit(EXIT_FAILURE);
    }
    (*l)->size = newSize;
}

void push_bullet(bullet_list *l, bullet_item i)
{
    if ((*l)->count >= (*l)->size)
    {
        resizeBulletList(l, ((*l)->count) * 2);
    }
    (*l)->container[(*l)->count++] = i;
}

bullet_item bullet_at(bullet_list *l, int idx)
{
    if (idx < ((*l)->count))
    {
        return (*l)->container[idx];
    }
    printf("Error bullet_at: Given index idx is out of boundaries.\n");
    exit(EXIT_FAILURE);
}

void clearBulletList(bullet_list *l)
{
    (*l)->count = 0;
}
