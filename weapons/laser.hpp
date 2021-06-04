#pragma once
#ifndef _LASER_HPP_
#define _LASER_HPP_

#include <stdio.h>
#include <stdlib.h>

struct laser
{
    int ID;
    int posx, posy;
    int boundy, boundx;
    bool live;
};

// === type definition of laser beam ===

// Allias for the original laser structure
typedef struct laser laser_str;

// Allias for the pointer to the laser structure
typedef laser_str *laser_beam;

// ==================================================

// ============== SETTER/GETTER =====================

// Create laser_beam
extern laser_beam createLaserBeam();

// Destroy laser_beam
extern void destroyLaserBeam(laser_beam *laser);

// Set laser_beam ID:
extern void setLaserBeamID(laser_beam *laser, int id);

// Get laser_beam ID
extern int laserBeamID(laser_beam *laser);

// Set laser_beam position X:
extern void setLaserBeamPosX(laser_beam *laser, int posx);

// Get laser_beam position X:
extern int laserBeamPosX(laser_beam *laser);

// Set laser_beam position Y:
extern void setLaserBeamPosY(laser_beam *laser, int posy);

// Get laser_beam position Y:
extern int laserBeamPosY(laser_beam *laser);

// Set laser_beam boundary X:
extern void setLaserBeamBoundX(laser_beam *laser, int boundx);

// Get laser_beam boundary X:
extern int laserBeamBoundX(laser_beam *laser);

// Set laser_beam boundary Y:
extern void setLaserBeamBoundY(laser_beam *laser, int boundy);

// Get laser_beam boundary X:
extern int laserBeamBoundY(laser_beam *laser);

// Set laser_beam live:
extern void setLaserBeamLive(laser_beam *laser, bool live);

// Get laser_beam live:
extern bool laserBeamLive(laser_beam *laser);

#endif //_LASER_HPP_
