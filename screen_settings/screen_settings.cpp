#include "screen_settings.hpp"

struct screen_setting *createScreenSetting()
{
    struct screen_setting *setting = (struct screen_setting *)malloc(sizeof(struct screen_setting));
    if (!setting)
    {
        printf("Screen_setting error: An error occured while allocating memory block for screen_setting structure.\n");
        exit(EXIT_FAILURE);
    }
    return setting;
}

void destroyScreenSetting(struct screen_setting **setting)
{
    if ((*setting))
    {
        free(*setting);
    }
    else
    {
        printf("Destroy screen_setting error: screen_setting struct object has not been created yet.\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void initScreenSetting(struct screen_setting **setting)
{
    if ((*setting))
    {
        (*setting)->screen_height = DEF_SCREEN_HEIGHT;
        (*setting)->screen_width = DEF_SCREEN_WIDTH;
    }
    else
    {
        printf("Init screen_setting error: screen_setting struct object has not been created yet.\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void setScreenHeight(struct screen_setting **setting, int height)
{
    if (*setting)
    {
        (*setting)->screen_height = height;
    }
    else
    {
        printf("SetScreenHeight error: screen_setting struct object has not been created yet.\n");
        exit(EXIT_FAILURE);
    }
}

void setScreenWidth(struct screen_setting **setting, int width)
{
    if (*setting)
    {
        (*setting)->screen_width = width;
    }
    else
    {
        printf("SetScreenWidth error: screen_setting struct object has not been created yet.\n");
        exit(EXIT_FAILURE);
    }
}

int screenHeight(struct screen_setting **setting)
{
    if (*setting)
    {
        return (*setting)->screen_height;
    }
    printf("ScreenHeight error: screen_setting struct object has not been created yet.\n");
    exit(EXIT_FAILURE);
}

int screenWidth(struct screen_setting **setting)
{
    if (*setting)
    {
        return (*setting)->screen_width;
    }
    printf("ScreenWidth error: screen_setting struct object has not been created yet.\n");
    exit(EXIT_FAILURE);
}
