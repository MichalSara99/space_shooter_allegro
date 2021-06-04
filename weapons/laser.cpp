#include "laser.hpp"

laser_beam createLaserBeam()
{
    laser_beam laser = (laser_beam)malloc(sizeof(laser_str));
    if (!laser)
    {
        printf("Laser struct error: An error occured while allocating memory block for laser structure.\n");
        exit(EXIT_FAILURE);
    }
    return laser;
}

void destroyLaserBeam(laser_beam *laser)
{
    if ((*laser))
    {
        free(*laser);
    }
    return;
}

void setLaserBeamID(laser_beam *laser, int id)
{
    (*laser)->ID = id;
}

int laserBeamID(laser_beam *laser)
{
    return (*laser)->ID;
}

void setLaserBeamPosX(laser_beam *laser, int posx)
{
    (*laser)->posx = posx;
}

int laserBeamPosX(laser_beam *laser)
{
    return (*laser)->posx;
}

void setLaserBeamPosY(laser_beam *laser, int posy)
{
    (*laser)->posy = posy;
}

int laserBeamPosY(laser_beam *laser)
{
    return (*laser)->posy;
}

void setLaserBeamBoundX(laser_beam *laser, int boundx)
{
    (*laser)->boundx = boundx;
}

int laserBeamBoundX(laser_beam *laser)
{
    return (*laser)->boundx;
}

void setLaserBeamBoundY(laser_beam *laser, int boundy)
{
    (*laser)->boundy = boundy;
}

int laserBeamBoundY(laser_beam *laser)
{
    return (*laser)->boundy;
}

void setLaserBeamLive(laser_beam *laser, bool live)
{
    (*laser)->live = live;
}

bool laserBeamLive(laser_beam *laser)
{
    return (*laser)->live;
}
