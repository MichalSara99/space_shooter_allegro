#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

// own includes
#include "game/display.hpp"
#include "game/game.hpp"
#include "game_settings/game_settings.hpp"
#include "screen_settings/screen_settings.hpp"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    struct screen_setting *screen_setting = createScreenSetting();
    struct game_setting *game_setting = createGameSetting();
    initScreenSetting(&screen_setting);
    initGameSetting(&game_setting);

    ALLEGRO_DISPLAY *display = createDisplay(screenWidth(&screen_setting), screenHeight(&screen_setting));

    game(display, &screen_setting, &game_setting);

    // Deallocating memory blocks:
    destroyScreenSetting(&screen_setting);
    destroyGameSetting(&game_setting);
    al_destroy_display(display);

    return 0;
}
