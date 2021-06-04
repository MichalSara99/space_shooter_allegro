#pragma once
#ifndef _SCREEN_SETTINGS_HPP_
#define _SCREEN_SETTINGS_HPP_

#include <stdio.h>
#include <stdlib.h>

#define DEF_SCREEN_WIDTH 1190
#define DEF_SCREEN_HEIGHT 720

//========================== DECLARATIONS ===========================

struct screen_setting
{
    int screen_width;
    int screen_height;
};

/// Memory management for spaceship structure:

// Allocates memory for screen_setting structure
extern struct screen_setting *createScreenSetting();
// Deallocates memory for screen_setting structure
extern void destroyScreenSetting(struct screen_setting **setting);

/// Other methods:

// Initialize screen_setting:
extern void initScreenSetting(struct screen_setting **setting);
// Set screen height:
extern void setScreenHeight(struct screen_setting **setting, int height);
// Set screen width:
extern void setScreenWidth(struct screen_setting **setting, int width);
// Get screen height:
extern int screenHeight(struct screen_setting **setting);
// Get screen width:
extern int screenWidth(struct screen_setting **setting);

#endif //_SCREEN_SETTINGS_HPP_
