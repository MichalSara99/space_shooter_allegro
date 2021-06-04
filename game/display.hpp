#pragma once
#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

// own includes:
#include "screen_settings/screen_settings.hpp"

//======================== INLINE EXTERNAL DECLARATIONS =======================
// these are callable from other units

// creates Allegro 5 game display
extern inline ALLEGRO_DISPLAY *createDisplay(int screenWidth, int screenHeight);

//============================= INLINE DEFINITIONS ============================

inline ALLEGRO_DISPLAY *createDisplay(int screenWidth, int screenHeight)
{
    if (!al_init())
    {
        al_show_native_message_box(NULL, "Allergo 5 library error", "Library error",
                                   "An error occured while loading Allegro 5 library", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        exit(EXIT_FAILURE);
    }
    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY *display = al_create_display(screenWidth, screenHeight);
    if (!display)
    {
        al_show_native_message_box(display, "Allegro 5 display error", "Display error",
                                   "An error occured while showing Allegro display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        exit(EXIT_FAILURE);
    }
    al_set_window_title(display, "SPACE SHOOTER 2D");
    return display;
}

#endif //_DISPLAY_HPP_
