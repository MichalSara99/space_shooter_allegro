#pragma once
#ifndef _GAME_SETTINGS_HPP_
#define _GAME_SETTINGS_HPP_

#include <stdio.h>
#include <stdlib.h>

#define PRIVATE static
#define DEF_FPS 60.0
#define KEYS_CNT 5

//============================== DECLARATIONS =============================

enum CONTROLS
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
    SPACE,
    TAB,
    ALT,
    LCTRL
};

struct game_setting
{
    bool keys[KEYS_CNT];
    double fps;
};

//=============================== DEFINITIONS =============================

/// Memory management for spaceship structure:

// Allocates memory for game_setting structure
extern struct game_setting *createGameSetting();
// Deallocates memory for screen_setting structure
extern void destroyGameSetting(struct game_setting **settings);

/// Other methods:

// Initialize game_setting structure:
extern void initGameSetting(struct game_setting **setting);
// Set frames per second member of game_setting structure:
extern void setFramesPerSecond(struct game_setting **setting, double fps);
// Get frames per second member of game_setting structure:
extern double framesPerSecond(struct game_setting **setting);

#endif //_GAME_SETTINGS_HPP_
