#include "game_settings.hpp"

struct game_setting *createGameSetting()
{
    struct game_setting *setting = (struct game_setting *)malloc(sizeof(struct game_setting));
    if (!setting)
    {
        printf("Game_setting error: An error occured while allocating memory block for game_setting structure.\n");
        exit(EXIT_FAILURE);
    }
    return setting;
}

void destroyGameSetting(struct game_setting **setting)
{
    if (setting)
    {
        free(*setting);
    }
    else
    {
        printf("Destroy game_setting error: game_setting struct object has not been created yet.\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void initGameSetting(struct game_setting **setting)
{
    if ((*setting))
    {
        (*setting)->fps = DEF_FPS;
        (*setting)->keys[UP] = false;
        (*setting)->keys[DOWN] = false;
        (*setting)->keys[LEFT] = false;
        (*setting)->keys[RIGHT] = false;
    }
    else
    {
        printf("Init game_setting error: game_setting struct object has not been created yet.\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void setFramesPerSecond(struct game_setting **setting, double fps)
{
    (*setting)->fps = fps;
}

double framesPerSecond(struct game_setting **setting)
{
    return (*setting)->fps;
}
