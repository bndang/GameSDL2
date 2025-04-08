#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>

#include "const.h"
#include "logic.h"

class Graphics {
private:
    SDL_Texture *cellEmpty, *cellX, *cellO;
    SDL_Texture* background;

public:
    void initG();

    void renderTexture(SDL_Texture *texture, int x, int y);

    void render(const Tictactoe& game);

    void quitG();
};

#endif // _GRAPHICS__H

