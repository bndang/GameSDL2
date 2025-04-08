#ifndef _MUSIC__H
#define _MUSIC__H

#include <SDL_mixer.h>
#include "graphics.h"

class Music{
private:
    Mix_Music* gMusic;
    Mix_Chunk* gChunk;

public:
    void initM();

    Mix_Music *loadMusic(const char* path);
    void playMusic();

    Mix_Chunk* loadSound(const char* path);
    void playClickSound();

    void quitM();
};

#endif // _MUSIC__H

