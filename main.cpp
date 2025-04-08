#include "graphics.h"
#include "const.h"
#include "logic.h"
#include "music.h"
#include "play.h"
#include "OpenGame.h"
#include "EndGame.h"

int main(int argc, char* argv[]) {
    SDL_Event event;
    bool run = true;

    Opengame(event, run);

    if (run) {
        runGame();
    }

    SDL_Quit();
    TTF_Quit();

    return 0;
}
